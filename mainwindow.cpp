#include "mainwindow.h"
#include "ui_mainwindow.h"
int choques=-1;
int movi=-5,movi2=5;
int saltos=0;
int l,L;
int nivel=1;
int dificultad=1;
bool cargado=false;
int num_jugadores;
QString user,contra,posiciones;
int puntaje=0;
int pn=0;
int vida1=5,vida2=5;
int px1=32,py1=150,px2=32,py2=150;
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
        ui->Vida2->hide();
    ui->usuario->hide();
    ui->contrasena->hide();
    ui->Pausa->hide();
    ui->Play->hide();
    view->hide();

    ui->Puntaje->setText(QString::number(pn));
    ui->Vida->setText(QString::number(vida1));
    ui->Vida2->setText(QString::number(vida1));


}

MainWindow::~MainWindow()
{
    delete timer;
    delete scene;
    delete ui;
}

void MainWindow::actualizar()
{

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
    for(int i=0;i<enemigos.size();i++){
        if(personaje->collidesWithItem(enemigos.at(i))){
          b->set_vel(b->getVX(),b->getVY(),23,105);
          vida1-=1;
          ui->Vida->setText(QString::number(vida1));
        }}
    if(vida1<0){

         timer->stop();
        QString txt;
        txt="Te han matado, suerte para la proxima";
        QMessageBox::about(this,"¡Lo Siento!",txt);
        this->close();
    }
    px1=b->getPX();
    py1=b->getPY();

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
        for(int i=0;i<enemigos.size();i++){
            if(personaje2->collidesWithItem(enemigos.at(i))){
              d->set_vel(d->getVX(),d->getVY(),23,105);
              vida2-=1;
              ui->Vida2->setText(QString::number(vida2));
            }}
        if(vida2<0){

             timer->stop();
            QString txt;
            txt="Te han matado, suerte para la proxima";
            QMessageBox::about(this,"¡Lo Siento!",txt);
            this->close();
        }
        for(int i=0;i<paredes.size();i++){
            if(personaje2->collidesWithItem(paredes.at(i))){
              d->set_vel(d->getVX(),0,d->getPX(),L+d->getPY());
            }}
        px2=d->getPX();
        py2=d->getPY();
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
    if(num_jugadores==2){}else{
        for(int i=0;i<enemigos.size();i++){
            if(personaje->collidesWithItem(enemigos.at(i))){
              b->set_vel(b->getVX(),b->getVY(),23,105);
              vida1-=1;
              ui->Vida->setText(QString::number(vida1));
            }}
    }

    if(vida1<0){

         timer->stop();
        QString txt;
        txt="Te han matado, suerte para la proxima";
        QMessageBox::about(this,"¡Lo Siento!",txt);
        this->close();
    }
    px1=b->getPX();
    py1=b->getPY();
}

void MainWindow::mover_enemigo()
{
    for(int i=0; i<enemigos.size();i++) //ciclo que lee toda la lista de enemigos
    {
        /* enemmigo 1 y 2 son las bolas que rebotan
         * enemigo 3 y 4 las bolas con movimiento MCU
         * enemigo 5 con el movimiento MAS*/

        //qDebug() <<"velocidad: "<<enemigos.at(i)->getVel();
        //qDebug() <<"velocidadx: "<<enemigos.at(i)->getVelx();
        if(enemigos.at(i)->getVel()>70){enemigos.at(i)->setVel(70);} //condicion para que no supere cierta velocidad
        if(enemigos.at(i)->getVelx()<20){enemigos.at(i)->setVelx(20);} //condicion para que no rebote con una velocidad menor

        if(i==0) //condicion que pregunta si es el tercer enemigo
        {
            enemigos.at(i)->MAS(500,250,-120,1,2); //darle movimiento circular uniforme
            enemigos.at(i)->rotar(2); //rotar imagen
        }
        if(i==1) //condicion que pregunta si es el tercer enemigo
        {
            enemigos.at(i)->MAS(800,90,-120,1,1); //darle movimiento circular uniforme
            enemigos.at(i)->rotar(2); //rotar imagen
        }

        if(i==2) //condicion que pregunta si es el tercer enemigo
        {
            enemigos.at(i)->MAS(200,90,120,1,1); //darle movimiento circular uniforme
            enemigos.at(i)->rotar(2); //rotar imagen
        }

        if(i==3) //condicion que pregunta si es el cuarto enemigo
        {
            enemigos.at(i)->MAS(800,310,-120,1,1); //darle el movimiento armonico simple
            enemigos.at(i)->rotar(2); //rotar imagen
        }

        if(i==4) //condicion que pregunta si es el quinto enemigo
        {
            enemigos.at(i)->MAS(200,310,120,1,1); //darle movmiento armonico simple
            enemigos.at(i)->rotar(2); //rotar imagen
        }



}
}

