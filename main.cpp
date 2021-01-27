#include "mainwindow.h"

#include <QApplication>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //Con ayuda de la libreria QSplashScreen podremos mostrar una pantalla de carga con un logo png diseñado para el juego
    QSplashScreen splash;
    splash.setPixmap(QPixmap(":/recursos/imagenes/presentacion").scaled(308,274));
    splash.show();
    QTimer::singleShot(3000,&splash,SLOT(close()));
    QTimer::singleShot(3500,&w,SLOT(show()));

    return a.exec();
}
