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
	  void set_id(int a){id=a;};
	  void setNombre(string b){nombre=b;};

	};
	
	Actor::Actor(){
		id=0;
		nombre="N/A";
	}
	Actor::Actor(int clav ,string namae){
		id= clav;
		nombre= namae;
	}


    //Metodos de acceso
		int Actor::getId(void){return id;}
		string Actor::getNombre(void){return nombre;}

#endif