void MainWindow::mover_enemigo2()
{
    for(int i=0; i<enemigos.size();i++) //ciclo que lee toda la lista de enemigos
    {
        /* enemmigo 1 y 2 son las bolas que rebotan
         * enemigo 3 y 4 las bolas con movimiento MCU
         * enemigo 5 con el movimiento MAS*/

        //qDebug() <<"velocidad: "<<enemigos.at(i)->getVel();
        //qDebug() <<"velocidadx: "<<enemigos.at(i)->getVelx();
        if(enemigos.at(i)->getVel()>60){enemigos.at(i)->setVel(60);} //condicion para que no supere cierta velocidad
        if(enemigos.at(i)->getVelx()<30){enemigos.at(i)->setVelx(30);} //condicion para que no rebote con una velocidad menor

        if(i==0) //condicion que pregunta si es el primer enemigo
        {
            enemigos.at(i)->MCU(930,45,10,-1.5,0);
            enemigos.at(i)->rotar(2); //rotar imagen
        }
        if(i==1) //condicion que pregunta si es el segundo enemigo
        {
            enemigos.at(i)->MCU(70,45,-10,1.5,0);
            enemigos.at(i)->rotar(2); //rotar imagen
        }
        if(i==2) //condicion que pregunta si es el tercer enemigo
        {
            enemigos.at(i)->MAS(250,250,180,1,2); //darle movmiento armonico simple
            enemigos.at(i)->rotar(2); //rotar imagen
        }

        if(i==3) //condicion que pregunta si es el cuarto enemigo
        {
            enemigos.at(i)->MAS(750,250,180,1,2); //darle movmiento armonico simple
            enemigos.at(i)->rotar(2); //rotar imagen
        }

        if(i==4) //condicion que pregunta si es el quinto enemigo
        {
            enemigos.at(i)->MAS(500,250,-180,1,2); //darle movmiento armonico simple
            enemigos.at(i)->rotar(2); //rotar imagen
        }


    }


}

