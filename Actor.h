#include <iostream>
#include <string>

using namespace std;

class Actor {
    private:
        int id;
        string nombre;
    public:
        Actor();
        Actor(int num,string nom);
        int getId();
        string getNombre();
        void setId(int num);
        void setNombre(string nom);
};