#ifndef INFOUSUARIO_H
#define INFOUSUARIO_H

#include <QString>

class infoUsuario
{
private:
    QString adminUsuario;
    QString adminContrasena;

public:
    infoUsuario();
    QString getAdminUsuario();
    QString getadminContrasena();
};

#endif // INFOUSUARIO_H
