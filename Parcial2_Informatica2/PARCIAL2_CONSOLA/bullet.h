#ifndef BULLET_H
#define BULLET_H
#include "objetofisico.h"

class Bullet:public ObjetoFisico
{private:
    float vInicial;
    float aInicial;
public:
    Bullet();
    Bullet(float aInicial_,float vInicial_,float x_,float y_);
};

#endif // BULLET_H
