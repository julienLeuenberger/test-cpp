#include <iostream>
#include "pooEx1.h"
#include "square.h"
using namespace std;

void pooEx1()
{
    cout << "Ex1 Objet Square" << endl;
    Square sq;
    //sq.side_length = 3.4; // Cette ligne doit provoquer une erreur
    
    // Ici il faut mettre le côté de sq a 3.4;
    sq.set_size(3.4);
    // Compléter l'affichage ci-dessous.
    cout << "Le côté vaut : " << sq.get_side() << " et une aire de : " << sq.get_area() << endl;
}