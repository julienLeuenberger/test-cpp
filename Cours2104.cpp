#include <iostream>
#include "Cours2104.h"

using namespace std;


struct Example{
    Example() {cout << "Construit" << endl; }
    ~Example() {cout << "Détruit" << endl; }
    int foo;
    int bar;
};

struct Data{
    void init(int capacite){
        tab = new double[capacite];
    }
    void liberer(){
        delete[] tab;
        tab = nullptr;
        capacite = 0;
    }

    int capacite;
    double* tab;
};



void Cours2104_Alloc_ex1()
{
    cout << "Exercice 1 allocation 21 avril 2021" << endl;
    cout << "Example d'allocation"  << endl;
    
    cout << "Allocation pour un objet"  << endl;
    Example* e1 = new Example();
    delete e1;
    
    cout << "Allocation pour un tableau d'int"  << endl;
    int* tab = new int[5];
    delete[] tab;

    cout << "Allocation pour un tableau d'objet"  << endl;
    Example** e2 = new Example*[5]();
    e2[0] = new Example();

    cout << "Suppression de la case 0"  << endl;
    delete e2[0];
    cout << "Suppression du tableau"  << endl;
    delete[] e2;
}

void Cours2104_Alloc_ex2(){
    Data d;
    d.init(10);
    d.tab[0] = 12;
    cout << "La valeur de tab[0] " << d.tab[0] << endl;
    d.liberer();
}

#define ERROR_DIVIDE_ZERO 12

int divide(int a, int b)
{
    if (b==0)
    {
        throw ERROR_DIVIDE_ZERO;
    }
}

void Cours2104_Exception_ex1()
{
    try
    {
        int res = divide(5, 0);
    }
    catch(int e)
    {
        cout << "Il y a eu une exception avec le nombre " << e << endl;
    }
}
void Cours2104_Exception_ex2()
{
    try
    {
        int x = 0;
        cout << "Entrer la valeur de x pour le calcul 12 / x = " << endl;
        cin >> x;
        if (!cin) // test si erreur d'entrée
        {
            cout << "ERREUR d'entrée" << endl;
            cin.clear ();  // efface le bit d'erreur
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // vide le buffer
        }
        else
        {
            if(x==0)
            {
                throw overflow_error("Divide by zero");
            }
            cout << "Le résultat est : " << 12/x << endl;
        }
        }
    catch(const std::exception& e)
    {
        cout << "\033[1;31mIl y a eu une erreur\033[0m" << endl;
        cout << e.what() << endl;
    }
    
}
 // EX 3
// Foo : f1 est construit
// Erreur func1 : "BOOM"
// Foo : f1 est détruit   pas oublier

// EX 4
// Foo : f1 est construit
// Erreur func3 : "BOOM"
// Foo : f1 est détruit
// Erreur : ex4 : BOOM        enfait si on fait throw; on passe plus loin

// EX 5
// Foo : f1 est construit
// Foo : f3 est construit
// Foo : f2 est construit
// Foo : f4 est construit
// Foo : f4 est détruit Il détruit f4 comme il y a un throw
// Problème : BOOM
// Foo : f1 est détruit

// EX 6
// f2 et f3 ne sont pas supprimés
// f2 car l'exception arrive avant le delete
// f3 car c++ détruit automatiquement les objets mais pas les allocs (pointeurs)

struct Foo
{
    Foo(string name) : name(name)
    {
        cout << "Foo : " << name << " est construit" << endl;
    }
    
    ~Foo()
    {
        cout << "Foo : " << name << " détruit" << endl;
    }
    string name;
};

void func2() {
    throw "BOOM";
}

void func1(Foo& f) {
    try
    {
        func2();
    }
    catch(char const* s)
    {
        cout << "Erreur func1 : " << s << endl;
    }
    
}

void Cours2104_Exception_ex3()
{
    try
    {
        Foo f1("f1");
        func1(f1);
    }
    catch (char const* m)
    {
        cout << "Erreur func1 : " << m << endl;
    }
}

void func3(Foo& f) {
    try
    {
        func2();
    }
    catch(char const* s)
    {
        cout << "Erreur func3 : " << s << endl;
        throw;
    }
}

void Cours2104_Exception_ex4(){
    try
    {
        Foo f1("f1");
        func3(f1);
    }
    catch (char const* m)
    {
        cout << "Erreur ex4 : " << m << endl;
    }
}

void func5(){
    Foo f4("f4");
    throw "BOOM";
    Foo f5("f5");
}

void Cours2104_Exception_ex5(){
    Foo f1("f1");
    Foo* f3 = new Foo("f3");

    try
    {
        Foo* f2 = new Foo("f2");
        func5(); // Si elle func5 lève une exception delete f2 ne sera pas executé
        delete f2;
    }
    catch(char const* m)
    {
        cout << "Problème : " << m << endl;   
    }
}

// EX 7
// Foo : f1 est construit
// Foo : f3 est construit
// Foo : f2 est construit
// Foo : f4 est construit
// Foo : f4 est détruit Il détruit f4 comme il y a un throw
// Foo : f2 est détruit
// Problème : BOOM
// Foo : f3 est détruit // les derniers en premier
// Foo : f1 est détruit


struct DynamicFoo
{
    DynamicFoo(string name)
    {
        p = new Foo(name);
    }

    ~DynamicFoo()
    {
        delete p;
    }

    Foo* p;
};

void Cours2104_Exception_ex7()
{
    Foo f1("f1");
    DynamicFoo f3("f3");

    try
    {
        DynamicFoo f2("f2");
        func5();
    }
    catch(char const* m)
    {
        cout << "Problème : " << m << endl;   
    }
}
