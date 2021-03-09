#include <iostream>
#include "exConstruct2.h"
using namespace std;

class Point {
   public:
    Point() { cout << "Point construit" << endl; }

    Point(const Point& p) { 
        cout << "Point copié" << endl; 
        this->value = p.value; 
    }

    ~Point() { cout << "Point détruit" << endl; }

    int value;
};

void exConstruct2(void)
{
    cout << "Ex 2 :" << endl;
    Point p1;
    p1.value = 5;
    cout << "Décl P2" << endl;
    Point p2;

    cout << "P2 = P1"  << endl;
    p2 = p1;

    cout << "P3 = p1" << endl;
    Point p3 = p1;
    cout << "P4(p1)" << endl;
    Point p4(p1);

    p4.value = 6;

    cout << "P1 val : " << p1.value << endl;
    cout << "P2 val : " << p2.value << endl;
    cout << "P3 val : " << p3.value << endl;
    cout << "P4 val : " << p4.value << endl;
}