void MainWindow::mover_enemigo3()
{
    //qDebug()<<"tamaño lista;"<<enemigos.size();
    for(int i=0; i<enemigos.size();i++) //ciclo que lee toda la lista de enemigos
    {
        /* enemmigo 1 y 2 son las bolas que rebotan
         * enemigo 3 y 4 las bolas con movimiento MCU
         * enemigo 5 con el movimiento MAS*/

        //qDebug() <<"velocidad: "<<enemigos.at(i)->getVel();
        //qDebug() <<"velocidadx: "<<enemigos.at(i)->getVelx();
        if(enemigos.at(i)->getVel()>90){enemigos.at(i)->setVel(90);} //condicion para que no supere cierta velocidad
        if(enemigos.at(i)->getVelx()<30){enemigos.at(i)->setVelx(30);} //condicion para que no rebote con una velocidad menor



        if(i==2) //condicion que pregunta si es el tercer enemigo
        {
            enemigos.at(i)->MCU(250,275,100,-1.5,0); //darle movimiento circular uniforme

        }

        if(i==3) //condicion que pregunta si es el cuarto enemigo
        {
            enemigos.at(i)->MCU(750,275,100,-1.5,-3.1416); //darle el omvimiento circular uniforme

        }

        if(i==4) //condicion que pregunta si es el quinto enemigo
        {
            enemigos.at(i)->MAS(500,250,200,1,2); //darle movmiento armonico simple
            enemigos.at(i)->rotar(2); //rotar imagen
        }

        if(i==5) //condicion que pregunta si es el sexto enemigo
        {
            enemigos.at(i)->MAS(250,450,400,0.8,3);
            enemigos.at(i)->rotar(2); //rotar imagen
        }

        if(i==6) //condicion que pregunta si es el sexto enemigo
        {
            enemigos.at(i)->MAS(750,450,400,0.8,3);
            enemigos.at(i)->rotar(2); //rotar imagen
        }

    }
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
    ui->Vida2->hide();
    ui->Vida->show();
    ui->Pausa->show();
    ui->Play->show();
    ui->Puntaje->setText(QString::number(pn));
    ui->Vida->setText(QString::number(vida1));
    if(num_jugadores==2){
            ui->Vida2->show();
            ui->Vida2->setText(QString::number(vida2));
    }
    ifstream Leer;
    int ancho1,alto1,posix,posiy,posjx,posjy;

    h_limit = 1000;
    v_limit = 500;

    timer = new QTimer(this);
    timerenemigo = new QTimer; //creo el Qtimer
    timerenemigo2 = new QTimer; //creo el Qtimer
    timerenemigo3 = new QTimer; //creo el Qtimer
    scene = new QGraphicsScene(this);
    muro1 = new pared(3,100,-997,-400);
    muro2 = new pared(3,100,0,-400);
    muro4 = new pared(3,100,-997,-200);
    muro3 = new pared(3,100,0,-200);
    scene->setSceneRect(0,0,h_limit,v_limit);

    timerenemigo->stop(); //parar el timer del nivel 2
    timerenemigo2->stop();
    timerenemigo3->stop();

    view->show();
    view->setScene(scene);
    ui->centralwidget->adjustSize();
    scene->addRect(scene->sceneRect());
    view->resize(scene->width(),150+scene->height());
    this->resize(view->width(),view->height());
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    for(int i=0;i<paredes.size();i++){
        paredes.removeAt(i);}
    for(int i=0;i<monedas.size();i++){
        monedas.removeAt(i);}
    //jugador o jugadores
    crear_jugador();
    //enemigo 1
    bola1 = new enemigo(500,-350,260,260); //creo enemigo 1
    bola1->setImagen(2); //selecionar imagen
    bola1->setScale(0.2);//cambiar tamaño
    enemigos.push_back(bola1); //agrego enemigo 1 a la lista de enemigos
    scene->addItem(enemigos.at(0)); //añado enemigo 1 a la escena

    //enemigo 2
    bola2 = new enemigo(500,-350,260,260); //creo enemigo 2
    bola2->setImagen(2); //seleccionar la imagen
    bola2->setScale(0.2); //cambiar tamaño
    enemigos.push_back(bola2); //agrego enemigo 2 a la lista de enemigos
    scene->addItem(enemigos.at(1)); //añado enemigo 2 a la escena

    //enemigo 3
    bola3 = new enemigo(500,-350,260,260); //creo enemigo 3
    bola3->setImagen(2); //selecionar imagen
    bola3->setScale(0.2); //cambiar tamaño
    enemigos.push_back(bola3); //agrego enemigo 3 a la lista de enemigos
    scene->addItem(enemigos.at(2)); //añado enemigo 3 a la escena

    //enemigo 4
    bola4 = new enemigo(300,-10,260,260); //creo enemigo 4
    bola4->setImagen(2); //sleecionar imagen
    bola4->setScale(0.2); //cambiar tamaño cierra derecha
    enemigos.push_back(bola4); //agrego enemigo 4 a la lista de enemigos
    scene->addItem(enemigos.at(3)); //añado enemigo 4 a la escena

    //enemigo 5
    bola5 = new enemigo(500,-170,260,260); //creo enemigo 5
    bola5->setImagen(2); //seleccionar imagen
    bola5->setScale(0.2); //cambiar tamaño cierra mas
    enemigos.push_back(bola5); //agrego enemigo 4 a la lista de enemigos
    scene->addItem(enemigos.at(4)); //añado enemigo 4 a la escena

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

    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));
    timer->start(3);
    connect(timerenemigo,SIGNAL(timeout()),this,SLOT(mover_enemigo()));
    timerenemigo->start(12);
}

