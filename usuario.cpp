#include "usuario.h"
#include<iostream>

using std::cout, std::endl;

usuario::usuario()
{
    //nombre="ADMIN";
    //apellido="admin";
    //nombreUsuario="ADMIN";
    //contrasena="123";
}

void usuario::insertAtTheFront(usuario **head,QString newNombre, QString newApellido, QString newNombreUsuario, QString newContrasena){
   //Create a new node
   usuario *newUsuario=new usuario();
   newUsuario->nombre=newNombre;
   newUsuario->apellido=newApellido;
   newUsuario->nombreUsuario=newNombreUsuario;
   newUsuario->contrasena=newContrasena;
   newUsuario->autorizado=false;
   //Put it in front of the current head
   newUsuario->next=*head;
   //Move the head of the list to point a new node
   *head=newUsuario;
}

void usuario::insertAfter(usuario *previous,QString newNombre, QString newApellido, QString newNombreUsuario, QString newContrasena){
   //Check if previous node is NULL
   if (previous==nullptr){
       insertAtTheFront(&previous,newNombre,newApellido,newNombreUsuario,newContrasena);
   }
   //Prepare a New Node
   usuario *newUsuario=new usuario();
   newUsuario->nombre=newNombre;
   newUsuario->apellido=newApellido;
   newUsuario->nombreUsuario=newNombreUsuario;
   newUsuario->contrasena=newContrasena;
   newUsuario->autorizado=false;
   //Insert a New Node after previous
   newUsuario->next=previous->next;
   previous->next=newUsuario;
}

void usuario::printList(QListWidget *lista, usuario *primerUsuario){
    primerUsuario=primerUsuario->next;
    while(primerUsuario!=nullptr){
       lista->addItem(primerUsuario->nombre);
       lista->addItem(primerUsuario->apellido);
       lista->addItem(primerUsuario->nombreUsuario);
       lista->addItem(primerUsuario->contrasena);
       primerUsuario=primerUsuario->next;
    }
}

void usuario::autorizar(usuario *noUsuario, QString usuario, bool estado){
    noUsuario=noUsuario->next;
    while (noUsuario->nombreUsuario!=usuario&&noUsuario!=nullptr) {
       noUsuario=noUsuario->next;
    }
    if (noUsuario!=nullptr){
       noUsuario->autorizado=estado;
    }

}

bool usuario::getEstado(usuario *noUsuario,QString usuario){
    while (noUsuario->nombreUsuario!=usuario&&noUsuario!=nullptr) {
       noUsuario=noUsuario->next;
    }
    return noUsuario->autorizado;
}

void usuario::printNode(QListWidget *lista, usuario *noUsuario, QString usuario){
    while (noUsuario->nombreUsuario!=usuario&&noUsuario!=nullptr) {
       noUsuario=noUsuario->next;
    }
    lista->addItem(noUsuario->nombre);
    lista->addItem(noUsuario->apellido);
    lista->addItem(noUsuario->nombreUsuario);
    lista->addItem(noUsuario->contrasena);
}

void usuario::deleteFromList(QListWidget *lista, usuario *noUsuario, QString usuario){
    int row=1;
    while (noUsuario->nombreUsuario!=usuario&&noUsuario!=nullptr) {
       noUsuario=noUsuario->next;
       row++;
    }

    QListWidgetItem *contrasena=lista->takeItem(row+1);
    QListWidgetItem *nombreUsuario=lista->takeItem(row);
    QListWidgetItem *apellido=lista->takeItem(row-1);
    QListWidgetItem *nombre=lista->takeItem(row-2);
    delete nombre;
    delete apellido;
    delete contrasena;
    delete nombreUsuario;

}
