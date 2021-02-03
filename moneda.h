#ifndef MONEDA_H
#define MONEDA_H
#include <QGraphicsItem>
#include <QPainter>

class moneda: public QGraphicsItem //ereda funciones del QGraphicsItem
{

    int r=10;//radio de la esfera
    int posx, posy;//posicion de la esfera

public:
    moneda( int x, int y); //constructor de la moneda

    int getR() const;//funcion que devuelve el radio
    void setR(int radio);//funcion que le da valor al radio
    int getPosx() const;//funcion que devuelve la posicion x
    void setPosx(int px);//funcion que le da valor a la posicion x
    int getPosy() const;//funcion que devuelve la posicion y
    void setPosy(int py);//funcion que le da valor a la posicion y
    QRectF boundingRect() const;//funcion que dibuja
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);//funcion que pinta

};

#endif // MONEDA_H
