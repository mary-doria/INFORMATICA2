#ifndef CANNON_H
#define CANNON_H
#include "objetofisico.h"

class Cannon:public ObjetoFisico
{
public:
    Cannon();
    Cannon(float x_,float y_);
    bool generarDisparo(Cannon *cannonObjetivo, float radio, bool ofensivo);
    bool generarDisparo3(Cannon *cannonObjetivo, float radioO, float radioD, bool ofensivo);
    bool generarDisparo5(Cannon *cannonObjetivo, float radioO, float radioD, bool ofensivo);
};

#endif // CANNON_H
