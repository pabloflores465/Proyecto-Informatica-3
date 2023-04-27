#ifndef SINGUP_H
#define SINGUP_H

#include <QString>
#include <QListWidget>
#include <QListWidgetItem>
#include <QTextEdit>

class usuario
{
public:
    QString nombre;
    QString apellido;
    QString nombreUsuario;
    QString contrasena;
    bool autorizado;
    usuario *next;

public:
    usuario();
    void insertAtTheFront(usuario **head,QString newNombre, QString newApellido, QString newNombreUsuario, QString newContrasena);
    void insertAfter(usuario *previous,QString newNombre, QString newApellido, QString newNombreUsuario, QString newContrasena);
    void printList(QListWidget *lista, usuario *primerUsuario);
    void autorizar( usuario *noUsuario, QString usuario,bool estado);
    bool getEstado(usuario *noUsuario,QString usuario);
    void printNode(QListWidget *lista, usuario *noUsuario, QString usuario);
    void deleteFromList(QListWidget *lista, usuario *noUsuario, QString usuario);
    //,void editList(QListWidget *lista, QTextEdit *texto, usuario *noUsuario, QString )
};

#endif // SINGUP_H
