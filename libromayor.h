#ifndef LIBROMAYOR_H
#define LIBROMAYOR_H

#include "documentacion.h"

class libroMayor:public documentacion
{
private:
    //Totales de todas las cuentas
    double totalCuenta[20];

public:
    //Constructor de la clase
    libroMayor();
    //Destructor de la clase
    ~libroMayor(){}
    //Metodos set de los totales de las cuentas
    void setTotalCuenta(int indice, double _total);

    //Metodos get de los totales de las cuentas
    double getTotalCuenta(int indice);
};

#endif // LIBROMAYOR_H
