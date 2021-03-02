#include <iostream>
#include "pooEx2.h"
using namespace std;

class Value {
   public:
    int getValue() { return value; }

    void setValue(int value) { this->value = value; }

   private:
    int value;
};

class Container {
   public:
    Value& getValRef() { return val; }

    Value getVal() { return val; }

   private:
    Value val;
};

void pooEx2()
{
    cout << endl << "Exercice 2 reference" << endl;
    Container c;
    c.getValRef().setValue(4);
    Value v1 = c.getVal();
    Value v2 = c.getVal();
    Value v3 = c.getValRef(); // Attention v3 n'est pas une reference
    Value& v4 = c.getValRef();

    int num = 1;

    cout << num << ") V1 : " << v1.getValue() << endl;
    cout << num << ") V2 : " << v2.getValue() << endl;
    cout << num << ") V3 : " << v3.getValue() << endl;
    cout << num << ") V4 : " << v4.getValue() << endl;
    cout << num << ") C : " << c.getVal().getValue() << endl << endl;

    num = 2;
    v1.setValue(6);
    cout << num << ") V1 : " << v1.getValue() << endl;
    cout << num << ") V2 : " << v2.getValue() << endl;
    cout << num << ") V3 : " << v3.getValue() << endl;
    cout << num << ") V4 : " << v4.getValue() << endl;
    cout << num << ") C : " << c.getVal().getValue() << endl << endl;

    num = 3;
    v3.setValue(3);
    cout << num << ") V1 : " << v1.getValue() << endl;
    cout << num << ") V2 : " << v2.getValue() << endl;
    cout << num << ") V3 : " << v3.getValue() << endl;
    cout << num << ") V4 : " << v4.getValue() << endl;
    cout << num << ") C : " << c.getVal().getValue() << endl << endl;

    num = 4;
    v4.setValue(5);
    cout << num << ") V1 : " << v1.getValue() << endl;
    cout << num << ") V2 : " << v2.getValue() << endl;
    cout << num << ") V3 : " << v3.getValue() << endl;
    cout << num << ") V4 : " << v4.getValue() << endl;
    cout << num << ") C : " << c.getVal().getValue() << endl << endl;
}