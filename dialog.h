#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#include "login.h"

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
    void on_confirmarBBox_clicked();

private:
    Ui::Dialog *ui;

    logIn lI;
};

#endif // DIALOG_H
