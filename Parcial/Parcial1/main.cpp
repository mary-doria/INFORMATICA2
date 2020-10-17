#include <iostream>
#include <cmath>

using namespace std;

int main()
{
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
    case 1:
        cout<<"Ingrese aO(ingresa en radianes):"<<endl;//ANGULO DEL CAÑON ATACANTE
        cin>>aO;//ENTRA EL ANGULO DEL CAÑON ATACANTE
        int contador1=0;
        while(contador1<3){
            v = rand()%100;//VELOCIDAD INICIAL DE LA BALA OFENSIVA
            t = v*cos(aO)/d;//PARA HALLAR EL TIEMPO
            y = HO + v*sin(aO)*t - t*t*(9.8/2);//COMPONENTE EN Y DE LA FORMULA DEL TIRO PARABOLICO
            if(y < HD+ 0.05*d && y > HD-0.05*d){//SI LA ALTURA DE LA BALA SE ENCUENTRA ENTRE HD-0.05d y HD+0.05d
                cout<<"Colisiona"<<endl;
                contador1 += 1;
                cout<<"Velocidad fue"<<v<<endl;
                cout<<"Tiempo es "<<t<<endl;
                cout<<"Y es "<<y<<endl;
            }
        }




    }


    return 0;
}
