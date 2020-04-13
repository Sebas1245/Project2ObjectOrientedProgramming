#include <iostream>
#include <string>
#include <fstream>
#include "Funcion.h"
#include "Pelicula.h"

using namespace std;

int main(){
    // ITEM 1
    // declaro los arreglos de objetos de mis clases
    Actor arrActores[20];
    Funcion arrFunciones[20];
    Pelicula arrPelis[20];

    // ITEM 2
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
    
    // ITEM 3
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
                    sePudoAgregar = arrPelis[contPelis].agregarActor(arrActores[i]);
                }
            }
            if (!sePudoAgregar) {
                throw runtime_error("Error al cargar informacion del archivo de peliculas, no se puedo agregar el actor " + idDeActorEnPeli);
            }
        }
        // set titulo 
        getline(archPelis,titulo);
        arrPelis[contPelis].setTitulo(titulo);
        contPelis++;
    }
    // termino de cargar los datos del archivo de pelicula
    archPelis.close();

    // ITEM 4
    // pido y almaceno informacion de las funciones
    int numFunciones, numPeliFun, hora, minutos, sala;
    Hora horaPeli;
    string cveFun;
    cout << "¿Cuantas funciones habra el dia de hoy? " << endl;
    cin >> numFunciones;
    for (int i = 0; i < numFunciones; i++) {
        cout << "Introduzca la clave de funcion "; 
        cin >> cveFun;
        cout << "Introduzca el numero de pelicula ";
        cin >> numPeliFun;
        cout << "Introduzca el horario en el que se presentara la pelicula" << endl;
        cout << "Hora del dia (formato 24 hrs):"; 
        cin >> hora;
        cout << "Minuto: ";
        cin >> minutos;
        // valido que el formato de hora sea correcto
        while(hora >= 24 || hora < 0 || minutos < 0 || minutos > 59) {
            cout << "Se ha introducido la hora erroneamente, intentelo de nuevo. Recuerde que se debe introducir en formato de 24 horas" << endl;
            cout << "Hora del dia (formato 24 hrs): "; 
            cin >> hora;
            cout << "Minuto: ";
            cin >> minutos;
        }
        cout << "Introduzca la sala donde se presentara la pelicula ";
        cin >> sala;
        // establezco los valores para el objeto Hora que usare para establecer el valor del objeto Funcion
        horaPeli.setHh(hora);
        horaPeli.setMm(minutos);
        // establezco los valores para el iesimo elemento del arreglo
        arrFunciones[i].setCveFuncion(cveFun);
        arrFunciones[i].setNumPeli(numPeliFun);
        arrFunciones[i].setHora(horaPeli);
        arrFunciones[i].setSala(sala);
    }
    return 0;
}