#include "mainwindow.h"
#include "ui_mainwindow.h"
int choques=-1;
int movi=-5,movi2=5;
int saltos=0;
int l,L;
int nivel=0;
int num_jugadores;
QString user,contra,posiciones;
int puntaje=0;
int pn=0;
int vidas=5;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    srand(time(NULL));
    ui->setupUi(this);

    ui->cargarpartida->show();
    ui->nuevapartida->show();
    ui->un_jugador->hide();
    ui->buton->hide();
    ui->dos_jugadores->hide();
    ui->registrar->hide();
    ui->iniciar->hide();
    ui->volver->hide();
    ui->buton->setChecked(true);
    ui->label->hide();
    ui->label_2->hide();
    ui->label_5->hide();
    ui->label_6->hide();
    ui->Puntaje->hide();
    ui->Vida->hide();
    ui->usuario->hide();
    ui->contrasena->hide();
    ui->Guardar->hide();
    ui->Pausa->hide();
    ui->Play->hide();
    ui->eliminar->hide();
    ui->reiniciar->hide();
    view->hide();
    ui->Puntaje->setText(QString::number(pn));
    ui->Vida->setText(QString::number(vidas));

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
        borderCollisionE(enemigo->getEsf());
        enemigo2->actualizar(v_limit);
        borderCollisionE(enemigo2->getEsf());
        personaje->actualizar(v_limit);
        borderCollision(personaje->getEsf());
        if(num_jugadores==2){
            personaje2->actualizar(v_limit);
            borderCollision2(personaje->getEsf(),personaje2->getEsf());
}


}

void MainWindow::borderCollision2(cuerpo *b,cuerpo *d)
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
    if(num_jugadores==2){
        if(d->getPX()<d->getR()){
            d->set_vel(-1*d->getE()*d->getVX(),d->getVY(),d->getR(),d->getPY());

        }
        if(d->getPX()>h_limit-d->getR()){
            d->set_vel(-1*d->getE()*d->getVX(),d->getVY(),h_limit-d->getR(),d->getPY());
        }
        if(d->getPY()<d->getR()){
            d->set_vel(d->getVX(),-1*d->getE()*d->getVY(),d->getPX(),d->getR());
        }
        if(d->getPY()>v_limit-d->getR()){
            d->set_vel(d->getVX(),-1*d->getE()*d->getVY(),d->getPX(),v_limit-d->getR());
        }
        for(int i=0;i<paredes.size();i++){
            if(personaje2->collidesWithItem(paredes.at(i))){
              d->set_vel(d->getVX(),0,d->getPX(),L+d->getPY());
            }}
    }
