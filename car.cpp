#include "car.h"


double Wheel::getPressure(){
    return pressure;
}
void Wheel::setPressure(double pressure){
    this->pressure=pressure;
}

Wheel& Car::getWheel(int position){
    return wheels[position];
}

void Car::setPressure(double pressure){
    for (int i = 0; i < NOMBREROUES; i++)
    {
        this->wheels[i].setPressure(pressure);
    }
}