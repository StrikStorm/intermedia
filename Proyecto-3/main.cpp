//Milton Abrego Dávila
//558202
//Proyecto 3
//Doy mi palabra de que he realizado esta actividad con integridad academica
//#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <ctype.h>
#include "Reserva.h"
#include "Aparato.h"
#include "Cancha.h"
#include "Hora.h"

using namespace std;


int main(){
    int id,h,m,dur,fin,ID,clav,tiempMax,nH,nM;
    string nClave,t,clave,des;
    char tipo;
    double costo;
    bool conIns,xd;
    int cantPer;
    Servicio *servicios[20];
    Reserva saving;
    Reserva reserva[50];
    ifstream archOpen;
    string linea;
    int cont=0;
    int reservas=0;
    Hora comienso;
    Hora comparar;
    ofstream archExit;
    archOpen.open("Servicios.txt");
    while(archOpen>>clave>>tiempMax>>tipo>>costo){//aqui se registran todos los servicios
        
        if(tipo=='C' || tipo=='E' || tipo=='B'){
            archOpen>>t;
            getline(archOpen,des);

            if(t== "T"){
                conIns= true;
            }else{
                conIns= false;
            }
            
            servicios[cont] = new Aparato(clave, tiempMax, tipo, costo, conIns, des);
        
        }else{
            archOpen>>cantPer;
            getline(archOpen,des);
            servicios[cont] = new Cancha(clave, tiempMax, tipo, costo, cantPer, des);
        }
        cont++;
        
        
    }
    servicios[0]->muestra();
    archOpen.close();
    archOpen.open("Reserva.txt");
    cont=0;
    while(archOpen>>clave>>h>>m>>dur>>id){//aqui se meten todos los registros previos
        reserva[cont].setClave(clave);
        comienso.setHora(h);
        comienso.setMinutos(m);
        reserva[cont].setDuracion(dur);
        reserva[cont].setId(id);
        reserva[cont].setHora(comienso);
        cont++;
        reservas++;
    }
    archOpen.close();
    do{
        cout<<"1. Mostrar servicios disponibles"<<endl;
        cout<<"2. Mostrar lista de reservas"<<endl;
        cout<<"3. Consultar reservaciones por servicio"<<endl;
        cout<<"4. Consultar reservaciones por hora"<<endl;
        cout<<"5. Hacer una reservación"<<endl;
        cin>>fin;
    switch (fin)
    {
    case 1:
        cout<<"----Nuestos servicios disponibles son----"<<endl;
        for(int i=0; i<=19;i++){
            servicios[i]->muestra();
        }
        break;

    case 2:
        cout<<"----Nuestos servicios reservados son----"<<endl;
        
            for(int i=0;i<=reservas;i++){
                for(int c=0; c<=19;c++){
                    if(reserva[i].getClave()==servicios[c]->getClave()){//aqui se despliegan las reservas
                        cout<<"clave: "<<reserva[i].getClave()<<" Hora inicial: ";
                        reserva[i].getHora().muestra();
                        cout<<" Hora final: ";
                        reserva[i].calcHoraFin().muestra();
                        cout<<" con un costo de: "<<servicios[i]->calcCost(reserva[i].getDuracion())<<endl;
                    }
                }
            }
        
        break;

    case 3:
        cout<<"Cual es la ID del lo que decea consultar"<<endl;
            cin>>nClave;
            cout<<"----Nuestras reservaciones con este servicio son----"<<endl;
            for(int i=0;i<=reservas;i++){
                if(reserva[i].getClave()==nClave){
                    for(int c=0; c<=19;c++){
                        if(reserva[i].getClave()==servicios[c]->getClave()){
                            servicios[c]->muestra();
                            cout<<"clave: "<<reserva[i].getClave()<<" Hora inicial: ";
                            reserva[i].getHora().muestra();
                            cout<<"Hora final: ";
                            reserva[i].calcHoraFin().muestra();
                            cout<<" con un costo de: "<<servicios[i]->calcCost(reserva[i].getDuracion())<<endl;
                        }
                    }
                }
            }
        break;

    case 4:
        cout<<"que hora decea checar?(solo la hora, en hora militar)"<<endl;
            cin>>nH;
            cout<<"los minutos"<<endl;
            cin>>nM;
            comparar.setMinutos(nM);
            comparar.setHora(nH);
            for (int i = 0; i <=reservas; i++){
                if(comparar==reserva[i].getHora()){
                    for(int c=0;c<=20;c++){
                        if(reserva[i].getClave()==servicios[c]->getClave()){
                            servicios[c]->muestra(); 
                        }
                    }
                }
            }
        break;
    
    case 5:
        
            cout<<"Cual es SU ID"<<endl;
            cin>>ID;
            //do{
                cout<<"Cual es la id del servicio que dese rentar"<<endl;
                cin>>clave;
                /*for(int i=0; i<=19;i++){
                    if(servicios[i]->getClave()==clave){
                        xd=false;
                    }else{
                        
                        cout<<servicios[i]->getClave()<<endl;
                        xd=true;
                    }
                }
            }while(xd);*/
            cout<<"que hora decea reservar?(solo la hora en hora militar)"<<endl;
            cin>>nH;
            cout<<"los minutos"<<endl;
            cin>>nM;
            cout<<"Cuanto tiempo(en minutos) lo va a rentar?"<<endl;
            cin>>dur;
            comparar.setHora(nH);
            comparar.setMinutos(nM);
            for(int i=0; i<=reservas; i++){
                if(reserva[i].getClave()==clave){
                    for(int c=0;c<=19;c++){
                        if(reserva[i].getClave()==servicios[c]->getClave())
                            if(reserva[i].getHora()==comparar){
                                    cout<<"La hora es icompatible"<<endl;//aqui le advierte que ya hay una reservacion a esa hora
                            if(servicios[c]->getTiempoMax()==dur ){
                                    cout<<"la duración se exede del tiempo limite"<<endl;//aqui se evita que renten por tiempo de mas
                                }
                            }
                    }
                }
        
            }
            comparar.setHora(nH);
            comparar.setMinutos(nM);
            
            saving.setClave(clave);
            saving.setId(ID);
            saving.setHora(comparar);
            saving.setDuracion(dur);
            reserva[reservas+1]=saving;
            reservas++;
            for(int c=0;c<=19;c++){
                if(reserva[reservas].getClave()==servicios[c]->getClave()){
                    cout<<"le costara un total de: "<<servicios[c]->calcCost(dur)<<endl;
                        }
                    }
            
            archExit.open("Reserva.txt");
            for(int i=0; i<=reservas;i++){
                archExit<<reserva[i].getClave()<<" "<<reserva[i].getHora().getHora()<<" "<<reserva[i].getHora().getMinutos()<<" "<<reserva[i].getDuracion()<<" "<<reserva[i].getId()<<endl;//aqui se llena la hoja
            }
            archExit.close();
        break;

    default:
            cout<<"CERRANDO PROGRAMA....."<<endl;

        break;
    
    }
    }while(!fin==0);
}