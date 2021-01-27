#ifndef MONEDA_H
#define MONEDA_H
#include <QGraphicsItem>
#include <QPainter>

class moneda: public QGraphicsItem
{

    int r=10;
    int posx, posy;
    int velocidad = 5;

public:
    moneda( int x, int y);

    int getR() const;
    void setR(int radio);
    int getPosx() const;
    void setPosx(int px);
    int getPosy() const;
    void setPosy(int py);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

};

#endif // MONEDA_H
