#include "SerialCommunication.hpp"

SerialCommunication::SerialCommunication()
{
    serial = new QSerialPort();
}


bool SerialCommunication::openPort(QString portName, int BaudRate)
{
    serial->setPortName(portName);
    //serial.setPortName("/dev/ttyACM1");
    serial->open(QIODevice::ReadWrite);

    baudRate = BaudRate;
    qDebug() << "BaudRate:" << baudRate;
    serial->setBaudRate(baudRate);

    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);


    if (serial->isOpen() && serial->isWritable())
    {
        qDebug() << "Ready..." << endl;
        //serial.write("R");

        if(serial->flush())
        {
            qDebug() << "ok" << endl;
        }
        //qDebug() <<"value sent!!! "<< endl;
        #if CERRAR_PUERTO_SERIAL
        serial->close();
        #endif

        return true;
        //ui->conectar_btn->setEnabled(false);
        //ui->conectar_btn->setText("Desconectar");
        //ui->btnDesconectar->setEnabled(true);
    }
    else
    {
        return false;
    }
}

QByteArray SerialCommunication::readData()
{
    QByteArray data;
    if(serial->isOpen())
    {
        data = serial->readAll();
    }
    else
    {
        qDbg << "serial Closed at SerialCommunication::readData()";
    }

    return data;
}
void SerialCommunication::escribir(/*QString datos*/ const char* datos)
{
    #if CERRAR_PUERTO_SERIAL
    serial->open(QIODevice::ReadWrite); //Ya debe estar abierto.
    #endif
    if(serial->isOpen()  &&  serial->isWritable())
    {
        //qDebug() << datos;
        //serial->write(datos.toStdString().c_str());
        serial->write(datos);

        if(serial->flush())
            qDebug() << "ok";
        #if CERRAR_PUERTO_SERIAL
        serial->close(); //Probar sin cerrar.
        #endif
    }
    else
        qDebug() << "Error: Puerto cerrado.";
}

void SerialCommunication::escribirCadena(const QByteArray &datos)
{
    #if CERRAR_PUERTO_SERIAL
    serial->open(QIODevice::ReadWrite); //Ya debe estar abierto.
    #endif
    if(serial->isOpen()  &&  serial->isWritable())
    {
        //qDebug() << datos;
        //serial->write(datos.toStdString().c_str());
        serial->write(datos);

        if(serial->flush())
            qDebug() << "ok";
        #if CERRAR_PUERTO_SERIAL
        serial->close(); //Probar sin cerrar.
        #endif
    }
    else
        qDebug() << "Error: Puerto cerrado.";
}
