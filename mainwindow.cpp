#include "mainwindow.h"
#include "ui_mainwindow.h"

int saltos=0;
int choques=-1;
int movi=-5;
int l;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    srand(time(NULL));
    ui->setupUi(this);
    ifstream Leer;
    int ancho1,alto1,posix,posiy,posjx,posjy;

    h_limit = 1000;
    v_limit = 500;

    timer = new QTimer(this);
    scene = new QGraphicsScene(this);
    muro1 = new pared(3,100,-997,-400);
    muro2 = new pared(3,100,0,-400);
    muro4 = new pared(3,100,-997,-200);
    muro3 = new pared(3,100,0,-200);
    scene->setSceneRect(0,0,h_limit,v_limit);

    view->setScene(scene);
    ui->centralwidget->adjustSize();
    scene->addRect(scene->sceneRect());
    view->resize(scene->width(),scene->height());
    this->resize(view->width(),view->height());
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    personaje = new cuerpograf;
    enemigo =new grafenemigo;
    personaje->actualizar(v_limit);
    enemigo->actualizar(v_limit);

    ui->cargarpartida->show();
    ui->nuevapartida->show();
    ui->un_jugador->hide();
    ui->dos_jugadores->hide();
    ui->registrar->hide();
    ui->iniciar->hide();
    ui->volver->hide();
    ui->label->hide();
    ui->label_2->hide();
    ui->usuario->hide();
    ui->contrasena->hide();

    Leer.open("/Users/Gabriel Restrepo/Documents/juego_solitario/coords.txt");
    char linea[20];
    Leer.getline(linea, sizeof(linea));
    while (!Leer.eof()) {
        for(int i=0; i<4;i++){
            char *puntero;
            if(i==0){
                puntero = strtok(linea, ",");
                ancho1 = atoi(puntero);
            }
            if(i==1){
                puntero = strtok(NULL, ",");
                alto1 = atoi(puntero);
            }
            if(i==2){
                puntero = strtok(NULL, ",");
                posix = atoi(puntero);
            }
            if(i==3){
                puntero = strtok(NULL, ",");
                posiy = atoi(puntero);
            }
        }
        paredes.push_back(new pared (ancho1,alto1,posix,posiy));
        scene->addItem(paredes.back());
        Leer.getline(linea, sizeof(linea));
    }
    Leer.close();

    Leer.open("/Users/Gabriel Restrepo/Documents/juego_solitario/money.txt");
    char line[20];
    Leer.getline(line, sizeof(line));
    while (!Leer.eof()) {
        for(int i=0; i<2;i++){
            char *puntero;
            if(i==0){
                puntero = strtok(line, ",");
                posjx = atoi(puntero);
            }
            if(i==1){
                puntero = strtok(NULL, ",");
                posjy = atoi(puntero);
            }
        }
        monedas.push_back(new moneda (posjx,posjy));

        scene->addItem(monedas.back());
        Leer.getline(line, sizeof(line));
    }
    Leer.close();
    scene->addItem(muro1);
    scene->addItem(muro2);
    scene->addItem(muro3);
    scene->addItem(muro4);
    scene->addItem(personaje);
    scene->addItem(enemigo);

    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));
    timer->start(3);
    timere = new QTimer();
    connect(timere,SIGNAL(timeout()),this,SLOT(moveenemy()));
    timere->start(3);
}

MainWindow::~MainWindow()
{
    delete timer;
    delete scene;
    delete ui;
}

void MainWindow::actualizar()
{
        enemigo->actualizar(v_limit);
        personaje->actualizar(v_limit);
        borderCollision(personaje->getEsf());
        borderCollisionE(enemigo->getEsf());

}

