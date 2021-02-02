#include "grafjugador.h"
cuerpograf::cuerpograf():escala(1)
{
    float posx,posy,velx,vely,mass,r,K,e;
    posx = 32;
    posy = 150;
    r = 20;
    mass = 50;
    velx = 0;
    vely = 0;
    K = 0.08;
    e = 0.2;
    esf = new cuerpo(posx,posy,velx,vely,mass,r,K,e);
}

cuerpograf::~cuerpograf()
{
    delete esf;
}

QRectF cuerpograf::boundingRect() const
{
    return QRectF(-1*escala*esf->getR(),-1*escala*esf->getR(),2*escala*esf->getR(),2*escala*esf->getR());
}

void cuerpograf::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::blue);
    painter->drawEllipse(boundingRect());
}

void cuerpograf::setEscala(float s)
{
    escala = s;
}


void cuerpograf::actualizar(float v_lim)
{
    esf->actualizar();
    setPos(esf->getPX(),v_lim-esf->getPY());
}

cuerpo *cuerpograf::getEsf()
{
    return esf;
}
