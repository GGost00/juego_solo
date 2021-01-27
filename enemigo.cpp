#include "enemigo.h"
#include <math.h>
#include <cmath>

enemy::enemy(float posX_, float posY_, float velX_, float velY_, float masa_, float radio_, float K_, float e_)
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

enemy::~enemy()
{

}

void enemy::actualizar()
{
    V = pow(((VX*VX)+(VY*VY)),(1/2));
    angulo = atan2(VY,VX);
    AX = -((K*(V*V)*(R*R))/mass)*cos(angulo);
    AY = (-((K*(V*V)*(R*R))/mass)*sin(angulo))-G;
    PX = PX + ((VX*(dt)))+(((AX*(dt*dt)))/2);
    PY = PY + ((VY*(dt)))+(((AY*(dt*dt)))/2);
    VX = VX + AX*dt;
    VY = VY + AY*dt;
}


float enemy::getPY() const
{
    return PY;
}

float enemy::getMass() const
{
    return mass;
}

float enemy::getR() const
{
    return R;
}

float enemy::getVX() const
{
    return VX;
}

float enemy::getVY() const
{
    return VY;
}

float enemy::getE() const
{
    return e;
}

float enemy::getPX() const
{
    return PX;
}

void enemy::set_vel(float vx, float vy, float px, float py)
{
    VX = vx;
    VY = vy;
    PX = px;
    PY = py;
}
