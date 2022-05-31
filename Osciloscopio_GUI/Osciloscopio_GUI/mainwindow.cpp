#include "mainwindow.h"
#include "ui_mainwindow.h"

unsigned long int currentIndex = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ////// Inicialización y llenado de los elementos
    // Comunicación serial.
    serialCom = new SerialCommunication();
    parser = new DataParser();
    osciloscope = new Osciloscope();
    //serial = new QSerialPort(this);

    fillPortsInfo();
    fillPortsParameters();

    LCDDisplays[0] = ui->input1_lcd;
    LCDDisplays[1] = ui->input2_lcd;


    /// Conexiones.
    connect(serialCom->serial,  SIGNAL(readyRead()),
            this,               SLOT(displayReadedData())   );

    connect(ui->serialPortSelector_cmb,   SIGNAL(currentIndexChanged(int)),
            this,                           SLOT(showPortInfo(int))   );

#if CONNECT_AT_BOOT
    ui->conectar_btn->pressed();
#endif

    //QCustomPlot* customPlot;
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setPen(QPen(QColor(40, 110, 255))); // blue line
    ui->customPlot->addGraph();
    ui->customPlot->graph(1)->setPen(QPen(QColor(255, 110, 40))); // red line

    //QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    //timeTicker->setTimeFormat("%h:%m:%s");
    //ui->customPlot->xAxis->setTicker(timeTicker);
    ui->customPlot->axisRect()->setupFullAxesBox();
    ui->customPlot->yAxis->setRange(-1.2, 1100);


    // make left and bottom axes transfer their ranges to right and top axes:
    connect(ui->customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->yAxis2, SLOT(setRange(QCPRange)));


}

MainWindow::~MainWindow()
{

    ui->conectar_btn->click();

    delete ui;
}


void MainWindow::fillPortsInfo()
{
    // Consultar los puertos disponibles y agregarlos a cmbSerialPortSelector
    ui->serialPortSelector_cmb->clear();

    static const QString blankString = QObject::tr("N/A");
    QString description;
    QString manufacturer;
    //QString serialNumber;
    const auto puertosDisponibles = QSerialPortInfo::availablePorts();
    //foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    foreach (const QSerialPortInfo &info, puertosDisponibles)
    {
        QStringList list;
        description = info.description();
        manufacturer = info.manufacturer();
        //serialNumber = info.serialNumber();

        list << info.portName()
             << (!description.isEmpty() ? description : blankString)
             << (!manufacturer.isEmpty() ? manufacturer : blankString)
             //<< (!serialNumber.isEmpty() ? serialNumber : blankString)
             << info.systemLocation()
             << (info.vendorIdentifier() ? QString::number(info.vendorIdentifier(), 16) : blankString)
             << (info.productIdentifier() ? QString::number(info.productIdentifier(), 16) : blankString);

        ui->serialPortSelector_cmb->addItem(list.first(), list);
    }

    qDebug() << "Cantidad de puertos disponibles: " << puertosDisponibles.length();
    if(puertosDisponibles.length() < 1)
    {
        qDebug() << "No se encontraron dispositivos conectados.";
    }
}

void MainWindow::fillPortsParameters()
{
    ui->baudRate_cmb->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
    ui->baudRate_cmb->addItem(QStringLiteral("19200"), QSerialPort::Baud19200);
    ui->baudRate_cmb->addItem(QStringLiteral("38400"), QSerialPort::Baud38400);
    ui->baudRate_cmb->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);
    ui->baudRate_cmb->addItem(QStringLiteral("250000"), 250000);
    ui->baudRate_cmb->addItem(QStringLiteral("250000"), 250000);
    ui->baudRate_cmb->addItem(QStringLiteral("300000"), 300000);
    ui->baudRate_cmb->addItem(QStringLiteral("400000"), 400000);
    ui->baudRate_cmb->addItem(QStringLiteral("500000"), 500000);
    ui->baudRate_cmb->addItem(QStringLiteral("600000"), 600000);
    ui->baudRate_cmb->addItem(QStringLiteral("Custom"));

    //ui->cmbBaudRate->setCurrentIndex(2); //38400
    //ui->baudRate_cmb->setCurrentIndex(3);//115200
    ui->baudRate_cmb->setCurrentIndex(8);//500000
}
void MainWindow::showPortInfo(int idx)
{
    // Mostrar la información del puerto en la etiqueta lblDescripción
    if(idx != -1)
    {
        QStringList list = ui->serialPortSelector_cmb->itemData(idx).toStringList();
        ui->description_lbl->setText(tr("Descripción: %1").arg(list.at(1)));
    }
}

