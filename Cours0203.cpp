#include <iostream>
#include "Cours0203.h"

using namespace std;

// class : de base tout est privé mais on rend public les méthodes
class Truck_o{
    public:
        void set_door_nbr(int nbr){
            this->nbr_door = nbr;
        }
        int get_door_nbr(){
            return
            
            this->nbr_door;
        }

    private:
        int nbr_door;
        int nbr_wheel;
    
};
// struct tout est public
struct Car_o{
    int nbr_door;
    int nbr_wheel;

    void set_door_nbr(int nbr){
        this->nbr_door = nbr;
    }
    int get_door_nbr(){
        return this->nbr_door;
    }
};


typedef struct{
    int nbr_door;
    int nbr_wheel;
}Car;

typedef struct{
    int nbr_door;
    int nbr_wheel;
}Truck;

void set_car_door_nbr(Car* car, int nbr)
{
    car->nbr_door=nbr*2;
}

void set_truck_door_nbr(Truck* truck, int nbr)
{
    truck->nbr_door=nbr*2;
}

void Cours0203()
{
    cout<<"Bonjour"<<endl;
    Car c;
    Car_o c_o;
    c_o.nbr_door = 4;
    cout<<"Nombre de portes de c_o "<<c_o.nbr_door<<endl;
    c_o.set_door_nbr(5);
    set_car_door_nbr(&c, 5);
    c.nbr_door = 3;
    cout<<"Nombre de portes de c_o "<<c_o.nbr_door<<endl;
    cout<<"Récupération du nombres de portes "<<c_o.get_door_nbr()<<endl;

    Truck_o t_o;
    Truck_o tab_o[10];
    t_o.set_door_nbr(4);
    cout<<"Récupération du nombres de portes de t_o "<<t_o.get_door_nbr()<<endl;

}