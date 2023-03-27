#include "librodiario.h"

//Metodos set de los indices de las cuentas
void libroDiario::setCuenta1(int primera)
{
    this->cuenta1=primera;
}
void libroDiario::setCuenta2(int segunda)
{
    this->cuenta2=segunda;
}
void libroDiario::setCuenta3(int tercera)
{
    this->cuenta3=tercera;
}
void libroDiario::setCuenta4(int cuarta)
{
    this->cuenta4=cuarta;
}
//Metodos get de los indices de las cuentas
int libroDiario::getCuenta1()
{
    return this->cuenta1;
}
int libroDiario::getCuenta2()
{
    return this->cuenta2;
}
int libroDiario::getCuenta3()
{
    return this->cuenta3;
}
int libroDiario::getCuenta4()
{
    return this->cuenta4;
}
//Metodos set de los valores de las cuentas
void libroDiario::setValor1(int first)
{
    this->valor1=first;
}
void libroDiario::setValor2(int second)
{
    this->valor2=second;
}
void libroDiario::setValor3(int third)
{
    this->valor3=third;
}
void libroDiario::setValor4(int fourth)
{
    this->valor4=fourth;
}
//Metodos get de los valores de las cuentas
double libroDiario::getValor1()
{
    return this->valor1;
}
double libroDiario::getValor2()
{
    return this->valor2;
}
double libroDiario::getValor3()
{
    return this->valor3;
}
double libroDiario::getValor4()
{
    return this->valor4;
}
