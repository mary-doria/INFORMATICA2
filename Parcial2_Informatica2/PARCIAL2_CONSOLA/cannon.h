#ifndef CANNON_H
#define CANNON_H
#include "objetofisico.h"

class Cannon:public ObjetoFisico
{
public:
    Cannon();
    Cannon(float x_,float y_);
    bool generarDisparo(Cannon cannon, float radio, bool ofensivo);
};

#endif // CANNON_H
