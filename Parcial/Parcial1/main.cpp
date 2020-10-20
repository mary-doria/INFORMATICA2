/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

void generar_disparo(float HO,float HD, float d,float radio, bool ofensivo);

int main()
{//EN EL OFENSIVO SERIA (0,H0) EN EL DEFENSIVO SERIA(D,HD)
    float HO,HD,d,aO,aD,y,t,v;//PARAMETROS DE ENTRADA
    int opcion;

    cout<<"Ingrese HO:"<<endl;//ALTURA A LA QUE ESTA EL CAÑON OFENSIVO
    cin>>HO;//ENTRADA DEL CAÑON OFENSIVO AL PROGRAMA
    cout<<"Ingrese HD:"<<endl;//ALTURA DEL CAÑON DEFENSIVO
    cin>>HD;//ENTRADA DEL CAÑON DEFENSIVO AL PROGRAMA
    cout<<"Ingrese d:"<<endl;//ENTRADA DE LA DISTANCIA DE LA POSICION DE LOS 2 CAÑONES
    cin>>d;//ENTRADA DE LA DISTANCIA AL PROGRAMA

    cout<<"Elija una opcion"<<endl;
    cout<<"1. Generar disparos (al menos tres) ofensivos que comprometan la integridad del cañón defensivo"<<endl;
    cout<<"2. Generar disparos (al menos tres) defensivos que comprometan la integridad del cañón ofensivo"<<endl;
    cout<<"3. Dado un disparo ofensivo, generar (al menos tres) disparos defensivos que impida que el canón defensivo sea destruido sin importar si el cañón ofensivo pueda ser destruido"<<endl;
    cout<<"4. Dado un disparo ofensivo, generar (al emnos tres) disparo defensivos que impidan que los canones defensivo y ofensivo puedan ser destruidos"<<endl;
    cin>>opcion;

    switch(opcion){
    case 1:{
      generar_disparo(HO,HD,d,0.05,true);
      }
        break;
     case 2:{
      generar_disparo(HO,HD,d,0.025,false);
        /*cout<<"Ingrese aD(ingresa en radianes):"<<endl;//ANGULO DEL CAÑON DEFENSOR
        cin>>aD;//ENTRA EL ANGULO DEL CAÑON DEFENSOR
        int contador1=0;
        while(contador1<3){
            v = rand()%100;//VELOCIDAD INICIAL DE LA BALA DEFENSIVA
            t = -v*cos(aD)/d;//PARA HALLAR EL TIEMPO
            y = HD + v*sin(aD)*t - t*t*(9.8/2);//COMPONENTE EN Y DE LA FORMULA DEL TIRO PARABOLICO
            if(y < HO+ 0.025*d & y > HO-0.025*d){//SI LA ALTURA DE LA BALA SE ENCUENTRA ENTRE HO-0.025d y HO+0.025d
                cout<<"Colisiona"<<endl;
                contador1 += 1;
                cout<<"Velocidad fue:"<<v<<endl;
                cout<<"Tiempo es: "<<t<<endl;
                cout<<"Y es :"<<y<<endl;//ALTURA DE LA BALA DEFENSIVA
            }
        }*/}
        break;
      case 3:{

      }

    }




    }

void generar_disparo(float HO,float HD, float d,float radio, bool ofensivo){
      float a, v, t, y;
      int contador1=0;
      for(float i=0;i<20;i+=1){
        //cout<<"Ingrese aO(ingresa en radianes):"<<endl;//ANGULO DEL CAÑON ATACANTE
        //cin>>aO;//ENTRA EL ANGULO DEL CAÑON ATACANTE
        a = (3.1416/2)*(i/20);//ANGULO DEL CAÑON ATACANTE ENTRE 0 Y 90° CON INCREMENTOS DE 5°
        for(float j=0;j<20;j+=1){
           v = (100/20)*j;//VELOCIDAD INICIAL DE LA BALA OFENSIVA-COGER UNA VELOCIDAD MENOR QUE 100METROS CON INCREMENTOS DE 5METROS
          if(contador1<3){
              t = v*cos(a)/d;//PARA HALLAR EL TIEMPO EN LA COMPONENTE X SEGUN LA FORMULA DEL MOVIEMIENTO PARABOLICO
              y = HO + v*sin(a)*t - t*t*(9.8/2);//COMPONENTE EN Y DE LA FORMULA DEL TIRO PARABOLICO
              //cout<<"Velocidad fue:"<<v<<endl;
               //   cout<<"Tiempo es :"<<t<<endl;
                //  cout<<"Y es: "<<y<<endl;
              if(y < HD+ radio*d & y > HD-radio*d){//SI LA ALTURA DE LA BALA SE ENCUENTRA ENTRE HD-0.05d y HD+0.05d
                  //SE DA A ENTENDER SI LA ALTURA DE LA BALA ESTA A 0.05*d O MENOS DEL CAÑON DEFENSOR
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
        }

      }

}
