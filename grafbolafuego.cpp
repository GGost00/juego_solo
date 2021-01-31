#include "grafbolafuego.h"

grafbolafuego::grafbolafuego()
{

}

QRectF grafbolafuego::boundingRect() const
{
    return QRectF(-1*escala*esf->getR(),-1*escala*esf->getR(),2*escala*esf->getR(),2*escala*esf->getR());
}

void grafbolafuego::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

}
