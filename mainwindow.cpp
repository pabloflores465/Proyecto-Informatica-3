#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "librodiario.h"
#include "libromayor.h"
#include "documentacion.h"
#include <iostream>
#include <QString>

documentacion docu;
libroDiario libroD;
libroMayor libroM;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);\

    //for de libro diario
    for(int i=0;i<20;i++){
        ui->cuentasCBox->addItem(docu.getCuenta(i));
    }
    //for de libro mayor
    for(int i=0;i<20;i++){
        ui->cuenta2->addItem(libroD.documentacion::getCuenta(i));
        ui->cuenta3->addItem(libroD.documentacion::getCuenta(i));
        ui->cuenta4->addItem(libroD.documentacion::getCuenta(i));
        ui->cuenta1->addItem(libroD.documentacion::getCuenta(i));
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_consultarButton_clicked(){
    ui->descripcionlist->addItem(docu.getCuenta((ui->cuentasCBox->currentIndex())));
    ui->descripcionlist->addItem(docu.getClasificacion((ui->cuentasCBox->currentIndex())));
    ui->descripcionlist->addItem(docu.getDescripcion((ui->cuentasCBox->currentIndex())));
}

void MainWindow::sumaCuentasLibroM(QComboBox *cuenta){
    if(libroD.documentacion::getClasificacion(cuenta->currentIndex())=="Activo"){
        if(libroD.getClasificacion(numeroCuenta)=="Debe"){
            libroM.setTotalCuenta(cuenta->currentIndex(), libroM.getTotalCuenta(cuenta->currentIndex())+libroD.getValor(numeroCuenta));
        }
        else if(libroD.getClasificacion(numeroCuenta)=="Haber"){
            libroM.setTotalCuenta(cuenta->currentIndex(), libroM.getTotalCuenta(cuenta->currentIndex())-libroD.getValor(numeroCuenta));
        }
    }
    else if(libroD.documentacion::getClasificacion(cuenta->currentIndex())=="Pasivo"){
        if(libroD.getClasificacion(numeroCuenta)=="Debe"){
            libroM.setTotalCuenta(cuenta->currentIndex(), libroM.getTotalCuenta(cuenta->currentIndex())+libroD.getValor(numeroCuenta));
        }
        else if(libroD.getClasificacion(numeroCuenta)=="Haber"){
            libroM.setTotalCuenta(cuenta->currentIndex(), libroM.getTotalCuenta(cuenta->currentIndex())-libroD.getValor(numeroCuenta));
        }
    }
    else if(libroD.documentacion::getClasificacion(cuenta->currentIndex())=="Ingreso"){
        if(libroD.getClasificacion(numeroCuenta)=="Debe"){
            libroM.setTotalCuenta(cuenta->currentIndex(), libroM.getTotalCuenta(cuenta->currentIndex())+libroD.getValor(numeroCuenta));
        }
        else if(libroD.getClasificacion(numeroCuenta)=="Haber"){
            libroM.setTotalCuenta(cuenta->currentIndex(), libroM.getTotalCuenta(cuenta->currentIndex())-libroD.getValor(numeroCuenta));
        }

    }
    else if(libroD.documentacion::getClasificacion(cuenta->currentIndex())=="Gasto"){
        if(libroD.getClasificacion(numeroCuenta)=="Debe"){
            libroM.setTotalCuenta(cuenta->currentIndex(), libroM.getTotalCuenta(cuenta->currentIndex())+libroD.getValor(numeroCuenta));
        }
        else if(libroD.getClasificacion(numeroCuenta)=="Haber"){
            libroM.setTotalCuenta(cuenta->currentIndex(), libroM.getTotalCuenta(cuenta->currentIndex())-libroD.getValor(numeroCuenta));
        }
    }
}

void MainWindow::on_anadirCuenta_clicked()
{

    libroD.setCuenta(numeroCuenta, ui->cuenta1->currentText());
    libroD.setValor(numeroCuenta, ui->valor1->value());
    libroD.setClasificacion(numeroCuenta, ui->clasificacion1->currentText());
    sumaCuentasLibroM(ui->cuenta1);
    numeroCuenta++;
    libroD.setCuenta(numeroCuenta, ui->cuenta2->currentText());
    libroD.setValor(numeroCuenta, ui->valor2->value());
    libroD.setClasificacion(numeroCuenta, ui->clasificacion2->currentText());
    sumaCuentasLibroM(ui->cuenta2);
    numeroCuenta++;
    libroD.setCuenta(numeroCuenta, ui->cuenta3->currentText());
    libroD.setValor(numeroCuenta,ui->valor3->value());
    libroD.setClasificacion(numeroCuenta, ui->clasificacion3->currentText());
    sumaCuentasLibroM(ui->cuenta3);
    numeroCuenta++;
    libroD.setCuenta(numeroCuenta, ui->cuenta4->currentText());
    libroD.setValor(numeroCuenta,ui->valor4->value());
    libroD.setClasificacion(numeroCuenta, ui->clasificacion4->currentText());
    sumaCuentasLibroM(ui->cuenta4);
    numeroCuenta++;

    ui->activosList->clear();
    ui->pasivosList->clear();
    ui->ingresosList->clear();
    ui->gastosList->clear();
    for(int i=0;i<20;i++){
        if(libroM.getClasificacion(i)=="Activo"){
            ui->activosList->addItem(libroM.getCuenta(i));
            ui->activosList->addItem(QString::number(libroM.getTotalCuenta(i)));
        }
        else if(libroM.getClasificacion(i)=="Pasivo"){
            ui->pasivosList->addItem(libroM.getCuenta(i));
            ui->pasivosList->addItem(QString::number(libroM.getTotalCuenta(i)));
        }
        else if(libroM.getClasificacion(i)=="Ingreso"){
            ui->ingresosList->addItem(libroM.getCuenta(i));
            ui->ingresosList->addItem(QString::number(libroM.getTotalCuenta(i)));
        }
        else if(libroM.getClasificacion(i)=="Gasto"){
            ui->gastosList->addItem(libroM.getCuenta(i));
            ui->gastosList->addItem(QString::number(libroM.getTotalCuenta(i)));
        }
    }
}






