#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qcombobox.h"
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



private:
    Ui::MainWindow *ui;

    int numeroCuenta=0;
    void sumaCuentasLibroM(QComboBox *cuenta);

};
#endif // MAINWINDOW_H