void MainWindow::level2()
{

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
    ui->Vida2->hide();
    ui->Vida->show();
    ui->Pausa->show();
    ui->Play->show();
    ui->Puntaje->setText(QString::number(pn));
    ui->Vida->setText(QString::number(vida1));
    if(num_jugadores==2){
            ui->Vida2->show();
            ui->Vida2->setText(QString::number(vida2));
    }
    ifstream Leer;
    int ancho1,alto1,posix,posiy,posjx,posjy;

    h_limit = 1000;
    v_limit = 500;

    timer = new QTimer(this);
    timerenemigo = new QTimer; //creo el Qtimer
    timerenemigo2 = new QTimer; //creo el Qtimer
    timerenemigo3 = new QTimer; //creo el Qtimer
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
    for(int i=0;i<paredes.size();i++){
        paredes.removeAt(i);}
    for(int i=0;i<monedas.size();i++){
        monedas.removeAt(i);}
    for(int i=0;i<enemigos.size();i++){ //ciclo que recorre toda la lista de enemigos
        enemigos.removeAt(i);
    }

    crear_jugador();
    //enemigo 6
    bola6 = new enemigo(250,-450,512,512); //creo enemigo 1
    bola6->setImagen(4); //selecionar imagen
    bola6->setScale(0.1);//cambiar tamaño
    enemigos.push_back(bola6); //agrego enemigo 1 a la lista de enemigos
    scene->addItem(enemigos.at(0)); //añado enemigo 1 a la escena

    //enemigo 7
    bola7 = new enemigo(250,-450,512,512); //creo enemigo 6
    bola7->setImagen(4); //seleccionar la imagen
    bola7->setScale(0.1); //cambiar tamaño
    enemigos.push_back(bola7); //agrego enemigo 6 a la lista de enemigos
    scene->addItem(enemigos.at(1)); //añado enemigo 6 a la escena

    //enemigo 8
    bola8 = new enemigo(250,-450,260,260); //creo enemigo 3
    bola8->setImagen(2); //selecionar imagen
    bola8->setScale(0.3); //cambiar tamaño
    enemigos.push_back(bola8); //agrego enemigo 3 a la lista de enemigos
    scene->addItem(enemigos.at(2)); //añado enemigo 3 a la escena

    //enemigo 9
    bola9 = new enemigo(750,-450,260,260); //creo enemigo 4
    bola9->setImagen(2); //sleecionar imagen
    bola9->setScale(0.3); //cambiar tamaño
    enemigos.push_back(bola9); //agrego enemigo 4 a la lista de enemigos
    scene->addItem(enemigos.at(3)); //añado enemigo 4 a la escena

    //enemigo 10
    bola10 = new enemigo(500,-170,260,260); //creo enemigo 5
    bola10->setImagen(2); //seleccionar imagen
    bola10->setScale(0.6); //cambiar tamaño
    enemigos.push_back(bola10); //agrego enemigo 4 a la lista de enemigos
    scene->addItem(enemigos.at(4)); //añado enemigo 4 a la escena

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

    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));
    timer->start(3);
    connect(timerenemigo2,SIGNAL(timeout()),this,SLOT(mover_enemigo2())); //conecto el timer al movimiento del enemigo
    timerenemigo2->start(12);
}

