#include <iostream>
#include "pooEx3.h"
#include "car.h"
using namespace std;


void pooEx3(){
    std::cout << " Exercice 3" << endl;
    Car c;
    c.setPressure(2.3);
    for (int i = 0; i < NOMBREROUES; i++)
    {
        cout << "Roue : " << i << " pression : " << c.getWheel(i).getPressure() << endl;
    }
}