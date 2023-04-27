#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qcombobox.h"
#include "QListWidget"
#include <QMainWindow>
#include <QMessageBox>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_consultarButton_clicked();
    void on_anadirCuenta_clicked();



    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    void sumaCuentasLibroM(QComboBox *cuenta, int numeroCuenta);
    void valoresDebe(QListWidget *clasificacion, int cuenta);
    void valoresHaber(QListWidget *clasificaion, int cuenta);
    void agregarAlMayor(QListWidget *clasificacion, int cuenta);

};
#endif // MAINWINDOW_H
