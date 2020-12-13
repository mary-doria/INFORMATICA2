#include "bullet.h"

Bullet::Bullet(float aInicial_,float vInicial_,float x_,float y_)
{ this->aInicial=aInicial_;
  this->vInicial=vInicial_;
  this->setX(x_);
  this->setY(y_);
}
