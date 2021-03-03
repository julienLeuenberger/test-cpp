#pragma once

#define NOMBREROUES 4

class Wheel{
    public:
        double getPressure();
        void setPressure(double pressure);
    
    private:
        double pressure;

};
class Car{
    public:
        Wheel& getWheel(int position);
        void setPressure(double pressure);
    private:
        Wheel wheels[NOMBREROUES];

};