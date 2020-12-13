#include <iostream>
#include <cannon.h>
#include <bullet.h>
#include <objetofisico.h>


using namespace std;

int main()
{int d,HD,HO;

    int opcion;
        cout<<"Elija una opcion"<<endl;
        cout<<"1. Generar disparos (al menos tres) ofensivos que comprometan la integridad del canon defensivo"<<endl;
        cout<<"2. Generar disparos (al menos tres) defensivos que comprometan la integridad del canon ofensivo"<<endl;
        cout<<"3. Dado un disparo ofensivo, generar (al menos tres) disparos defensivos que impida que el canon defensivo sea destruido sin importar si el canon ofensivo pueda ser destruido"<<endl;
        cout<<"4. Dado un disparo ofensivo, generar (al emnos tres) disparo defensivos que impidan que los canones defensivo y ofensivo puedan ser destruidos"<<endl;
        cout<<"5. Dado un disparo ofensivo efectivo y un disparo defensivo que comprometa la "<<endl;
        cout<<"efectividad del ataque ofensivo, generar (al menos tres) disparos que neutralicen el ataque defensivo y permitan que el ataque ofensivo sea efectivo."<<endl;
        cin>>opcion;

        switch(opcion){
        case 1:{Cannon * cannon_defensivo=new Cannon(0,HD);//Crear un puntero ,que contenga la posicion del canon defensivo



        }
            break;
         case 2:{
         ;}
            break;
          case 3:{
         ;
          }
            break;
        case 4:{
          ;
          }
        case 5:{
          ;
          }
}}

