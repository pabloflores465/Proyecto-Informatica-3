#include "libromayor.h"


//Constructor de la clase
libroMayor::libroMayor()
{
    for(int i=0;i<20;i++){
        this->totalCuenta[i]=0.00;
    }

}
void libroMayor::setTotalCuenta(int indice, double _total){
    this->totalCuenta[indice]=_total;
}

double libroMayor::getTotalCuenta(int indice){
    return totalCuenta[indice];
}

