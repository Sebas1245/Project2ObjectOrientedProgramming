#include <iostream>
#include <string>
#include "Hora.h"

using namespace std;

class Funcion {
    private:
        string cveFuncion;
        int numPeli;
        Hora hora;
        int sala;
    public:
        Funcion();
        Funcion(string clave, int numP, Hora, int numSala);
        string getCveFuncion();
        int getNumPeli();
        Hora getHora();
        int getSala();
        void setCveFuncion(string clave);
        void setNumPeli(int num);
        void setHora(Hora);
        void setSala(int numSala);
};