#include <iostream>
#include <string>
#include "Pelicula.h"

using namespace std;

Pelicula::Pelicula() {
    numPeli = 0;
    titulo = "N/D";
    anio = 0;
    duracion = 0;
    genero = "N/D";
    cantActores = 0;
    for(int i = 0; i < 10; i++) {
        listaActores[i].setId(0);
        listaActores[i].setNombre(" ");
    }
}


// metodos de acceso
int Pelicula::getNumPeli() {
    return numPeli;
}

string Pelicula::getTitulo() {
    return titulo;
}

int Pelicula::getAnio() {
    return anio;
}

int Pelicula::getDuracion() {
    return duracion;
}

string Pelicula::getGenero() {
    return genero;
}

int Pelicula::getCantActores() {
    return cantActores;
}
// metodos de modificacion
void Pelicula::setNumPeli(int num) {
    numPeli = num;
}

void Pelicula::setTitulo(string nom) {
    titulo = nom;
}

void Pelicula::setAnio(int num) {
    anio = num;
}

void Pelicula::setDuracion(int num) {
    duracion = num;
}

void Pelicula::setGenero(string nom) {
    genero = nom;
}

// metodos especiales
Actor Pelicula::getActorFromList(int i) {
    return listaActores[i];
}

bool Pelicula::agregarActor(Actor act) {
    // reviso las condiciones para regresar falso
    for (int i = 0; i < 10; i++ ) {
        // si tengo un actor repetido
        if(act.getId() == listaActores[i].getId()) {
            return false;
        }
        // si el ultimo espacio del arreglo está ocupado
        else if (i == 9 &&  listaActores[i].getNombre() != " ") {
            return false;
        }
    }
    // si no se ha terminado la funcion agrego el actor a la lista
    for (int i = cantActores; i < 10; i++) {
        // reviso hasta llegar al primer espacio vacío en la lista
        if(listaActores[i].getNombre() != "N/D") {
            listaActores[i].setNombre(act.getNombre());
            listaActores[i].setId(act.getId());
            cantActores++;
            return true;
        }
    }
}