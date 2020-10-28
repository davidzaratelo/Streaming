//Se define la Clase en caso de que no este definida
#ifndef EPISODIO_H_INCLUDED
//Se define la clase.
#define EPISODIO_H_INCLUDED
#include "Video.h"
#include <iostream>
using namespace std;

class Episodio:public Video{
private:
string tituloserie;
string temporada;
public:
Episodio();
Episodio(float);
Episodio(string,string,string,string,string,string,float);
void mostrarContenido();
void califVideo(float,float);
float operator+(Episodio e2){
  float final;
  final=e2.calificacion+this->calificacion;
  return final;
}

};



#endif
