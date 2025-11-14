#ifndef SERIALMANAGER_H
#define SERIALMANAGER_H

#include <QObject>
#include <QSerialPort> // 串口操作核心类
#include <QSerialPortInfo>// 串口信息类（用于获取端口列表等）

class SerialManager : public QObject
{
    Q_OBJECT
public:
    explicit SerialManager(QObject *parent = nullptr);

private:
    // 核心对象
    QSerialPort *serialPort;        // 串口对象

signals:
    // 收到数据时发射：参数为收到的字节数据
    void dataReceived(const QByteArray &data);
    // 发生错误时发射：参数为错误描述
    void errorOccurred(const QString &error);
    // 串口打开/关闭结果：参数为是否成功
    void portOpened(bool success);
    // 串口列表检测信息
    void initPort(QList<QSerialPortInfo> ports);

public slots:
    //打开串口的槽函数
    void openPort(const QString &portName, QSerialPort::BaudRate baudRate,
                  QSerialPort::DataBits dataBits,QSerialPort::StopBits stopBits,QSerialPort::Parity parity);
    //关闭串口
    void closePort();
    //发送数据的槽函数
    void writeData(const QByteArray &data);
    //获取串口列表
    void initSerialPort();

private slots:
    //处理串口收到数据的事件（当QSerialPort::readyRead信号触发时调用）
    void handleReadyRead();
    //处理串口错误事件（当QSerialPort::errorOccurred信号触发时调用
    void handleError(QSerialPort::SerialPortError error);
};

#endif // SERIALMANAGER_H
