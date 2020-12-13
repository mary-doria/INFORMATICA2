#include "objetofisico.h"

ObjetoFisico::ObjetoFisico()
{

}

ObjetoFisico::ObjetoFisico(float x_,float y_)
{
this->x=x_;
this->y=y_;

}

float ObjetoFisico::getX() const
{
    return this->x;
}

void ObjetoFisico::setX(float value)
{
    this->x = value;
}

float ObjetoFisico::getY() const
{
    return this->y;
}

void ObjetoFisico::setY(float value)
{
    this->y = value;
}

