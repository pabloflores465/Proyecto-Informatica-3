#ifndef ESTADORESULTADOS_H
#define ESTADORESULTADOS_H


class estadoResultados
{
private:
    double totalIngresos;
    double utilidadBruta;
    double utilidadAntesImpuestos;
    double utilidadNeta;
    double isr;

public:
    estadoResultados();
    void setTotalIngresos(double _totalingresos);
    void setUtilidadBruta(double _utlidadB);
    void setUtilidadAntesImpuestos(double _utilidadAntesI);
    void setUtilidadNeta(double _utilidadNeta);
    void setIsr(double _isr);
    double getTotalIngresos();
    double getUtilidadBruta();
    double getUtilidadAntesImpuestos();
    double getUtilidadNeta();
    double getIsr();

};

#endif // ESTADORESULTADOS_H
