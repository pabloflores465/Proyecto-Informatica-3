#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "librodiario.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //contador que permite que se mueva el array
    int i=0;
    //Arreglo para guardar el indice de las cuentas
    int indiceCuentas[100];
    //Arreglo para guardar el monto de las cuentas
    double montoCuentas[100];
    //Arreglo para guardar el indice de las clasificaciones de cuentas
    int indiceClasCuentas[100];
    //objeto para acceder a la clase libroDiario
    libroDiario lib;

    //Extracción de valores del formulario
    int c1=ui->cta1Ui->currentIndex();
    int c2=ui->cta2Ui->currentIndex();
    int c3=ui->cta3Ui->currentIndex();
    int c4=ui->cta4Ui->currentIndex();

    int clf1=ui->clf1Ui->currentIndex();
    int clf2=ui->clf2Ui->currentIndex();
    int clf3=ui->clf3Ui->currentIndex();
    int clf4=ui->clf3Ui_2->currentIndex();

    double mtd1=ui->mtd1Ui->value();
    double mtd2=ui->mtd2Ui->value();
    double mtd3=ui->mtd3Ui->value();
    double mtd4=ui->mtd4Ui->value();

    //Al metodo set se le pasan los valores
    lib.setCuenta1(c1);
    lib.setCuenta2(c2);
    lib.setCuenta3(c3);
    lib.setCuenta4(c4);

    lib.setValor1(mtd1);
    lib.setValor2(mtd2);
    lib.setValor3(mtd3);
    lib.setValor4(mtd4);

    lib.setClasf1(clf1);
    lib.setClasf2(clf2);
    lib.setClasf3(clf3);
    lib.setClasf4(clf4);

}

