//Milton Abrego Dávila
//558202
//Proyecto 3
#include <iostream>
#include "Servicio.h"

using namespace std;
class Aparato:public Servicio {
    public:
        Aparato();
        Aparato(string clave, int tiempMax, char tipo, double nA, bool nB, string nS);
        double getCosto(){return costX15Min;};
        bool getInstructor(){return conIns;};
        string getDescripcion(){return des;};
        void setCosto(double nA){costX15Min= nA;};
        void setInstructor(bool nB){conIns= nB;};
        void setDescripcion(string nS){des=nS;};
        double calcCost(int );
        void muestra();
    
    private:
        double costX15Min;
        bool conIns;
        string des;


};

Aparato::Aparato():Servicio(){
    costX15Min=0;
    conIns=false;
    des="N/A";
}

Aparato::Aparato(string clave, int tiempMax, char tipo, double nA, bool nB, string nS):Servicio(clave, tiempMax,tipo){
    costX15Min= nA;
    conIns= nB;
    des= nS;
}

double Aparato::calcCost(int t){
    int cont=0;
    do{
        if(t>0){
            t=t-15;
            cont++;
        }
    }while(t>0);
    return(cont*getCosto());
}

void Aparato::muestra(){
    if(conIns){
        cout<<"clave: "<<clave<<" Tiempo maximo: "<<tiempMax<<" Tipo: "<<tipo<<" Costo cada 15 minutos: "<<costX15Min<<
        " Tiene instructor: "<<"SI"<<endl<<" Descripcion: "<<des<<endl;
    }else{
        cout<<"clave: "<<clave<<" Tiempo maximo: "<<tiempMax<<" Tipo: "<<tipo<<" Costo cada 15 minutos: "<<costX15Min<<
        " Tiene instructor: "<<"No"<<endl<<" Descripcion: "<<des<<endl;
    }
}