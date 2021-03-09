#include <iostream>
#include "exHeritage1.h"
using namespace std;

void C1::afficher() { cout << "Val : " << val << endl; }

void exHeritage1()
{
    C2 c;
    c.afficher();
    c.val = 2;
    c.afficher();
}
