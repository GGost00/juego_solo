#ifndef GRAFJUGADOR_H
#define GRAFJUGADOR_H
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "jugador.h"
#include <stdlib.h>
#include <time.h>

class cuerpograf: public QGraphicsItem
{
public:
    cuerpograf();
    ~cuerpograf();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
    void setEscala(float s);
    void actualizar(float v_lim);
    cuerpo *getEsf();

private:
    cuerpo * esf;
    float escala;
};

#endif // GRAFJUGADOR_H
