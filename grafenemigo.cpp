#include "grafenemigo.h"
grafenemigo::grafenemigo():escala(1)
{
    float posx,posy,velx,vely,mass,r,K,e;
    posx = 800;
    posy = 150;
    r = 20;
    mass = 50;
    velx = 0;
    vely = 0;
    K = 0.08;
    e = 0.6;
    esf = new enemy(posx,posy,velx,vely,mass,r,K,e);
}

grafenemigo::~grafenemigo()
{
    delete esf;
}

QRectF grafenemigo::boundingRect() const
{
    return QRectF(-1*escala*esf->getR(),-1*escala*esf->getR(),2*escala*esf->getR(),2*escala*esf->getR());
}

void grafenemigo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::red);
    painter->drawEllipse(boundingRect());
}

void grafenemigo::setEscala(float s)
{
    escala = s;
}

void grafenemigo::actualizar(float v_lim)
{
    esf->actualizar();
    setPos(esf->getPX(),v_lim-esf->getPY());
}

enemy *grafenemigo::getEsf()
{
    return esf;
}

