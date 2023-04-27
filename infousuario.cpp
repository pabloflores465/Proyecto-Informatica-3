#include "infousuario.h"

infoUsuario::infoUsuario()
{
    this->adminUsuario="Admin";
    this->adminContrasena="ADMIN";
}

QString infoUsuario::getAdminUsuario(){
    return adminUsuario;
}

QString infoUsuario::getadminContrasena(){
    return adminContrasena;
}
