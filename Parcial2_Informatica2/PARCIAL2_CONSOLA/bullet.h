#ifndef BULLET_H
#define BULLET_H
#include "objetofisico.h"

class Bullet:public ObjetoFisico
{private:
    float vInicial;
    float aInicial;
public:
    Bullet();
};

#endif // BULLET_H
