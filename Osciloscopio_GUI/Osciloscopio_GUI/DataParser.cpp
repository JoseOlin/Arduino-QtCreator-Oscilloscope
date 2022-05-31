#include "DataParser.hpp"

DataParser::DataParser()
{

}

bool DataParser::buscarExpresionRegular_returnNextFloat(QString cadHead, QString fuente, float& match_float)
{
    // https://stackoverflow.com/questions/8775011/floating-point-regular-expression

    //  Expresión para floatantes:   ^[-+]?[0-9]*\\.?[0-9]+([eE][-+]?[0-9]+)?$
    QString expReg = cadHead + ": ^[-+]?[0-9]*(\\.[0-9]+)?";
    QRegularExpression expRegInt_R(expReg);

    QRegularExpressionMatch RegExMatch = expRegInt_R.match(fuente);
    //int indiceJy_Fin
    //int indiceJy_Ini = expRegInt.indexIn(renglonDatos_s);
    if(RegExMatch.hasMatch() )
    {
        QString match_s = RegExMatch.captured(1);
        //int match_int = match_s.toInt();
        match_float = match_s.toFloat();
        return true;
    }
    else
    {
        return false;
    }
}

int DataParser::buscarExpresionRegular(QString expReg, QString fuente)
{
    //QRegularExpression expRegInt_R("J_Y: (\\d+)");
    QRegularExpression expRegInt_R(expReg);
    QRegularExpressionMatch RegExMatch = expRegInt_R.match(fuente);
    //int indiceJy_Fin
    //int indiceJy_Ini = expRegInt.indexIn(renglonDatos_s);
    QString match_s = RegExMatch.captured(1);
    int match_int = match_s.toInt();

    return match_int;
}

/* TODO: Evaluar si esta es necesaria
bool DataParser::findCommaSeparatedInts(QString cadHead, QString fuente,
                                        int& input1,
                                        int& input2,
                                        int& input3,
                                        int& input4,
                                        int& input5,
                                        int& input6
                                        )
{
    QString expReg = cadHead + ": (\\d+),(\\d+),(\\d+),(\\d+),(\\d+),(\\d+)";

}*/

bool DataParser::buscarExpresionRegular_returnNextInt(QString cadHead, QString fuente, int& match_int)
{

    //QRegularExpression expRegInt_R("J_Y: (\\d+)");
    //QString expReg = cadHead + ": (-?(\\d+))"; //Positive or negative values.
    QString expReg = cadHead + ": (\\d+)"; //Only positive values
    QRegularExpression expRegInt_R(expReg);
    QRegularExpressionMatch RegExMatch = expRegInt_R.match(fuente);
    //int indiceJy_Fin
    //int indiceJy_Ini = expRegInt.indexIn(renglonDatos_s);
    if(RegExMatch.hasMatch() )
    {
        QString match_s = RegExMatch.captured(1);
        //int match_int = match_s.toInt();
        match_int = match_s.toInt();
        return true;
    }
    else
    {
        return false;
    }
}
