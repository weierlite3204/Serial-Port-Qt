#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <SerialManager.h>
#include <QSerialPort>
#include <QThread>
#include <QSerialPortInfo>// 串口信息类（用于获取端口列表等）

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    QThread *m_workerThread;        //线程
    SerialManager *m_serialmanager; //串口对象

    // 配置参数
    QString portName;               // 端口名 "COM3"
    QSerialPort::BaudRate baudRate; // 波特率 115200
    QSerialPort::DataBits dataBits; // 数据位 Data8
    QSerialPort::StopBits stopBits; // 停止位 OneStop
    QSerialPort::Parity parity;     // 校验位 NoParity

    // 状态标志
    bool isOpened;                  // 串口是否打开

    // 统计数据
    quint64 rxCount;                // 接收字节数
    quint64 txCount;                // 发送字节数

    // 缓冲区
    QByteArray rxBuffer;            // 接收缓冲区
    QByteArray txBuffer;            // 发送缓冲区

    // 定时器
    QTimer *autoSendTimer;          // 自动发送定时器

    // 初始化串口线程：创建线程、工作对象，连接信号槽
    void setupSerialThread();

signals:
    // 向串口工作线程发送"打开串口"请求（参数：端口名、波特率、数据位、停止位、校验位）
    void openPortRequested(const QString &portName, QSerialPort::BaudRate baudRate,
                           QSerialPort::DataBits dataBits,QSerialPort::StopBits stopBits,QSerialPort::Parity parity);
    // 向串口工作线程发送"关闭串口"请求
    void closePortRequested();
    // 向串口工作线程发送"发送数据"请求（参数：要发送的数据）
    void writeDataRequested(const QByteArray &data);
    // 请求刷新串口列表
    void initcombo();

private slots:
    // 处理串口工作线程发来的"收到数据"信号（在主线程执行，可安全更新UI）
    void onDataReceived(const QByteArray &data);
    // 处理串口工作线程发来的"错误发生"信号
    void onErrorOccurred(const QString &error);
    // 处理串口工作线程发来的"串口打开结果"信号
    void onPortOpened(bool success);
    // 处理串口工作线程发来的串口列表信息
    void onPortRefresh(QList<QSerialPortInfo> ports);
    // 开启串口按钮， 向串口工作线程发送"打开串口"请求
    void on_btnOpen_clicked();
    // 关闭串口按钮， 向串口工作线程发送"关闭串口"请求
    void on_btnClose_clicked();
    // 刷新串口列表按钮
    void on_btnRefresh_clicked();
};
#endif // WIDGET_H
