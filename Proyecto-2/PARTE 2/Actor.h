#ifndef ACTOR__H__
#define ACTOR__H__
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
class Actor {
    private://Atributos
		  int id;
 		  string nombre;

    public:
        //Constructor
      Actor();
	  Actor(int, string);
	  int getId();
	  string getNombre();
	  void setId(int);
	  void setNombre(string);

	};
	
	Actor::Actor(){
		id=0;
		nombre="";
	}
	Actor::Actor(int clav ,string namae){
		id= clav;
		nombre= namae;
	}


    //Metodos de acceso
		int Actor::getId(void){return id;}
		string Actor::getNombre(void){return nombre;}

        //Metodos de modificacion
		void Actor::setId(int nuevoId){id= nuevoId;}
		void Actor::setNombre(string nuevoNombre){nombre= nuevoNombre;}

#endif
