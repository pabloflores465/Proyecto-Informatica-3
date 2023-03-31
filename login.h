#ifndef LOGIN_H
#define LOGIN_H

#include"singup.h"

class logIn
{
private:
    int noUsuarios=0;
    QString *nombre=new QString [noUsuarios];
    QString *contrasena=new QString[noUsuarios];
public:
    logIn();
    void setNoUsuarios(int nU);

    void setNombre(int indice, QString n);
    void setContrasena(int indice, QString c);

    int getNoUsuarios();
    QString getNombre(int indice);
    QString getContrasena(int indice);
};

#endif // LOGIN_H
