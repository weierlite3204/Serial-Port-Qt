#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , m_workerThread(nullptr)
    , m_serialmanager(nullptr)
{
    ui->setupUi(this);

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

}

// 处理串口工作线程发来的"错误发生"信号
void Widget::onErrorOccurred(const QString &error)
{
    QMessageBox::warning(nullptr, "串口错误信息", error);
}

// 处理串口工作线程发来的"串口打开结果"信号
void Widget::onPortOpened(bool success)
{
    if(success == false)
    {
        ui->btnClose->setEnabled(false);
        ui->btnOpen->setEnabled(true);
        return;
    }
    ui->btnOpen->setEnabled(false);
    ui->btnClose->setEnabled(true);
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

// 刷新串口列表按钮
void Widget::on_btnRefresh_clicked()
{
    emit initcombo();
}
