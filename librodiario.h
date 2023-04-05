#ifndef LIBRODIARIO_H
#define LIBRODIARIO_H

#include"documentacion.h"

#include <QString>

class libroDiario:public documentacion
{
private:
    //atributos de los indices de las cuentas
    QString cuenta[100];

    //atributos de los valores de las cuentas
    double valor[100];

    //atributos de los indices de las cuentas
    QString clasificacion[100];


public:
    //Constructor
    libroDiario();
    //Destructor
    ~libroDiario(){}
    //Metodos set de los indices de las cuentas
    void setCuenta(int indice, QString _cuenta);

    //Metodos get de los indices de las cuentas
    QString getCuenta(int indice);

    //Metodos set de los valores de las cuentas
    void setValor(int indice, double _valor);

    //Metodos get de los valores de las cuentas
    double getValor(int indice);

    //metodos set de los indices de las clasificacion de cuentas
    void setClasificacion(int indice, QString _clasificacion);

     //metodos get de los indices de las clasificacion de cuentas
    QString getClasificacion(int indice);
};


#endif // LIBRODIARIO_H
