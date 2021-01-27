#ifndef GRAFENEMIGO_H
#define GRAFENEMIGO_H
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <stdlib.h>
#include <time.h>
#include "enemigo.h"

class grafenemigo: public QGraphicsItem
{
public:
    grafenemigo();
    ~grafenemigo();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
    void setEscala(float s);
    void actualizar(float v_lim);
    enemy *getEsf();

private:
    enemy * esf;
    float escala;
};

#endif // GRAFENEMIGO_H
