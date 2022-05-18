//Milton Abrego Dávila
//558202
//Proyecto 3

#include <iostream>
#include "Hora.h"

using namespace std;
class Reserva{
    public:
        Reserva(){claveServicio= "N/A"; idCliente= 0; horaInicio; duracion= 0;};
        Reserva(string nClave, int nId, Hora nHoraIn, int nDura){claveServicio= nClave; idCliente= nId; horaInicio= nHoraIn; duracion= nDura;};
        string getClave(){return claveServicio;};
        void setDuracion(int nDura){duracion= nDura;};
        void setHora(Hora nHoraIn){horaInicio= nHoraIn;};
        void setId(int nId){idCliente= nId;};
        void setClave(string nClave){claveServicio= nClave;};
        int getId(){return idCliente;};
        Hora getHora(){return horaInicio;};
        int getDuracion(){return duracion;};
        Hora calcHoraFin(){return (horaInicio+duracion);};

    private:
        string claveServicio;
        int idCliente;
        Hora horaInicio;
        int duracion;
};