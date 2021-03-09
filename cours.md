## Cours 09 mars 
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

