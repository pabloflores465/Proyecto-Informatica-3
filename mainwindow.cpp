#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "librodiario.h"
#include "libromayor.h"
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
double montoCuentas[100]={0};
//Arreglo para guardar el indice de las clasificaciones de cuentas
int indiceClasCuentas[100];

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




//arreglo para gurdar los totales de las cuentas
double total[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
void MainWindow::on_pushButton_2_clicked()
{
    //variables del debe y haber
    double db[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    double hb[20]{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    //bandera para evitar que se vuelva a colocar la cuenta
    int num[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    for (int i=0;i<100;i++)
    {

        int sw=indiceCuentas[i];
        switch(sw)
        {
        //Activos 1-6
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
                            db[0]=db[0]+montoCuentas[j];
                        }
                        //haber
                        else
                        {
                            hb[0]=hb[0]+montoCuentas[j];
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
        //iva por cobrar
        case 2:
        {
            for(int j=0;j<100;j++)
            {
                if(indiceCuentas[j]==2)
                {
                    //debe
                    if(indiceClasCuentas[j]==0)
                    {

                        db[1]=db[1]+montoCuentas[j];

                    }
                    //haber
                    else
                    {
                        hb[1]=hb[1]+montoCuentas[j];
                    }
                }
            }
            if(num[1]==0)
            {
                total[1]=(db[1]-hb[1]);
                num[1]++;
            }
            break;
        }
        //Inventarios
        case 3:
        {
            for(int j=0;j<100;j++)
            {


                if(indiceCuentas[j]==3)
                {
                    //debe
                    if(indiceClasCuentas[j]==0)
                    {

                        db[2]=db[2]+montoCuentas[j];

                    }
                    //haber
                    else
                    {
                        hb[2]=hb[2]+montoCuentas[j];
                    }
                }
            }
            if(num[2]==0)
            {
                total[2]=(db[2]-hb[2]);
                num[2]++;
            }
        }
        //Clientes
        case 4:
        {
            for(int j=0;j<100;j++)
            {


                if(indiceCuentas[j]==4)
                {
                    //debe
                    if(indiceClasCuentas[j]==0)
                    {

                        db[3]=db[3]+montoCuentas[j];

                    }
                    //haber
                    else
                    {
                        hb[3]=hb[3]+montoCuentas[j];
                    }
                }
            }
            if(num[3]==0)
            {
                total[3]=(db[3]-hb[3]);
                num[3]++;
            }
        }
        //Vehiculos
        case 5:
        {
            for(int j=0;j<100;j++)
            {


                if(indiceCuentas[j]==5)
                {
                    //debe
                    if(indiceClasCuentas[j]==0)
                    {

                        db[4]=db[4]+montoCuentas[j];

                    }
                    //haber
                    else
                    {
                        hb[4]=hb[4]+montoCuentas[j];
                    }
                }
            }
            if(num[4]==0)
            {
                total[4]=(db[4]-hb[4]);
                num[4]++;
            }
        }
        //Gastos de organización
        case 6:
        {
            for(int j=0;j<100;j++)
            {


                if(indiceCuentas[j]==6)
                {
                    //debe
                    if(indiceClasCuentas[j]==0)
                    {

                        db[5]=db[5]+montoCuentas[j];

                    }
                    //haber
                    else
                    {
                        hb[5]=hb[5]+montoCuentas[j];
                    }
                }
            }
            if(num[5]==0)
            {
                total[5]=(db[5]-hb[5]);
                num[5]++;
            }
        }
        //Pasivos
        //Capital Social
        case 7:
        {
            for(int j=0;j<100;j++)
            {


                if(indiceCuentas[j]==7)
                {
                    //debe
                    if(indiceClasCuentas[j]==0)
                    {

                        db[6]=db[6]+montoCuentas[j];

                    }
                    //haber
                    else
                    {
                        hb[6]=hb[6]+montoCuentas[j];
                    }
                }
            }
            if(num[6]==0)
            {
                total[6]=(db[6]-hb[6]);
                num[6]++;
            }
        }
        case 8:
        {
            for(int j=0;j<100;j++)
            {


                if(indiceCuentas[j]==8)
                {
                    //debe
                    if(indiceClasCuentas[j]==0)
                    {

                        db[7]=db[7]+montoCuentas[j];

                    }
                    //haber
                    else
                    {
                        hb[7]=hb[7]+montoCuentas[j];
                    }
                }
            }
            if(num[7]==0)
            {
                total[7]=(db[7]-hb[7]);
                num[7]++;
            }
        }
        case 9:
        {
            for(int j=0;j<100;j++)
            {


                if(indiceCuentas[j]==9)
                {
                    //debe
                    if(indiceClasCuentas[j]==0)
                    {

                        db[8]=db[8]+montoCuentas[j];

                    }
                    //haber
                    else
                    {
                        hb[8]=hb[8]+montoCuentas[j];
                    }
                }
            }
            if(num[8]==0)
            {
                total[8]=(db[8]-hb[8]);
                num[8]++;
            }
        }
        case 10:
        {
            for(int j=0;j<100;j++)
            {


                if(indiceCuentas[j]==10)
                {
                    //debe
                    if(indiceClasCuentas[j]==0)
                    {

                        db[9]=db[9]+montoCuentas[j];

                    }
                    //haber
                    else
                    {
                        hb[9]=hb[9]+montoCuentas[j];
                    }
                }
            }
            if(num[9]==0)
            {
                total[9]=(db[9]-hb[9]);
                num[9]++;
            }
        }
        case 11:
        {
            for(int j=0;j<100;j++)
            {


                if(indiceCuentas[j]==11)
                {
                    //debe
                    if(indiceClasCuentas[j]==0)
                    {

                        db[10]=db[10]+montoCuentas[j];

                    }
                    //haber
                    else
                    {
                        hb[10]=hb[10]+montoCuentas[j];
                    }
                }
            }
            if(num[10]==0)
            {
                total[10]=(db[10]-hb[10]);
                num[10]++;
            }
        }
        case 12:
        {
            for(int j=0;j<100;j++)
            {


                if(indiceCuentas[j]==12)
                {
                    //debe
                    if(indiceClasCuentas[j]==0)
                    {

                        db[11]=db[11]+montoCuentas[j];

                    }
                    //haber
                    else
                    {
                        hb[11]=hb[11]+montoCuentas[j];
                    }
                }
            }
            if(num[11]==0)
            {
                total[11]=(db[11]-hb[11]);
                num[11]++;
            }
        }
        case 13:
        {
            for(int j=0;j<100;j++)
            {


                if(indiceCuentas[j]==13)
                {
                    //debe
                    if(indiceClasCuentas[j]==0)
                    {

                        db[12]=db[12]+montoCuentas[j];

                    }
                    //haber
                    else
                    {
                        hb[12]=hb[12]+montoCuentas[j];
                    }
                }
            }
            if(num[12]==0)
            {
                total[12]=(db[12]-hb[12]);
                num[12]++;
            }
        }
        case 14:
        {
            for(int j=0;j<100;j++)
            {


                if(indiceCuentas[j]==14)
                {
                    //debe
                    if(indiceClasCuentas[j]==0)
                    {

                        db[13]=db[13]+montoCuentas[j];

                    }
                    //haber
                    else
                    {
                        hb[13]=hb[13]+montoCuentas[j];
                    }
                }
            }
            if(num[13]==0)
            {
                total[13]=(db[13]-hb[13]);
                num[13]++;
            }
        }
        case 15:
        {
            for(int j=0;j<100;j++)
            {


                if(indiceCuentas[j]==15)
                {
                    //debe
                    if(indiceClasCuentas[j]==0)
                    {

                        db[14]=db[14]+montoCuentas[j];

                    }
                    //haber
                    else
                    {
                        hb[14]=hb[14]+montoCuentas[j];
                    }
                }
            }
            if(num[14]==0)
            {
                total[14]=(db[14]-hb[14]);
                num[14]++;
            }
        }
        case 16:
        {
            for(int j=0;j<100;j++)
            {


                if(indiceCuentas[j]==16)
                {
                    //debe
                    if(indiceClasCuentas[j]==0)
                    {

                        db[15]=db[15]+montoCuentas[j];

                    }
                    //haber
                    else
                    {
                        hb[15]=hb[15]+montoCuentas[j];
                    }
                }
            }
            if(num[15]==0)
            {
                total[15]=(db[15]-hb[15]);
                num[15]++;
            }
        }
        case 17:
        {
            for(int j=0;j<100;j++)
            {


                if(indiceCuentas[j]==17)
                {
                    //debe
                    if(indiceClasCuentas[j]==0)
                    {

                        db[16]=db[16]+montoCuentas[j];

                    }
                    //haber
                    else
                    {
                        hb[16]=hb[16]+montoCuentas[j];
                    }
                }
            }
            if(num[16]==0)
            {
                total[16]=(db[16]-hb[16]);
                num[16]++;
            }
        }
        case 18:
        {
            for(int j=0;j<100;j++)
            {


                if(indiceCuentas[j]==18)
                {
                    //debe
                    if(indiceClasCuentas[j]==0)
                    {

                        db[17]=db[17]+montoCuentas[j];

                    }
                    //haber
                    else
                    {
                        hb[17]=hb[17]+montoCuentas[j];
                    }
                }
            }
            if(num[17]==0)
            {
                total[17]=(db[17]-hb[17]);
                num[17]++;
            }
        }
        case 19:
        {
            for(int j=0;j<100;j++)
            {


                if(indiceCuentas[j]==19)
                {
                    //debe
                    if(indiceClasCuentas[j]==0)
                    {

                        db[18]=db[18]+montoCuentas[j];

                    }
                    //haber
                    else
                    {
                        hb[18]=hb[18]+montoCuentas[j];
                    }
                }
            }
            if(num[18]==0)
            {
                total[18]=(db[18]-hb[18]);
                num[18]++;
            }
        }
        case 20:
        {
            for(int j=0;j<100;j++)
            {


                if(indiceCuentas[j]==20)
                {
                    //debe
                    if(indiceClasCuentas[j]==0)
                    {

                        db[19]=db[19]+montoCuentas[j];

                    }
                    //haber
                    else
                    {
                        hb[19]=hb[19]+montoCuentas[j];
                    }
                }
            }
            if(num[19]==0)
            {
                total[19]=(db[19]-hb[19]);
                num[19]++;
            }
        }
        }
    }
    //Activos
    QString Qres1=QString::number(total[0]);
    QString Qres2=QString::number(total[1]);
    QString Qres3=QString::number(total[2]);
    QString Qres4=QString::number(total[3]);
    QString Qres5=QString::number(total[4]);
    QString Qres6=QString::number(total[5]);
    //Pasivos
    QString Qres7=QString::number(total[6]);
    QString Qres8=QString::number(total[7]);
    QString Qres9=QString::number(total[8]);
    QString Qres10=QString::number(total[9]);
    QString Qres11=QString::number(total[10]);
    QString Qres12=QString::number(total[11]);
    //Ingresos
    QString Qres13=QString::number(total[12]);
    //Gastos
    QString Qres14=QString::number(total[13]);
    QString Qres15=QString::number(total[14]);
    QString Qres16=QString::number(total[15]);
    QString Qres17=QString::number(total[16]);
    QString Qres18=QString::number(total[17]);
    QString Qres19=QString::number(total[18]);
    QString Qres20=QString::number(total[19]);

    //Activos
    ui->activosUi->addItem("Bancos: "+Qres1);
    ui->activosUi->addItem("Iva por cobrar: "+Qres2);
    ui->activosUi->addItem("Iventarios: "+Qres3);
    ui->activosUi->addItem("Vehiculos: "+Qres4);
    ui->activosUi->addItem("Clientes: "+Qres5);
    ui->activosUi->addItem("Gastos de organizació: "+Qres6);
    //Pasivos
    ui->pasivosUi->addItem("Capital Social: "+Qres7);
    ui->pasivosUi->addItem("Proveedores "+Qres8);
    ui->pasivosUi->addItem("Iva por pagar: "+Qres9);
    ui->pasivosUi->addItem("Prestaciones laborales por pagar: "+Qres10);
    ui->pasivosUi->addItem("Depreciación acumulada de Vehiculo: "+Qres11);
    ui->pasivosUi->addItem("Documentos por pagar: "+Qres12);
    //Ingresos
    ui->IngresosUi->addItem("Ventas: "+Qres13);
    //Gastos
    ui->gastosUi->addItem("Alquileres: "+Qres14);
    ui->gastosUi->addItem("Sueldos de administración: "+Qres15);
    ui->gastosUi->addItem("Sueldos de ventas: "+Qres16);
    ui->gastosUi->addItem("Prestaciones laborales: "+Qres17);
    ui->gastosUi->addItem("Depreciación de Vehiculo: "+Qres18);
    ui->gastosUi->addItem("Amortizacion Gastos de organización: "+Qres19);
    ui->gastosUi->addItem("Costo de ventas: "+Qres20);


    //Se le pasan valores a los metodos set del libro mayor(totales)
    libroMayor my;
    my.setTotalesCt1(total[0]);
    my.setTotalesCt2(total[1]);
    my.setTotalesCt3(total[2]);
    my.setTotalesCt4(total[3]);
    my.setTotalesCt5(total[4]);
    my.setTotalesCt6(total[5]);
    my.setTotalesCt7(total[6]);
    my.setTotalesCt8(total[7]);
    my.setTotalesCt9(total[8]);
    my.setTotalesCt10(total[9]);
    my.setTotalesCt11(total[10]);
    my.setTotalesCt12(total[11]);
    my.setTotalesCt13(total[12]);
    my.setTotalesCt14(total[13]);
    my.setTotalesCt15(total[14]);
    my.setTotalesCt16(total[15]);
    my.setTotalesCt17(total[16]);
    my.setTotalesCt18(total[17]);
    my.setTotalesCt19(total[18]);
    my.setTotalesCt20(total[19]);


}
