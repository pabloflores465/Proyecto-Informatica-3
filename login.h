#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "mainwindow.h"
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

private:
    Ui::Login *ui;
    bool primerUsuarioCreado=false;
    MainWindow *mainW;
    usuario user;
    usuario *currentUser=new usuario();

};

#endif // LOGIN_H
