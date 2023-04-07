#include "balancegeneral.h"

balanceGeneral::balanceGeneral()
{
    this->totalActivos=0.00;
    this->totalPasivos=0.00;
    this->totalCapital=0.00;
    this->totalPasivosCapital=0.00;

}

void balanceGeneral::setTotalActivos(double _totalActivos){
    this->totalActivos=_totalActivos;
}

void balanceGeneral::setTotalPasivos(double _totalPasivos){
    this->totalPasivos=_totalPasivos;
}

void balanceGeneral::setTotalCapital(double _totalCapital){
    this->totalCapital=_totalCapital;
}

void balanceGeneral::setTotalPasivosCapital(double _totalPasivosCapital){
    this->totalPasivosCapital=_totalPasivosCapital;
}

double balanceGeneral::getTotalActivos(){
    return totalActivos;

}

double balanceGeneral::getTotalPasivos(){
    return totalPasivos;

}

double balanceGeneral::getTotalCapital(){
    return totalCapital;

}

double balanceGeneral::getTotalPasivosCapital(){
    return totalPasivosCapital;

}
