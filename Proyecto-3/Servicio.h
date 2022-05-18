//Milton Abrego Dávila
//558202
//Proyecto 3
#ifndef SERVICIO_H_
#define SERVICIO_H_
#include <iostream>

using namespace std;
class Servicio{
    public:
        Servicio(){clave="N/A"; tiempMax=0; tipo=' ';};
        Servicio(string a, int b, char c){clave= a; tiempMax= b; tipo= c;};
        string getClave(){return clave;};
        int getTiempoMax(){return tiempMax;};
        char getTipo(){return tipo;};
        virtual double calcCost(int)=0;
        virtual void muestra()=0;
    
    protected:
        string clave;
        int tiempMax;
        char tipo;
};

#endif