#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>//libreria de Main Window
#include <QTimer>// libreria para los timers
#include <QGraphicsScene>//libreria para la escena
#include <QGraphicsView>//libreria para el Graphics View
#include<QDesktopWidget>// libreria de widget
#include <QMessageBox>//libreria para mensaje de texto
#include <QKeyEvent>// libreria de teclas
#include <iostream>//libreria para archivos
#include <fstream>//libreria para archivos
#include "jugador.h"//incluir clase jugador
#include "grafjugador.h"// clase que dibuja al jugador
#include "enemigo.h" //incluir la clase villano.
#include "pared.h"//clase que hace las paredes
#include "moneda.h"//clase que hace las monedas

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QList<pared *> paredes;// lista para las paredes
    QList<moneda *> monedas;//lista para las monedas
    //lista
    QList<enemigo*> enemigos; //lista de enemigos
    QList<enemigo*> enemigos2; //lista de enemigos

public slots:
    void actualizar(); // funcion para mover al personaje

    void mover_enemigo(); //funcion para mover enemigos en el nivel 1

    void mover_enemigo2(); //funcion para mover enemigos en el nivel 2

    void mover_enemigo3(); //funcion para mover enemigos en el nivel 3

private slots:
    void on_cargarpartida_clicked(); //boton para cargar partida

    void on_nuevapartida_clicked();//boton generar una nueva partida

    void on_iniciar_clicked();// boton para iniciar partida despues de cargarla

    void on_registrar_clicked();// boton para iniciar partida despues de crearla

    void on_volver_clicked();//boton para volver al menu

    void on_pushButton_clicked();// boton para salir del juego

    void on_Play_clicked();// boton para reanudar el juego

    void on_Pausa_clicked();// boton para pausar el juego

    void on_actionGuardar_triggered();// boton para guardar el progreso del juego

    void on_actionReiniciar_triggered();// boton para reiniciar el nivel del juego

    void on_actionEliminar_triggered();// boton para eliminar el usuario

    void on_actionControles_triggered();// boton para ver los controles del juego

    void on_actionInstrucciones_triggered();// boton para ver las instrucciones del juego

private:
    Ui::MainWindow *ui;
    QTimer *timer;//timer del jugador
    QTimer *timerenemigo; //timer de los enemigos
    QTimer *timerenemigo2; //timer de los enemigos
    QTimer *timerenemigo3; //timer de los enemigos
    QGraphicsScene *scene;// se crea la escena
    int h_limit;
    int v_limit;
    void borderCollision2(cuerpo *b,cuerpo *d);
    void borderCollision(cuerpo *b);
    void keyPressEvent(QKeyEvent *event);
    void level1();
    void level2();
    void level3();
    void destructorlevel1();
    void crear_jugador();

    //personajes
    cuerpograf * personaje;
    cuerpograf * personaje2;

    //enemigos nivel 1
    enemigo *bola1;
    enemigo *bola2;
    enemigo *bola3;
    enemigo *bola4;
    enemigo *bola5;
    //enemigos nivel 2
    enemigo *bola6;
    enemigo *bola7;
    enemigo *bola8;
    enemigo *bola9;
    enemigo *bola10;
    //enemigos nivel 3
    enemigo *bola11;
    enemigo *bola12;
    enemigo *bola13;
    enemigo *bola14;
    enemigo *bola15;
    enemigo *bola16;
    enemigo *bola17;
   //muros de teletransporte
    pared *muro1;
    pared *muro2;
    pared *muro3;
    pared *muro4;

    QGraphicsView * view = new QGraphicsView(this);// se crea el view
    QList<moneda *> eliminarMoneda(QList<moneda *> monedas,int pos);//funcion para eliminar la moneda tomada
};
#endif // MAINWINDOW_H
