#include "login.h"

logIn::logIn()
{
    //this->nombre[noUsuarios]="";
    //this->contrasena[noUsuarios]="";
}
void logIn::setNoUsuarios(int nU){
    this->noUsuarios=nU;
}

void logIn::setNombre(int indice, QString n){
    this->nombre[indice]=n;
}
void logIn::setContrasena(int indice, QString c){
    this->contrasena[indice]=c;
}

int logIn::getNoUsuarios(){
    return noUsuarios;
}

QString logIn::getNombre(int indice){
    return nombre[indice];
}

QString logIn::getContrasena(int indice){
    return contrasena[indice];
}
