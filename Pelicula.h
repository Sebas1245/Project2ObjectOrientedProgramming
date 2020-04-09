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
};
