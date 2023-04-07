#ifndef BALANCEGENERAL_H
#define BALANCEGENERAL_H


class balanceGeneral
{
private:
    double totalActivos;
    double totalPasivos;
    double totalCapital;
    double totalPasivosCapital;
public:
    balanceGeneral();
    void setTotalActivos(double _totalActivos);
    void setTotalPasivos(double _totalPasivos);
    void setTotalCapital(double _totalCapital);
    void setTotalPasivosCapital(double _totalPasivosCapital);
    double getTotalActivos();
    double getTotalPasivos();
    double getTotalCapital();
    double getTotalPasivosCapital();
};

#endif // BALANCEGENERAL_H