void MainWindow::level3()
{

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
    ui->Vida2->hide();
    ui->Vida->show();
    ui->Pausa->show();
    ui->Play->show();
    ui->Puntaje->setText(QString::number(pn));
    ui->Vida->setText(QString::number(vida1));
    if(num_jugadores==2){
            ui->Vida2->show();
            ui->Vida2->setText(QString::number(vida2));
    }
    ifstream Leer;
    int ancho1,alto1,posix,posiy,posjx,posjy;

    h_limit = 1000;
    v_limit = 500;

    timer = new QTimer(this);
    timerenemigo = new QTimer; //creo el Qtimer
    timerenemigo2 = new QTimer; //creo el Qtimer
    timerenemigo3 = new QTimer; //creo el Qtimer
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
    for(int i=0;i<paredes.size();i++){
        paredes.removeAt(i);}
    for(int i=0;i<monedas.size();i++){
        monedas.removeAt(i);}
    for(int i=0;i<enemigos.size();i++){ //ciclo que recorre toda la lista de enemigos
        enemigos.removeAt(i);
    }

    crear_jugador();
    //enemigo 11
    bola11 = new enemigo(25,-200,81,82,30,0); //creo enemigo 11
    bola11->setImagen(2); //selecionar imagen
    bola11->setScale(0.6);//cambiar tamaño
    enemigos.push_back(bola11); //agrego enemigo 11 a la lista de enemigos
    scene->addItem(enemigos.at(0)); //añado enemigo 11 a la escena

    //enemigo 12
    bola12 = new enemigo(975,-200,81,82,30,180); //creo enemigo 12
    bola12->setImagen(2); //seleccionar la imagen
    bola12->setScale(0.6); //cambiar tamaño
    enemigos.push_back(bola12); //agrego enemigo 12 a la lista de enemigos
    scene->addItem(enemigos.at(1)); //añado enemigo 12 a la escena

    //enemigo 13..
    bola13 = new enemigo(500,-350,512,512); //creo enemigo 13
    bola13->setImagen(1); //selecionar imagen
    bola13->setScale(0.1); //cambiar tamaño
    enemigos.push_back(bola13); //agrego enemigo 13 a la lista de enemigos
    scene->addItem(enemigos.at(2)); //añado enemigo 13 a la escena

    //enemigo 14
    bola14 = new enemigo(750,-350,512,512); //creo enemigo 14
    bola14->setImagen(1); //sleecionar imagen
    bola14->setScale(0.1); //cambiar tamaño
    enemigos.push_back(bola14); //agrego enemigo 14 a la lista de enemigos
    scene->addItem(enemigos.at(3)); //añado enemigo 14 a la escena

    //enemigo 15
    bola15 = new enemigo(500,-170,260,260); //creo enemigo 15
    bola15->setImagen(2); //seleccionar imagen
    bola15->setScale(0.2); //cambiar tamaño
    enemigos.push_back(bola15); //agrego enemigo 4 a la lista de enemigos
    scene->addItem(enemigos.at(4)); //añado enemigo 4 a la escena

    //enemigo 16
    bola16 = new enemigo(250,-170,1024,576); //creo enemigo 16
    bola16->setImagen(3); //seleccionar imagen
    bola16->setScale(0.1); //cambiar tamaño
    enemigos.push_back(bola16); //agrego enemigo 16 a la lista de enemigos
    scene->addItem(enemigos.at(5)); //añado enemigo 16 a la escena

    //enemigo 17
    bola17 = new enemigo(750,-170,1024,576); //creo enemigo 17
    bola17->setImagen(3); //seleccionar imagen
    bola17->setScale(0.1); //cambiar tamaño
    enemigos.push_back(bola17); //agrego enemigo 17 a la lista de enemigos
    scene->addItem(enemigos.at(6)); //añado enemigo 17 a la escena

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

    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));
    timer->start(3);
    connect(timerenemigo3,SIGNAL(timeout()),this,SLOT(mover_enemigo3())); //conecto el timer al movimiento del enemigo
    timerenemigo3->start(12);
}

