#include <iostream>
#include <cmath>

using namespace std;

void generar_disparo(float HO,float HD, float d,float radio, bool ofensivo);
void generar_disparo_defensivo(float HO,float HD, float d,float radioOfensivo, float radioDefensivo);
void generar_disparo_defensivo_2(float HO,float HD, float d,float radioOfensivo, float radioDefensivo);


int main()
{//EN EL OFENSIVO SERIA (0,H0) EN EL DEFENSIVO SERIA(D,HD)
    float HO,HD,d;//PARAMETROS DE ENTRADA
    int opcion;

    cout<<"Ingrese HO:"<<endl;//ALTURA A LA QUE ESTA EL CAÑON OFENSIVO
    cin>>HO;//ENTRADA DEL CAÑON OFENSIVO AL PROGRAMA
    cout<<"Ingrese HD:"<<endl;//ALTURA DEL CAÑON DEFENSIVO
    cin>>HD;//ENTRADA DEL CAÑON DEFENSIVO AL PROGRAMA
    cout<<"Ingrese d:"<<endl;//ENTRADA DE LA DISTANCIA DE LA POSICION DE LOS 2 CAÑONES
    cin>>d;//ENTRADA DE LA DISTANCIA AL PROGRAMA

    cout<<"Elija una opcion"<<endl;
    cout<<"1. Generar disparos (al menos tres) ofensivos que comprometan la integridad del canon defensivo"<<endl;
    cout<<"2. Generar disparos (al menos tres) defensivos que comprometan la integridad del canon ofensivo"<<endl;
    cout<<"3. Dado un disparo ofensivo, generar (al menos tres) disparos defensivos que impida que el canon defensivo sea destruido sin importar si el canon ofensivo pueda ser destruido"<<endl;
    cout<<"4. Dado un disparo ofensivo, generar (al emnos tres) disparo defensivos que impidan que los canones defensivo y ofensivo puedan ser destruidos"<<endl;
    cin>>opcion;

    switch(opcion){
    case 1:{
      generar_disparo(HO,HD,d,0.05,true);}
        break;
     case 2:{
      generar_disparo(HD,HO,d,0.025,false);}
        break;
      case 3:{
      generar_disparo_defensivo(HO,HD,d,0.05,0.025);
      }
        break;
    case 4:{
      generar_disparo_defensivo_2(HO,HD,d,0.05,0.025);
      }

    }}


