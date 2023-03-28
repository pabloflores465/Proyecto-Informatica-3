#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "librodiario.h"
#include <iostream>

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

//contador que permite que se mueva el array
int i=0;
int k=0;
int j=0;
//Arreglo para guardar el indice de las cuentas
int indiceCuentas[100];
//Arreglo para guardar el monto de las cuentas
double montoCuentas[100];
//Arreglo para guardar el indice de las clasificaciones de cuentas
int indiceClasCuentas[100];

void MainWindow::on_pushButton_clicked()
{

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

    //Se llenan los arreglos
    //Indice de cuentas
    indiceCuentas[i]=lib.getCuenta1();
    i++;
    indiceCuentas[i]=lib.getCuenta2();
    i++;
    indiceCuentas[i]=lib.getCuenta3();
    i++;
    indiceCuentas[i]=lib.getCuenta4();
    i++;
    //Monto de las cuentas
    montoCuentas[k]=lib.getValor1();
    k++;
    montoCuentas[k]=lib.getValor2();
    k++;
    montoCuentas[k]=lib.getValor3();
    k++;
    montoCuentas[k]=lib.getValor4();
    k++;
    //Indice de la clasificación de cuentas
    indiceClasCuentas[j]=lib.getClasf1();
    j++;
    indiceClasCuentas[j]=lib.getClasf2();
    j++;
    indiceClasCuentas[j]=lib.getClasf3();
    j++;
    indiceClasCuentas[j]=lib.getClasf4();
    j++;
}
//Inica variables debe y haber

//banderas para inicializar el valor del debe y del haber
int b1=0;
int b2=0;
void MainWindow::on_pushButton_2_clicked()
{
    double db=0;
    double hb=0;
    double res=0;
    //bandera para evitar que se vuelva a colocar la cuenta
    int num=0;
    for (int i=0;i<100;i++)
    {

        int sw=indiceCuentas[i];
        switch(sw)
        {
        //Bancos
            case 1:
            {
                for(int j=0;j<100;j++)
                {
                    //debe

                    if(indiceClasCuentas[j]==0)
                    {
                        if (b1==0)
                        {
                            db=montoCuentas[0];
                            b1++;
                        }
                        else
                        {
                            db=db+montoCuentas[j];
                        }


                    }
                    else
                    {
                        if(b2==0)
                        {
                            hb=montoCuentas[0];
                            b2++;
                        }
                        else
                        {
                            hb=hb+montoCuentas[j];
                        }


                    }

                }
                if(num==0)
                {
                    res=db-hb;
                    QString Qres=QString::number(res);
                    ui->activosUi->addItem("Bancos: "+Qres);
                    num++;
                }

                break;

            }



        }
    }

}

