#ifndef SERIALCOMMUNICATION_HPP
#define SERIALCOMMUNICATION_HPP

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

#include <QDebug>
#define qDbg qDebug()

#define COMM_DEBUG 0


class SerialCommunication
{

public:
    SerialCommunication();

    QSerialPort* serial;

    bool openPort(QString portName, int BaudRate);

    //void fillPortsInfo();
    //void fillPortsParameters();
    //void showPortInfo(int idx);

    QByteArray readData();
    void escribir(const char *datos);
    void escribirCadena(const QByteArray &datos);

private slots:
    // Serial comm

private:
    // Serial comm
    int baudRate = QSerialPort::Baud115200;

};

#endif // SERIALCOMMUNICATION_HPP
