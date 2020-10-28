#include <iostream>
#include "Pelicula.h"
using namespace std;
Pelicula::Pelicula(string codigo,string titulo,string genero,string duracion,float calificacion):Video(codigo,titulo,genero,duracion,calificacion){
  cantidadcalif=1;
}
Pelicula:: Pelicula(float calif){
  calificacion=calif;
}
Pelicula::Pelicula(){

}

void Pelicula::mostrarContenido(){
cout<<"ID "<<id<<"; " <<titulo <<"; " << genero<<"; "<<duracion <<"; "<<calificacion<<endl;
}

void Pelicula::califVideo(float nueva,float pasada){
Pelicula p1(pasada);
Pelicula p2(nueva);

p1.setCalificacion(calificacion*cantidadcalif);
sumarCantidad();
setCalificacion((p1+p2)/cantidadcalif);
}
