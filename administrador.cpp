#include "administrador.h"
#include "ui_administrador.h"
#include "login.h"

#include <iostream>
#include <QListWidgetItem>
//Login login;
using std::cout;

extern usuario user;
extern usuario *currentUser;

Administrador::Administrador(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Administrador)
{
    ui->setupUi(this);
    user.printList(ui->usuariosNoUtorizados,currentUser);
    user.printList(ui->editarUsuario,currentUser);
    ui->usuariosAutorizados->setCurrentItem(0);
}

Administrador::~Administrador()
{
    delete ui;
}

void Administrador::on_autorizarUsuario_clicked()
{
    QListWidgetItem *usuarioSeleccionado=ui->usuariosNoUtorizados->currentItem();
    QString nombreU=usuarioSeleccionado->text();
    user.autorizar(currentUser,nombreU,true);
    if(user.getEstado(currentUser,nombreU)==true&&usuarioSeleccionado!=nullptr){
        user.printNode(ui->usuariosAutorizados,currentUser,nombreU);
        user.deleteFromList(ui->usuariosNoUtorizados,currentUser,nombreU);
    }

}
