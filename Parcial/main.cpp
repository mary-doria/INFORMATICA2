#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int HO,HD,d,aO,aD,opcion,t,v;

    cout<<"Ingrese HO"<<endl;
    cin>>HO;
    cout<<"Ingrese HD"<<endl;
    cin>>HD;
    cout<<"Ingrese d"<<endl;
    cin>>d;

    cout<<"Elija una opcion"<<endl;
    cout<<"1. Generar disparos (al menos tres) ofensivos que comprometan la integridad del cañón defensivo"<<endl;
    cout<<"2. Generar disparos (al menos tres) defensivos que comprometan la integridad del cañón ofensivo"<<endl;
    cout<<"3. Dado un disparo ofensivo, generar (al menos tres) disparos defensivos que impida que el cañón defensivo sea destruido sin importar si el cañón ofensivo pueda ser destruido"<<endl;
    cout<<"4. Dado un disparo ofensivo, generar (al emnos tres) disparo defensivos que impidan que los cañones defensivo y ofensivo puedan ser destruidos"<<endl;
    cin>>opcion;

    switch(opcion){
        case 1:
        cout<<"Ingrese la velocidad de la bala"<<endl;
        cin>>v;
        cout<<"Ingrese aO"<<endl;
        cin>>aO;
        //cout<<"Ingrese aD"<<endl;
        //cin>>aD;
        t = v*cos(aO)/d;
        cout<<t<<endl;
        if(HD == HO + v*sin(aO)t - t*t(9.8/2)){
            cout<<"Colisiona"<<endl;
        } else {
            cout<<"No colisiona"<<endl;
        }

    }

    return 0;
}
