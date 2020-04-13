#include <iostream>
#include <string>
#include <fstream>
#include "Funcion.h"
#include "Pelicula.h"

using namespace std;

int main(){
    // declaro los arreglos de objetos de mis clases
    Actor arrActores[20];
    Funcion arrFunciones[20];
    Pelicula arrPelis[20];

    // cargo info del archivo actores al arreglo
    ifstream archActores;
    archActores.open("actores.txt");
    int actorId, numActores = 0;
    string actorName;
    while( archActores >> actorId && getline(archActores,actorName) ) {
        arrActores[numActores].setId(actorId);
        arrActores[numActores].setNombre(actorName);
        numActores++;
    }
    // termino de cargar datos del archivo de actor
    archActores.close();
    
    // cargo info del archivo de peliculas al arreglo
    ifstream archPelis;
    archPelis.open("peliculas.txt");
    int numPeli, yr, cantActores, duracion, contPelis = 0; 
    string genero, titulo;
    while (archPelis >> numPeli) {
        // set numeroPeli
        arrPelis[contPelis].setNumPeli(numPeli);
        // set anio
        archPelis >> yr;
        arrPelis[contPelis].setAnio(yr);
        // set duracion
        archPelis >> duracion;
        arrPelis[contPelis].setDuracion(duracion);
        // set genero
        archPelis >> genero;
        arrPelis[contPelis].setGenero(genero);
        // set lista actores
        archPelis >> cantActores;
        int idDeActorEnPeli;
        bool sePudoAgregar;
        for (int i = 0; i < cantActores; i++) {
            archPelis >> idDeActorEnPeli;
            for (int i = 0; i < 20; i++) {
                if(idDeActorEnPeli == arrActores[i].getId()) {
                    cout << arrActores[i].getNombre() << "  " << arrActores[i].getId();
                    sePudoAgregar = arrPelis[contPelis].agregarActor(arrActores[i]);
                }
            }
            if (sePudoAgregar) {
                cout << "Se agrego el actor " << idDeActorEnPeli << endl;
            }
            else {
                cout << "No se pudo agregar el actor " << idDeActorEnPeli << endl;
            }
        }
        // set titulo 
        getline(archPelis,titulo);
        arrPelis[contPelis].setTitulo(titulo);
        contPelis++;
    }
    // termino de cargar los datos del archivo de pelicula
    archPelis.close();

    return 0;
}