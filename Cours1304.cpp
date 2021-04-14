#include <iostream>
#include "Cours1304.h"

using namespace std;
struct GrandMere 
{
    GrandMere(){ cout << "Grand-mère construite" << endl; }
    GrandMere(int a) : value(a) { cout << "Grand-mère construite avec val" << a << endl; }
    int value;
};

struct Pere : public virtual GrandMere{
    Pere(){ cout << "Pere construit" << endl; }
    Pere(int a) : GrandMere(a) { cout << "Pere construit avec val" << endl; }
};

struct Mere : public virtual GrandMere{
    Mere(){ cout << "Mere construite" << endl; }
    Mere(int a) : GrandMere(a) { cout << "Mere construite avec val" << endl; }
};

struct  ENfant : public Mere, public Pere
{
    ENfant(){ cout << "Enfant construit" << endl; }
    ENfant(int a) : GrandMere(a), Mere(8) { cout << "Enfant construit avec val" << endl; }
};

void Cours1304()
{
    cout << "Example heritage" << endl;
    ENfant e(12);
    cout << "Value = " << e.value << endl;
}
