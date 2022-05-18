#ifndef FUNCION__H__
#define FUNCION__H__
#include <iostream>
#include <string>
#include <fstream>
#include "Reloj.h"

using namespace std;
class Funcion {
    private:
        //Atributos
		string funcion;
 		int numPeli;
 		Reloj hora;
 		int sala;

    public:
        //Constructor
        Funcion(string, int, Reloj,int);
		Funcion();
		string getFuncion();
		int getNumPeli();
		Reloj getHora();
		int getSala();
		void setFuncion(string);
		void setNumPeli(int);
		void setHora(Reloj);
		void setSala(int);
	};
Funcion::Funcion(){
	funcion = "N/A";
	numPeli=0;
	hora;
	sala=0;
}

Funcion::Funcion(string nuevoFuncion, int nuevoNumPeli, Reloj nuevoHora,int nuevoSala){
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

		Reloj Funcion::getHora(){
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

		void Funcion::setHora(Reloj nuevoHora){
			hora= nuevoHora;
			}

		void Funcion::setSala(int nuevoSala){
			sala= nuevoSala;
			}

#endif
