#include "dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"

#include <QMessageBox>
#include <QApplication>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_verificarButton2_clicked(){

    user.insertAfter(currentUser, ui->nombreLEdit->text(), ui->apellidoLEdit->text(), ui->setUsuarioLEdit->text(), ui->setContraLEdit->text());
    QMessageBox::information(this, "Autorización", "Usuario creado con éxito");
}

void Dialog::on_verificarButton_clicked()
{
    usuario *firstUser=currentUser;
    while(currentUser!=nullptr){
        if (ui->usuarioLEdit->text()!=currentUser->nombre){
            currentUser=currentUser->next;
        }
        if(ui->contraLEdit->text()!=currentUser->contrasena){
            currentUser=currentUser->next;
        }
        else{
            QMessageBox::information(this,"Éxito","Autorizacion realizada con éxito");
            mainW=new MainWindow(this);
            mainW->show();
            currentUser=currentUser->next;
        }

    }
    currentUser=firstUser;
}

