#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "idojaras.h"
#include "foldterulet.h"
using namespace std;


Idojaras* Idojaras::keszit(int &kezdPara,int &r){
    if(kezdPara > 70){
        kezdPara = 30;
        cout << "Idojaras: esos---->\tParatartalom: " << kezdPara << endl;
        return Esos::instance();
    }
    else if(kezdPara < 40){
        cout << "Idojaras: napos\t---->\tParatartalom: " << kezdPara << endl;
        return Napos::instance();
    }
    else{
        int ertek = (kezdPara - 40)*3.3;
        if(r < ertek){
            cout << "Idojaras: esos\t---->\tParatartalom: " << kezdPara << endl;
            return Esos::instance();
        }
        else{
            cout << "Idojaras: felhos---->\tParatartalom: " << kezdPara << endl;
            return Felhos::instance();
        }
    }
}

Napos* Napos::_instance = nullptr;
Napos* Napos::instance(){
    if(_instance == nullptr){
        _instance = new Napos();
    }
    return _instance;
}

Idojaras* Napos::valtoztat(Puszta* p){
    p->vizValtozas(-3);
    return this;
}

Idojaras* Napos::valtoztat(Zold* z){
    z->vizValtozas(-6);
    return this;
}

Idojaras* Napos::valtoztat(Tavas* t){
    t->vizValtozas(-10);
    return this;
}

Felhos* Felhos::_instance = nullptr;
Felhos* Felhos::instance(){
    if(_instance == nullptr){
        _instance = new Felhos();
    }
    return _instance;
}

Idojaras* Felhos::valtoztat(Puszta* p){
    p->vizValtozas(1);
    return this;
}

Idojaras* Felhos::valtoztat(Zold* z){
    z->vizValtozas(2);
    return this;
}

Idojaras* Felhos::valtoztat(Tavas* t){
    t->vizValtozas(3);
    return this;
}

Esos* Esos::_instance = nullptr;
Esos* Esos::instance(){
    if(_instance == nullptr){
        _instance = new Esos();
    }
    return _instance;
}

Idojaras* Esos::valtoztat(Puszta* p){
    p->vizValtozas(5);
    return this;
}

Idojaras* Esos::valtoztat(Zold* z){
    z->vizValtozas(10);
    return this;
}

Idojaras* Esos::valtoztat(Tavas* t){
    t->vizValtozas(15);
    return this;
}