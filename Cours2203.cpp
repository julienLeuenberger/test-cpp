#include <iostream>
#include "Cours2203.h"

using namespace std;

class Human{
    public:
    Human(string name):name(name){}
    virtual void speak()
    {
        cout << "Je suis un humain " << endl; 
    }
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
    Human human("Human");
    Man man1("Jean");
    Women women1("Alice");
    
    printName(human);
    printName(man1);
    printName(women1);

    Human* tab[4];
    tab[0] = &human;
    tab[1] = &man1;
    tab[2] = &women1;

    for(int i = 0; i<3; i++)
    {
        tab[i]->speak();
    }
}