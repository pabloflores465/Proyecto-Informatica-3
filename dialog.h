#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "mainwindow.h"
#include "usuario.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();


private slots:
    void on_verificarButton2_clicked();
    void on_verificarButton_clicked();

private:
    Ui::Dialog *ui;

    MainWindow *mainW;
    usuario user;

    usuario *currentUser=new usuario();

};

#endif // DIALOG_H
