#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include <iostream>
#include <QMessageBox>

using std::cout;

usuario user;
usuario *currentUser=new usuario();

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_verificarButton2_clicked(){
    bool nombreCorrecto=true;
    usuario *usuarioRegistrarse=currentUser;
    if (ui->setUsuarioLEdit->text()==""||ui->setContraLEdit->text()==""){
        nombreCorrecto=false;
        QMessageBox::information(this,"Error","El usuario y/o contraseña no pueden estar vacios");
    }
    while (currentUser!=nullptr) {
        if(ui->setUsuarioLEdit->text()==currentUser->nombreUsuario&&nombreCorrecto==true){
            nombreCorrecto=false;
            QMessageBox::information(this,"Error","Lo sentimos el usuario ya está en la lista");
            currentUser=nullptr;
        }
        else{
            currentUser=currentUser->next;
        }
    }
    currentUser=usuarioRegistrarse;
    if(nombreCorrecto==true){
        user.insertAfter(currentUser, ui->nombreLEdit->text(), ui->apellidoLEdit->text(), ui->setUsuarioLEdit->text(), ui->setContraLEdit->text());
        QMessageBox::information(this, "Autorización", "Usuario creado con éxito");
        primerUsuarioCreado=true;
    }
}

void Login::on_verificarButton_clicked()
{
    //Esta es una bandera para el primer usuario
    usuario *firstUser=currentUser;
    bool verificacionCompletada=false;
    if (primerUsuarioCreado==false){
        currentUser=nullptr;
        verificacionCompletada=true;
        QMessageBox::information(this,"Error","Lo sentimos no hay ningún usuario en la lista prueba registrarte");
    }
    else if (ui->usuarioLEdit->text()==""||ui->contraLEdit->text()==""){
        currentUser=nullptr;
        verificacionCompletada=true;
        QMessageBox::information(this,"Error","El usuario y/o contraseña no pueden estar vacios");
    }
    //Se verifica si el usuario o la contraseña son válidos
    while(currentUser!=nullptr){
        if (ui->usuarioLEdit->text()!=currentUser->nombreUsuario){
            currentUser=currentUser->next;
        }
        //El else es importante ya que si no se verifican las dos condiciones en simultaneo
        //con el else primero verifica los usuarios y luego las contraseñas
        else if(ui->contraLEdit->text()!=currentUser->contrasena){
            currentUser=currentUser->next;
        }
        else{
            QMessageBox::information(this,"Éxito","Autorizacion realizada con éxito");
            mainW=new MainWindow(this);
            mainW->show();
            verificacionCompletada=true;
            currentUser=nullptr;
        }

    }
    if (verificacionCompletada==false){
        QMessageBox::information(this,"Error","Lo sentimos el usuario y/o contraseña no son válidos \n pruebe registrarse");
    }
    currentUser=firstUser;
}

void Login::on_verificarAdministrador_clicked()
{
    if(ui->usuarioAdmin->text()!=infoadmin.getAdminUsuario()||ui->contraAdmin->text()!=infoadmin.getadminContrasena()){
        QMessageBox::information(this,"Error","El usuarios o la contraseña no son correctos");
    }
    else {
        QMessageBox::information(this,"Éxito","Autorización Completada");
        admin=new Administrador(this);
        admin->show();
    }
}