//    if(personaje->collidesWithItem(muro1)){
//        b->set_vel(-1*b->getE()*b->getVX(),b->getVY(),b->getR(),b->getPY());
//    }
//    if(personaje->collidesWithItem(muro2)){

    //    }
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
                pn+=1;
                ui->Puntaje->setText(QString::number(pn));

            }
        }
        if(monedas.size()==NULL && nivel==1){
            destructorlevel1();
            nivel+=1;

            level2();
        }
        if(monedas.size()==NULL && nivel==2){
            destructorlevel1();
            nivel+=1;

            level3();
        }
        if(monedas.size()==NULL && nivel==3){
            timere->stop();
             timer->stop();
            QString txt;
            txt="Felicidades has recuperado el tesoro";
            QMessageBox::about(this,"¡FELICIDADES!",txt);

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
                pn+=1;
                ui->Puntaje->setText(QString::number(pn));
            }
        }
        if(monedas.size()==NULL && nivel==1){
            destructorlevel1();
            nivel+=1;
            level2();
        }
        if(monedas.size()==NULL && nivel==2){
            destructorlevel1();
            nivel+=1;
            level3();
        }
        if(monedas.size()==NULL && nivel==3){
            timere->stop();
            timer->stop();
            QString txt;
            txt="Felicidades has recuperado el tesoro";
            QMessageBox::about(this,"¡FELICIDADES!",txt);

        }
        if(personaje->collidesWithItem(muro1)){
            b->set_vel(10,b->getVY(),b->getPX(),b->getPY());
        }
        if(personaje->collidesWithItem(muro2)){
            b->set_vel(10,b->getVY(),b->getPX(),b->getPY());
        }
    }
    if(event->key() == Qt::Key_W){
        saltos+=1;

        for(int i=0;i<monedas.size();i++){
            if(personaje->collidesWithItem(monedas.at(i))){
                scene->removeItem(monedas.at(i));
                monedas= eliminarMoneda(monedas,i);                
                pn+=1;
                ui->Puntaje->setText(QString::number(pn));
            }
        }
        if(monedas.size()==NULL && nivel==1){
            destructorlevel1();
            nivel+=1;
            level2();
        }
        if(monedas.size()==NULL && nivel==2){
            destructorlevel1();
            nivel+=1;
            level3();
        }
        if(monedas.size()==NULL && nivel==3){
            timere->stop();
            timer->stop();
            QString txt;
            txt="Felicidades has recuperado el tesoro";
            QMessageBox::about(this,"¡FELICIDADES!",txt);

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
    if (num_jugadores==2){
        cuerpo * d = personaje2->getEsf();
        if(event->key() == Qt::Key_K){
            d->set_vel(10,d->getVY(),d->getPX(),d->getPY());
            for(int i=0;i<monedas.size();i++){
                if(personaje2->collidesWithItem(monedas.at(i))){
                    scene->removeItem(monedas.at(i));
                    monedas= eliminarMoneda(monedas,i);
                    pn+=1;
                    ui->Puntaje->setText(QString::number(pn));

                }
            }
            if(monedas.size()==NULL && nivel==1){
                destructorlevel1();
                nivel+=1;

                level2();
            }
            if(monedas.size()==NULL && nivel==2){
                destructorlevel1();
                nivel+=1;

                level3();
            }
            if(monedas.size()==NULL && nivel==3){
                timere->stop();
                 timer->stop();
                QString txt;
                txt="Felicidades has recuperado el tesoro";
                QMessageBox::about(this,"¡FELICIDADES!",txt);

            }
            if(personaje2->collidesWithItem(muro1)){
                d->set_vel(-10,d->getVY(),d->getPX(),d->getPY());
            }
            if(personaje2->collidesWithItem(muro2)){
                d->set_vel(-10,d->getVY(),d->getPX(),d->getPY());
            }
        }
        if(event->key() == Qt::Key_H){
            d->set_vel(-10,d->getVY(),d->getPX(),d->getPY());
            for(int i=0;i<monedas.size();i++){
                if(personaje2->collidesWithItem(monedas.at(i))){
                    scene->removeItem(monedas.at(i));
                    monedas= eliminarMoneda(monedas,i);
                    pn+=1;
                    ui->Puntaje->setText(QString::number(pn));
                }
            }
            if(monedas.size()==NULL && nivel==1){
                destructorlevel1();
                nivel+=1;
                level2();
            }
            if(monedas.size()==NULL && nivel==2){
                destructorlevel1();
                nivel+=1;
                level3();
            }
            if(monedas.size()==NULL && nivel==3){
                timere->stop();
                timer->stop();
                QString txt;
                txt="Felicidades has recuperado el tesoro";
                QMessageBox::about(this,"¡FELICIDADES!",txt);

            }
            if(personaje2->collidesWithItem(muro1)){
                d->set_vel(10,d->getVY(),d->getPX(),d->getPY());
            }
            if(personaje2->collidesWithItem(muro2)){
                d->set_vel(10,d->getVY(),d->getPX(),d->getPY());
            }
        }
        if(event->key() == Qt::Key_U){
            saltos+=1;

            for(int i=0;i<monedas.size();i++){
                if(personaje2->collidesWithItem(monedas.at(i))){
                    scene->removeItem(monedas.at(i));
                    monedas= eliminarMoneda(monedas,i);
                    pn+=1;
                    ui->Puntaje->setText(QString::number(pn));
                }
            }
            if(monedas.size()==NULL && nivel==1){
                destructorlevel1();
                nivel+=1;
                level2();
            }
            if(monedas.size()==NULL && nivel==2){
                destructorlevel1();
                nivel+=1;
                level3();
            }
            if(monedas.size()==NULL && nivel==3){
                timere->stop();
                timer->stop();
                QString txt;
                txt="Felicidades has recuperado el tesoro";
                QMessageBox::about(this,"¡FELICIDADES!",txt);

            }
            if(saltos%4==0){
                saltos-=4;
            }
            else{
                L=-1;
                d->set_vel(d->getVX(),40,d->getPX(),d->getPY());
                if(personaje2->collidesWithItem(muro1)){
                    d->set_vel(d->getVX(),-10,d->getPX(),d->getPY());
                }
                if(personaje2->collidesWithItem(muro2)){
                    d->set_vel(d->getVX(),-10,d->getPX(),d->getPY());
                }
            }

        }
        if(event->key() != Qt::Key_W && event->key() != Qt::Key_U){
            L=1;
        }
    }
if(event->key() != Qt::Key_W && event->key() != Qt::Key_U){
    l=1;
}
}

void MainWindow::level1()
{
    ui->setupUi(this);
    nivel=1;

    ui->cargarpartida->hide();
    ui->nuevapartida->hide();
    ui->un_jugador->hide();
    ui->dos_jugadores->hide();
    ui->registrar->hide();
    ui->iniciar->hide();
    ui->volver->hide();
    ui->label->hide();
    ui->label_2->hide();
    ui->usuario->hide();
    ui->label_4->hide();
    ui->buton->hide();
    ui->contrasena->hide();
    ui->label_3->hide();
    ui->pushButton->hide();
    ui->label_5->show();
    ui->label_6->show();
    ui->Puntaje->show();
    ui->Vida->show();
    ui->Guardar->show();
    ui->Pausa->show();
    ui->Play->show();
    ui->eliminar->show();
    ui->reiniciar->show();
    ui->Puntaje->setText(QString::number(pn));
    ui->Vida->setText(QString::number(vidas));
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

    view->show();
    view->setScene(scene);
    ui->centralwidget->adjustSize();
    scene->addRect(scene->sceneRect());
    view->resize(scene->width(),150+scene->height());
    this->resize(view->width(),view->height());
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    crear_jugador();
    enemigo =new grafenemigo;
    enemigo->actualizar(v_limit);
    enemigo2 =new grafenemigo;
    enemigo2->actualizar(v_limit);
    enemigo2->setPos(70,460);

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
    scene->addItem(enemigo);
    scene->addItem(enemigo2);

    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));
    timer->start(3);
    timere = new QTimer();
    connect(timere,SIGNAL(timeout()),this,SLOT(moveenemy()));
    timere->start(3);
}

