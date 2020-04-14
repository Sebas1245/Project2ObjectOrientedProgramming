#include <iostream>
#include <string>
#include "Actor.h"

using namespace std;

class Pelicula {
    private:
        int numPeli;
        string titulo;
        int anio;
        int duracion;
        string genero;
        int cantActores;
        Actor listaActores[10];
    public:
        Pelicula();
        Pelicula(int numP, string tit, int a, int dur, string gen, int numActores, Actor lActores[10]);
        // metodos de acceso
        int getNumPeli();
        string getTitulo();
        int getAnio();
        int getDuracion();
        string getGenero();
        int getCantActores();
        // metodos de modificación
        void setNumPeli(int num);
        void setTitulo(string nom);
        void setAnio(int num);
        void setDuracion(int num);
        void setGenero(string nom);
        // metodos especiales 
        Actor getActorFromList(int index);
        bool agregarActor(Actor);
        void muestra();
};