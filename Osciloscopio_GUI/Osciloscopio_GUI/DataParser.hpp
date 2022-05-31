#ifndef DATAPARSER_H
#define DATAPARSER_H

#include <QString>
#include <QRegularExpression>


class DataParser
{
public:
    DataParser();

    bool buscarExpresionRegular_returnNextFloat(QString cadHead,
                                                QString fuente,
                                                float& match_float);

    int buscarExpresionRegular(QString expReg, QString fuente);

    bool buscarExpresionRegular_returnNextInt(QString cadHead,
                                              QString fuente,
                                              int& match_int);

private:
};

#endif // DATAPARSER_H
