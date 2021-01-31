//#include "balafuego.h"

//balafuego::balafuego(float PX_,float PY_)
//{
//    PX=PX_;
//    PY=PY_;
//    r=10;
//    Dt=0;
//    timer =new QTimer;

//    connect(timer,SIGNAL(timeout()),this,SLOT(Actualizar()));
//    timer->start(3);
//    setPos(PX,PY);

//}

//balafuego::~balafuego()
//{

//}

//void balafuego::Actualizar()
//{
//    PX=5*cos(Dt);
//    PY=5*sin(Dt);
//    Dt+=1;
//    setPos(PX+5,PY);

//}

//QRectF balafuego::boundingRect() const
//{
//    return QRectF(-r,-r,2*r,2*r);
//}

//void balafuego::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
//{
//    painter->setBrush(Qt::yellow);
//    painter->drawEllipse(boundingRect());
//}
