#ifndef JUGADOR_H
#define JUGADOR_H


class cuerpo
{
private:
    float PX; //pos en x
    float PY; //pos en y
    float mass; // masa del cuerpo
    float R; //radio del cuerpo
    float VX; //vel en x
    float VY; //vel en y
    float angulo; //angulo en el que va el cuerpo
    float AX; //acel en x
    float AY; //acel en y
    float G; //gravedad
    float K; //Resistencia del aire
    float e; //Coeficiente de restitucion
    float V; //vector de velocidad
    float dt; //delta tiempo

public:
    cuerpo(float posX_,float posY_,float velX_,float velY_,float masa_,float radio_,float K_,float e_);//constructor de la clase jugador
    ~cuerpo();//destructor de la clase jugador
    void actualizar();//funcion que actualiza el movimiento del jugador

    float getPX() const;//funncion que devuelve la posicion x
    float getPY() const;//funncion que devuelve la posicion y
    float getMass() const;//funncion que devuelve la masa
    float getR() const;//funncion que devuelve el radio
    float getVX() const;//funncion que devuelve la velocidad x
    float getVY() const;//funncion que devuelve la velocidad y
    float getE() const;//funncion que devuelve el coeficiente de restitucion
    void set_vel(float vx, float vy, float px, float py);//funcion que actualiza la posicion y la velocidad

};


#endif // JUGADOR_H
