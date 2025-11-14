#include "widget.h"
#include "ui_widget.h"
#include "serialmanager.h"
#include <QSerialPortInfo>
#include <QDateTime>
#include <QTimer>
#include <QRegularExpression>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , m_workerThread(nullptr)
    , m_serialmanager(nullptr)
    , isOpened(false)
    , isPaused(false)
    , rxCount(0)
    , txCount(0)
{
    ui->setupUi(this);
    
    // 初始化自动发送定时器并设置对象名，确保connectSlotsByName能找到
    autoSendTimer = new QTimer(this);

    // 连接定时器超时信号与槽函数
    connect(autoSendTimer, &QTimer::timeout, this, &Widget::autoSendTimerTimeout);
    
    // 默认选择ASCII发送和ASCII显示
    ui->radioAsciiSend->setChecked(true);
    ui->radioAsciiReceive->setChecked(true);
    
    // 初始化自动发送间隔为1000ms
    ui->spinBoxInterval->setValue(1000);
    
    // 初始化状态指示
    ui->labelStatus->setText("未连接");
    ui->labelRxCount->setText("接收：0");
    ui->labelTxCount->setText("发送：0");
    ui->textEditReceive->setReadOnly(true);// 接收文本只读
    
    setupSerialThread();// 初始化串口线程：创建线程、工作对象，连接信号槽

    emit initcombo();// 请求刷新串口列表
}

Widget::~Widget()
{
    // 安全关闭线程
    if (m_workerThread) {
        emit closePortRequested();//发送关闭串口信号
        m_workerThread->quit();
        m_workerThread->wait();
        delete m_workerThread;
    }
    delete ui;

}

// 初始化串口线程：创建线程、工作对象，连接信号槽
void Widget::setupSerialThread()
{
    //创建子线程
    m_workerThread = new QThread(this);

    //创建串口工作类
    m_serialmanager = new SerialManager();

    // 将工作对象移动到子线程
    m_serialmanager->moveToThread(m_workerThread);

    // 连接主线程信号到串口线程的槽函数
    connect(this,&Widget::openPortRequested,m_serialmanager,&SerialManager::openPort);//发送开启串口信号

    connect(this,&Widget::closePortRequested,m_serialmanager,&SerialManager::closePort);//发送关闭串口信号

    connect(this,&Widget::writeDataRequested,m_serialmanager,&SerialManager::writeData);//发送数据信号

    connect(this,&Widget::initcombo,m_serialmanager,&SerialManager::initSerialPort);//发送刷新串口列表信号

    // 连接串口线程信号到主线程的槽函数
    connect(m_serialmanager,&SerialManager::dataReceived,this,&Widget::onDataReceived);//接收数据

    connect(m_serialmanager,&SerialManager::errorOccurred,this,&Widget::onErrorOccurred);//接收错误信息

    connect(m_serialmanager,&SerialManager::portOpened,this,&Widget::onPortOpened);//接收串口打开结果（成功或者失败）

    connect(m_serialmanager,&SerialManager::initPort,this,&Widget::onPortRefresh);//接收串口列表信息

    // 线程结束时自动销毁工作对象（避免内存泄漏）
    connect(m_workerThread,&QThread::finished,m_serialmanager,&SerialManager::deleteLater);

    //开启线程(进入事件循环)
    m_workerThread->start();
}

// 处理串口工作线程发来的"收到数据"信号（在主线程执行，可安全更新UI）
void Widget::onDataReceived(const QByteArray &data)
{
    // 如果暂停接收，则直接返回
    if (isPaused) {
        return;
    }

    // 将数据添加到接收缓冲区
    rxBuffer.append(data);

    // 更新接收计数
    rxCount += data.size();
    ui->labelRxCount->setText(QString("接收：%1").arg(rxCount));

    // 显示接收到的数据
    updateDisplay();
}

