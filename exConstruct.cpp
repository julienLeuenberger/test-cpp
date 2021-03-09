#include <iostream>
#include "exConstruct.h"
using namespace std;


class C1 {
   public:
    C1() { cout << "C1 est construit" << endl; }
    ~C1() { cout << "C1 est détruit" << endl; }
};

class C2 {
   public:
    C2() { cout << "C2 est construit" << endl; }
    C2(int a) { cout << "C2 avec param : " << a << endl; }
    ~C2() { cout << "C2 est détruit" << endl; }

    C1 c1[3];
};

void exConstruct(void)
{
    C2 c(3);
}