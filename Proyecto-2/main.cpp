
/*
Nombre: Milton Abrego Davila
Matricula: 558202
Fecha: 10/12/2021

Titulo: Cine
Explicacion: Te permite ver las peliculas y sus horas disponibles con los actores que cada pelicula


Doy mi palabra que he realizado esta actividad con integridad academica

*/

#include <iostream>
#include <string>
#include <fstream>
#include "Actor.h"
#include "Funcion.h"
#include "Pelicula.h"

using namespace std;

Actor consActor(string t, Actor a){//lee los actores del documento y los mete al programa
  string actr;
  string num;
  int cont;
  num=t.substr(0,t.find(" "));
  a.setId(stoi(num));
  a.setNombre(t.erase(0,t.find(" ")));

  return a;
}

Pelicula consPeli(string t, Pelicula p){
  int c;
  string titulo;
  string numPeliTxt;
  string yerTxt;
  string durTxt;
  string genero;
  string cantActTxt;
  p.setNumPeli(stoi(t.substr(0,t.find(" "))));
  yerTxt=t.erase(0,t.find(" "));
  yerTxt=t.erase(0,1);
  durTxt=yerTxt.erase(0,yerTxt.find(" "));
  durTxt=yerTxt.erase(0,1);
  genero=durTxt.erase(0,durTxt.find(" "));
  genero=durTxt.erase(0,1);
  cantActTxt=genero.erase(0,genero.find(" "));
  p.setCantAct(stoi(cantActTxt.substr(0,cantActTxt.find(" "))));
  p.setYear(stoi(yerTxt.substr(0,yerTxt.find(" "))));
  p.setDuracion(stoi(durTxt.substr(0,durTxt.find(" "))));
  p.setGenero(genero.substr(0,genero.find(" ")));
  titulo=cantActTxt.erase(0,cantActTxt.find(" "));
  
  for(int i=0;i<=p.getCantAct()-1;i++){
    c=stoi(titulo.substr(1,titulo.find(" ")));
    titulo=titulo.erase(1,titulo.find(" "));
    p.setListAct(i,c);
  }
  p.setTitulo(titulo);
  

  return p;
}

/*Funcion consFun(string t, Funcion f){
  int c;
  string titulo;
  string numPeliTxt;
  string yerTxt;
  string durTxt;
  string genero;
  string cantActTxt;
  numPeliTxt=t.erase(0,t.find(" "));
  yerTxt=numPeliTxt.erase(0,numPeliTxt.find(" "));
  durTxt=yerTxt.erase(0,yerTxt.find(" "));
  genero=durTxt.erase(0,durTxt.find(" "));
  cantActTxt=genero.erase(0,genero.find(" "));
  titulo=cantActTxt.erase(0,cantActTxt.find(" "));
  titulo=titulo.erase(0,titulo.find(" "));
  titulo=titulo.erase(0,titulo.find(" "));
  c=stoi(numPeliTxt.substr(0,numPeliTxt.find(" ")));
  f.setNumPeli(c);
  f.setFuncion(titulo.substr(0,titulo.find(" ")));
  return f;
}*/

