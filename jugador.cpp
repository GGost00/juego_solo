#include "jugador.h"
#include <math.h>
#include <cmath>


cuerpo::cuerpo(float posX_, float posY_, float velX_, float velY_, float masa_, float radio_, float K_, float e_)
{
    PX = posX_; //pos en x
    PY = posY_; //pos en y
    mass = masa_; // masa del cuerpo
    R = radio_; //radio del cuerpo
    VX = velX_; //vel en x
    VY = velY_; //vel en y
    AX = 0; //acel en x
    AY = 0; //acel en y
    G = 10; //gravedad
    K = K_; //Resistencia del aire
    e = e_; //Coeficiente de restitucion
    V = 0; //vector de velocidad
    dt = 0.1; //delta tiempo
}

cuerpo::~cuerpo()
{

}

void cuerpo::actualizar()
{
    V = pow(((VX*VX)+(VY*VY)),(1/2));// se calcula la velocidad
    angulo = atan2(VY,VX);//se calcula el angulo a partir de las velocidades
    AX = -((K*(V*V)*(R*R))/mass)*cos(angulo);//se calcula la aceleracion x
    AY = (-((K*(V*V)*(R*R))/mass)*sin(angulo))-G;//se calcula la aceleracion en y
    PX = PX + ((VX*(dt)))+(((AX*(dt*dt)))/2);//se calcula la posicion en x
    PY = PY + ((VY*(dt)))+(((AY*(dt*dt)))/2);//se calcula la posicion en y
    VX = VX + AX*dt;//se calcula la velocidad x
    VY = VY + AY*dt;//se calcula la velocidad y
}


float cuerpo::getPY() const
{
    return PY;//se retorna la posicion y del cuerpo
}

float cuerpo::getMass() const
{
    return mass;//se retorna la masa del cuerpo
}

float cuerpo::getR() const
{
    return R;// se retorna el radio
}

float cuerpo::getVX() const
{
    return VX;//se retorna la velocidad x
}

float cuerpo::getVY() const
{
    return VY;//se retorna el valor de la velocidad y
}

float cuerpo::getE() const
{
    return e;//se retorna el valor de la constante de restitucion
}

float cuerpo::getPX() const
{
    return PX;//se retorna la posicion x
}

void cuerpo::set_vel(float vx, float vy, float px, float py)
{
    VX = vx;//se le da valor a la velocidad x
    VY = vy;//se le da valor a la velocidad y
    PX = px;//se le da una posicion x
    PY = py;//se le da una posicion y
}
