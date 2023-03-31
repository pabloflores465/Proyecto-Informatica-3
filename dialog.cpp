#include "dialog.h"
#include "ui_dialog.h"

#include <QMessageBox>

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

void Dialog::on_confirmarBBox_clicked()
{
    int i=1;
    lI.setNoUsuarios(i);
    lI.setNombre(3,ui->usuarioLEdit->text());
    ui->nombreLEdit->setText(lI.getNombre(3));
    i++;

}

