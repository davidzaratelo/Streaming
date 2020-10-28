//Se define la Clase en caso de que no este definida
#ifndef VIDEO_H_INCLUDED
//Se define la clase.
#define VIDEO_H_INCLUDED
using namespace std;
#include <iostream>

class Video{
protected:
string id;
string titulo;
string genero;
string duracion;
float calificacion;
int cantidadcalif;
public:
Video();
Video(string,string,string,string,float);
string getID();
string getTitulo();
string getDuracion();
string getGenero();
float getCalificacion();
void setCalificacion(float);
virtual void mostrarContenido()=0;
int getCantidadCalif();
virtual void califVideo(float,float)=0;
int cantidadCalif();
void sumarCantidad();

};

#endif
