#include <iostream>
#include "Cours2203.h"

using namespace std;

class Human{
    public:
    Human(string name):name(name){}
    virtual void speak() = 0; // Un humain ne plus parler et on ne peut plus construire un humain

    /*{
        cout << "Je suis un humain " << endl; 
    }*/
    void printName()
    {
        cout << "Mon nom est : " << name << endl;
    }
    private:
    string name;
};

class Man : public Human{
    public:
        Man(string name) : Human(name) {}
        void speak() override
        {
            cout << "Je suis un homme" << endl;
        }
};

class Women : public Human{
    public:
        Women(string name) : Human(name) {}
        void speak() override
        {
            cout << "Je suis une femme" << endl;
        }
};


void printName(Human& h){
    h.printName();
    h.speak();
}



void Cours2203(){
    //Human human("Human");
    Man man1("Jean");
    Women women1("Alice");
    
    //printName(human);
    printName(man1);
    printName(women1);

    Human* tab[4];
    //tab[0] = &human;
    tab[1] = &man1;
    tab[2] = &women1;

    for(int i = 0; i<3; i++)
    {
        tab[i]->speak();
    }
}

struct A{
    A() { cout << "Const A" << endl; }
    A(int a) : val(a) { cout << "Const A1 : " << val << endl; }
    
    void print(){ cout << "Val : " << val << endl; }
    void test1() { cout << "Test 1 A" << endl; }
    virtual void test2() { cout << "Test 2 A" << endl; }
    
    int val = 6;
};

struct B : public A{
    B(){ cout << "Constr B" << endl; }

    void test1() { cout << "Test 1 B" << endl; }
    void test2() override { cout << "Test 2 B" << endl; }
};

struct C : public A{
    C() :A(4) { cout << "Constr C" << endl; }

    void test2() override { cout << "Test 2 C" << endl; }    
};

struct D : public B{
    D(){ cout << "Constr D" << endl; }

    void test1() { cout << "Test 1 D" << endl; }
    void test2() override { cout << "Test 2 D" << endl; }    
};

struct E : public B{
    E(){ cout << "Constr E" << endl; }

    void test1() { cout << "Test 1 E" << endl; }
};

void funcTest(A& p){
    p.test1();
    p.test2();
}

void cours22032()
{
    cout << "Constructeur A" << endl;
    A a;
    cout << "Constructeur B" << endl;
    B b;
    cout << "Constructeur C" << endl;
    C c;
    cout << "Constructeur D" << endl;
    D d;
    cout << "Constructeur E" << endl;
    E e;

    cout << "Call test 1" << endl;
    a.test1();
    b.test1();
    c.test1();
    d.test1();

    cout << "Call print E" << endl;
    e.print();
    cout << "Call print C" << endl;
    c.print();

    cout << "Call func test a" << endl;
    funcTest(a);
    cout << "Call func test b" << endl;
    funcTest(b);
    cout << "Call func test c" << endl;
    funcTest(c);
    cout << "Call func test d" << endl;
    funcTest(d);
    cout << "Call func test e" << endl;
    funcTest(e);

    cout << "Call ref 1c" << endl;
    A& r1 = c;
    r1.test1();
    r1.test2();

    cout << "Call ref 1e" << endl;
    A& r2 = e;
    r2.test1();
    r2.test2();
}