int main (){
  int a=0;
  int menu;
  int b=0;
  int input_int;
  int cont=0;
  Reloj r_input;
  Actor act[20];
  Pelicula peli[20];
  Funcion fun[20];
  string t;
  ifstream archOpen;
  archOpen.open("Actores.txt");//aqui se consigue el arrey de actores
  while(!archOpen.eof()){
    cin.ignore();
    getline(archOpen,t);
    act[a] = consActor(t, act[a]);
    a++;
  }
 archOpen.close();
 a=0;
 archOpen.open("Peliculas.txt");//aqui se consigue el arrey de peliculas
  while(!archOpen.eof()){
    cin.ignore();
    getline(archOpen,t);
    peli[a]= consPeli(t, peli[a]);
    a++;
  }
 archOpen.close();

 cout<<"cuantas funciones va a poner?"<<endl;
 cin>>b;
 while(!b>0&&b>20){
   cout<<"cantidad invalida de funciones"<<endl;
   cin>>b;
 }
 for(int i=0;i<=b;i++){
   cout<<"inserte el nombre de la funcion"<<endl;
   cin>>t;
   fun[i].setFuncion(t);
   cout<<"inserte el numero de la pelicula"<<endl;
   cin>>input_int;
   cont=1;
   while(cont<0){//Todo esto es para validar el numero de pelicula
     for(int o=0;o<20;o++){
      if(!peli[o].getNumPeli()==input_int||!cont==0){
        cont++;
      }else
        cont=0;
     }
    if(!cont==0){
      cout<<"numero de pelicula invalido INSERTELO DE NUEVO"<<endl;
      cin>>input_int;
    }
   }
   fun[i].setNumPeli(input_int);
   cout<<"inserte la sala"<<endl;
   cin>>input_int;
   fun[i].setSala(input_int);
   cout<<"inserte la hora de inicio(PRIMERO LA HORA DESPUES LOS MINUTOS)"<<endl;
   cin>>input_int;
   while(!input_int>=0&&!input_int<24){
     cout<<"numero de horas invalido INSERTE DE NUEVO"<<endl;
     cin>>input_int;
   }
   r_input.setHora(input_int);
   cin>>input_int;
   while(!input_int>0&&!input_int<60){
     cout<<"numero de minutos invalido INSERTE DE NUEVO"<<endl;
     cin>>input_int;
   }
   r_input.setMinutos(input_int);
   fun[i].setHora(r_input);
 }

 do{
   cout<<"1) Consultar Actor de la lista"<<endl;
   cout<<"2) Consultar todas las peliculas en la lista"<<endl;
   cout<<"3) Consultar todas las funciones disponibles"<<endl;
   cout<<"4) Consulta funciones por hora"<<endl;
   cout<<"5) Consulta funciones por clave"<<endl;
   cout<<"6) Consulta la participacion de un Actor"<<endl;
   
   cin>>menu;

   switch (menu)
   {
   case 1:
      cout<<"inserte el ID del Actor"<<endl;
      cin>>input_int;
      cont=1;
      while(cont<0){//Todo esto es para validar el numero del Actor
        for(int o=0;o<20;o++){
          if(!act[o].getId()==input_int||!cont==0){
            cont++;
          }else{
            cout<<act[o].getNombre()<<endl;
            break;
            }
        }
        if(!cont==0){
          cout<<"ID de Actor invalido INSERTELO DE NUEVO"<<endl;
          cin>>input_int;
        }
      }
      
     break;

    case 2:
     cout<<"-------------------------------------"<<endl;
     for(int i=0;i<=a;i++){
       cout<<"Titulo: "<<peli[i].getTitulo()<<endl;
       cout<<"Año: "<<peli[i].getYear()<<endl;
       cout<<"Duracion: "<<peli[i].getDuracion()<<endl;
       cout<<"Genero: "<<peli[i].getGenero()<<endl;
       cout<<"Actores:"<<endl;
       for(int o=0;o<=peli[i].getCantAct();o++){
         for(int p=0;p<=20;p++){
           if(peli[i].getListAct(o)==act[p].getId())
              cout<<"       "<<act[p].getNombre()<<endl;
         }
       }
       cout<<"-------------------------------------"<<endl;
     }
     break;

    case 3:
     cout<<"-------------------------------------"<<endl;
     for(int i=0;i<=b;i++){
       cout<<"Funcion: "<<fun[i].getFuncion()<<endl;
       for(int o=0;o<=a;o++){
         if(fun[i].getNumPeli()==peli[o].getNumPeli())
          cout<<"Pelicula: "<<peli[o].getTitulo()<<endl;
       }
       cout<<"Sala: "<<fun[i].getSala()<<endl;
       cout<<"Hora: ";
       fun[i].getHora().muestra();
       cout<<"-------------------------------------"<<endl;
     }
     break;

    case 4:
      cout<<"inserte la hora que busca(PRIMERO LA HORA DESPUES LOS MINUTOS)"<<endl;
      cin>>input_int;
      while(!input_int>=0&&!input_int<24){
        cout<<"numero de horas invalido INSERTE DE NUEVO"<<endl;
        cin>>input_int;
      }
      r_input.setHora(input_int);
      cin>>input_int;
      while(!input_int>0&&!input_int<60){
        cout<<"numero de minutos invalido INSERTE DE NUEVO"<<endl;
        cin>>input_int;
      }
      r_input.setMinutos(input_int);
      cout<<"las siguientes funciones se presentan a esta hora:"<<endl;

      cout<<"-------------------------------------"<<endl;
     for(int i=0;i<=b;i++){
       if(r_input==fun[i].getHora()){
       cout<<"Funcion: "<<fun[i].getFuncion()<<endl;
       for(int o=0;o<=a;o++){
         if(fun[i].getNumPeli()==peli[o].getNumPeli())
          cout<<"Pelicula: "<<peli[o].getTitulo()<<endl;
       }
       cout<<"Sala: "<<fun[i].getSala()<<endl;
       cout<<"Hora: ";
       fun[i].getHora().muestra();
       }
       cout<<"-------------------------------------"<<endl;
     }

     break;

    case 5:
     cout<<"inserte el nombre de la funcion"<<endl;
     cin>>t;
     cout<<"las siguientes funciones se presentan con este nombre:"<<endl;

      cout<<"-------------------------------------"<<endl;
     for(int i=0;i<=b;i++){
       if(t==fun[i].getFuncion()){
       cout<<"Funcion: "<<fun[i].getFuncion()<<endl;
       for(int o=0;o<=a;o++){
         if(fun[i].getNumPeli()==peli[o].getNumPeli())
          cout<<"Pelicula: "<<peli[o].getTitulo()<<endl;
       }
       cout<<"Sala: "<<fun[i].getSala()<<endl;
       cout<<"Hora: ";
       fun[i].getHora().muestra();
       }
       cout<<"-------------------------------------"<<endl;
     }
     break;

    case 6:
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

      for(int i=0;i<=20;i++){
        for(int x=0;x<=peli[i].getCantAct();x++){
          if(input_int==peli[i].getListAct(x)){
            cout<<"Pelicula: "<<peli[i].getTitulo();
            cout<<"Año: "<<peli[i].getYear();
          }
        
        }
      }

     break;
   
   default:
     break;
   }
 }while(!menu==0);
}