#ifndef CANNON_H
#define CANNON_H
#include "objetofisico.h"


class Cannon:public ObjetoFisico
{
public:
    Cannon();
    Cannon(float x_,float y_);
};

#endif // CANNON_H
