#include <iostream>
#include <cannon.h>
#include <bullet.h>
#include <objetofisico.h>


using namespace std;

int main()
{   cout<<"Pautas para ingresar HO y HD:"<<endl;
    cout<<"1.HD en el primer caso y tercer caso debe ser mayor que HO ,ya que si no lo es el angulo de "<<endl;
    cout<<"disparo seria mayor de 90 grados y no tiene sentido que sea negativo "<<endl;
    cout<<"2.HO en el segundo caso y quinto caso debe ser mayor que HD ,ya que si no lo es el angulo de "<<endl;
    cout<<"disparo seria mayor de 90 grados y no tiene sentido que sea negativo" <<endl;
    int d,HD,HO;

    cout<<"Ingrese HO:"<<endl;//ALTURA A LA QUE ESTA EL CAÑON OFENSIVO
    cin>>HO;//ENTRADA DEL CAÑON OFENSIVO AL PROGRAMA
    cout<<"Ingrese HD:"<<endl;//ALTURA DEL CAÑON DEFENSIVO
    cin>>HD;//ENTRADA DEL CAÑON DEFENSIVO AL PROGRAMA
    cout<<"Ingrese d:"<<endl;//ENTRADA DE LA DISTANCIA DE LA POSICION DE LOS 2 CAÑONES
    cin>>d;//ENTRADA DE LA DISTANCIA AL PROGRAMA

    int opcion;
    cout<<"Elija una opcion"<<endl;
    cout<<"1. Generar disparos (al menos tres) ofensivos que comprometan la integridad del canon defensivo"<<endl;
    cout<<"2. Generar disparos (al menos tres) defensivos que comprometan la integridad del canon ofensivo"<<endl;
    cout<<"3. Dado un disparo ofensivo, generar (al menos tres) disparos defensivos que impida que el canon defensivo sea destruido sin importar si el canon ofensivo pueda ser destruido"<<endl;
    cout<<"4. Dado un disparo ofensivo, generar (al emnos tres) disparo defensivos que impidan que los canones defensivo y ofensivo puedan ser destruidos"<<endl;
    cout<<"5. Dado un disparo ofensivo efectivo y un disparo defensivo que comprometa la "<<endl;
    cout<<"efectividad del ataque ofensivo, generar (al menos tres) disparos que neutralicen el ataque defensivo"<<endl;
    cout<<" y permitan que el ataque ofensivo sea efectivo."<<endl;
    cin>>opcion;

    switch(opcion){
    case 1:{
        Cannon * cannon_ofensivo=new Cannon(d,HO);//Crear un puntero ,que contenga la posicion del canon ofensivo
        Cannon * cannon_defensivo=new Cannon(0,HD);//Crear un puntero ,que contenga la posicion del canon defensivo
        bool colisiona = cannon_ofensivo->generarDisparo(cannon_defensivo, 0.05, 1);

    }
        break;
     case 2:{
        Cannon * cannon_ofensivo=new Cannon(d,HO);//Crear un puntero ,que contenga la posicion del canon ofensivo
        Cannon * cannon_defensivo=new Cannon(0,HD);//Crear un puntero ,que contenga la posicion del canon defensivo
        bool colisiona = cannon_defensivo->generarDisparo(cannon_ofensivo, 0.025, 1);
     ;}
        break;
      case 3:{
        Cannon * cannon_ofensivo=new Cannon(d,HO);//Crear un puntero ,que contenga la posicion del canon ofensivo
        Cannon * cannon_defensivo=new Cannon(0,HD);//Crear un puntero ,que contenga la posicion del canon defensivo
        bool colisiona = cannon_ofensivo->generarDisparo3(cannon_defensivo, 0.05, 0.025, 1);
      }
        break;
    case 4:{cout<<"NO SE REALIZO"<<endl;
      ;
      }
    case 5:{
        Cannon * cannon_ofensivo=new Cannon(d,HO);//Crear un puntero ,que contenga la posicion del canon ofensivo
        Cannon * cannon_defensivo=new Cannon(0,HD);//Crear un puntero ,que contenga la posicion del canon defensivo
        bool colisiona = cannon_ofensivo->generarDisparo5(cannon_defensivo, 0.05, 0.025, 1);

      }
}}

