#ifndef LIBROMAYOR_H
#define LIBROMAYOR_H

#include "documentacion.h"

class libroMayor:public documentacion
{
private:
    double totalDebe[20];
    double totalHaber[20];
    //Totales de todas las cuentas
    double totalCuenta[20];

public:
    //Constructor de la clase
    libroMayor();
    //Destructor de la clase
    ~libroMayor(){}
    //Total debe
    void setTotalDebe(int indice, double _total);
    double getTotalDebe(int indice);
    void setTotalHaber(int indice, double _total);
    double getTotalHaber(int indice);
    //Metodos set de los totales de las cuentas
    void setTotalCuenta(int indice, double _total);

    //Metodos get de los totales de las cuentas
    double getTotalCuenta(int indice);
};

#endif // LIBROMAYOR_H
