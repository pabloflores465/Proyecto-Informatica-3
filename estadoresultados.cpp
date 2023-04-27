#include "estadoresultados.h"

estadoResultados::estadoResultados()
{
    totalIngresos=0.00;
    utilidadBruta=0.00;
    utilidadAntesImpuestos=0.00;
    utilidadNeta=0.00;
    isr=0.00;
}

void estadoResultados::setTotalIngresos(double _totalIngresos){
    this->totalIngresos=_totalIngresos;
}

void estadoResultados::setUtilidadBruta(double _utlidadB){
    this->utilidadBruta=_utlidadB;
}

void estadoResultados::setUtilidadAntesImpuestos(double _utilidadAntesI){
    this->utilidadAntesImpuestos=_utilidadAntesI;
}

void estadoResultados::setUtilidadNeta(double _utilidadNeta){
    this->utilidadNeta=_utilidadNeta;
}

void estadoResultados::setIsr(double _isr){
    this->isr=_isr;
}

double estadoResultados::getUtilidadBruta(){
    return utilidadBruta;
}

double estadoResultados::getUtilidadAntesImpuestos(){
    return utilidadAntesImpuestos;
}

double estadoResultados::getUtilidadNeta(){
    return utilidadNeta;
}

double estadoResultados::getTotalIngresos(){
    return totalIngresos;
}

double estadoResultados::getIsr(){
    return isr;
}
