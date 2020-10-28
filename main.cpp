#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;
#include <vector>
#include "Video.cpp"
#include "Pelicula.cpp"
#include "Episodio.cpp"
int main(){
int answer,cond,opcion;
float minimo,maximo,nueva;
string codigo,titulo,duracion,genero,calificacion,tipo,temporada,tituloserie,busgen,id,vid,nombre,document;
float calif,temp;
ifstream archivo;
vector <Video*> peliculas;
vector <Video*> episodios;
cond=1;
while (cond==1) {
cout<<endl;
cout<<"Bienvenido, en esta aplicacion usted es capaz de calificar diferentes peliculas y series"<<endl;
cout<<"A continuacion eliga la accion que desee realizar:"<<endl;
cout<<"1. Cargar archivo de datos"<<endl;
cout<<"2. Mostrar los videos en general, con una cierta calificacion o de un cierto genero"<<endl;
cout<<"3. Mostrar los episodios de una determinada serie con una calificacion determinada"<<endl;
cout<<"4. Mostrar las peliculas con cierta calificacion"<<endl;
cout<<"5. Calificar un video"<<endl;
cout<<"0. Salir"<<endl<<endl;
cin>>answer;
cout<<endl;
  if (answer==1) {
    cout<<"Cual es el nombre del archivo? (incluye el tipo de archivo, por ejemplo Hola.txt)"<<endl;
    cin>>document;
    archivo.open(document,ios::in); //Se abre el archivo para leer los datos
          if (archivo.fail()) {
            cout<<"No es posible abrir este archivo"<<endl;
            exit(1);
          }
          while (!archivo.eof()) {
            getline(archivo,tipo);
                    if (tipo=="Pelicula") {
                      getline(archivo,codigo);
                      getline(archivo,titulo);
                      getline(archivo,genero);
                      getline(archivo,duracion);
                      getline(archivo,calificacion);
                      calif=stof(calificacion);
                      Video *Video;
                      Video=new Pelicula(codigo,titulo,genero,duracion,calif);
                      peliculas.push_back(Video);
                    }
                    if (tipo=="Serie") {
                      getline(archivo,codigo);
                      getline(archivo,tituloserie);
                      getline(archivo,genero);
                      getline(archivo,temporada);
                      getline(archivo,titulo);
                      getline(archivo,duracion);
                      getline(archivo,calificacion);
                      calif=stof(calificacion);
                      Video *Video;
                      Video=new Episodio(codigo,tituloserie,genero,temporada,titulo,duracion,calif);
                      episodios.push_back(Video);
                    }
        }
  }
  if (answer==2) {
  cout<<"Eliga una de las siguientes ocpiones:"<<endl;
  cout<<"1. Mostrar videos en general"<<endl;
  cout<<"2. Mostrar videos con una cierta calificacion"<<endl;
  cout<<"3. Mostrar videos de un cierto genero "<<endl;
  cin>>opcion;
  cout<<endl;
            if (opcion==1) {
                for (int i=0;i<peliculas.size();i++) {
                  peliculas[i]->mostrarContenido();
                }
                for (int i=0;i<episodios.size();i++) {
                    episodios[i]->mostrarContenido();
                }
            }
            if (opcion==2) {
            cout<<"REMINDER: "<<endl;
            cout<<"El rango de calificaciones es de 0.0 a 5.0: "<<endl;
            cout<<"Inserte el rango minimo de la calificacion del video a mostrar (en decimal)"<<endl;
            cin>>minimo;
            cout<<"Inserte el rango maximo de la calificacion del video a mostrar (en decimal)"<<endl;
            cin>>maximo;
            cout<<endl;
                for (int i=0;i<peliculas.size();i++) {
                  if (peliculas[i]->getCalificacion()>=minimo && peliculas[i]->getCalificacion()<=maximo) {
                    peliculas[i]->mostrarContenido();
                  }
                }
                for (int i=0;i<episodios.size();i++) {
                  if (episodios[i]->getCalificacion()>=minimo && episodios[i]->getCalificacion()<=maximo) {
                    episodios[i]->mostrarContenido();
                  }
                }
            }
            if (opcion==3) {
            cout<<"Ingrese el genero que desee buscar: (Escribe el genero con la primera letra en mayuscula)"<<endl;
            cin>>busgen;
            cout<<endl;
                for (int i=0;i<peliculas.size();i++) {
                  if (peliculas[i]->getGenero()==busgen) {
                    peliculas[i]->mostrarContenido();
                  }
                }
                for (int i=0;i<episodios.size();i++) {
                  if (episodios[i]->getGenero()==busgen) {
                    episodios[i]->mostrarContenido();
                  }
                }
            }

  }
  if (answer==3) {
    cout<<"Escriba a continuacion el ID de la serie que se desea consultar"<<endl;
    cin>>id;
        cout<<"REMINDER: "<<endl;
        cout<<"El rango de calificaciones es de 0.0 a 5.0: "<<endl;
        cout<<"Inserte el rango minimo de la calificacion de la serie a mostrar (en decimal)"<<endl;
        cin>>minimo;
        cout<<"Inserte el rango maximo de la calificacion de la serie a mostrar (en decimal)"<<endl;
        cin>>maximo;
        cout<<endl;
        for (int i=0;i<episodios.size();i++) {
          if (episodios[i]->getCalificacion()>=minimo && episodios[i]->getCalificacion()<=maximo && id==episodios[i]->getID()) {
            episodios[i]->mostrarContenido();
          }
        }
  }
  if (answer==4) {
    cout<<"REMINDER: "<<endl;
    cout<<"El rango de calificaciones es de 0.0 a 5.0: "<<endl;
    cout<<"Inserte el rango minimo de la calificacion de la pelicula a mostrar (en decimal)"<<endl;
    cin>>minimo;
    cout<<"Inserte el rango maximo de la calificacion de la pelicula a mostrar (en decimal)"<<endl;
    cin>>maximo;
    cout<<endl;
    for (int i=0;i<peliculas.size();i++) {
      if (peliculas[i]->getCalificacion()>=minimo && peliculas[i]->getCalificacion()<=maximo) {
        peliculas[i]->mostrarContenido();
      }
    }
  }
  if (answer==5) {
    cout<<"Deseas calificar una serie o una pelicula? (Primera letra en mayuscula y utiliza espacios si es necesario)"<<endl;
    cin>>vid;
    cout<<endl;
          if (vid=="Pelicula" ) {
            cout<<"Ingresa el titulo de la pelicula (Primera letra en mayuscula y utiliza espacios si es necesario):"<<endl;
            getline(cin,nombre);
            getline(cin,nombre);
            cout<<"Ingresa la calificacion (en decimal)"<<endl;
            cin>>nueva;
            cout<<endl;
            for (int i=0;i<peliculas.size();i++) {
              if (nombre==peliculas[i]->getTitulo()) {
                peliculas[i]->califVideo(nueva,peliculas[i]->getCalificacion());
                peliculas[i]->mostrarContenido();
              }
            }
          }
          if (vid=="Serie") {
            cout<<"Ingresa el titulo del capitulo de la serie (Primera letra en mayuscula y utiliza espacios si es necesario):"<<endl;
            getline(cin,nombre);
            getline(cin,nombre);
            cout<<"Ingresa la calificacion (en decimal)"<<endl;
            cin>>nueva;
            cout<<endl;
            for (int i=0;i<episodios.size();i++) {
              if (nombre==episodios[i]->getTitulo()) {
                episodios[i]->califVideo(nueva,episodios[i]->getCalificacion());
                episodios[i]->mostrarContenido();
              }
            }
          }


  }
  if (answer==0) {
    cond=2;
    cout<<"Gracias por su visita!!!"<<endl;
  }
 }



return 0;
}
