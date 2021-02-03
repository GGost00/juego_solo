#include "grafjugador.h"
cuerpograf::cuerpograf():escala(1)
{
    float posx,posy,velx,vely,mass,r,K,e;//crea valores float
    posx = 32;//se le da ina posicion en x
    posy = 150;//se le da una posicion en y
    r = 20;//se le da un radio
    mass = 50;//se le da una masa
    velx = 0;//se le da una velocidad x
    vely = 0;//se le da una velocidad y
    K = 0.08;//se le da resistencia al aire
    e = 0.2;//se le da elasticidad
    esf = new cuerpo(posx,posy,velx,vely,mass,r,K,e);//se crea una esfera la cuar sera el personaje
}

cuerpograf::~cuerpograf()
{
    delete esf; //se destruye el personaje
}

QRectF cuerpograf::boundingRect() const
{
    return QRectF(-1*escala*esf->getR(),-1*escala*esf->getR(),2*escala*esf->getR(),2*escala*esf->getR());//retorna una esfera
}

void cuerpograf::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::blue);
    painter->drawEllipse(boundingRect());
}

void cuerpograf::setEscala(float s)
{
    escala = s;//se le da una escala al personaje
}


void cuerpograf::actualizar(float v_lim)
{
    esf->actualizar();//se actualiza la posicion
    setPos(esf->getPX(),v_lim-esf->getPY());//se pone al jugador en la nueva posicion
}

cuerpo *cuerpograf::getEsf()
{
    return esf; // retorna al personaje
}
