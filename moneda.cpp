#include "moneda.h"
moneda::moneda( int x, int y)
{

    posx = x;//se le da la posicion en x
    posy = y;//se le da la posicion en y
    setPos(posx,posy);
}
int moneda::getR() const
{
    return r;// se devuelve el radio de la esfera
}

void moneda::setR(int value)
{
    r = value;// se le da valor al radio
}

int moneda::getPosx() const
{
    return posx;//se devuelve la posicion en x
}

void moneda::setPosx(int value)
{
    posx = value;// se le da una posicion x
}

int moneda::getPosy() const
{
    return posy;//se devuelve la posicion en y
}

void moneda::setPosy(int value)
{
    posy = value;// se le da una posicion y
}

QRectF moneda::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);//dibuja una esfera
}

void moneda::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)//pinta una esfera
{
    painter->setBrush(Qt::darkYellow);
    painter->drawEllipse(boundingRect());

}