// 根据当前显示模式更新接收文本框的内容
void Widget::updateDisplay()
{
    // 清空接收文本框
    ui->textEditReceive->clear();
    
    // 根据当前显示模式转换并显示整个缓冲区的数据
    QString displayText;
    
    // 检查是否需要显示时间戳
    bool showTimestamp = ui->checkTimestamp->isChecked();
    bool autoLine = ui->checkAutoLine->isChecked();
    bool hexMode = ui->radioHexReceive->isChecked();
    
    if (hexMode) {
        // HEX显示模式
        if (showTimestamp) {
            QDateTime currentTime = QDateTime::currentDateTime();
            displayText = currentTime.toString("yyyy-MM-dd HH:mm:ss.zzz") + " ";
        }
        
        QByteArray hexData = rxBuffer.toHex(' ');
        displayText += hexData.toUpper();//将小写字母转换成大写字母，并添加到displayText中
    } else {
        // ASCII显示模式
        if (showTimestamp) {
            QDateTime currentTime = QDateTime::currentDateTime();
            displayText = currentTime.toString("yyyy-MM-dd HH:mm:ss.zzz") + " ";
        }
        
        displayText += QString(rxBuffer);
    }
    
    // 如果需要自动换行，添加换行符
    if (autoLine && !displayText.isEmpty()) {
        displayText += "\n";
    }
    
    // 设置文本内容
    ui->textEditReceive->setPlainText(displayText);
    
    // 自动滚动到文本框底部
    QTextCursor cursor = ui->textEditReceive->textCursor();
    cursor.movePosition(QTextCursor::End);
    ui->textEditReceive->setTextCursor(cursor);
}

// 处理串口工作线程发来的"错误发生"信号
void Widget::onErrorOccurred(const QString &error)
{
    QMessageBox::warning(nullptr, "串口错误信息", error);
}

// 处理串口工作线程发来的"串口打开结果"信号
void Widget::onPortOpened(bool success)
{
    isOpened = success;
    
    if(success == false)
    {
        ui->btnClose->setEnabled(false);
        ui->btnOpen->setEnabled(true);
        ui->labelStatus->setText("未连接");
        // 停止自动发送计时器
        autoSendTimer->stop();
        // 取消自动发送复选框的选中状态
        ui->checkAutoSend->setChecked(false);
    }
    else
    {
        ui->btnOpen->setEnabled(false);
        ui->btnClose->setEnabled(true);
        ui->labelStatus->setText("已连接");
    }
}

// 处理串口工作线程发来的串口列表信息
void Widget::onPortRefresh(QList<QSerialPortInfo> ports)
{
    // 清空ComboBox
    ui->comboBoxPort->clear();

    // 遍历所有串口并添加到ComboBox
    for (const QSerialPortInfo &info : ports) {
        // 添加串口名称（如 COM1, /dev/ttyUSB0）
        ui->comboBoxPort->addItem(info.portName());

        // 可以在调试时打印串口详细信息
        qDebug() << "Port:" << info.portName()
                 << "Description:" << info.description()
                 << "Manufacturer:" << info.manufacturer()
                 << "System Location:" << info.systemLocation();
    }

    // 如果没有检测到串口，可以添加提示
    if (ui->comboBoxPort->count() == 0) {
        ui->comboBoxPort->addItem("无可用串口");
    }
}

// 开启串口按钮， 向串口工作线程发送"打开串口"请求
void Widget::on_btnOpen_clicked()
{
    // 设置开启串口不能使用
    ui->btnOpen->setEnabled(false);
    // 1. 获取串口号
    portName = ui->comboBoxPort->currentText(); //串口号
    if (portName == "无可用串口") {
        QMessageBox::warning(nullptr, "参数错误", "请选择有效的串口号");
        ui->btnOpen->setEnabled(true);
        return ;
    }

    // 2. 转换波特率
    QString baudText = ui->comboBoxBaudRate->currentText();
    if (baudText == "4800") {
        baudRate = QSerialPort::Baud4800;
    } else if (baudText == "9600") {
        baudRate = QSerialPort::Baud9600;
    } else if (baudText == "19200") {
        baudRate = QSerialPort::Baud19200;
    } else if (baudText == "38400") {
        baudRate = QSerialPort::Baud38400;
    } else if (baudText == "57600") {
        baudRate = QSerialPort::Baud57600;
    }

    // 3. 转换数据位
    int dataBit = ui->comboBoxDataBits->currentText().toInt();
    switch (dataBit) {
    case 5: dataBits = QSerialPort::Data5; break;
    case 6: dataBits = QSerialPort::Data6; break;
    case 7: dataBits = QSerialPort::Data7; break;
    case 8: dataBits = QSerialPort::Data8; break;
    default:
        QMessageBox::warning(nullptr, "参数错误", "数据位必须是5/6/7/8");
        ui->btnOpen->setEnabled(true);
        return ;
    }

    // 4. 转换停止位
    int stopBit = ui->comboBoxStopBits->currentText().toInt();

    switch (stopBit) {
    case 1: stopBits = QSerialPort::OneStop; break;
    case 2: stopBits = QSerialPort::TwoStop; break;
    default:
        QMessageBox::warning(nullptr, "参数错误", "停止位必须是1/2");
        ui->btnOpen->setEnabled(true);
        return ;
    }

    // 5. 转换奇偶位
    QString Parity = ui->comboBoxParity->currentText(); //奇偶位

    if(Parity =="无") parity = QSerialPort::NoParity;
    if(Parity =="奇") parity = QSerialPort::OddParity;
    if(Parity =="偶") parity = QSerialPort::EvenParity;

    // 发送打开串口的信号
    emit openPortRequested(portName,baudRate,dataBits,stopBits,parity);
}

