#ifndef SINGUP_H
#define SINGUP_H

#include <QString>

class usuario
{
public:
    usuario();
    QString nombre;
    QString apellido;
    QString nombreUsuario;
    QString contrasena;
    usuario *next;

public:
    void insertAtTheFront(usuario **head,QString newNombre, QString newApellido, QString newNombreUsuario, QString newContrasena);
    void insertAfter(usuario *previous,QString newNombre, QString newApellido, QString newNombreUsuario, QString newContrasena);

};

#endif // SINGUP_H