void MainWindow::level2()
{
    ui->setupUi(this);

    ui->cargarpartida->hide();
    ui->nuevapartida->hide();
    ui->un_jugador->hide();
    ui->dos_jugadores->hide();
    ui->registrar->hide();
    ui->iniciar->hide();
    ui->volver->hide();
    ui->label->hide();
    ui->label_2->hide();
    ui->usuario->hide();
    ui->label_4->hide();
    ui->contrasena->hide();
    ui->label_3->hide();
    ui->pushButton->hide();
    ui->Puntaje->setText(QString::number(pn));
    ui->Vida->setText(QString::number(vidas));
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

    view->show();
    view->setScene(scene);
    ui->centralwidget->adjustSize();
    scene->addRect(scene->sceneRect());
    view->resize(scene->width(),150+scene->height());
    this->resize(view->width(),view->height());
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    crear_jugador();
    enemigo =new grafenemigo;
    enemigo->actualizar(v_limit);
    for(int i=0;i<paredes.size();i++){
        paredes.removeAt(i);}
    for(int i=0;i<paredes.size();i++){
            paredes.removeAt(i);}

    Leer.open("/Users/Gabriel Restrepo/Documents/juego_solitario/coords2.txt");
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

    Leer.open("/Users/Gabriel Restrepo/Documents/juego_solitario/money2.txt");
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
    scene->addItem(enemigo);

    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));

    connect(timere,SIGNAL(timeout()),this,SLOT(moveenemy()));

}