void MainWindow::destructorlevel1()
{
    delete timer;
    delete timerenemigo;
    delete timerenemigo2;
    delete timerenemigo3;
    for(int i=0;i<enemigos.size();i++){ //ciclo que recorre toda la lista de enemigos
        enemigos.removeAt(i);
    }
    for(int i=0;i<enemigos.size();i++){ //ciclo que recorre toda la lista de enemigos
        enemigos.removeAt(i);
    }
    for(int i=0;i<paredes.size();i++){
        paredes.removeAt(i);}
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
        string Nnames,clave,nivel_,punaje_,cantjugadores,px1_,px2_,py1_,py2_;

        ifstream leer;
        ofstream Temp,Guardar;
        Guardar.open("../juego_solitario/partidas/Guardar.txt",ios::app);
        leer.open("../juego_solitario/partidas/Guardar.txt");
        Temp.open("../juego_solitario/partidas/temp.txt",ios::app);
        bool encontrado =false;
        leer>>Nnames;
        while (!leer.eof()) {
            leer>>clave;
            leer>>nivel_;
            leer>>punaje_;
            leer>>cantjugadores;
            leer>>px1_;
            leer>>py1_;
            leer>>px2_;
            leer>>py2_;
            if(Nnames==user.toStdString()&&clave==contra.toStdString()){
                encontrado=true;
                cargado=true;
                nivel=stoi(nivel_);
                pn=stoi(punaje_);
                num_jugadores=stoi(cantjugadores);
                Temp<<Nnames<<" "<<clave<<" "<<nivel_<<" "<<punaje_<<" "<<cantjugadores<<" "<<px1_<<" "<<py1_<<" "<<px2_<<" "<<py2_<<endl;

            }
            else{
                Temp<<Nnames<<" "<<clave<<" "<<nivel_<<" "<<punaje_<<" "<<cantjugadores<<" "<<px1_<<" "<<py1_<<" "<<px2_<<" "<<py2_<<endl;
            }
            leer>>Nnames;

        }
        if(!encontrado){
            Temp<<user.toStdString()<<" "<<contra.toStdString()<<" "<<1<<" "<<pn<<" "<<num_jugadores<<" "<<px1<<" "<<py1<<" "<<px2<<" "<<py2<<endl;
        }
        leer.close();
        Temp.close();
        Guardar.close();
        remove("../juego_solitario/partidas/Guardar.txt");
        rename("../juego_solitario/partidas/temp.txt","../juego_solitario/partidas/Guardar.txt");
    }
    if (cargado==true){
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
        if(nivel==1){level1();}
         if(nivel==2){
             vida1=250;
             vida2=250;
             level2();}
         if(nivel==3){
             vida1=250;
             vida2=250;level3();}

    }
    else{

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


}

