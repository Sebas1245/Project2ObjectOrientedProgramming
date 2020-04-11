#include <iostream>
#include "Hora.h"

using namespace std;

Hora::Hora() {
    hh = 0;
    mm = 0;
}

Hora::Hora(int hr, int min) {
    hh = hr;
    mm = min;
}

int Hora::getHh() {
    return hh;
}

int Hora::getMm() {
    return mm;
}

void Hora::setHh(int hr) {
    hh = hr;
}

void Hora::setMm(int min) {
    mm = min;
}