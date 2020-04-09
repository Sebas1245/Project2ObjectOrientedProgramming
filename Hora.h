#include <iostream>

using namespace std;

class Hora {
    private:
        int hh;
        int mm;
    public:
        Hora();
        Hora(int hora, int min);
        int getHh();
        int getMm();
        void setHh(int hr);
        void setMm(int min);
};