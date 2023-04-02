#include "login.h"

logIn::logIn()
{
    autorizacion=false;
}

void logIn::setAutorizacion(bool a){
    this->autorizacion=a;
}

bool logIn::getAutorizacion(){
    return autorizacion;
}
