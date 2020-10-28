//Se define la Clase en caso de que no este definida
#ifndef SERIE_H_INCLUDED
//Se define la clase.
#define SERIE_H_INCLUDED
#include <iostream>
#include <vector>
#include "Episodio.h"
using namespace std;


class Serie{
private:
vector <Episodio> episodios;
int temporadas;
string genero;
string titulo;
string id;
public:
Serie(int,string,string,string);
void establecerEpisodios(int,Episodio);
};


#endif
