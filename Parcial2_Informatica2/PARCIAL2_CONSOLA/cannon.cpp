#include "cannon.h"
#include "bullet.h"
#include <cmath>
#include <iostream>

using namespace std;

Cannon::Cannon(float x_,float y_)
{
    this->setX(x_);
    this->setY(y_);
}

bool Cannon::generarDisparo(Cannon *cannonObjetivo, float radio, bool ofensivo)
{
  Bullet *bullet;
  float a, v, t, y, d;
  int contador1=0;
  for(float i=0;i<20;i+=1){
    a = (3.1416/2)*(i/20);//ANGULO DEL CAÑON ATACANTE ENTRE 0 Y 90° CON INCREMENTOS DE 5°
    for(float j=0;j<20;j+=1){
    v = (100/20)*j;//VELOCIDAD INICIAL DE LA BALA OFENSIVA-COGER UNA VELOCIDAD MENOR QUE 100METROS CON INCREMENTOS DE 5METROS
    if(contador1<3){
      bullet = new Bullet(a, v, this->getX(), this->getY());
      d = abs(this->getX()-cannonObjetivo->getX());
      t = d/(v*cos(a));//PARA HALLAR EL TIEMPO EN LA COMPONENTE X SEGUN LA FORMULA DEL MOVIEMIENTO PARABOLICO
      y = this->getY() +(v*sin(a)*t) - (t*t*(9.8/2));//COMPONENTE EN Y DE LA FORMULA DEL TIRO PARABOLICO
          if(cannonObjetivo->getY() < y+ radio*d & cannonObjetivo->getY() > y-radio*d){//SI LA ALTURA DE LA BALA SE ENCUENTRA ENTRE (HD-0.05d y HD+0.05d) o (HD-0.025d y HD+0.025d)
          //SE DA A ENTENDER SI LA ALTURA DE LA BALA ESTA A (0.05*d o 0.025*d) O MENOS DEL CAÑON DEFENSOR
          cout<<"Colisiona"<<endl;
          contador1 += 1;
          cout<<"Angulo fue:"<<a<<endl;
          cout<<"Velocidad fue:"<<v<<endl;
          cout<<"Tiempo es :"<<t<<endl;
          cout<<"Y es: "<<y<<endl;//ALTURA DE LA BALA OFENSIVA
          }
      }
      if(contador1==3){
        break;
      }
      }
    if(contador1==3){
      break;
    }}
}
