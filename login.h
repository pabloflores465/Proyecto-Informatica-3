#ifndef LOGIN_H
#define LOGIN_H


#include "administrador.h"
#include <QDialog>
#include "mainwindow.h"
#include "infousuario.h"
#include "usuario.h"

namespace Ui {
class Login;
}


class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_verificarButton2_clicked();
    void on_verificarButton_clicked();
    void on_verificarAdministrador_clicked();

private:
    Ui::Login *ui;
    bool primerUsuarioCreado=true;
    MainWindow *mainW;
    Administrador *admin;

    infoUsuario infoadmin;
};

#endif // LOGIN_H