void MainWindow::borderCollision(cuerpo *b)
{
    if(b->getPX()<b->getR()){
        b->set_vel(-1*b->getE()*b->getVX(),b->getVY(),b->getR(),b->getPY());

    }
    if(b->getPX()>h_limit-b->getR()){
        b->set_vel(-1*b->getE()*b->getVX(),b->getVY(),h_limit-b->getR(),b->getPY());
    }
    if(b->getPY()<b->getR()){
        b->set_vel(b->getVX(),-1*b->getE()*b->getVY(),b->getPX(),b->getR());
    }
    if(b->getPY()>v_limit-b->getR()){
        b->set_vel(b->getVX(),-1*b->getE()*b->getVY(),b->getPX(),v_limit-b->getR());
    }
    for(int i=0;i<paredes.size();i++){
        if(personaje->collidesWithItem(paredes.at(i))){
          b->set_vel(b->getVX(),0,b->getPX(),l+b->getPY());
        }}
//    if(personaje->collidesWithItem(muro1)){
//        b->set_vel(-1*b->getE()*b->getVX(),b->getVY(),b->getR(),b->getPY());
//    }
//    if(personaje->collidesWithItem(muro2)){

//    }
}
void MainWindow::borderCollisionE(enemy *c)
{
    if(c->getPX()<c->getR()){
        c->set_vel(-1*c->getE()*c->getVX(),c->getVY(),c->getR(),c->getPY());

    }
    if(c->getPX()>h_limit-c->getR()){
        c->set_vel(-1*c->getE()*c->getVX(),c->getVY(),h_limit-c->getR(),c->getPY());
    }
    if(c->getPY()<c->getR()){
        c->set_vel(c->getVX(),-1*c->getE()*c->getVY(),c->getPX(),c->getR());
    }
    if(c->getPY()>v_limit-c->getR()){
        c->set_vel(c->getVX(),-1*c->getE()*c->getVY(),c->getPX(),v_limit-c->getR());
    }
    for(int i=0;i<paredes.size();i++){
        if(enemigo->collidesWithItem(paredes.at(i))){
          c->set_vel(movi,0,c->getPX(),1+c->getPY());
        }}
//    if(personaje->collidesWithItem(muro1)){
//        c->set_vel(-1*c->getE()*c->getVX(),c->getVY(),c->getR(),c->getPY());
//    }
//    if(personaje->collidesWithItem(muro2)){

//    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    cuerpo * b = personaje->getEsf();
    if(event->key() == Qt::Key_D){
        b->set_vel(10,b->getVY(),b->getPX(),b->getPY());
        for(int i=0;i<monedas.size();i++){
            if(personaje->collidesWithItem(monedas.at(i))){
                scene->removeItem(monedas.at(i));
                monedas= eliminarMoneda(monedas,i);
            }
        }
        if(personaje->collidesWithItem(muro1)){
            b->set_vel(-10,b->getVY(),b->getPX(),b->getPY());
        }
        if(personaje->collidesWithItem(muro2)){
            b->set_vel(-10,b->getVY(),b->getPX(),b->getPY());
        }
    }
    if(event->key() == Qt::Key_A){
        b->set_vel(-10,b->getVY(),b->getPX(),b->getPY());
        for(int i=0;i<monedas.size();i++){
            if(personaje->collidesWithItem(monedas.at(i))){
                scene->removeItem(monedas.at(i));
                monedas= eliminarMoneda(monedas,i);
            }
        }
        if(personaje->collidesWithItem(muro1)){
            b->set_vel(10,b->getVY(),b->getPX(),b->getPY());
        }
        if(personaje->collidesWithItem(muro2)){
            b->set_vel(10,b->getVY(),b->getPX(),b->getPY());
        }
    }
    if(event->key() == Qt::Key_Space){
        saltos+=1;

        for(int i=0;i<monedas.size();i++){
            if(personaje->collidesWithItem(monedas.at(i))){
                scene->removeItem(monedas.at(i));
                monedas= eliminarMoneda(monedas,i);
            }
        }
        if(saltos%4==0){
            saltos-=4;
        }
        else{
            l=-1;
            b->set_vel(b->getVX(),40,b->getPX(),b->getPY());
            if(personaje->collidesWithItem(muro1)){
                b->set_vel(b->getVX(),-10,b->getPX(),b->getPY());
            }
            if(personaje->collidesWithItem(muro2)){
                b->set_vel(b->getVX(),-10,b->getPX(),b->getPY());
            }
        }

    }
    else{l=1;}

}
void MainWindow::moveenemy()
{
    enemy * c = enemigo->getEsf();
    //    if(enemigo->x() < personaje->x()){
    //        c->set_vel(5,c->getVY(),c->getPX(),c->getPY());
    //        if(enemigo->collidesWithItem(muro1)){
    //            c->set_vel(-5,c->getVY(),c->getPX(),c->getPY());
    //        }
    //        if(enemigo->collidesWithItem(muro2)){
    //            c->set_vel(-5,c->getVY(),c->getPX(),c->getPY());
    //        }
    //    }
    //    else if(enemigo->x() > personaje->x()){
    //        c->set_vel(-5,c->getVY(),c->getPX(),c->getPY());
    //        if(enemigo->collidesWithItem(muro1)){
    //            c->set_vel(5,c->getVY(),c->getPX(),c->getPY());
    //        }
    //        if(enemigo->collidesWithItem(muro2)){
    //            c->set_vel(5,c->getVY(),c->getPX(),c->getPY());
    //        }
    //    }
    c->set_vel(movi,c->getVY(),c->getPX(),c->getPY());
    if(enemigo->collidesWithItem(muro4)){
      c->set_vel(movi,c->getVY(),25,c->getPY());
    }
    if(enemigo->collidesWithItem(muro3)){
      c->set_vel(movi,c->getVY(),975,c->getPY());
    }
    if(enemigo->collidesWithItem(muro2)){
        choques+=1;
        if(choques%2==0 && choques!=0){
            choques-=2;
            c->set_vel(c->getVX(),c->getVY(),c->getPX(),459);
            movi=5;
        }else{
            c->set_vel(c->getVX(),c->getVY(),932,459);
            movi=-5;
        }
    }
    if(enemigo->collidesWithItem(muro1)){
        choques+=1;
        if(choques%2==0 && choques!=0){
            choques-=2;
            movi=-5;
            c->set_vel(c->getVX(),c->getVY(),c->getPX(),459);

        }else{
            movi=5;
            c->set_vel(c->getVX(),c->getVY(),70,459);
        }
    }






//    if(enemigo->y() < personaje->y()){
//        enemigo->down();
//        if(enemigo->collidesWithItem(muro1)){
//            enemigo->up();
//        }
//        if(enemigo->collidesWithItem(muro2)){
//            enemigo->up();
//        }
//    }
//    else if(enemigo->y() > personaje->y()){
//        enemigo->up();
//        if(enemigo->collidesWithItem(muro1)){
//            enemigo->down();
//        }
//        if(enemigo->collidesWithItem(muro2)){
//            enemigo->down();
//        }
//    }
    //enemigo->setPos(enemigo->posx,enemigo->posy);

}
QList<moneda *> MainWindow::eliminarMoneda(QList<moneda *> monedas, int pos)
{
    QList<moneda *> aux;
    for (int i; i<monedas.size() ;i++ ) {
        if(i!=pos){
            aux.push_back(monedas.at(i));
        }
    }
    return aux;
}

