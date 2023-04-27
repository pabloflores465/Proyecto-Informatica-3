    #include "librodiario.h"

//Constructor

libroDiario::libroDiario()
{
    for(int i=0;i<100;i++){
       this->cuenta[i]="";
    }
    for(int i=0;i<100;i++){
       this->valor[i]=0.00;
    }
    for(int i=0;i<100;i++){
        this->clasificacion[i]="";
    }
}

void libroDiario::setCuenta(int indice, QString _cuenta){
    this->cuenta[indice]=_cuenta;
}
void libroDiario::setValor(int indice, double _valor){
    this->valor[indice]=_valor;
}

void libroDiario::setClasificacion(int indice, QString _clasificacion){
    this->clasificacion[indice]=_clasificacion;
}
QString libroDiario::getCuenta(int indice){
    return cuenta[indice];
}

double libroDiario::getValor(int indice){
    return valor[indice];
}

QString libroDiario::getClasificacion(int indice){
    return clasificacion[indice];
}

