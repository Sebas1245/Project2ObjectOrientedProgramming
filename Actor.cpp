#include <iostream>
#include <string>
#include "Actor.h"

using namespace std;

Actor::Actor() {
    id = 0;
    nombre = "N/D";
}

Actor::Actor(int num, string nom) {
    id = num;
    nombre = nom;
}

int Actor::getId() {
    return id;
}

string Actor::getNombre() {
    return nombre;
}

void Actor::setId(int num) {
    id = num;
}

void Actor::setNombre(string nom) {
    nombre = nom;
}

void Actor::muestra() {
    cout << "ID: " << id;
    cout << "\t Nombre: " << nombre << endl; 
}