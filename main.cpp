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
        cout << "----------------------------------------------------------------------------------------------" << endl;
        cout << "Eliga una opcion introduciendo una de las letras mostradas" << endl;
        cout << "A. Consultar actores en la lista " << endl;
        cout << "B. Consultar películas en la lista " << endl;
        cout << "C. Consultar todas las funciones disponibles " << endl;
        cout << "D. Consultar las funciones por hora " << endl;
        cout << "E. Consultar por clave de funcion " << endl;
        cout << "F. Consultar participaciones de un actor en peliculas " << endl;
        cout << "G. Terminar " << endl;
        cout << "----------------------------------------------------------------------------------------------" << endl;
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

// pedirValidarHora
// Pide los valores de horas y minutos en formato de 24 horas y valida que sean correctos
// Recibe: hr y min como parametros por referencia
// Regresa: hr y min como parametros por referencia
void pedirValidarHora(int &hr, int &min) {
    int hora, minutos;
    bool inputFail1 = false, inputFail2 = false;
    cout << "Hora (formato 24 hrs): "; 
    cin >> hora;
    inputFail1 = cin.fail();
    if(inputFail1) {
        cout << "Error, no se introdujo un numero " << endl;
        cin.clear();
        cin.ignore(10,'\n');
    }
    cout << "Minuto: ";
    cin >> minutos;
    inputFail2 = cin.fail();
    if(inputFail2) {
        cout << "No se introdujo un numero, intentelo de nuevo" << endl;
        cin.clear();
        cin.ignore(10,'\n');
    }
    // valido que el formato de hora sea correcto
    while(hora >= 24 || hora < 0 || minutos < 0 || minutos > 59 || inputFail1 || inputFail2) {
        cout << "Se ha introducido la hora erroneamente, intentelo de nuevo. Recuerde que se debe introducir en formato de 24 horas" << endl;
        cout << "Hora (formato 24 hrs): "; 
        cin >> hora;
        inputFail1 = cin.fail();
        if(inputFail1) {
            cout << "Error, no se introdujo un numero " << endl;
            cin.clear();
            cin.ignore(10,'\n');
        }
        cout << "Minuto: ";
        cin >> minutos;
        inputFail2 = cin.fail();
        if(inputFail2) {
            cout << "No se introdujo un numero, intentelo de nuevo" << endl;
            cin.clear();
            cin.ignore(10,'\n');
        }
    }
    hr = hora;
    min = minutos;
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
        // pedir el num de pelicula y validar que exista en el arreglo
        bool numPeliValido;
        int intentos = 0;
        do{
            if(intentos == 0) {
                cout << "Introduzca el numero de Pelicula ";
            }
            else {
                cout << "Error, el numero de pelicula ingresado no existe en el sistema. Ingrese un numero valido. ";
            }
            cin >> numPeliFun;
            for(int j = 0; j < 20; j++) {
                if(numPeliFun == arrPelis[j].getNumPeli()) {
                    numPeliValido = true;
                    break;
                }
                else {
                    numPeliValido = false;
                }
            }
            intentos++;
        }while(!numPeliValido);
        cout << "Introduzca el horario en el que se presentara la pelicula" << endl;
        pedirValidarHora(hora,minutos);
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
                {
                    cout << "Los actores en la lista son: " << endl;
                    for (int i = 0; i < 20; i++) {
                        if(arrActores[i].getId() != 0) {
                            cout << i+1 << ")";
                            arrActores[i].muestra();
                        }
                    }
                }
                break;
            case 'B':
                {
                    cout << "Las peliculas en la lista son: " << endl;
                    for (int i = 0; i < 20; i++) {
                        // if para saber que el elemento del arreglo no es un objeto sin información
                        if(arrPelis[i].getTitulo() != "N/D") {
                            cout << i+1 << ") ";
                            arrPelis[i].muestra();
                        }
                    }
                }
                break;
            case 'C':
                {
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
                }
                break;
            case 'D':
                {
                    cout << "Introduzca la hora";
                    int horaCasoD, minCasoD;
                    bool peliculaSeObtuvoPorHora;
                    pedirValidarHora(horaCasoD, minCasoD);
                    for(int i = 0; i < numFunciones; i++) {
                        // si la hora y los minutos son iguales mostrarlo todo
                        if (horaCasoD == arrFunciones[i].getHora().getHh() && minCasoD == arrFunciones[i].getHora().getMm()) {
                            peliculaSeObtuvoPorHora = true;
                            // comparar numero de Peli para la funcion con numero de Peli para arreglo de Pelis
                            for (int j = 0; j < 20; j++) {
                                // cuando sean iguales desplegar titulo
                                if(arrFunciones[i].getNumPeli() == arrPelis[j].getNumPeli()){
                                    cout << "Pelicula: " <<arrPelis[j].getTitulo();
                                }
                            }
                            cout << "\t Sala: " << arrFunciones[i].getSala() << endl;
                        }
                        else {
                            peliculaSeObtuvoPorHora = false;
                        }
                    }
                    // si no se obtuvo una pelicula en la hora introducida mostrar feedback al usuario
                    if(!peliculaSeObtuvoPorHora) {
                        cout << "La hora introducida no concuerda con las horas de las peliculas que se presentaran hoy. " << endl;
                    }
                }
                break;
            case 'E':
                { 
                    // pedir clave de función 
                    string inputClaveFun;
                    int indexClaveEncontrada;
                    cout << "Introduzca la clave de la funcion " << endl;
                    cin >> inputClaveFun;
                    // validar
                    // recorrer el arreglo, si no lo encuentro en ningun elemento volver a pedir
                    do {
                        for(int i = 0; i < numFunciones; i++) {
                            if(inputClaveFun != arrFunciones[i].getCveFuncion()) {
                                indexClaveEncontrada = -1;
                            }
                            else {
                                indexClaveEncontrada = i;
                                break;
                            }
                        }
                        if(indexClaveEncontrada == -1) {
                            cout << "Error, clave inexistente. Introduzca una clave valida" << endl;
                            cin.ignore();
                            cin >> inputClaveFun;
                        }
                    }while(indexClaveEncontrada == -1);

                    // desplegar conforme a la clave introducida usando el indice encontrado
                    cout << "Sala: " << arrFunciones[indexClaveEncontrada].getSala() << "\t Hora: ";
                    arrFunciones[indexClaveEncontrada].getHora().muestra();
                    for (int i = 0; i < 20; i++) {
                        // cuando sean iguales desplegar la informacion de la pelicula
                        if(arrFunciones[indexClaveEncontrada].getNumPeli() == arrPelis[i].getNumPeli()){
                            cout << "Titulo: "<< arrPelis[i].getTitulo();
                            cout << "\t Genero: " << arrPelis[i].getGenero();
                            cout << "\t Duracion: "<< arrPelis[i].getDuracion()  << " minutos"<< endl;
                            cout << "Reparto: ";
                            // desplegamos la lista de actores
                            for(int j = 0; j < arrPelis[i].getCantActores(); j++) {
                                cout << arrPelis[i].getActorFromList(j).getNombre() << " ";
                            }
                        }
                    }
                    cout << endl;
                }
                break;
            case 'F':
                {   
                    int inputID, noDeIntentos = 0, indexFoundID, foundIDNumber;
                    bool validID;
                    // ciclo donde pido y valido el ID de actor
                    do{
                        if(noDeIntentos > 0) {
                            cout << "Error, el ID introducido no existe. Introduzca un ID de actor valido " << endl;
                        }
                        else {
                            cout << "Introduzca el no. de ID del actor que desea consultar. " << endl;
                        }
                        cin >> inputID;
                        for(int i = 0; i < 20; i++) {
                            if(arrActores[i].getId() != inputID) {
                                validID = false;
                            }
                            else {
                                foundIDNumber = arrActores[i].getId();
                                indexFoundID = i;
                                validID = true;
                                break;
                            }
                        }
                        noDeIntentos++;
                    }while(!validID);
                    // despliego la informacion de la consulta
                    cout << "Participaciones de " << arrActores[indexFoundID].getNombre() << endl;
                    for(int i = 0; i < 20; i++) {
                        for(int j = 0; j < arrPelis[i].getCantActores(); j++) {
                            if(arrPelis[i].getActorFromList(j).getId() == foundIDNumber) {
                                cout << "Pelicula: " << arrPelis[i].getTitulo();
                                cout << "\t Anio: " << arrPelis[i].getAnio() << endl;
                            }
                        }
                    }
                }
                break;
            default:
                cout << "La sesion ha terminado, gracias. " << endl;
                break;
        }
    } while(respMenu != 'G');
    
    return 0;
}