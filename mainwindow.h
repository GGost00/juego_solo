#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <iostream>
#include <fstream>
#include "jugador.h"
#include "grafjugador.h"
#include "enemigo.h"
#include "grafenemigo.h"
#include "pared.h"
#include "moneda.h"

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
    QList<pared *> paredes;
    QList<moneda *> monedas;

public slots:
    void actualizar();
    void moveenemy();

private slots:
    void on_cargarpartida_clicked();

    void on_nuevapartida_clicked();

    void on_iniciar_clicked();

    void on_registrar_clicked();

    void on_volver_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QTimer *timere;
    QGraphicsScene *scene;
    float dt;
    int h_limit;
    int v_limit;
    void borderCollision(cuerpo *b);
    void borderCollisionE(enemy *b);
    void keyPressEvent(QKeyEvent *event);
    cuerpograf * personaje;
    grafenemigo*  enemigo;
    pared *muro1;
    pared *muro2;
    pared *muro3;
    pared *muro4;
    QList<cuerpograf *> bars;
    QGraphicsView * view = new QGraphicsView(this);
    QList<moneda *> eliminarMoneda(QList<moneda *> monedas,int pos);
};
#endif // MAINWINDOW_H
