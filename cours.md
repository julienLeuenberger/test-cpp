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
