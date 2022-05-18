#ifndef FUNCION__H__
#define FUNCION__H__
#include <iostream>
#include <string>
#include <fstream>
#include "Hora.h"

using namespace std;
class Funcion {
    private:
        //Atributos
		string funcion;
 		int numPeli;
 		Hora hora;
 		int sala;

    public:
        //Constructor
        Funcion(string, int, Hora,int);
		Funcion();
		string getFuncion();
		int getNumPeli();
		Hora getHora();
		int getSala();
		void setFuncion(string);
		void setNumPeli(int);
		void setHora(Hora);
		void setSala(int);
	};
Funcion::Funcion(){
	funcion = "N/A";
	numPeli=0;
	hora;
	sala=0;
}

Funcion::Funcion(string nuevoFuncion, int nuevoNumPeli, Hora nuevoHora,int nuevoSala){
	funcion= nuevoFuncion;
	numPeli= nuevoNumPeli;
	hora= nuevoHora;
	sala= nuevoSala;
}
        //Metodos de acceso
		string Funcion::getFuncion(){
			return funcion;
			}

		int Funcion::getNumPeli(){
			return numPeli;
			}

		Hora Funcion::getHora(){
			return hora;
			}

		int Funcion::getSala(){
			return sala;
			}


        //Metodos de modificacion
		void Funcion::setFuncion(string nuevoFuncion){
			funcion= nuevoFuncion;
			}

		void Funcion::setNumPeli(int nuevoNumPeli){
			numPeli= nuevoNumPeli;
			}

		void Funcion::setHora(Hora nuevoHora){
			hora= nuevoHora;
			}

		void Funcion::setSala(int nuevoSala){
			sala= nuevoSala;
			}

#endif