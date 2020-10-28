#include <iostream>
#include "Video.h"
using namespace std;


Video::Video(){

}
Video::Video(string codigo,string titu,string gen,string durac,float calific){
  id=codigo;
  titulo=titu;
  genero=gen;
  duracion=durac;
  calificacion=calific;
  cantidadcalif=1;
}

string Video::getID(){
  return id;
}
string Video:: getTitulo(){
  return titulo;
}
string Video:: getDuracion(){
  return duracion;
}
string Video:: getGenero(){
  return genero;
}
float Video:: getCalificacion(){
  return calificacion;
}

void Video::mostrarContenido(){

}
int Video:: getCantidadCalif(){
  return cantidadcalif;
}

void Video::sumarCantidad(){
  cantidadcalif=cantidadcalif+1;
}

void Video::califVideo(float nueva,float pasada){

}
void Video::setCalificacion(float calif){
  calificacion=calif;
}
