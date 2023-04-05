#ifndef DOCUMENTACION_H
#define DOCUMENTACION_H

#include <QString>

class documentacion
{
private:
    QString cuenta[20];
    QString clasificacion[20];
    QString descripcion[20];
public:
    documentacion();
    QString getCuenta(int indice);
    virtual QString getClasificacion(int indice);
    virtual QString getDescripcion(int indice);
};

#endif // DOCUMENTACION_H
