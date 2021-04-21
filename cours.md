# Cours 09 mars 
Tous les fichiers présentés dans le cours se trouveront dans un repo github : exemple-cours
La représentation des objets en C++:
il faut comprendre la séparation entre représentation et instanciation
```
// représentation
struct Car{
    Door& get_door(int index){
        return doors[index];
    }
    void init_door(int id){
        doors[id].init();
        this->num = 4;
    }
    Doors doors[2];
    int num;
}
Car c, c1 // une variable c et une variable c1
```
On peut clairement faire des objets d'objets d'objets
Initialisation : 3 solutions
1) Dans le constructeur (L'attribut peut être passé en paramètre)
    Risque d'appeler 2 fois le constructeur
2) Dans la définition (L'attribut sera fixe)
```
class Container
[
    public:
        Container(){

        }
];

Container c;
```
3) Liste d'initialisation (Pratique pour les constantes)
```
class Container
[
    public:
        Container() : o(3), o2(4) {}
        Object o;
        Object o2
];

Container c;
```
Avec cette méthode, le compilateur va déjà passer dans le constructeur avant d'instanciatier o



## Héritage
Si on fait une classe Square et une classe Hexagon on aura pour chaque :
```
class Square{
    const int nbr_side;
    double side_lengthM

    double area(){
        return pow(side_length, 2);
    }
}

class Hexagon{
    const int nbr_side;
    double side_lengthM

    double area(){
        return 3.0 * sqrt(3) / 2.0 * pow(side_length, 2);
    }
}
```
Elles ont les mêmes non de méthode

C'est là que l'orienté objet devient puissant avec l'héritage

"""
// Parent
class Shape{
    public:
        Shape() {}
        double side_length;
        string name;
        int nbr_side;

};
// Enfant
class Square : public Shape{
    public:
        Square() {}

        double area(){
            return pow(this->side_length, 2);
        }
}
"""
Tout ce que le parent a accès l'enfant a aussi pour autant que ce soit public ou protected
Protected pour soi-même et les enfants
Private pour soi-même uniquement

Constructeurs des classes enfants: les 2 premiers sont identiques
```
class Square : public Shape{
    public:
    Square() {}
};

class Square : public Shape{
    public:
    Square() : Shape() {}
};

class Square : public Shape{
    public:
    Square() : Shape(2) {}
};
```


## Cours 16 mars
+ public
- private
dièse protected
agrégation : objet non responsable du cycle de vie
Composition : responsable


## Cours 23 mars
Polymorphisme : virtual avant la méthode de la classe parent
Pour éviter les problème : écrire override vers les fonctions enfants
En mettant une fonction virtual à 0 on ne peut plus construire d'humain


## Cours 30 mars
Valeur static propre à une classe et donc à toutes les instances
=> initialiser en dehors de la classe
Allocation : Foo* p = new Foo();

## Cours 13 avril
Héritage virtuel
Voir exemple Cours1304.cpp => c'est une structure d'héritage en diamant
ça peut poser problème et on essaie d'éviter
Correction exercice 2 polymorphisme:
La classe printable est une interface. Une interface est une classe avec UNIQUEMENT des méthodes virtuelles pures. Elle permet de faire hériter certaine méthodes.
Règle ou bonne pratique : héritages multiples si les classes ont des attributs
Règle ou bonne pratique : une classe peut hériter d'une 2ème classe uniquement si c'est un interface

On ne peut pas instancier une interface ou toute classe avec au moins une méthode virtuelle pure.
Si une méthode est virtuelle dans une classe (pas une interface), le destructeur doit être virtuel

## Cours 20 avril
Rappel allocation
On remarque que delete veut toujours une adresse (un pointeur)

Foo* p = new Foo();
// p retourne null si problème
delete p;


Foo* tab[10]; // 10 est fixe désavantage
tab[0] = new Foo();
delete tab[0];


int* tab_i = new int[10]; // fixe aussi
delete[] tab_i;




Foo** alloc(int capacite)
{
    Foo** tab = new Foo*[capacite](); // dans tab on a une adresse de tableau
    for (int i =0; i < capacite; i++)
    {
        tab[i] = nullptrM
    }
    tab[0] = new Foo();
    tab[0]->value ) 12;

    return tab;
}

int main ()
{

    Foo** tab = alloc(10);
    delete tab[0];
    delete[] tab;
}

// tableau amélioré

struct Data
{
    int nbr;
    int capacite;
    Foo** tab;

    // add
    // delete
    // init
};


Erreur en C++:
Exemple pour une division par zéro : on teste avant la valeur, ... => naif car beaucoup de retour de code pour un code simple et ça engendre le double de ligne de code

Solution:

const int ERROR_FLOATING_POINT = 100;

int func1(int value)
{
    if(value == 0)
    {
        throw ERROR_FLOATING_POINT
    }
}


try
{
    int ret func1(0);
}
catch(int value) // problème entier
{
    cout << "Il y a eu un problème : "<< value << endl;
}
catch(...) // autre problème
{

}

Quand on lève des exceptions il faut absolument les catcher
Si on trouve pas le type d'execption on retire le catch(...) et on lit le message d'erreur. 




Il existe une interface exception qui contient au moins "what"
class MyException : public exception
{
    public:
        MyException(string const& phrase = "", int num=0) throw(): num(num), phrase(phrase){}
        virtual const char* what() const throw()
        {
            return phrase.c_str();
        }
        virtual ~MyException() throw() {}
        int num;
    private:
        string phrase;

};

// au moment de l'erreur :
    throw MyException("Problème BOOM", ERROR_FLOATING_POINT)


catch(MyException& e) // interet du & ou * : on ne passe que l'adresse sinon on copie l'entier de l'objet (temps de calcul) 
{
    cout << "Il y a eu un problème : "<< e.what << "le num : " << e.num << endl;
}

Une variable déclarée dans try n'existe pas dans le catch ou le reste du code

Si on veut propager d'un catch a un suivant on peut faire : throw;

Si c'est ça arrive souvent ce n'est pas une exception

Une boucle for avec un try catch à l'intérieur peut être une bonne solution pour lire du texte par exemple

## Cours 21 avril
On peut faire une allocation dans un try catch pour directement gérer le problème dans le catch
