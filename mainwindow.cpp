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
//Contadores para ver cuantos espacios tiene el arreglo
int ver=0;
void MainWindow::on_pushButton_clicked()
{

    //objeto para acceder a la clase libroDiario
    libroDiario lib;


    int a=ui->cta1Ui->currentIndex();
    int b=ui->cta2Ui->currentIndex();
    int c=ui->cta3Ui->currentIndex();
    int d=ui->cta4Ui->currentIndex();
    if(a!=0)
    {
        //Extracción de valores del formulario
        int c1=ui->cta1Ui->currentIndex();
        int clf1=ui->clf1Ui->currentIndex();
        double mtd1=ui->mtd1Ui->value();
        //Al metodo set se le pasan los valores
        lib.setCuenta1(c1);
        lib.setValor1(mtd1);
        lib.setClasf1(clf1);
        ver++;


    }
    if (b!=0)
    {
        //Extracción de valores del formulario
        int c2=ui->cta2Ui->currentIndex();
        int clf2=ui->clf2Ui->currentIndex();
        double mtd2=ui->mtd2Ui->value();
        //Al metodo set se le pasan los valores
        lib.setCuenta2(c2);
        lib.setValor2(mtd2);
        lib.setClasf2(clf2);
        ver++;


    }
    if(c!=0)
    {
        //Extracción de valores del formulario
        int c3=ui->cta3Ui->currentIndex();
        int clf3=ui->clf3Ui->currentIndex();
        double mtd3=ui->mtd3Ui->value();
        //Al metodo set se le pasan los valores
        lib.setCuenta3(c3);
        lib.setValor3(mtd3);
         lib.setClasf3(clf3);
         ver++;

    }
    if(d!=0)
    {
        //Extracción de valores del formulario
        int c4=ui->cta4Ui->currentIndex();
        int clf4=ui->clf3Ui_2->currentIndex();
        double mtd4=ui->mtd4Ui->value();
        //Al metodo set se le pasan los valores
        lib.setCuenta4(c4);
        lib.setValor4(mtd4);
         lib.setClasf4(clf4);
         ver++;

    }
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



//banderas para inicializar el valor del debe y del haber
int b[19]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};


//arreglo para gurdar los totales de las cuentas
double total[19];
void MainWindow::on_pushButton_2_clicked()
{
    //variables del debe y haber
    double db[19]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    double hb[19]{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    //bandera para evitar que se vuelva a colocar la cuenta
    int num[19]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
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


                    if(indiceCuentas[j]==1)
                    {
                        //debe
                        if(indiceClasCuentas[j]==0)
                        {
                            if (b[0]==0)
                            {
                                db[0]=montoCuentas[0];
                                b[0]++;
                            }
                            else
                            {
                                db[0]=db[0]+montoCuentas[j];
                            }
                        }
                        //haber
                        else
                        {
                            if(b[0]==0)
                            {
                                hb[0]=montoCuentas[0];
                                b[0]++;
                            }
                            else
                            {
                                hb[0]=hb[0]+montoCuentas[j];
                            }
                        }
                    }

                }
                if(num[0]==0)
                {

                    total[0]=(db[0]-hb[0]);
                    num[0]++;

                }

                break;

            }
        case 2:
        {
            for(int j=0;j<100;j++)
            {


                if(indiceCuentas[j]==2)
                {
                    //debe
                    if(indiceClasCuentas[j]==0)
                    {
                        if (b[0]==0)
                        {
                            db[1]=montoCuentas[0];
                            b[0]++;
                        }
                        else
                        {
                            db[1]=db[1]+montoCuentas[j];
                        }
                    }
                    //haber
                    else
                    {
                        if(b[0]==0)
                        {
                            hb[1]=montoCuentas[0];
                            b[0]++;
                        }
                        else
                        {
                            hb[1]=hb[1]+montoCuentas[j];
                        }
                    }
                }

            }
            if(num[1]==0)
            {

                total[1]=(db[1]-hb[1]);
                num[1]++;

            }

        }



        }
    }

    QString Qres1=QString::number(total[0]);
     QString Qres2=QString::number(total[1]);
    ui->activosUi->addItem("Bancos: "+Qres1);
    ui->activosUi->addItem("Iva por cobrar: "+Qres2);

}
