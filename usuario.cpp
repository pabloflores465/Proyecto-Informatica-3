#include "usuario.h"

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
   //Insert a New Node after previous
   newUsuario->next=previous->next;
   previous->next=newUsuario;
}
