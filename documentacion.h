#ifndef DOCUMENTACION_H
#define DOCUMENTACION_H

#include <QString>

class documentacion
{
private:
    QString cuentas[20];
    QString clasificacion[20];
    QString descripcion[20];
public:
    documentacion();
    QString getCuentas(int indice);
    QString getClasificacion(int indice);
    QString getDescripcion(int indice);
};

#endif // DOCUMENTACION_H