// 关闭串口按钮， 向串口工作线程发送"关闭串口"请求
void Widget::on_btnClose_clicked()
{
    ui->btnClose->setEnabled(false);
    emit closePortRequested();//发送关闭串口信号
}

// 发送按钮点击事件
void Widget::on_btnSend_clicked()
{
    // 如果串口未打开，则直接返回
    if (!isOpened) {
        QMessageBox::warning(this, "提示", "请先打开串口");
        return;
    }

    QString sendText = ui->textEditSend->toPlainText();
    if (sendText.isEmpty()) {
        return;
    }

    QByteArray sendData;

    // 根据发送模式转换数据
    if (ui->radioHexSend->isChecked()) {
        // HEX发送模式
        // 移除所有非十六进制字符
        sendText = sendText.remove(QRegularExpression("[^0-9A-Fa-f]"));
        
        // 确保字符数为偶数
        if (sendText.length() % 2 != 0) {
            QMessageBox::warning(this, "提示", "HEX发送数据必须是偶数个字符");
            return;
        }
        
        // 转换为字节数组
        for (int i = 0; i < sendText.length(); i += 2) {
            QString byteStr = sendText.mid(i, 2);
            bool ok;
            char byte = byteStr.toUInt(&ok, 16);
            if (!ok) {
                QMessageBox::warning(this, "提示", "HEX发送数据包含无效字符");
                return;
            }
            sendData.append(byte);
        }
    } else {
        // ASCII发送模式
        sendData = sendText.toUtf8();
    }

    // 如果需要发送新行
    if (ui->checkSendNewLine->isChecked()) {
        sendData.append("\r\n");
    }

    // 发送数据
    emit writeDataRequested(sendData);

    // 更新发送计数
    txCount += sendData.size();
    ui->labelTxCount->setText(QString("发送：%1").arg(txCount));
}

// 清空接收按钮点击事件
void Widget::on_btnClearReceive_clicked()
{
    // 清空接收缓冲区
    rxBuffer.clear();
    // 清空接收文本框
    ui->textEditReceive->clear();
    // 重置接收计数
    rxCount = 0;
    ui->labelRxCount->setText(QString("接收：%1").arg(rxCount));
}

// 暂停接收按钮点击事件
void Widget::on_btnPauseReceive_clicked()
{
    isPaused = !isPaused;
    if (isPaused) {
        ui->btnPauseReceive->setText("继续接收");
    } else {
        ui->btnPauseReceive->setText("暂停接收");
    }
}

// 自动发送复选框状态变化事件
void Widget::on_checkAutoSend_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked) {
        // 检查串口是否已经打开
        if (!isOpened) {
            QMessageBox::warning(this, "提示", "请先打开串口");
            // 取消自动发送复选框的选中状态
            ui->checkAutoSend->setChecked(false);
            return;
        }
        // 启用自动发送
        int interval = ui->spinBoxInterval->value();
        autoSendTimer->start(interval);
    } else {
        // 禁用自动发送
        autoSendTimer->stop();
    }
}

// HEX显示单选按钮状态变化事件
void Widget::on_radioHexReceive_toggled(bool checked)
{
    if (checked) {
        // HEX显示模式被选中，重新显示缓冲区数据
        updateDisplay();
    }
}

// ASCII显示单选按钮状态变化事件
void Widget::on_radioAsciiReceive_toggled(bool checked)
{
    if (checked) {
        // ASCII显示模式被选中，重新显示缓冲区数据
        updateDisplay();
    }
}

// HEX发送单选按钮状态变化事件
void Widget::on_radioHexSend_toggled(bool checked)
{
    if (checked) {
        // HEX发送模式被选中
        // 可以在这里添加模式切换的额外逻辑
    }
}

// ASCII发送单选按钮状态变化事件
void Widget::on_radioAsciiSend_toggled(bool checked)
{
    if (checked) {
        // ASCII发送模式被选中
        // 可以在这里添加模式切换的额外逻辑
    }
}

// 自动发送定时器超时事件
void Widget::autoSendTimerTimeout()
{
    // 自动发送时调用发送按钮的处理函数
    on_btnSend_clicked();
}

// 刷新串口列表按钮
void Widget::on_btnRefresh_clicked()
{
    emit initcombo();
}
