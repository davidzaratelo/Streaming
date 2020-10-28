#include <iostream>
//Se define la Clase en caso de que no este definida
#ifndef PELICULA_H_INCLUDED
//Se define la clase.
#define PELICULA_H_INCLUDED
#include "Video.h"
using namespace std;

class Pelicula:public Video{
private:
public:
Pelicula(string,string,string,string,float);
Pelicula(float);
Pelicula();
void mostrarContenido();
void califVideo(float,float);
float operator+(Pelicula p2){
  float final;
  final=p2.calificacion+this->calificacion;
  return final;
}

};


#endif
