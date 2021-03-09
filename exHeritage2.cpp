#include <iostream>
#include "exHeritage2.h"
using namespace std;

struct Parent{
    Parent(){
        cout << "Aff : A" << endl;
    }
    Parent(int a){
        cout << "Aff : B" << endl;
    }
};

struct Enfant : public Parent{
    Enfant(){
        cout << "Aff : C" << endl;
    }
    Enfant(int a){
        cout << "Aff : D" << endl;
    }
    Enfant(int a, int b) : Parent(a){
        cout << "Aff : E" << endl;
    }
    Enfant(double a) : Parent(a){
        cout << "Aff : F" << endl;
    }
};

void exHeritage2(){
    cout << "Exercice 2" << endl;
    cout << "E1" << endl;
    Enfant e1;
    cout << "p1" << endl;
    Parent p1(12);
    cout << "E2" << endl;
    Enfant e2(1,2);
    cout << "E3" << endl;
    Enfant e3(5.3);
    cout << "E4" << endl;
    Enfant e4(2);
}

