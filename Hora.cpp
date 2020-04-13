#include <iostream>
#include <iomanip>
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

void Hora::muestra() {
    int dispHh;
    string timeOfDay;
    if (hh >= 12 && hh <= 23) {
        dispHh = hh-12;
        timeOfDay = "PM";
    }
    else if (hh >=0 && hh < 12){
        dispHh = hh;
        timeOfDay = "AM";
    }
    cout << setw(2) << setfill('0') << dispHh << ":" << setw(2) << setfill('0') << mm << " " << timeOfDay << endl;
}