void MainWindow::on_cargarpartida_clicked()
{
    ui->cargarpartida->hide();
    ui->nuevapartida->hide();
    ui->un_jugador->hide();
    ui->dos_jugadores->hide();
    ui->registrar->hide();
    ui->iniciar->show();
    ui->volver->show();
    ui->label->show();
    ui->label_2->show();
    ui->usuario->show();
    ui->contrasena->show();
}

void MainWindow::on_nuevapartida_clicked()
{
    ui->cargarpartida->hide();
    ui->nuevapartida->hide();
    ui->un_jugador->show();
    ui->dos_jugadores->show();
    ui->registrar->show();
    ui->iniciar->hide();
    ui->volver->show();
    ui->label->show();
    ui->label_2->show();
    ui->usuario->show();
    ui->contrasena->show();
}

void MainWindow::on_iniciar_clicked()
{
    ui->cargarpartida->show();
    ui->nuevapartida->show();
    ui->un_jugador->hide();
    ui->dos_jugadores->hide();
    ui->registrar->hide();
    ui->iniciar->hide();
    ui->volver->hide();
    ui->label->hide();
    ui->label_2->hide();
    ui->usuario->hide();
    ui->contrasena->hide();
}

void MainWindow::on_registrar_clicked()
{
    ui->cargarpartida->show();
    ui->nuevapartida->show();
    ui->un_jugador->hide();
    ui->dos_jugadores->hide();
    ui->registrar->hide();
    ui->iniciar->hide();
    ui->volver->hide();
    ui->label->hide();
    ui->label_2->hide();
    ui->usuario->hide();
    ui->contrasena->hide();
}

void MainWindow::on_volver_clicked()
{
    ui->cargarpartida->show();
    ui->nuevapartida->show();
    ui->un_jugador->hide();
    ui->dos_jugadores->hide();
    ui->registrar->hide();
    ui->iniciar->hide();
    ui->volver->hide();
    ui->label->hide();
    ui->label_2->hide();
    ui->usuario->hide();
    ui->contrasena->hide();
}

void MainWindow::on_pushButton_clicked()
{
    this->close();
}
