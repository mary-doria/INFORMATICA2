#ifndef BULLET_H
#define BULLET_H
#include "objetofisico.h"
#include "cannon.h"

class Bullet:public ObjetoFisico
{private:
    float vInicial;
    float aInicial;
    float t;
public:
    Bullet();
    Bullet(float aInicial_,float vInicial_,float x_,float y_);
    bool detectarColision(ObjetoFisico *objetoFisico, float radio, float d);
    void recorrerDistanciaX(float d);
    float getT() const;
    void setT(float value);
};

#endif // BULLET_H
