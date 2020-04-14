#include <iostream>
#include <string>
#include <fstream>
#include "Funcion.h"
#include "Pelicula.h"

using namespace std;

// menu
// Despliega el menu al Usuario y obtiene la opción del menú que se desea ejecutar
// No recibe ningun parametro
// Regresa variable tipo char, siendo este el caracter de la opcion elegida por el usuario
char menu(){
    char resp;
    bool respCorrecta;
    do {
        cout << "Eliga una opcion introduciendo una de las letras mostradas" << endl;
        cout << "A. Consultar actores en la lista " << endl;
        cout << "B. Consultar películas en la lista " << endl;
        cout << "C. Consultar todas las funciones disponibles " << endl;
        cout << "D. Consultar las funciones por hora " << endl;
        cout << "E. Consultar por clave de funcion " << endl;
        cout << "F. Consultar participaciones de un actor en peliculas " << endl;
        cout << "G. Terminar " << endl;
        cin >> resp;
        resp = toupper(resp);
        if(resp == 'A' || resp == 'B' || resp == 'C' || resp == 'D' || resp == 'E' || resp =='F' || resp == 'G') {
            respCorrecta = true;
        }
        else {
            respCorrecta = false; 
        }      
    } while(respCorrecta == false);
    return resp;
}

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
        cin.ignore();
        cout << "Introduzca el numero de pelicula ";
        cin >> numPeliFun;
        cout << "Introduzca el horario en el que se presentara la pelicula" << endl;
        cout << "Hora (formato 24 hrs): "; 
        cin >> hora;
        cout << "Minuto: ";
        cin >> minutos;
        // valido que el formato de hora sea correcto
        while(hora >= 24 || hora < 0 || minutos < 0 || minutos > 59) {
            cout << "Se ha introducido la hora erroneamente, intentelo de nuevo. Recuerde que se debe introducir en formato de 24 horas" << endl;
            cout << "Hora (formato 24 hrs): "; 
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

    // ITEM 5
    // menu 
    char respMenu;
    do {
        respMenu = menu();
        switch (respMenu) {
            case 'A':
                cout << "Los actores en la lista son: " << endl;
                for (int i = 0; i < 20; i++) {
                    arrActores[i].muestra();
                }
                break;
            case 'B':
                cout << "Las peliculas en la lista son: " << endl;
                for (int i = 0; i < 20; i++) {
                    // if para saber que el elemento del arreglo no es un objeto sin información
                    if(arrPelis[i].getTitulo() != "N/D") {
                        cout << i+1 << ") ";
                        arrPelis[i].muestra();
                    }
                }
                break;
            case 'C':
                for (int i = 0; i < numFunciones; i++) {
                    // mostrar clave de funcion
                    cout << "Funcion: "<< arrFunciones[i].getCveFuncion();
                    // comparar numero de Peli para la funcion con numero de Peli para arreglo de Pelis
                    for (int j = 0; j < 20; j++) {
                        // cuando sean iguales desplegar titulo
                        if(arrFunciones[i].getNumPeli() == arrPelis[j].getNumPeli()){
                            cout << "\t Pelicula: " <<arrPelis[j].getTitulo();
                        }
                    }
                    // desplegar sala 
                    cout << "\t Sala: " << arrFunciones[i].getSala() << "\t ";
                    // desplegar hora
                    cout << "Horario: "; 
                    Hora horaDesplegar;
                    horaDesplegar = arrFunciones[i].getHora();
                    horaDesplegar.muestra();
                }
                break;
            case 'D':
                // code
                break;
            case 'E':
                // code
                break;
            case 'F':
                // code
                break;
            default:
                cout << "La sesion ha terminado, gracias. " << endl;
                break;
        }
    } while(respMenu != 'G');
    
    return 0;
}