void MainWindow::on_serialPortSelector_cmb_currentIndexChanged(int index)
{
    showPortInfo(index);
}

void MainWindow::on_conectar_btn_pressed()
{
    if (!serialCom->serial->isOpen())
    {
        QString portName = ui->serialPortSelector_cmb->currentText();
        int baudRate = ui->baudRate_cmb->currentText().toInt();

        qDebug() << "Port name: " << portName;

        bool portOpenAndWritable = serialCom->openPort(portName, baudRate);

        if (portOpenAndWritable)
        {
            ui->conectar_btn->setText("Desconectar");
        }
        else
        {
            fillPortsInfo();

            qDebug() << "Was an error while creating the Serial Port. btnConectar_pressed()";
            QMessageBox msg;
            msg.setText("Was an error while creating the Serial Port. btnConectar_pressed()");
            msg.exec();
        }
    }
    else // serial->isOpen()
    {
        serialCom->serial->close();

        if(!serialCom->serial->isOpen())
        {
            ui->conectar_btn->setText("Conectar");
            //ui->btnConectar->setEnabled(true);
            //ui->btnDesconectar->setEnabled(false);
        }
        else
        {
            QMessageBox msg;
            msg.setText("No se pudo cerrar el puerto");
            msg.exec();
        }
    }
}

/*void MainWindow::displayReadedData_osciloscope()
{
    QByteArray data = serialCom->readData();
    qdbg << data;

}*/

void MainWindow::displayReadedData()
{
    QByteArray data = serialCom->readData();

    if(!data.isEmpty())
    {
        int indSalto;// = data.indexOf("\n");
        //La cadena leída puede contener varios renglones. Separarlos.
        int cantSaltos = data.count("\n");
        qDebug() << "cantSaltos: " << cantSaltos; //2 Saltos máximo, en los experimentos.
        if(cantSaltos > 0)
        {
            int cont = 0;
            while(cont < cantSaltos)
            {
                indSalto = data.indexOf("\n");
                //qDebug() << "indSalto: " <<indSalto;
                QString cadenaTemp = data.left(indSalto+1);
                //qDebug() << "cadenaTemp: " << cadenaTemp;

                renglonDatos_s.append(cadenaTemp);
                #if COMM_DEBUG
                qDebug() << renglonDatos_s;
                #endif

                desplegarValores(renglonDatos_s);

                data.remove(0, indSalto+1); // Si llegó un salto de línea en el data, enviar y limpiar el renglón.
                renglonDatos_s.clear();
                cont++;
            }
            renglonDatos_s.append(data);// El resto del dato ponerlo en el renglón, para concatenarlo con la siguiente lectura.
            ui->customPlot->replot();
        }
        else
        {
            renglonDatos_s.append(data);
        }
    }
    else
    {
        qDbg << "MainWindow::displayReadedData()  data.isEmpty()";
    }

}

/// Parsing data functions
void MainWindow::desplegarValores(QString renglonDatos)
{
    /* Función para desplegar los datos que se reciben por Serial y mostrar
     * los errores en la GUI.
     * Se invoca en displayReadedData()  */

    ui->infoSalida_txt->insertPlainText(renglonDatos);
    ui->infoSalida_txt->ensureCursorVisible();

    displayInfoInputs(renglonDatos);

    /// Separar renglón datos para mostrar valores del Joystick.
    ///* Errors
    /*QRegularExpression expRegInt_R = QRegularExpression ("(\\*\\*)(.+)(\\*\\*)");
    // \\*\\* = **             (.+) = Any character one or more times
    QRegularExpressionMatch match = expRegInt_R.match(renglonDatos);
    QString Error_s = match.captured(0);
    if( Error_s.length() > 0 )
    {
        ui->erroresSalida_txt->insertPlainText(Error_s);
        ui->erroresSalida_txt->insertPlainText("\n");
        ui->erroresSalida_txt->ensureCursorVisible();
    }*/
}

void MainWindow::displayInfoInputs(QString renglonDatos)
{

    for(int ind = 0; ind < cantInputs-4; ind++)
    {
        parser->buscarExpresionRegular_returnNextInt(cadInputs[ind], renglonDatos, inputs[ind]);
        LCDDisplays[ind]->display(inputs[ind]);

        ui->customPlot->graph(ind)->addData(currentIndex, inputs[ind]);

    }
    currentIndex++;

    // make key axis range scroll with the data (at a constant range size of 8):
    ui->customPlot->xAxis->setRange(currentIndex, osciloscope->rangeSize, Qt::AlignRight);
    //ui->customPlot->replot();
}

void MainWindow::on_rangeSize_dial_valueChanged(int value)
{
    osciloscope->rangeSize = value;
}

