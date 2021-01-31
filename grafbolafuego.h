#ifndef GRAFBOLAFUEGO_H
#define GRAFBOLAFUEGO_H
#include <QPainter>
#include <QGraphicsItem>
#include "bolafuego.h"

class grafbolafuego: public QGraphicsItem
{
private:
    bolafuego * esf;
    float escala;
public:
    grafbolafuego();
    ~grafbolafuego();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
    void actualizar();
};

#endif // GRAFBOLAFUEGO_H
