#include <iostream>
#include "Cours3003.h"
#include <math.h>

using namespace std;

class Printable{
    public :
    Printable(){}
    virtual string print() = 0; //

};
class Shape : public Printable{
    public:
        Shape(){};
        virtual ~Shape(){
            cout << "Shape est détruit" << endl;
        }

        virtual void calculArea()=0;
    protected:
        double area;
};
class Rectangle : public Shape{
    public:
        Rectangle(int height, int width):height(height), width(width){};
        ~Rectangle()
        {
            cout << " Rectangle est détruit " << endl;
        }
        void calculArea() override 
        {
            area = height*width;
        }
        string print() override
        {
            return "Un rectangle avec une aire de : " + to_string(area);

        }
    private:
        int height;
        int width;
};

class Hexagon : public Shape{
    public:
        Hexagon(int sideLength):sideLength(sideLength){};
        ~Hexagon()
        {
            cout << " Hexagon est détruit " << endl;
        }
        void calculArea() override 
        {
            area = 3*sqrt(3)*sideLength*sideLength/2;
        }
        string print() override
        {
            return "Un hexagon avec une aire de : " + to_string(area);

        }
    private:
        int sideLength;
};

class Text : public Printable{
    public:
        Text(string text):text(text){};
        string print() override
        {
            return "Le message : " + text;
        }
    private:
        string text;
};


void affichage(Printable& p)
{
    cout << "Le message à afficher est : " << endl;
    p.print();
}

void Cours3003()
{
    Shape* shapes[4] = {nullptr};
    shapes[0] = new Rectangle(10,20);
    shapes[1] = new Hexagon(3);

    shapes[0]->calculArea();
    shapes[1]->calculArea();

    Text t("Bonjour");

    affichage(*shapes[0]);
    affichage(t);

    delete shapes[0];
    delete shapes[1];

  

}

/*
Exercice 2 : Questions
1. La classe a pour but de faire en sorte que tous ses enfants soit printable
2. Non car Shape est une classe purement virtuelle
3. Non car Printable est une classe purement virtuelle
4. Oui il appel le destructeur enfant et ensuite le destructeur parent
5. Le destructeur du rectangle et ensuite celle de shape

Exercice 3: Questions
Le danger est qu'on stocke l'adresse d'un nouveau Rectangle dans p1 et dans p2. 
On supprime p1 mais on ne supprime pas p2. A la prochaine allocation, on risque
de mettre des valeurs dans p2
*/