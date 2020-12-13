#include "bullet.h"
#include "math.h"

float Bullet::getT() const
{
    return t;
}

void Bullet::setT(float value)
{
    t = value;
}

Bullet::Bullet(float aInicial_,float vInicial_,float x_,float y_)
{
    this->t=0;
    this->aInicial=aInicial_;
  this->vInicial=vInicial_;
  this->setX(x_);
  this->setY(y_);
}

bool Bullet::detectarColision(Cannon *cannon_objetivo, float radio, float d)
{
    if(cannon_objetivo->getY() < y+ radio*d & cannon_objetivo->getY() > y-radio*d){
        return true;
    } else {
        return false;
    }
}

void Bullet::recorrerDistanciaX(float d){
    x = d;
    this->t = d/(this->vInicial*cos(this->aInicial));//PARA HALLAR EL TIEMPO EN LA COMPONENTE X SEGUN LA FORMULA DEL MOVIEMIENTO PARABOLICO
    y = this->getY() +(this->vInicial*sin(this->aInicial)*this->t) - (this->t*this->t*(9.8/2));//COMPONENTE EN Y DE LA FORMULA DEL TIRO PARABOLICO
}