void generar_disparo(float HO,float HD, float d,float radio, bool ofensivo){
    //a: angulo de disparo
    //radio:radio de impacto segun el canon que dispare
    //ofensivo: es un booleano que indica cual de los dos canones fue el que genero los 3 disparos
      float a, v, t, y;
      int contador1=0;
      for(float i=0;i<20;i+=1){
        a = (3.1416/2)*(i/20);//ANGULO DEL CAÑON ATACANTE ENTRE 0 Y 90° CON INCREMENTOS DE 5°
        for(float j=0;j<20;j+=1){
        v = (100/20)*j;//VELOCIDAD INICIAL DE LA BALA OFENSIVA-COGER UNA VELOCIDAD MENOR QUE 100METROS CON INCREMENTOS DE 5METROS
        if(contador1<3){
          t = d/(v*cos(a));//PARA HALLAR EL TIEMPO EN LA COMPONENTE X SEGUN LA FORMULA DEL MOVIEMIENTO PARABOLICO
          y = HO +(v*sin(a)*t) - (t*t*(9.8/2));//COMPONENTE EN Y DE LA FORMULA DEL TIRO PARABOLICO
              if(HD < y+ radio*d & HD > y-radio*d){//SI LA ALTURA DE LA BALA SE ENCUENTRA ENTRE (HD-0.05d y HD+0.05d) o (HD-0.025d y HD+0.025d)
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
        }}}

void generar_disparo_defensivo(float HO,float HD, float d,float radioOfensivo, float radioDefensivo){
    float a, v, t, y;
    float ad, vd, t1, yO, yD;
    int contador1=0;
    int contador2=0;
    for(float i=0;i<20;i+=1){
      a = (3.1416/2)*(i/20);//ANGULO DEL CAÑON ATACANTE ENTRE 0 Y 90° CON INCREMENTOS DE 5°
      for(float j=0;j<20;j+=1){
        v = (100/20)*j;//VELOCIDAD INICIAL DE LA BALA OFENSIVA-COGER UNA VELOCIDAD MENOR QUE 100METROS CON INCREMENTOS DE 5METROS
        t = d/(v*cos(a));//PARA HALLAR EL TIEMPO EN LA COMPONENTE X SEGUN LA FORMULA DEL MOVIEMIENTO PARABOLICO
        y = HO + (v*sin(a)*t) - (t*t*(9.8/2));//COMPONENTE EN Y DE LA FORMULA DEL TIRO PARABOLICO
        if(y < HD+ radioOfensivo*d & y > HD-radioOfensivo*d){//SI LA ALTURA DE LA BALA SE ENCUENTRA ENTRE (HD-0.05d y HD+0.05d) o (HD-0.025d y HD+0.025d)
        //SE DA A ENTENDER SI LA ALTURA DE LA BALA ESTA A 0.05*d O MENOS DEL CAÑON DEFENSOR

        contador1 += 1;

        for(float m=0;m<20;m+=1){
            ad = (3.1416/2)*(m/20);//ANGULO DEL CAÑON DEFENSOR ENTRE 0 Y 90° CON INCREMENTOS DE 5°
            for(float n=0;n<20;n+=1){
                if(contador2<3){
                    vd = (100/20)*n;//VELOCIDAD INICIAL DE LA BALA DEFENSIVA-COGER UNA VELOCIDAD MENOR QUE 100METROS CON INCREMENTOS DE 5METROS
                    t1=(d+vd*cos(ad)*(2.5))/((v*cos(a)+vd*cos(ad)));//
                    yO = HO + (v*sin(a)*t1) - (t1*t1*(9.8/2));
                    yD = HD + (vd*sin(ad)*t1) - (t1*t1*(9.8/2));
                    //cout<<"Posicion yd "<<yD<<" yO "<<yO<<endl;
                    if ((yO < yD+ radioDefensivo*d) & (yO > yD-radioDefensivo*d)){
                        cout<<"Colisiona"<<endl;
                        cout<<"Angulo fue:"<<a<<endl;
                        cout<<"Velocidad fue:"<<v<<endl;

                        cout<<"Ha destruido la bala ofensiva"<<endl;
                        cout<<"Angulo de la bala defensiva fue:"<<ad<<endl;
                        cout<<"Velocidad de la bala defensiva fue:"<<vd<<endl;
                        cout<<"Tiempo de encuentro es :"<<t1<<endl;
                        cout<<"La posicion del encuentro en Y es: "<<yD<<endl;//ALTURA DE LA BALA OFENSIVA
                        contador2+=1;
                    }
                }
                if(contador2==3){
                    break;
                }
            }
            if(contador2==3){
                break;
            }
        }
        if(contador2==0){
            cout<<"La bala defensiva impacta a la ofensiva"<<endl;
        }

        }
      }}
}

void generar_disparo_defensivo_2(float HO,float HD, float d,float radioOfensivo, float radioDefensivo){
    float a, v, t, y;
    float ad, vd, t1, yO, yD, yD1;
    int contador1=0;
    int contador2=0;
    for(float i=0;i<20;i+=1){
      a = (3.1416/2)*(i/20);//ANGULO DEL CAÑON ATACANTE ENTRE 0 Y 90° CON INCREMENTOS DE 5°
      for(float j=0;j<20;j+=1){
        v = (100/20)*j;//VELOCIDAD INICIAL DE LA BALA OFENSIVA-COGER UNA VELOCIDAD MENOR QUE 100METROS CON INCREMENTOS DE 5METROS
        t = d/(v*cos(a));//PARA HALLAR EL TIEMPO EN LA COMPONENTE X SEGUN LA FORMULA DEL MOVIEMIENTO PARABOLICO
        y = HO + (v*sin(a)*t) - (t*t*(9.8/2));//COMPONENTE EN Y DE LA FORMULA DEL TIRO PARABOLICO
        if(y < HD+ radioOfensivo*d & y > HD-radioOfensivo*d){//SI LA ALTURA DE LA BALA SE ENCUENTRA ENTRE (HD-0.05d y HD+0.05d) o (HD-0.025d y HD+0.025d)
        //SE DA A ENTENDER SI LA ALTURA DE LA BALA ESTA A 0.05*d O MENOS DEL CAÑON DEFENSOR

        contador1 += 1;

        for(float m=0;m<20;m+=1){
            ad = (3.1416/2)*(m/20);//ANGULO DEL CAÑON DEFENSOR ENTRE 0 Y 90° CON INCREMENTOS DE 5°
            for(float n=0;n<20;n+=1){
                if(contador2<3){
                    vd = (100/20)*n;//VELOCIDAD INICIAL DE LA BALA DEFENSIVA-COGER UNA VELOCIDAD MENOR QUE 100METROS CON INCREMENTOS DE 5METROS
                    t1=(d+vd*cos(ad)*(2.5))/((v*cos(a)+vd*cos(ad)));
                    yO = HO + (v*sin(a)*t1) - (t1*t1*(9.8/2));
                    yD = HD + (vd*sin(ad)*t1) - (t1*t1*(9.8/2));
                    yD1 = HD + (vd*sin(ad)*t) - (t*t*(9.8/2));
                    //cout<<"Posicion yd "<<yD<<" yO "<<yO<<endl;
            if ((yO < yD+ radioDefensivo*d) & (yO > yD-radioDefensivo*d)){//REVISA SI LA BALA OFENSIVA ESTA EN EL RANGO DE LA BALA DEFENSIVA
                if (!(HO < yD1+ radioDefensivo*d) & (HO > yD1-radioDefensivo*d)){//REVISA SI LA BALA DEFENSIVA NO COLISIONA CON EL CANON OFENSIVO
                    cout<<"Colisiona"<<endl;
                    cout<<"Angulo fue:"<<a<<endl;
                    cout<<"Velocidad fue:"<<v<<endl;

                    cout<<"Ha destruido la bala ofensiva"<<endl;
                    cout<<"Angulo de la bala defensiva fue:"<<ad<<endl;
                    cout<<"Velocidad de la bala defensiva fue:"<<vd<<endl;
                    cout<<"Tiempo de encuentro es :"<<t1<<endl;
                    cout<<"La posicion del encuentro en Y es: "<<yD<<endl;//ALTURA DE LA BALA OFENSIVA
                            contador2+=1;
                        }

                    }
                }
                if(contador2==3){
                    break;
                }
            }
            if(contador2==3){
                break;
            }
        }
        if(contador2==0){
            cout<<"La bala defensiva impacta a la ofensiva pero destruye al canon ofensivo"<<endl;
        }

        }
      }}
}
