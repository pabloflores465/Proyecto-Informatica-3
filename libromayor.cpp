#include "libromayor.h"


//Constructor de la clase
libroMayor::libroMayor()
{
    for (int i = 0; i < 20; i++) {
        this->totalDebe[i]=0.00;
    }
    for (int i = 0; i < 20; i++) {
        this->totalHaber[i]=0.00;
    }
    for(int i=0;i<20;i++){
        this->totalCuenta[i]=0.00;
    }

}

void libroMayor::setTotalDebe(int indice, double _total){
    this->totalDebe[indice]=_total;
}

double libroMayor::getTotalDebe(int indice){
    return totalDebe[indice];
}

void libroMayor::setTotalHaber(int indice, double _total){
    this->totalHaber[indice]=_total;
}

double libroMayor::getTotalHaber(int indice){
    return totalHaber[indice];
}

void libroMayor::setTotalCuenta(int indice, double _total){
    this->totalCuenta[indice]=_total;
}

double libroMayor::getTotalCuenta(int indice){
    return totalCuenta[indice];
}