void MainWindow::level3()
{
    ui->setupUi(this);

    ui->cargarpartida->hide();
    ui->nuevapartida->hide();
    ui->un_jugador->hide();
    ui->dos_jugadores->hide();
    ui->registrar->hide();
    ui->iniciar->hide();
    ui->volver->hide();
    ui->label->hide();
    ui->label_2->hide();
    ui->usuario->hide();
    ui->label_4->hide();
    ui->contrasena->hide();
    ui->label_3->hide();
    ui->pushButton->hide();
    ui->Puntaje->setText(QString::number(pn));
    ui->Vida->setText(QString::number(vidas));
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

    view->show();
    view->setScene(scene);
    ui->centralwidget->adjustSize();
    scene->addRect(scene->sceneRect());
    view->resize(scene->width(),150+scene->height());
    this->resize(view->width(),view->height());
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    crear_jugador();
    enemigo =new grafenemigo;
    enemigo->actualizar(v_limit);
    for(int i=0;i<paredes.size();i++){
        paredes.removeAt(i);}
    for(int i=0;i<paredes.size();i++){
        paredes.removeAt(i);}

    Leer.open("/Users/Gabriel Restrepo/Documents/juego_solitario/coords3.txt");
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

    Leer.open("/Users/Gabriel Restrepo/Documents/juego_solitario/money3.txt");
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
    scene->addItem(enemigo);

    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));
    connect(timere,SIGNAL(timeout()),this,SLOT(moveenemy()));

}

void MainWindow::destructorlevel1()
{
    for(int i=0;i<paredes.size();i++){
        paredes.removeAt(i);}
    for(int i=0;i<monedas.size();i++){
        monedas.removeAt(i);}
}

void MainWindow::crear_jugador()
{
    personaje = new cuerpograf;
    personaje->actualizar(v_limit);
    scene->addItem(personaje);
    if(num_jugadores==2){
        personaje2 = new cuerpograf;
        personaje2->actualizar(v_limit);
        scene->addItem(personaje2);
    }
}


