#include <iostream>
#include <string>
#include <fstream>

using namespace std;


#include "Actor.h"
#include "Hora.h"
#include "Pelicula.h"
#include "Funcion.h"

/*
Milton Abrego Dávila 
558202
18/10/2021
Proyecto 2

Doy mi palabra de que he relizado esta actividad con integridad academica
*/

int main(){
    int id, m, h;
    int ac = 0;
    int a, num, sala, cfun, idp, ok=0, input_int,cont; 
    string ida, actores, peliculas, genero, test, input_string;
    Actor act[20];//almacena datos de los actores
    Funcion fun[20];//almacena datos de las funciones
    Pelicula peli[20];//almacena datos de las pelis
    ifstream af;
    Hora hh, p,hhmm;
    bool comprovar;
    af.open("Actores.txt");
    
    
    while(!af.eof()){ // consigue el id y el actor del txt actor para almacenar en el H
 
        getline(af, ida);
        
        id = stoi(ida.substr(0,ida.find(" ")));
        actores = ida.erase(0,ida.find(" "));
        act[ac].set_id(id);
        act[ac].setNombre(actores);
        ac++;
    }
    af.close();
    string x;
    af.open("Peliculas.txt");
    ac = 0;
    while(!af.eof())
    {
        
        getline(af, ida);
        test = ida.substr(0,ida.find(" "));
        id = stoi(test);
        peli[ac].setNumPeli(id);
        
        ida = ida.erase(0, ida.find(" "));
        ida = ida.erase(0,1);
        test = ida.substr(0,ida.find(" "));
        a = stoi(test);
        peli[ac].setYear(a);
        
        ida = ida.erase(0, ida.find(" "));
        ida = ida.erase(0,1);
        test = ida.substr(0,ida.find(" "));
        m = stoi(test);
        peli[ac].setDuracion(m);
        
        ida = ida.erase(0, ida.find(" "));
        ida = ida.erase(0,1);
        genero = ida.substr(0,ida.find(" "));
        peli[ac].setGenero(genero);
        
        ida = ida.erase(0, ida.find(" "));
        ida = ida.erase(0,1);
        test = ida.substr(0,ida.find(" "));
        num = stoi(test);

        peli[ac].setCantAct(num);
        ida = ida.erase(0, ida.find(" "));
        ida = ida.erase(0,1);
        
        
            for (int e = 0; e < num; e++){
                id = stoi(ida.substr(0,ida.find(" ")));
                ida = ida.erase(0, ida.find(" "));
                ida = ida.erase(0,1);
                peli[ac].setListAct(e, id);
            }
        
        peli[ac].setTitulo(ida);
        ac++;

    }
    
    
        cout<<"Cuantas funciones desea ingresar? "<<endl;
        cin>>cfun;
        for (int i = 0; i < cfun; i++)
        {
            cout<<"------------------------------------------------"<<endl;
            cout<<"Nueva Funcion: "<<i+1<<endl;
            cout<<"Hora que es? "<<endl;
            cin >> h;
            while((0<h)&&(24<h)){
                cout<<"numero de horas invalido INSERTE DE NUEVO"<<endl;
                cin>>h;
            }
            cout << "En que Minuto es? "<<endl;
            cin >> m;
            while((0<m)&&(60<m)){
                cout<<"numero de minutos invalido INSERTE DE NUEVO"<<endl;
                cin>>m;
            }
            cout<<m<<endl;
            cout<<"En que sala quiere la nueva funcion? "<<endl;
            cin>> sala;
            cout<<"ID (Nombre) de la funcion: "<<endl;
            cin>>ida;
            cout<<"ID de la Pelicla que se mostrara"<<endl;
            cin>>id;
            cont=1;
            while(cont<0){//Todo esto es para validar el numero de pelicula
                for(int o=0;o<20;o++){
                    if(peli[o].getNumPeli()!=id||cont!=0){
                        cont++;
                    }else
                        cont=0;
                    }
                    if(cont!=0){
                        cout<<"numero de pelicula invalido INSERTELO DE NUEVO"<<endl;
                        cin>>id;
                    }
            }
            hhmm.setHora(h);
            hhmm.setMinutos(m);
            fun[i].setSala(sala);
            fun[i].setFuncion(ida);
            fun[i].setNumPeli(id);
            fun[i].setHora(hhmm);
        }
        


int opcion=1;
    do{
        cout<<"================================================"<<endl;
        cout << "1) Lista de Actores" << endl;
        cout << "2) Lista de peliculas" << endl;
        cout << "3) Funciones Disponibles" << endl;
        cout << "4) Consultar funciones por Hora" << endl;
        cout << "5) Consulta por clave una Funcion" << endl;
        cout << "6) Consulta lista de peliculas que participa un actor" << endl;
        cout << "7) Terminar" << endl;
        cout<<"================================================="<<endl;
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            for (int i = 0; i < 20; i++)//imprime lista de actores con sus ids
            {
                cout<<"------------------------------------------------"<<endl;
                cout<<"ID: "<<act[i].getId()<<endl;
                cout<<"Actor: "<<act[i].getNombre()<<endl;
                cout<<"------------------------------------------------"<<endl;   
            }
            break; 

        case 2: 
            for (int i = 0; i < ac; i++)//imprime los datos de las peliculas
            {
                cout<<"------------------------------------------------"<<endl;
                cout<<"Titulo: "<<peli[i].getTitulo()<<endl;
                cout<<"Anio: "<<peli[i].getYear()<<endl;
                cout<<"Duracion: "<<peli[i].getDuracion()<<" Minutos"<<endl;
                cout<<"Genero: "<<peli[i].getGenero()<<endl;
                cout<<"Actores en la pelicula: ";
                for (int x = 0; x < peli[i].getCantAct(); x++)
                {
                    cout<<peli[i].getListAct(x);
                    cout<<". ";
                }
                cout<<endl;
                cout<<"------------------------------------------------"<<endl;   
            }
            break;


        case 3: //se hare un for que despliega las funciones
            for (int i = 0; i < cfun; i++)
            {
                cout<<"------------------------------------------------"<<endl;
                cout<<"Sala: "<<fun[i].getSala()<<endl;
                cout<<"Hora: "; fun[i].getHora().muestra();
                cout<<"Numero de Peli: "<<fun[i].getNumPeli()<<endl;
                cout<<"ID: "<<fun[i].getFuncion()<<endl;
                cout<<"------------------------------------------------"<<endl;
            }
            
            break;

        case 4: //despliega las funciones en orden de hora
        
            cout<<"Hora de Inicio es? "<<endl;
            cin >> h;
            cout << "Minuto de Inicio es? "<<endl;
            cin >> m;
            if(0>=h<=23 && 0>=m<=59){
            for (int j = 0; j < cfun; j++)
            {
                if (h == fun[j].getHora().getHora() && m == fun[j].getHora().getMinutos())
                {
                    for (int g = 0; g < 20; g++)
                    {
                        if(fun[j].getNumPeli() == peli[g].getNumPeli()){
                            cout<<"------------------------------------------------"<<endl;
                            cout<<"El Titulo de la Pelicula es: "<<peli[g].getTitulo()<<endl;
                            cout<<"En La sala: "<<fun[j].getSala()<<endl;
                            cout<<"------------------------------------------------"<<endl;
                            
                        }
                    }
                    
                }
                else cout<<"********Hora no valida******** "<<endl;
            }
            
            
        }else cout<<"********Hora no valida******** "<<endl;
            break;


        case 5: //Consulta por id de la funcion y le pide al usario el id
            cout<<"Clave de la Funcion: "<<endl;
            cin>>ida;
            for (int i = 0; i < cfun; i++)
            {
                if (ida == fun[i].getFuncion())
                {
                    cout<<"------------------------------------------------"<<endl;
                    cout<<"La Sala de la Funcion: "<<fun[i].getSala()<<endl;
                    for (int x = 0; x < 20; x++)
                    {
                        if(peli[x].getNumPeli() == fun[i].getNumPeli())
                        {
                            cout<<"Titulo: "<<peli[x].getTitulo()<<endl;
                            cout<<"Duracion (En Minutos): "<<peli[x].getDuracion()<<endl;
                            cout<<"Genero: "<<peli[x].getGenero()<<endl;
                            cout<<"Actores que participan en la Pelicula: ";
                            for (int c = 0; c < peli[x].getCantAct(); c++)
                            {
                                cout<<peli[x].getListAct(c)<<". ";

                            }
                            cout<<endl;
                        }
                    }
                    cout<<"Hora de la Funcion: "; fun[i].getHora().muestra();
                    cout<<"------------------------------------------------"<<endl;
                }
               else cout<<"********No existe esta clave***********"<<endl; 
            }
            
            break;

        case 6: //ve las pelis que particia un actor.

            cout<<"ingrese el ID del Actor"<<endl;
            cin>>input_int;

            cont=1;
             while(cont<0){//Todo esto es para validar el actor
                for(int o=0;o<20;o++){
                if(!act[o].getId()==input_int||!cont==0){
                    cont++;
                }else
                    cont=0;
                }
                if(!cont==0){
                    cout<<"ID de actor Invalido INSERTELO DE NUEVO"<<endl;
                    cin>>input_int;
                }
            }

            for(int i=0;i<=19;i++){
                for(int x=0;x<=peli[i].getCantAct()-1;x++){
                    if(input_int==peli[i].getListAct(x)){
                        cout<<"------------------------------------------------"<<endl;
                        cout<<"Pelicula: "<<peli[i].getTitulo()<<endl;
                        cout<<"Año: "<<peli[i].getYear()<<endl;
                        cout<<"------------------------------------------------"<<endl;
                    }
        
                }
            }

        break;

        default:
            break;
        }
    }while(opcion!=7);




    return 0;
}