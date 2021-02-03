#include "pared.h"

pared::pared(int w_, int h_, int x, int y)
{
    w = w_;//se le da un largo a la pared
    h = h_;//se le da un ancho a la pared
    posx = x;// se le da una posicion x
    posy = y;// se le da una posicion y
}

QRectF pared::boundingRect() const
{
    return QRectF(-posx,-posy,w,h);//se dibuja un rectangulo
}

void pared::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    painter->setBrush(Qt::blue);
//    painter->drawRect(boundingRect());
}
