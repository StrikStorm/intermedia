//Milton Abrego Dávila
//558202
//Proyecto 3
#include <iostream>
#include "Servicio.h"

using namespace std;
class Cancha:public Servicio{
    public:
        Cancha();
        Cancha(string clave, int, char, double , int , string );
        double getCost(){return costXHora;};
        int getCantMaxPer(){return cantMaxPer;};
        string getDeporte(){return deporte;};
        void setCosto(double costN){costXHora=costN;};
        void setCantMaxPer(int cantN){cantMaxPer=cantN;};
        void setDeporte(string depN){deporte=depN;};
        double calcCost(int t){return(t*getCost());};
        void muestra();

    private:
        double costXHora;
        int cantMaxPer;
        string deporte;
};

Cancha::Cancha():Servicio(){
    costXHora=0;
    cantMaxPer=0;
    deporte="N/A";
}

Cancha::Cancha(string n_clave, int n_tiempMax, char n_tipo, double a, int b, string c):Servicio(n_clave,n_tiempMax,n_tipo){
    costXHora=a;
    cantMaxPer=b;
    deporte=c;
    }

void Cancha::muestra(){
    cout<<"clave: "<<clave<<" Tiempo maximo: "<<tiempMax<<" Tipo: "<<tipo<<" Costo por Hora: "<<costXHora<<
    " Cantidad maxima de personas: "<<cantMaxPer<<" Deporte: "<<deporte<<endl;
}