#include <iostream>
#include "Cours0303.h"

using namespace std;

class Object{
    public:
        Object(){
            cout << "Obj" << endl;
        }
};


class Truck{
    public:
        Truck(){
            cout << "Le camion est construit" << endl;
            nbr_wheel = 4;
            nbr_door = 5;
            // Allouer de la mémoire pour des données
        }
        // On fait des destructeurs pour redonner de la mémoire en cas d'allocation
        ~Truck(){
            cout << "Le camion est detruit" << endl;
            // Libérer de la mémoire
        }
        Object o; // Objet dans un objet
    private:
        int nbr_wheel;
        int nbr_door;
};

void Cours0303(){

    Truck c;
}
    
