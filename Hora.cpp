#include <iostream>
#include "Hora.h"

using namespace std;

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