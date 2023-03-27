#ifndef LIBRODIARIO_H
#define LIBRODIARIO_H


class libroDiario
{
private:
    //atributos de los indices de las cuentas
    int cuenta1;
    int cuenta2;
    int cuenta3;
    int cuenta4;
    //atributos de los valores de las cuentas
    double valor1;
    double valor2;
    double valor3;
    double valor4;
public:
    //Metodos set de los indices de las cuentas
    void setCuenta1(int primera);
    void setCuenta2(int segunda);
    void setCuenta3(int tercera);
    void setCuenta4(int cuarta);
    //Metodos get de los indices de las cuentas
    int getCuenta1();
    int getCuenta2();
    int getCuenta3();
    int getCuenta4();
    //Metodos set de los valores de las cuentas
    void setValor1(int first);
    void setValor2(int second);
    void setValor3(int third);
    void setValor4(int fourth);
    //Metodos get de los valores de las cuentas
    double getValor1();
    double getValor2();
    double getValor3();
    double getValor4();

};


#endif // LIBRODIARIO_H
