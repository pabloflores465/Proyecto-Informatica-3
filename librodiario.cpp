#include "librodiario.h"

//Metodos set de los indices de las cuentas
void setCuenta1(int primera)
{
    this->cuenta1=primera;
}
void setCuenta2(int segunda)
{
    this->cuenta2=segunda;
}
void setCuenta3(int tercera)
{
    this->cuenta3=tercera;
}
void setCuenta4(int cuarta)
{
    this->cuenta4=cuarta;
}
//Metodos get de los indices de las cuentas
int getCuenta1()
{
    return this->cuenta1;
}
int getCuenta2()
{
    return this->cuenta2;
}
int getCuenta3()
{
    return this->cuenta3;
}
int getCuenta4()
{
    return this->cuenta4;
}
//Metodos set de los valores de las cuentas
void setValor1(int first)
{
    this->valor1=first;
}
void setValor2(int second)
{
    this->valor2=second;
}
void setValor3(int third)
{
    this->valor3=third;
}
void setValor4(int fourth)
{
    this->valor4=fourth;
}
//Metodos get de los valores de las cuentas
double getValor1()
{
    return this->valor1;
}
double getValor2()
{
    return this->valor2;
}
double getValor3()
{
    return this->valor3;
}
double getValor4()
{
    return this->valor4;
}
