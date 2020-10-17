#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int HO,HD,d,aO,aD,opcion,t,v;//PARAMETROS DE ENTRADA

    cout<<"Ingrese HO:"<<endl;//ALTURA A LA QUE ESTA EL CAÑON OFENSIVO
    cin>>HO;//ENTRADA DEL CAÑON OFENSIVO AL PROGRAMA
    cout<<"Ingrese HD:"<<endl;//ALTURA DEL CAÑON DEFENSIVO
    cin>>HD;//ENTRADA DEL CAÑON DEFENSIVO AL PROGRAMA
    cout<<"Ingrese d:"<<endl;//ENTRADA DE LA DISTANCIA DE LA POSICION DE LOS 2 CAÑONES
    cin>>d;//ENTRADA DE LA DISTANCIA AL PROGRAMA

    cout<<"Elija una opcion"<<endl;
    cout<<"1. Generar disparos (al menos tres) ofensivos que comprometan la integridad del cañón defensivo"<<endl;
    cout<<"2. Generar disparos (al menos tres) defensivos que comprometan la integridad del cañón ofensivo"<<endl;
    cout<<"3. Dado un disparo ofensivo, generar (al menos tres) disparos defensivos que impida que el cañón defensivo sea destruido sin importar si el cañón ofensivo pueda ser destruido"<<endl;
    cout<<"4. Dado un disparo ofensivo, generar (al emnos tres) disparo defensivos que impidan que los cañones defensivo y ofensivo puedan ser destruidos"<<endl;
    cin>>opcion;

    switch(opcion){
        case 1:
        cout<<"Ingrese la velocidad de la bala:"<<endl;//VELOCIDAD INICIAL DE LA BALA
        cin>>v;
        cout<<"Ingrese aO(ingresa en radianes):"<<endl;//ANGULO DEL CAÑON ATACANTE
        cin>>aO;//ENTRA EL ANGULO DEL CAÑON ATACANTE
        //cout<<"Ingrese aD"<<endl;
        //cin>>aD;
        t = v*cos(aO)/d;//PARA HALLAR EL TIEMPO
        y = HO + v*sin(aO)*t - t*t*(9.8/2);//COMPONENTE EN Y DE LA FORMULA DEL TIRO PARABOLICO
        if(y < HD+ 0.05*d && y > HD-0.05*d){//SI LA ALTURA DE LA BALA SE ENCUENTRA ENTRE HD-0.05d y HD+0.05d
            cout<<"Colisiona"<<endl;
        } else {
            cout<<"No colisiona"<<endl;
        }



    }

    return 0;
}
