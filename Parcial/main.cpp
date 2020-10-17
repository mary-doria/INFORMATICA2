#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int HO,HD,d,aO,aD,opcion;

    cout<<"Ingrese HO"<<endl;
    cin>>HO;
    cout<<"Ingrese HD"<<endl;
    cin>>HD;
    cout<<"Ingrese d"<<endl;
    cin>>d;
    cout<<"Ingrese aO"<<endl;
    cin>>aO;
    cout<<"Ingrese aD"<<endl;
    cin>>aD;

    cout<<"Elija una opcion"<<endl;
    cout<<"1. Generar disparos (al menos tres) ofensivos que comprometan la integridad del cañón defensivo"<<endl;
    cout<<"2. Generar disparos (al menos tres) defensivos que comprometan la integridad del cañón ofensivo"<<endl;
    cout<<"3. Dado un disparo ofensivo, generar (al menos tres) disparos defensivos que impida que el cañón defensivo sea destruido sin importar si el cañón ofensivo pueda ser destruido"<<endl;
    cout<<"4. Dado un disparo ofensivo, generar (al emnos tres) disparo defensivos que impidan que los cañones defensivo y ofensivo puedan ser destruidos"<<endl;
    cin>>opcion;

    return 0;
}
