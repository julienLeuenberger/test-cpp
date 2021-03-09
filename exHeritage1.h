#pragma once

class C1 {
   public:
    void afficher();
    //protected:
    int val;
};

class C2 : public C1 {
   public:
    C2() { val = 4; } 
    
};


void exHeritage1();