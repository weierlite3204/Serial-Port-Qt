#include "serialmanager.h"
#include <QDebug>
SerialManager::SerialManager(QObject *parent)
    : QObject{parent},
      serialPort(new QSerialPort(this))
{
    // 连接信号槽
    connect(serialPort, &QSerialPort::readyRead, this, &SerialManager::handleReadyRead);
    connect(serialPort, &QSerialPort::errorOccurred, this, &SerialManager::handleError);
}

void SerialManager::openPort(const QString &portName, QSerialPort::BaudRate baudRate,
                             QSerialPort::DataBits dataBits,QSerialPort::StopBits stopBits,QSerialPort::Parity parity)
{
    serialPort->setPortName(portName);//配置串口号
    serialPort->setBaudRate(baudRate);//配置波特率
    serialPort->setDataBits(dataBits);//配置数据位
    serialPort->setStopBits(stopBits);//配置停止位
    serialPort->setParity(parity);//配置效验位

    //尝试打开串口
    if (serialPort->open(QIODevice::ReadWrite))
    {
        //串口打开成功
        qDebug()<<"串口打开成功";
        QString successMsg = QString("串口打开成功：%1（波特率：%2，数据位：%3，停止位：%4，校验位：%5）")
                                 .arg(portName)
                                 .arg(baudRate)
                                 .arg(dataBits)
                                 .arg(stopBits)
                                 .arg(parity);
        qDebug()<<successMsg;
        emit portOpened(true);//发送打开成功的信息
    }else
    {
        //串口打开失败
        qDebug()<<"串口打开失败";
        //打开失败
        emit portOpened(false);
        // 反馈错误原因（通过errorString()获取详细信息）
        emit errorOccurred("串口打开失败：" + serialPort->errorString());
    }
}

void SerialManager::closePort()
{
    if (serialPort && serialPort->isOpen()) {
        serialPort->close();     // 关闭串口
        qDebug() << "串口已关闭";
    }
    emit portOpened(false);
}

void SerialManager::writeData(const QByteArray &data)
{
    if (serialPort && serialPort->isOpen()) {
        serialPort->write(data);
    }
}

void SerialManager::handleReadyRead()
{
    if (serialPort) {
        QByteArray data = serialPort->readAll();
        if (!data.isEmpty()) {
            emit dataReceived(data);
        }
    }
}

void SerialManager::handleError(QSerialPort::SerialPortError error)
{
    if (error != QSerialPort::NoError && serialPort) {
        emit errorOccurred("串口错误：" + serialPort->errorString());
    }
}

void SerialManager::initSerialPort()
{
    // 获取所有可用的串口
    QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();

    emit initPort(ports);
}
