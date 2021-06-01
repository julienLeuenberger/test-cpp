#include <iostream>
#include "Cours0106.h"

using namespace std;

class Point{
    public:
        Point() : x(0), y(0) {}
        Point(int x, int y) : x(x), y(y) {}
        int getX() const {return x;} 
        int getY() const {return y;}

    private:
        int x;
        int y;
};

Point add_point(const Point& p1, const Point& p2) // référence ou pointeur
{
    int x = p1.getX() + p2.getX();
    int y = p1.getY() + p2.getY(); 
    Point p(x, y);
    return p;

}

Point operator+(const Point& p1, const Point& p2) // référence ou pointeur
{
    return add_point(p1, p2);
}

bool operator==(const Point& p1, const Point& p2) 
{
    bool b;
    if (p1.getX() == p2.getX() && p1.getY() == p2.getY())
    {
        b=true;
    }
    else
    {
        b=false;
    }
    return b;
}


void Cours0106(){
    cout << "Surcharge opérateur" << endl;
    Point p1(12,4);
    Point p2(3,1);

    Point p = p1 + p2;
    cout << "px : " << std::to_string(p.getX()) << endl;
    cout << "py : " << std::to_string(p.getY()) << endl;
    Point p3(20,8);
    Point p4(20,8);
    if(p3 == p4)
    {
        cout << "Les points sont égaux" << endl;
    }

    int val1 = 12;
    val1+=3;
}
    