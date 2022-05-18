#include <iostream>
#include <string>
#include <fstream>

using namespace std;
/*
Milton Abrego Dávila
558202
24/08/2021
Este programa tiene el obgetivo de analizar y crear achivos html del codigo que le introduscas

Doy mi palabra de que he relizado esta actividad con integridad academica
*/

int main() {
  ifstream fraseOpen;
  ofstream pagExit;
  string doc;
  string html;
  int pos;//se usa para guardar pocisiones de caracteres y asi borrar con facilidad lo no deseado
  cout<<"Escribe el nombre del codigo que desea analisar con terminacion '.txt'"<<endl;//el archivo tiene que estar en la misma carpeta
  cin>>doc;
  fraseOpen.open(doc);
  pos=doc.find(".txt");
  doc.erase(pos,4);
  html=doc+".html";
  pagExit.open(html);
  string etiquetas;
  string linea;
  
  pagExit<<"<!DOCTYPE html>\n<html>\n<head>\n<title>\nDocumentación del archivo "<<doc<<".cpp\n</title>\n</head>"<<endl;//esto es el principo del archivo html
  while(!fraseOpen.eof()){//se corre un ciclo hasta que termine el archivo
   getline(fraseOpen,linea);
//cada "if" busca una de las etiquetas
   if(linea.find("@progName")!=-1){
     pos=linea.find("@progName");
     linea.erase(pos,9);
     pagExit<<"<body>\n<h2>\n"<<linea<<"<br>\n</h2>"<<endl;
   }
   else{
     if(linea.find("@Author")!=-1){
       pos=linea.find("@Author");
       linea.erase(pos,8);
       pagExit<<"<strong> Autor: </strong>"<<linea<<"<br>"<<endl;
     }
     else{
       if(linea.find("@date")!=-1){
         pos=linea.find("@date");
         linea.erase(pos,5);
         pagExit<<"<strong> Fecha de elaboración </strong> "<<linea<<"<br>"<<endl;
       }
       else{
         if(linea.find("@desc")!=-1){
           pos=linea.find("@desc");
           linea.erase(pos,5);
           pagExit<<"<strong> Descripción: </strong>"<<linea<<"<br>"<<endl;
         }
         else{
           if(linea.find("@funcName")!=-1){
             pos=linea.find("@funcName");
             linea.erase(pos,9);
             pagExit<<"<h3>\n<hr><br>Función:"<<linea<<"<br>\n</h3>"<<endl;
           }
           else{
             if(linea.find("@parametros")!=-1){
               pos=linea.find("@parametros");
               linea.erase(pos,11);
               pagExit<<"<strong> Parametro: </strong>"<<linea<<"<br>"<<endl;
             }
             else{
               if(linea.find("@return")!=-1){
                 pos=linea.find("@return");
                 linea.erase(pos,7);
                 pagExit<<"<strong> Valor de retorno:</strong>"<<linea<<"<br>"<<endl;
               }
             }
           }
         }
       }
     }
   }


  }
  pagExit<<"</body>\n</html>"<<endl;//termina el archivo html
  fraseOpen.close();
  pagExit.close();
}