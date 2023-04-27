#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include <QMainWindow>
#include "infousuario.h"
//#include "login.h"
//class Login;

namespace Ui {
class Administrador;
}

class Administrador : public QMainWindow
{
    Q_OBJECT

public:
    explicit Administrador(QWidget *parent = nullptr);
    ~Administrador();

private slots:
    void on_autorizarUsuario_clicked();

private:
    Ui::Administrador *ui;
};

#endif // ADMINISTRADOR_H
