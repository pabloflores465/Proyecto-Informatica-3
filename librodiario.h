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
    //atributos de los indices de las cuentas
    int clasf1;
    int clasf2;
    int clasf3;
    int clasf4;

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
    void setValor1(double first);
    void setValor2(double second);
    void setValor3(double third);
    void setValor4(double fourth);
    //Metodos get de los valores de las cuentas
    double getValor1();
    double getValor2();
    double getValor3();
    double getValor4();
    //metodos set de los indices de las clasificacion de cuentas
    void setClasf1(int one);
    void setClasf2(int two);
    void setClasf3(int three);
    void setClasf4(int four);
     //metodos get de los indices de las clasificacion de cuentas
    int getClasf1();
    int getClasf2();
    int getClasf3();
    int getClasf4();
};


#endif // LIBRODIARIO_H
