#ifndef GRAFJUGADOR_H
#define GRAFJUGADOR_H
#include <QPainter>//libreria Painter
#include <QGraphicsItem>//libreria GraphicsItem
#include <QGraphicsScene>//libreria de GraphicsScene
#include "jugador.h"// clase jugador
#include <stdlib.h>//clase stdlib
#include <time.h>//clase time

class cuerpograf: public QGraphicsItem //ereda las funciones del QGraphicsItem
{
public:
    cuerpograf();//constructor por defecto de la clase
    ~cuerpograf();//destructor por defecto de la clase
    QRectF boundingRect() const;//funcion que dibuja
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);//funcion que pinta
    void setEscala(float s);//funcion para darle la escala al jugador
    void actualizar(float v_lim);//funcion para actualizar el movimiento del jugador
    cuerpo *getEsf();//funcion de la clase jugador

private:
    cuerpo * esf;//instancia de la clase jugador
    float escala;//valor que le da la escala al jugador
};

#endif // GRAFJUGADOR_H
