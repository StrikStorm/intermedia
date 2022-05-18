#ifndef _PELICULA_H_
#define _PELICULA_H_
#include <iostream>
using namespace std;

class Pelicula {
    private:
        //Atributos
		int numPeli;
 		string titulo;
 		int year;
 		int duracion;//El tiempo esta en minutos
 		string genero;
 		int cantAct;
 		int listAct[20];
		 
		

    public:
        //Constructor
        Pelicula(int nuevoNumPeli, string nuevoTitulo, int nuevoYear, int nuevoDuracion, string nuevoGenero, int nuevoCantAct, int nuevoListAct[20]);
		Pelicula();
		void setNumPeli(int);
		void setTitulo(string);
		void setYear(int);
		void setDuracion(int);
		void setGenero(string);
		void setCantAct(int);
		void setListAct(int, int);
		int getNumPeli();
		string getTitulo();
		int getYear();
		int getDuracion();
		string getGenero();
		int getCantAct();
		int getListAct(int);

};

Pelicula::Pelicula(){
	numPeli=0;
	titulo="";
	year=0;
	duracion=0;
	genero="";
	cantAct=0;
	listAct[cantAct]=0;
}

Pelicula::Pelicula(int nuevoNumPeli, string nuevoTitulo, int nuevoYear, int nuevoDuracion, string nuevoGenero, int nuevoCantAct, int nuevoListAct[20]){
	titulo = nuevoTitulo;
	year = nuevoYear;
	duracion = nuevoDuracion;
	genero = nuevoGenero;
	cantAct = nuevoCantAct;
	listAct[cantAct] = nuevoListAct[cantAct];
}

        //Metodos de acceso
		int Pelicula::getNumPeli(void){return numPeli;}
		string Pelicula::getTitulo(void){return titulo;}
		int Pelicula::getYear(void){return year;}
		int Pelicula::getDuracion(void){return duracion;}
		string Pelicula::getGenero(void){return genero;}
		int Pelicula::getCantAct(void){return cantAct;}
		int Pelicula::getListAct(int a){return listAct[a];}


        //Metodos de modificacion
		void Pelicula::setNumPeli(int nuevoNumPeli){numPeli= nuevoNumPeli;}
		void Pelicula::setTitulo(string nuevoTitulo){titulo= nuevoTitulo;}
		void Pelicula::setYear(int nuevoYear){year= nuevoYear;}
		void Pelicula::setDuracion(int nuevoDuracion){duracion= nuevoDuracion;}
		void Pelicula::setGenero(string nuevoGenero){genero= nuevoGenero;}
		void Pelicula::setCantAct(int nuevoCantAct){cantAct= nuevoCantAct;}
		void Pelicula::setListAct(int a, int b){listAct[a]= b;}

#endif