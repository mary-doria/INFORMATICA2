#include "cannon.h"
#include "bullet.h"
#include "objetofisico.h"
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

      bullet->recorrerDistanciaX(d);
          if(bullet->detectarColision((ObjetoFisico *)cannonObjetivo, radio, d)){//SI LA ALTURA DE LA BALA SE ENCUENTRA ENTRE (HD-0.05d y HD+0.05d) o (HD-0.025d y HD+0.025d)
          //SE DA A ENTENDER SI LA ALTURA DE LA BALA ESTA A (0.05*d o 0.025*d) O MENOS DEL CAÑON DEFENSOR
          cout<<"Colisiona"<<endl;
          contador1 += 1;
          cout<<"Angulo fue:"<<a<<endl;
          cout<<"Velocidad fue:"<<v<<endl;
          cout<<"Tiempo es :"<<bullet->getT()<<endl;
          cout<<"Y es: "<<bullet->getY()<<endl;//ALTURA DE LA BALA OFENSIVA
          cout<<"X es: "<<bullet->getX()<<endl;//DISTANCIA RECORRIDA DE LA BALA OFENSIVA
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

bool Cannon::generarDisparo3(Cannon *cannonObjetivo, float radioO, float radioD, bool ofensivo)
{
  Bullet *bullet, *bulletSimulada, *bulletDefensiva;
  float a, v, t, y, d, ad, vd;
  int contador1=0;
  int contador2=0;
  for(float i=0;i<20;i+=1){
    a = (3.1416/2)*(i/20);//ANGULO DEL CAÑON ATACANTE ENTRE 0 Y 90° CON INCREMENTOS DE 5°
    for(float j=0;j<20;j+=1){
    v = (100/20)*j;//VELOCIDAD INICIAL DE LA BALA OFENSIVA-COGER UNA VELOCIDAD MENOR QUE 100METROS CON INCREMENTOS DE 5METROS
    if(contador1<3){
      bullet = new Bullet(a, v, this->getX(), this->getY());
      d = abs(this->getX()-cannonObjetivo->getX());

      bullet->recorrerDistanciaX(d);
          if(bullet->detectarColision((ObjetoFisico *)cannonObjetivo, radioO, d)){//SI LA ALTURA DE LA BALA SE ENCUENTRA ENTRE (HD-0.05d y HD+0.05d) o (HD-0.025d y HD+0.025d)
            for(float m=0; m<20; m+=1){
                ad = (3.1416/2)*(m/20);
                for(float n=1;n<20;n+=1){
                    if(contador2<3){
                        vd = (100/20)*n;
                        bulletSimulada = new Bullet(a, v, this->getX(), this->getY());//Creo una bala simulada ofensiva
                        bulletDefensiva = new Bullet(ad, -vd, cannonObjetivo->getX(), cannonObjetivo->getY());//Creo una bala defensiva
                        t = (d-vd*cos(ad)*(2.5))/((v*cos(a)+vd*cos(ad)));//Tiempo de encuentro de las dos balas
                        bulletSimulada->recorrerDistanciaT(t);
                        bulletDefensiva->recorrerDistanciaT(t);
                        if(bulletSimulada->detectarColision((ObjetoFisico *)bulletDefensiva, radioD, d)){
                            cout<<"Colisiona"<<endl;
                            cout<<"Angulo fue:"<<a<<endl;
                            cout<<"Velocidad fue:"<<v<<endl;
                            cout<<"Ha destruido la bala ofensiva"<<endl;
                            cout<<"Angulo de la bala defensiva fue:"<<ad<<endl;
                            cout<<"Velocidad de la bala defensiva fue:"<<vd<<endl;
                            cout<<"Tiempo de encuentro es :"<<t<<endl;
                            cout<<"La posicion del encuentro en Y es: "<<bulletDefensiva->getY()<<endl;//ALTURA DE LA BALA OFENSIVA
                            contador2+=1;
                        }
                    }
                    if(contador2==3){
                        break;
                    }
                }
            }
            if(contador2==3){
                break;
            }
          }
      }
      }
  }
}

bool Cannon::generarDisparo5(Cannon *cannonObjetivo, float radioO, float radioD, bool ofensivo)
{
  Bullet *bullet, *bulletSimulada, *bulletDefensiva, *bulletDefensivaSimulada, *bulletNeutralizadora;
  float a, v, t, d, ad, vd, a3, v3;
  int contador1=0;
  int contador2=0;
  int contador3=0;
  for(float i=20;i>=0;i-=1){
    a = (3.1416/2)*(i/20);//ANGULO DEL CAÑON ATACANTE ENTRE 0 Y 90° CON INCREMENTOS DE 5°
    for(float j=0;j<20;j+=1){
    v = (100/20)*j;//VELOCIDAD INICIAL DE LA BALA OFENSIVA-COGER UNA VELOCIDAD MENOR QUE 100METROS CON INCREMENTOS DE 5METROS
    if(contador1<3){
      bullet = new Bullet(a, v, this->getX(), this->getY());
      d = abs(this->getX()-cannonObjetivo->getX());

      bullet->recorrerDistanciaX(d);
          if(bullet->detectarColision((ObjetoFisico *)cannonObjetivo, radioO, d)){//SI LA ALTURA DE LA BALA SE ENCUENTRA ENTRE (HD-0.05d y HD+0.05d) o (HD-0.025d y HD+0.025d)
            for(float m=20; m>=0; m-=1){
                ad = (3.1416/2)*(m/20);
                for(float n=1;n<20;n+=1){
                    if(contador2<3){
                        vd = (100/20)*n;
                        bulletSimulada = new Bullet(a, v, this->getX(), this->getY());
                        bulletDefensiva = new Bullet(ad, -vd, cannonObjetivo->getX(), cannonObjetivo->getY());
                        t = (d-vd*cos(ad)*(2.5))/((v*cos(a)+vd*cos(ad)));
                        bulletSimulada->recorrerDistanciaT(t);
                        bulletDefensiva->recorrerDistanciaT(t);
                        if(bulletSimulada->detectarColision((ObjetoFisico *)bulletDefensiva, radioD, d)){
                            for(float p=0;p<20;p+=1){
                                a3 = (3.1416/2)*(p/20);
                                for(float q=1000;q>0;q-=1){
                                    if(contador3<3){
                                        v3 = (100/20)*q;
                                        bulletDefensivaSimulada = new Bullet(ad, -vd, cannonObjetivo->getX(), cannonObjetivo->getY());
                                        bulletNeutralizadora = new Bullet(a3, v3, this->getX(), this->getY());
                                        t = (d - v3*cos(a3)) / (v3*cos(a3) + vd*cos(ad));
                                        bulletNeutralizadora->recorrerDistanciaT(t);
                                        bulletDefensivaSimulada->recorrerDistanciaT(t);
                                        //cout<<"Tiempo es "<<t<<endl;
                                        //cout<<"Neutralizadora se encuentra en ("<<bulletNeutralizadora->getX()<<", "<<bulletNeutralizadora->getY()<<")"<<endl;
                                        //cout<<"Defensiva se encuentra en ("<<bulletDefensivaSimulada->getX()<<", "<<bulletDefensivaSimulada->getY()<<")"<<endl;
                                        if(bulletNeutralizadora->detectarColision((ObjetoFisico *)bulletDefensivaSimulada, 0.005, d)){
                                            cout<<"Bala neutralizada"<<endl;
                                            cout<<"Angulo que neutraliza fue:"<<a3<<endl;
                                            cout<<"Velocidad que neutraliza fue:"<<v3<<endl;
                                            cout<<"Ha destruido la bala defensiva"<<endl;
                                            cout<<"Angulo de la bala defensiva fue:"<<ad<<endl;
                                            cout<<"Velocidad de la bala defensiva fue:"<<vd<<endl;
                                            cout<<"Tiempo de encuentro es :"<<t<<endl;
                                            cout<<"La posicion del encuentro en Y es: "<<bulletDefensivaSimulada->getY()<<endl;//ALTURA DE LA BALA OFENSIVA
                                            contador3++; }
                                    }
                                    if(contador3==3){
                                        break;
                                    }
                                }
                                if(contador3==3){
                                    break;
                                }
                            }

                        }
                    }

                }
            }
          }
      }
      }
  }
}