void MainWindow::on_registrar_clicked()
{
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
        string Nnames,clave,nivel_,punaje_,cantjugadores,px1_,px2_,py1_,py2_;

        ifstream leer;
        ofstream Temp,Guardar;
        Guardar.open("../juego_solitario/partidas/Guardar.txt",ios::app);
        leer.open("../juego_solitario/partidas/Guardar.txt");
        Temp.open("../juego_solitario/partidas/temp.txt",ios::app);
        bool encontrado =false;
        leer>>Nnames;
        while (!leer.eof()) {
            leer>>clave;
            leer>>nivel_;
            leer>>punaje_;
            leer>>cantjugadores;
            leer>>px1_;
            leer>>py1_;
            leer>>px2_;
            leer>>py2_;
            if(Nnames==user.toStdString()&&clave==contra.toStdString()){
                encontrado=true;
                Temp<<user.toStdString()<<" "<<contra.toStdString()<<" "<<nivel<<" "<<pn<<" "<<num_jugadores<<" "<<px1<<" "<<py1<<" "<<px2<<" "<<py2<<endl;
            }
            else{
                Temp<<Nnames<<" "<<clave<<" "<<nivel_<<" "<<punaje_<<" "<<cantjugadores<<" "<<px1_<<" "<<py1_<<" "<<px2_<<" "<<py2_<<endl;
            }
            leer>>Nnames;

        }
        if(!encontrado){
            Temp<<user.toStdString()<<" "<<contra.toStdString()<<" "<<1<<" "<<pn<<" "<<num_jugadores<<" "<<px1<<" "<<py1<<" "<<px2<<" "<<py2<<endl;
        }
        leer.close();
        Temp.close();
        Guardar.close();
        remove("../juego_solitario/partidas/Guardar.txt");
        rename("../juego_solitario/partidas/temp.txt","../juego_solitario/partidas/Guardar.txt");
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


void MainWindow::on_Play_clicked()
{
    timer->start(3);
    timerenemigo->start(12);
    timerenemigo2->start(12);
    timerenemigo3->start(12);
    ui->Pausa->show();
    ui->Play->hide();
}

void MainWindow::on_Pausa_clicked()
{
    timer->stop();
    timerenemigo->stop();
    timerenemigo2->stop();
    timerenemigo3->stop();
    ui->Pausa->hide();
    ui->Play->show();
}


void MainWindow::on_actionGuardar_triggered()
{

        string Nnames,clave,nivel_,punaje_,cantjugadores,px1_,px2_,py1_,py2_;

        ifstream leer;
        ofstream Temp,Guardar;
        Guardar.open("../juego_solitario/partidas/Guardar.txt",ios::app);
        leer.open("../juego_solitario/partidas/Guardar.txt");
        Temp.open("../juego_solitario/partidas/temp.txt",ios::app);
        bool encontrado =false;
        leer>>Nnames;
        while (!leer.eof()) {
            leer>>clave;
            leer>>nivel_;
            leer>>punaje_;
            leer>>cantjugadores;
            leer>>px1_;
            leer>>py1_;
            leer>>px2_;
            leer>>py2_;
            if(Nnames==user.toStdString()&& clave ==contra.toStdString()){
                encontrado=true;
                Temp<<user.toStdString()<<" "<<contra.toStdString()<<" "<<nivel<<" "<<pn<<" "<<num_jugadores<<" "<<px1<<" "<<py1<<" "<<px2<<" "<<py2<<endl;
            }
            else{
                Temp<<Nnames<<" "<<clave<<" "<<nivel_<<" "<<punaje_<<" "<<cantjugadores<<" "<<px1_<<" "<<py1_<<" "<<px2_<<" "<<py2_<<endl;
            }
            leer>>Nnames;

        }
        if(!encontrado){
            Temp<<user.toStdString()<<" "<<contra.toStdString()<<" "<<nivel<<" "<<pn<<" "<<num_jugadores<<" "<<px1<<" "<<px1<<" "<<px2<<" "<<py2<<endl;
        }
        leer.close();
        Temp.close();
        Guardar.close();
        remove("../juego_solitario/partidas/Guardar.txt");
        rename("../juego_solitario/partidas/temp.txt","../juego_solitario/partidas/Guardar.txt");


    QMessageBox msgBox;
    msgBox.setText("Partida Guardada");
    msgBox.setWindowTitle("¡EXITO!");
    msgBox.setWindowIcon(QIcon(":/recursos/imagenes/imagen.png"));
    msgBox.setStyleSheet("background-color:#211b18;"
                         "color:white;");
    msgBox.exec();
}

void MainWindow::on_actionReiniciar_triggered()
{
    switch (nivel) {
    case 1:
        destructorlevel1();
        vida1=500;
        vida2=500;
        pn=0;
        level1();
        break;
    case 2:
        destructorlevel1();
        vida1=250;
        vida2=250;
        pn=0;
        level2();
        break;
    case 3:
        destructorlevel1();
        vida1=250;
        vida2=250;
        pn=0;
        level3();
        break;

    }
}

void MainWindow::on_actionEliminar_triggered()
{

    string Nnames,clave,nivel_,punaje_,cantjugadores,px1_,px2_,py1_,py2_;

    ifstream leer;
    ofstream Temp,Guardar;
    Guardar.open("../juego_solitario/partidas/Guardar.txt",ios::app);
    leer.open("../juego_solitario/partidas/Guardar.txt");
    Temp.open("../juego_solitario/partidas/temp.txt",ios::app);
    bool encontrado =false;
    leer>>Nnames;
    while (!leer.eof()) {
        leer>>clave;
        leer>>nivel_;
        leer>>punaje_;
        leer>>cantjugadores;
        leer>>px1_;
        leer>>py1_;
        leer>>px2_;
        leer>>py2_;
        if(Nnames==user.toStdString() && clave==contra.toStdString()){
            encontrado=true;
        }
        else{
            Temp<<Nnames<<" "<<clave<<" "<<nivel_<<" "<<punaje_<<" "<<cantjugadores<<" "<<px1_<<" "<<py1_<<" "<<px2_<<" "<<py2_<<endl;
        }
        leer>>Nnames;

    }
    if(!encontrado){
        Temp<<user.toStdString()<<" "<<contra.toStdString()<<" "<<nivel<<" "<<pn<<" "<<num_jugadores<<" "<<px1<<" "<<px1<<" "<<px2<<" "<<py2<<endl;
    }
    leer.close();
    Temp.close();
    Guardar.close();
    remove("../juego_solitario/partidas/Guardar.txt");
    rename("../juego_solitario/partidas/temp.txt","../juego_solitario/partidas/Guardar.txt");


    QMessageBox msgBox;
    msgBox.setText("Usuario eliminado");
    msgBox.setWindowTitle("¡EXITO!");
    msgBox.setWindowIcon(QIcon(":/recursos/imagenes/imagen.png"));
    msgBox.setStyleSheet("background-color:#211b18;"
                         "color:white;");
    msgBox.exec();
    this->close();

}


void MainWindow::on_actionControles_triggered()
{
    timer->stop();
    timerenemigo->stop();
    timerenemigo2->stop();
    timerenemigo3->stop();
    QString txt;
    txt="para poder ver las propiedades de los planetas \n"
        "las cuales son:\n"
        "- Posicion (x,y)\n"
        "- Velocidad (x,y)\n"
        "- Aceleracion (x,y)\n"
        "Seleccione la opcion de planetas y seleccione\n"
        "el planeta al cual le desea ver las propiedades,\n"
        "estas cualidades saldran en la parde abajo  las\n"
        "cuales podra ver de una manera facil y sencilla.\n";
    QMessageBox::about(this,"Instrucciones",txt);
    timer->start(3);
    timerenemigo->start(12);
    timerenemigo2->start(12);
    timerenemigo3->start(12);
}

void MainWindow::on_actionInstrucciones_triggered()
{
    timer->stop();
    timerenemigo->stop();
    timerenemigo2->stop();
    timerenemigo3->stop();
    QString txt;
    txt="para poder ver las propiedades de los planetas \n"
        "las cuales son:\n"
        "- Posicion (x,y)\n"
        "- Velocidad (x,y)\n"
        "- Aceleracion (x,y)\n"
        "Seleccione la opcion de planetas y seleccione\n"
        "el planeta al cual le desea ver las propiedades,\n"
        "estas cualidades saldran en la parde abajo  las\n"
        "cuales podra ver de una manera facil y sencilla.\n";
    QMessageBox::about(this,"Instrucciones",txt);
    timer->start(3);
    timerenemigo->start(12);
    timerenemigo2->start(12);
    timerenemigo3->start(12);
}
