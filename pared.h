#ifndef PARED_H
#define PARED_H

#include <QGraphicsItem>
#include <QPainter>

class pared: public QGraphicsItem//se ereda del QGraphicsItem
{

    int w,h;//ancho y alto de la pared
    int posx, posy;//esquina superior izquierda de la pared

public:
    pared(int w_, int h_, int x, int y);//constructor de la pared
    QRectF boundingRect() const;//funcion que dibuja
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);//funcion que pinta
};

#endif // PARED_H
