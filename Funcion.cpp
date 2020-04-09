#include <iostream>
#include <string>
#include "Funcion.h"

using namespace std;

Funcion::Funcion() {
    cveFuncion = "N/D";
    numPeli = 0;
    hora.setHh(-1);
    hora.setMm(-1);
    sala = 0;
}

Funcion::Funcion(string clave, int numP, Hora hr, int numSala) {
    cveFuncion = clave;
    numPeli = numP;
    hora.setHh(hr.getHh);
    hora.setMm(hr.getMm);
    sala = numSala;
}

string Funcion::getCveFuncion() {
    return cveFuncion;
}

int Funcion::getNumPeli() {
    return numPeli;
}

Hora Funcion::getHora() {
    return hora;
}

int Funcion::getSala() {
    return sala;
}

void Funcion::setCveFuncion(string clave) {
    cveFuncion = clave;
}

void Funcion::setNumPeli(int num) {
    numPeli = num;
}

void Funcion::setHora(Hora hr) {
    hora.setHh(hr.getHh);
    hora.setMm(hr.getMm);
}

void Funcion::setSala(int numSala) {
    sala = numSala;
}
