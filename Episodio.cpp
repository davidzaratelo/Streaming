#include <iostream>
#include "Episodio.h"

Episodio::Episodio(){
}
Episodio:: Episodio(float calif){
  calificacion=calif;
}
Episodio::Episodio(string codigo,string tituloser,string genero,string temp,string titulo,string duracion,float calificacion):Video(codigo,titulo,genero,duracion,calificacion){
  temporada=temp;
  tituloserie=tituloser;
  cantidadcalif=1;
}
void Episodio::mostrarContenido(){
cout<<"ID "<<id << "; " << tituloserie<<"; "<<genero<<"; "<<temporada<<"; " << titulo<<"; "<<duracion<<"; "<<calificacion<<endl;
}

void Episodio::califVideo(float nueva,float pasada){
  Episodio e1(pasada);
  Episodio e2(nueva);
  e1.setCalificacion(calificacion*cantidadcalif);
  sumarCantidad();
  setCalificacion((e1+e2)/cantidadcalif);
}
