#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "librodiario.h"
#include "libromayor.h"
#include "documentacion.h"
#include "balancegeneral.h"
#include "estadoresultados.h"
#include <iostream>
#include <QString>
#include <QMessageBox>
#include <QCloseEvent>

using std::cout,std::endl;

documentacion docu;
libroDiario libroD;
libroMayor libroM;
const int cuentasTotales=20;
const int cuentasIngresadas=100;
int numeroPartida=0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);\

    //for de libro diario
    for(int i=0;i<cuentasTotales;i++){
        ui->cuentasCBox->addItem(docu.getCuenta(i));
    }
    //for de libro mayor
    for(int i=0;i<cuentasTotales;i++){
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

//Módulo de Documentación
void MainWindow::on_consultarButton_clicked(){
    ui->descripcionlist->addItem(docu.getCuenta((ui->cuentasCBox->currentIndex())));
    ui->descripcionlist->addItem(docu.getClasificacion((ui->cuentasCBox->currentIndex())));
    ui->descripcionlist->addItem(docu.getDescripcion((ui->cuentasCBox->currentIndex())));
}

//void MainWindow::
//Funciones del Libro Mayor


void MainWindow::sumaCuentasLibroM(QComboBox *cuenta, int numeroCuenta){
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
            libroM.setTotalCuenta(cuenta->currentIndex(), libroM.getTotalCuenta(cuenta->currentIndex())-libroD.getValor(numeroCuenta));
        }
        else if(libroD.getClasificacion(numeroCuenta)=="Haber"){
            libroM.setTotalCuenta(cuenta->currentIndex(), libroM.getTotalCuenta(cuenta->currentIndex())+libroD.getValor(numeroCuenta));
        }
    }
    else if(libroD.documentacion::getClasificacion(cuenta->currentIndex())=="Ingreso"){
        if(libroD.getClasificacion(numeroCuenta)=="Debe"){
            libroM.setTotalCuenta(cuenta->currentIndex(), libroM.getTotalCuenta(cuenta->currentIndex())-libroD.getValor(numeroCuenta));
        }
        else if(libroD.getClasificacion(numeroCuenta)=="Haber"){
            libroM.setTotalCuenta(cuenta->currentIndex(), libroM.getTotalCuenta(cuenta->currentIndex())+libroD.getValor(numeroCuenta));
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

void MainWindow::valoresDebe(QListWidget *clasificacion, int cuenta){
    for(int i=0;i<cuentasIngresadas;i++){
        if(libroD.getCuenta(i)==libroM.getCuenta(cuenta)&&libroD.getClasificacion(i)=="Debe"){
            clasificacion->addItem(QString::number(libroD.getValor(i)));
            libroM.setTotalDebe(cuenta, libroM.getTotalDebe(cuenta)+libroD.getValor(i));

        }

    }
}
void MainWindow::valoresHaber(QListWidget *clasificacion, int cuenta){
    for(int i=0;i<cuentasIngresadas;i++){
        if(libroD.getCuenta(i)==libroM.getCuenta(cuenta)&&libroD.getClasificacion(i)=="Haber"){
            clasificacion->addItem(QString::number(libroD.getValor(i)));
            libroM.setTotalHaber(cuenta, libroM.getTotalHaber(cuenta)+libroD.getValor(i));
        }
    }
}

void MainWindow::agregarAlMayor(QListWidget *clasificacion, int cuenta){
    clasificacion->addItem(libroM.getCuenta(cuenta));
    clasificacion->addItem("Debe");
    valoresDebe(clasificacion,cuenta);
    clasificacion->addItem("Total Debe");
    clasificacion->addItem(QString::number(libroM.getTotalDebe(cuenta)));
    clasificacion->addItem("Haber");
    valoresHaber(clasificacion,cuenta);
    clasificacion->addItem("Total Haber");
    clasificacion->addItem(QString::number(libroM.getTotalHaber(cuenta)));
    clasificacion->addItem("Total Cuenta");
    clasificacion->addItem(QString::number(libroM.getTotalCuenta(cuenta)));
}

void MainWindow::on_anadirCuenta_clicked()
{
    balanceGeneral balanceG;
    estadoResultados estadoR;

    int totalDebe=0;
    int totalHaber=0;
    int numeroCuenta=0;

    //Libro Diario
    libroD.setCuenta(numeroCuenta, ui->cuenta1->currentText());
    libroD.setValor(numeroCuenta, ui->valor1->value());
    libroD.setClasificacion(numeroCuenta, ui->clasificacion1->currentText());
    numeroCuenta++;
    libroD.setCuenta(numeroCuenta, ui->cuenta2->currentText());
    libroD.setValor(numeroCuenta, ui->valor2->value());
    libroD.setClasificacion(numeroCuenta, ui->clasificacion2->currentText());
    numeroCuenta++;
    libroD.setCuenta(numeroCuenta, ui->cuenta3->currentText());
    libroD.setValor(numeroCuenta,ui->valor3->value());
    libroD.setClasificacion(numeroCuenta, ui->clasificacion3->currentText());
    numeroCuenta++;
    libroD.setCuenta(numeroCuenta, ui->cuenta4->currentText());
    libroD.setValor(numeroCuenta,ui->valor4->value());
    libroD.setClasificacion(numeroCuenta, ui->clasificacion4->currentText());
    numeroCuenta++;

    for (int i = 0; i < numeroCuenta; ++i) {
        if(libroD.getClasificacion(i)=="Debe"){
            totalDebe=totalDebe+libroD.getValor(i);
        }
        else if(libroD.getClasificacion(i)=="Haber"){
            totalHaber=totalHaber+libroD.getValor(i);
        }
    }

    if(totalDebe!=totalHaber){
        QMessageBox::information(this,"Error","Lo siento las partidas no cuadran");
        return;
    }

    //Libro Mayor
    sumaCuentasLibroM(ui->cuenta1,numeroCuenta-4);
    sumaCuentasLibroM(ui->cuenta2,numeroCuenta-3);
    sumaCuentasLibroM(ui->cuenta3,numeroCuenta-2);
    sumaCuentasLibroM(ui->cuenta4,numeroCuenta-1);
    ui->activosList->clear();
    ui->pasivosList->clear();
    ui->ingresosList->clear();
    ui->gastosList->clear();
    for(int i=0;i<cuentasTotales;i++){
        if(libroM.getClasificacion(i)=="Activo"){
            agregarAlMayor(ui->activosList,i);
        }
        else if(libroM.getClasificacion(i)=="Pasivo"){
            agregarAlMayor(ui->pasivosList,i);
        }
        else if(libroM.getClasificacion(i)=="Ingreso"){
            agregarAlMayor(ui->ingresosList,i);
        }
        else if(libroM.getClasificacion(i)=="Gasto"){
            agregarAlMayor(ui->gastosList,i);
        }
    }

    //Estado de Resultados
    ui->estadoRList->clear();
    for (int i = 0; i < cuentasTotales; i++) {
        if(libroM.getClasificacion(i)=="Ingreso"){
            ui->estadoRList->addItem(libroM.getCuenta(i));
            ui->estadoRList->addItem(QString::number(libroM.getTotalCuenta(i)));
            estadoR.setTotalIngresos(estadoR.getTotalIngresos()+libroM.getTotalCuenta(i));
        }
    }
    int i1=0;
    while(libroM.getCuenta(i1)!="Costo de Ventas"){
        i1++;
    }
    ui->estadoRList->addItem(libroM.getCuenta(i1));
    ui->estadoRList->addItem(QString::number(libroM.getTotalCuenta(i1)));
    estadoR.setUtilidadBruta(estadoR.getTotalIngresos()-libroM.getTotalCuenta(i1));
    ui->estadoRList->addItem("Utilidad Bruta");
    ui->estadoRList->addItem(QString::number(estadoR.getUtilidadBruta()));
    estadoR.setUtilidadAntesImpuestos(estadoR.getUtilidadBruta());
    for (int i = 0; i < cuentasTotales; ++i) {
        if(libroM.getClasificacion(i)=="Gasto"&&libroM.getCuenta(i)!="Costo de Ventas"){
            ui->estadoRList->addItem(libroM.getCuenta(i));
            ui->estadoRList->addItem(QString::number(libroM.getTotalCuenta(i)));
            estadoR.setUtilidadAntesImpuestos(estadoR.getUtilidadAntesImpuestos()-libroM.getTotalCuenta(i));
        }
    }
    ui->estadoRList->addItem("Utilidad antes de impuestos");
    ui->estadoRList->addItem(QString::number(estadoR.getUtilidadAntesImpuestos()));

    estadoR.setUtilidadNeta(estadoR.getUtilidadAntesImpuestos());
    if(estadoR.getUtilidadAntesImpuestos()<0){
        estadoR.setIsr(0.00);
    }
    else if((estadoR.getUtilidadAntesImpuestos()/estadoR.getTotalIngresos())<=0.3){
        estadoR.setIsr(estadoR.getUtilidadAntesImpuestos()*0.25);
    }
    else if((estadoR.getUtilidadAntesImpuestos()/estadoR.getTotalIngresos())>0.3){
        if (estadoR.getUtilidadAntesImpuestos()<30000){
            estadoR.setIsr(estadoR.getUtilidadAntesImpuestos()*0.05);
        }
        else{
            int excesoRenta=(estadoR.getUtilidadAntesImpuestos()-30000);
            estadoR.setIsr((30000*0.05)+(excesoRenta*0.07));
        }
    }
    estadoR.setUtilidadNeta(estadoR.getUtilidadNeta()+estadoR.getIsr());
    ui->estadoRList->addItem("ISR");
    ui->estadoRList->addItem(QString::number(estadoR.getIsr()));
    ui->estadoRList->addItem("Utilidad Neta");
    ui->estadoRList->addItem(QString::number(estadoR.getUtilidadNeta()));

    //Balance General

    balanceG.setTotalCapital(balanceG.getTotalCapital()+estadoR.getUtilidadAntesImpuestos());
    ui->ActivosBG->clear();
    ui->PasivoBG->clear();
    ui->CapitalBG->clear();
    for (int i = 0; i < cuentasTotales; ++i) {
        if(libroM.getClasificacion(i)=="Activo"){
            ui->ActivosBG->addItem(libroM.getCuenta(i));
            ui->ActivosBG->addItem(QString::number(libroM.getTotalCuenta(i)));
            balanceG.setTotalActivos(balanceG.getTotalActivos()+libroM.getTotalCuenta(i));

        }
        else if(libroM.getClasificacion(i)=="Pasivo"&&libroM.getCuenta(i)!="Capital Social"){
            ui->PasivoBG->addItem(libroM.getCuenta(i));
            ui->PasivoBG->addItem(QString::number(libroM.getTotalCuenta(i)));
            balanceG.setTotalPasivos(balanceG.getTotalPasivos()+libroM.getTotalCuenta(i));
        }
        else if (libroM.getCuenta(i)=="Capital Social"){
            ui->CapitalBG->addItem(libroM.getCuenta(i));
            ui->CapitalBG->addItem(QString::number(libroM.getTotalCuenta(i)));
            balanceG.setTotalCapital(balanceG.getTotalCapital()+libroM.getTotalCuenta(i));
        }
    }



    balanceG.setTotalPasivosCapital(balanceG.getTotalPasivos()+balanceG.getTotalCapital());
    ui->ActivosBG->addItem("Total de Activos");
    ui->ActivosBG->addItem(QString::number(balanceG.getTotalActivos()));
    ui->PasivoBG->addItem("Total de Pasivos");
    ui->PasivoBG->addItem(QString::number(balanceG.getTotalPasivos()));
    ui->CapitalBG->addItem("Utilidad Antes de Impuestos");
    ui->CapitalBG->addItem(QString::number(estadoR.getUtilidadAntesImpuestos()));
    ui->CapitalBG->addItem("Total de Capital");
    ui->CapitalBG->addItem(QString::number(balanceG.getTotalCapital()));
    ui->CapitalBG->addItem("Total de Pasivos y Capital");
    ui->CapitalBG->addItem(QString::number(balanceG.getTotalPasivosCapital()));

}

