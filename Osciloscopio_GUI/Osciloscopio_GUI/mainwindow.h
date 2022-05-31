#ifndef MAINWINDOW_H
#define MAINWINDOW_H
/*
 * https://doc.qt.io/qt-6/qtserialport-index.html
 *
 * QT += serialport
 */

#include "SerialCommunication.hpp"
#include "DataParser.hpp"
#include "qcustomplot.h"
#include "osciloscope.h"

#include <QMainWindow>
#include <QMessageBox>
#include <QLCDNumber>

#include <QDebug>
#define qDbg qDebug()
#define CONNECT_AT_BOOT 1

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_serialPortSelector_cmb_currentIndexChanged(int index);
    void on_conectar_btn_pressed();
    void displayReadedData();
    void showPortInfo(int idx);

    void on_rangeSize_dial_valueChanged(int value);

private:
    Ui::MainWindow *ui;


    // Serial comm
    SerialCommunication *serialCom;
    void fillPortsInfo();
    void fillPortsParameters();

    // Data Parsing
    DataParser *parser = new DataParser();
    const static int cantInputs = 6;
    int inputs[cantInputs];
    QLCDNumber* LCDDisplays[cantInputs]; // = {ui->input1_lcd, ui. };
    QString cadInputs[cantInputs] = {"A0", "A1", "A2", "A3", "A4","A5"};

    QString renglonDatos_s;
    void displayInfoInputs(QString renglonDatos);
    void desplegarValores(QString renglonDatos);

    // Graphing
    Osciloscope *osciloscope;

};
#endif // MAINWINDOW_H