void MainWindow::moveenemy()
{
    enemy * c = enemigo->getEsf();
    enemy* k=enemigo2->getEsf();

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
    k->set_vel(movi2,k->getVY(),k->getPX(),k->getPY());
    if(enemigo2->collidesWithItem(muro4)){
      k->set_vel(movi2,k->getVY(),25,k->getPY());
    }
    if(enemigo2->collidesWithItem(muro3)){
      k->set_vel(movi2,k->getVY(),975,k->getPY());
    }
    if(enemigo2->collidesWithItem(muro2)){
        choques+=1;
        if(choques%2==0 && choques!=0){
            choques-=2;
            k->set_vel(k->getVX(),k->getVY(),k->getPX(),459);
            movi2=5;
        }else{
            k->set_vel(k->getVX(),k->getVY(),932,459);
            movi2=-5;
        }
    }
    if(enemigo2->collidesWithItem(muro1)){
        choques+=1;
        if(choques%2==0 && choques!=0){
            choques-=2;
            movi2=-5;
            k->set_vel(k->getVX(),k->getVY(),k->getPX(),459);

        }else{
            movi2=5;
            k->set_vel(k->getVX(),k->getVY(),70,459);
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
    user=ui->usuario->text();
    contra=ui->contrasena->text();
    if(user==NULL || contra==NULL){
        //En el caso de que el usuario no haya ingresado nada simplemente se le indicara que es un ingreso invalido
        QMessageBox msgBox;
        msgBox.setText("Usuario o Contraseña Invalida.");
        msgBox.setWindowTitle("Calabozo Medieval");
        msgBox.setWindowIcon(QIcon(":/recursos/imagenes/imagen.png"));
        msgBox.setStyleSheet("background-color:#211b18;"
                             "color:white;");
        msgBox.exec();
        ui->usuario->clear();
        ui->contrasena->clear();
        ui->buton->setChecked(true);


    }else{

        ui->cargarpartida->hide();
        ui->nuevapartida->hide();
        ui->un_jugador->hide();
        ui->dos_jugadores->hide();
        ui->registrar->hide();
        ui->iniciar->hide();
        ui->volver->hide();
        ui->label->hide();
        ui->label_2->hide();
        ui->usuario->hide();
        ui->label_4->hide();
        ui->contrasena->hide();
        ui->label_3->hide();
        ui->pushButton->hide();
        ui->buton->hide();
        level1();}


}

void MainWindow::on_registrar_clicked()
{
string ruta ="hola";
user=ui->usuario->text();
contra=ui->contrasena->text();

    if(user==NULL || contra==NULL || ui->buton->isChecked() ){
        //En el caso de que el usuario no haya ingresado nada simplemente se le indicara que es un ingreso invalido
        QMessageBox msgBox;
        msgBox.setText("Registro Invalida.");
        msgBox.setWindowTitle("Calabozo Medieval");
        msgBox.setWindowIcon(QIcon(":/recursos/imagenes/imagen.png"));
        msgBox.setStyleSheet("background-color:#211b18;"
                             "color:white;");
        msgBox.exec();
        ui->usuario->clear();
        ui->contrasena->clear();
        ui->buton->setChecked(true);


    }else{
        ui->cargarpartida->hide();
        ui->nuevapartida->hide();
        ui->un_jugador->hide();
        ui->dos_jugadores->hide();
        ui->registrar->hide();
        ui->iniciar->hide();
        ui->volver->hide();
        ui->label->hide();
        ui->label_2->hide();
        ui->usuario->hide();
        ui->label_4->hide();
        ui->contrasena->hide();
        ui->label_3->hide();
        ui->pushButton->hide();

        if(ui->un_jugador->isChecked())
            num_jugadores = 1;
        else if(ui->dos_jugadores->isChecked())
            num_jugadores = 2;

        puntaje+=pn;
        pn=0;
        ui->Puntaje->setText(QString::number(pn));
        ifstream pp;
        pp.open("../juego_solitario/partidas/Guardar.txt",ios::app);
        pp.close();
       ofstream guardar_;
       guardar_.open("../juego_solitario/partidas/Guardar.txt",ios::app);
       guardar_<<user.toStdString()<<"-"<<contra.toStdString()<<","<<nivel<<","<<puntaje<<","<<num_jugadores<<"."<<endl;
       guardar_.close();
       level1();
    }

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

void MainWindow::on_eliminar_clicked()
{

}

void MainWindow::on_reiniciar_clicked()
{
    switch (nivel) {
    case 1:
        destructorlevel1();
        level1();
        break;
    case 2:
        destructorlevel1();
        level2();
        break;
    case 3:
        destructorlevel1();
        level3();
        break;

    }
}

void MainWindow::on_Play_clicked()
{
    timer->start(3);
    timere->start(3);
}

void MainWindow::on_Pausa_clicked()
{
    timer->stop();
    timere->stop();
}

void MainWindow::on_Guardar_clicked()
{
    this->close();
    cuerpo *b =personaje->getEsf();
    cuerpo *d =personaje2->getEsf();

    puntaje+=pn;
    pn=0;
    for(int i=0;i<monedas.size();i++){
        posiciones+=monedas.at(i)->getPosx();
        posiciones+=",";
        posiciones+=monedas.at(i)->getPosy();
        posiciones+="\n";

    }
    ui->Puntaje->setText(QString::number(pn));
    ifstream pp;
    pp.open("../juego_solitario/partida.txt",ios::app);
    pp.close();
    ofstream guardar_;
    guardar_.open("../juego_solitario/Guardar.txt",ios::app);
    if(num_jugadores==2){
        guardar_<<user.toStdString()<<"-"<<contra.toStdString()<<","<<nivel<<","<<puntaje<<","<<num_jugadores<<","<<b->getPX()<<","<<b->getPY()<<","<<d->getPX()<<","<<d->getPY()<<endl;
    }else{
        guardar_<<user.toStdString()<<"-"<<contra.toStdString()<<","<<nivel<<","<<puntaje<<","<<num_jugadores<<b->getPX()<<","<<b->getPY()<<endl;
    }
    guardar_.close();
    ofstream partida;
    partida.open("../juego_solitario/partida.txt",ios::app);
    partida<<posiciones.toStdString();
    partida.close();

}
