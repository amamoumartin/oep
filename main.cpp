#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "idojaras.h"
#include "foldterulet.h"

using namespace std;

void beolvasas(const std::string& fajlnev,vector<Foldterulet*>& foldek, Idojaras* &alap, int r){
    ifstream f(fajlnev);
    if(f.fail()){
        cerr << "Fajl megnyitasa sikertelen!" << endl;
        exit (1);
    }
    int db,viz,alapPara;
    f >> db;
    foldek.resize(db);
    string tul;
    char ch;
    cout << "0. kor: \n";
    for(int i = 0; i < db; i++){
        f >> tul >> ch >> viz;
        foldek[i] = Foldterulet :: letrejon(ch,tul,viz);
        foldek[i]->get_adatok();
    }
    f >> alapPara;
    cout << "Kezdeti paratartalom:\t" << alapPara <<endl;
    alap = Idojaras :: keszit(alapPara,r);
    alap->set_para(alapPara);
}

void szimulacio(vector<Foldterulet*>& foldek, Idojaras* &aktualis,int r){
    int para = aktualis->get_para();
    bool helper;
    for(int i = 0; i <foldek.size();i++){
        helper = true;
        foldek[i]->valtozik(aktualis);
        Foldterulet* f = foldek[i]->ellenoriz(helper);
        if (!helper){
            foldek[i] = f;
        }
        foldek[i]->get_adatok();
        para += foldek[i]->pluszPara();
    }

    aktualis = Idojaras :: keszit(para,r);
    aktualis->set_para(para);
}

void legVizesebb(vector<Foldterulet*>& foldek,string& tulaj){
    int maxind = 0;
    for(int i = 1; i < foldek.size();i++){
        if(foldek[i]->get_viz() > foldek[maxind]->get_viz()){
            maxind = i;
        }
    }
    cout << "A legvizesebb foldterulet(ek):\n";
    tulaj = foldek[maxind]->get_tulaj();
    for(int i = 0; i < foldek.size();i++){
        if(foldek[i]->get_viz() == foldek[maxind]->get_viz()){
            foldek[i]->get_adatok();
        }
    }
}

void osszesTorlese(vector<Foldterulet*>& foldek)
{
    for(int i=0; i<foldek.size(); ++i) delete foldek[i];
    Napos::torol();
    Felhos::torol();
    Esos::torol();
}

 //#define NORMAL_MODE
#ifdef NORMAL_MODE

int main(){
    srand(time(NULL));
    rand();
    int r = rand() % 98 + 1;
    vector<Foldterulet*> foldek;
    Idojaras* alap;
    beolvasas("t4.txt",foldek,alap,r);
    for(int i = 0; i < 10; i ++){
        cout << "\n" << (i+1) << " kor: \n";
        szimulacio(foldek,alap,r);
    }
    string leg;
    legVizesebb(foldek,leg);
    osszesTorlese(foldek);

    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("4 terulet, r = 99"){
    int r = 99;
    vector<Foldterulet*> foldek;
    Idojaras* alap;
    beolvasas("t1.txt",foldek,alap,r);
    CHECK(foldek[0]->get_tulaj() == "Bean");
    CHECK(foldek[0]->get_viz() == 86);
    CHECK(foldek[1]->get_tulaj() == "Green");
    CHECK(foldek[1]->get_viz() == 26);
    CHECK(foldek[2]->get_tulaj() == "Dean");
    CHECK(foldek[3]->get_viz() == 35);
    for(int i = 0; i < 10; i ++){
        cout << "\n" << (i+1) << " kor: \n";
        szimulacio(foldek,alap,r);
    }
    system("CLS");
    CHECK(foldek[0]->get_tulaj() == "Bean");
    CHECK(foldek[0]->get_viz() == 176);
    CHECK(foldek[1]->get_tulaj() == "Green");
    CHECK(foldek[1]->get_viz() == 99);
    CHECK(foldek[2]->get_tulaj() == "Dean");
    CHECK(foldek[3]->get_viz() == 114);
    string leg;
    legVizesebb(foldek,leg);
    CHECK(leg == "Bean");
    osszesTorlese(foldek);
}

TEST_CASE("4 terulet, r = 55"){
    int r = 55;
    vector<Foldterulet*> foldek;
    Idojaras* alap;
    beolvasas("t1.txt",foldek,alap,r);
    CHECK(foldek[0]->get_tulaj() == "Bean");
    CHECK(foldek[0]->get_viz() == 86);
    CHECK(foldek[1]->get_tulaj() == "Green");
    CHECK(foldek[1]->get_viz() == 26);
    CHECK(foldek[2]->get_tulaj() == "Dean");
    CHECK(foldek[3]->get_viz() == 35);
    for(int i = 0; i < 10; i ++){
        cout << "\n" << (i+1) << " kor: \n";
        szimulacio(foldek,alap,r);
    }
    system("CLS");
    CHECK(foldek[0]->get_tulaj() == "Bean");
    CHECK(foldek[0]->get_viz() == 236);
    CHECK(foldek[1]->get_tulaj() == "Green");
    CHECK(foldek[1]->get_viz() == 161);
    CHECK(foldek[2]->get_tulaj() == "Dean");
    CHECK(foldek[3]->get_viz() == 175);
    string leg;
    legVizesebb(foldek,leg);
    CHECK(leg == "Bean");
    osszesTorlese(foldek);
}

TEST_CASE("4 terulet, r = 78"){
    int r = 78;
    vector<Foldterulet*> foldek;
    Idojaras* alap;
    beolvasas("t1.txt",foldek,alap,r);
    CHECK(foldek[0]->get_tulaj() == "Bean");
    CHECK(foldek[0]->get_viz() == 86);
    CHECK(foldek[1]->get_tulaj() == "Green");
    CHECK(foldek[1]->get_viz() == 26);
    CHECK(foldek[2]->get_tulaj() == "Dean");
    CHECK(foldek[3]->get_viz() == 35);
    for(int i = 0; i < 10; i ++){
        cout << "\n" << (i+1) << " kor: \n";
        szimulacio(foldek,alap,r);
    }
    system("CLS");
    CHECK(foldek[0]->get_tulaj() == "Bean");
    CHECK(foldek[0]->get_viz() == 224);
    CHECK(foldek[1]->get_tulaj() == "Green");
    CHECK(foldek[1]->get_viz() == 148);
    CHECK(foldek[2]->get_tulaj() == "Dean");
    CHECK(foldek[2]->get_viz() == 119);
    CHECK(foldek[3]->get_viz() == 162);
    string leg;
    legVizesebb(foldek,leg);
    CHECK(leg == "Bean");
    osszesTorlese(foldek);
}

TEST_CASE("3 terulet, r = 60"){
    int r = 60;
    vector<Foldterulet*> foldek;
    Idojaras* alap;
    beolvasas("t2.txt",foldek,alap,r);
    CHECK(foldek[0]->get_tulaj() == "Mean");
    CHECK(foldek[0]->get_viz() == 1);
    CHECK(foldek[1]->get_tulaj() == "Green");
    CHECK(foldek[1]->get_viz() == 2);
    CHECK(foldek[2]->get_tulaj() == "Lean");
    for(int i = 0; i < 10; i ++){
        cout << "\n" << (i+1) << " kor: \n";
        szimulacio(foldek,alap,r);
    }
    system("CLS");
    CHECK(foldek[0]->get_tulaj() == "Mean");
    CHECK(foldek[0]->get_viz() == 11);
    CHECK(foldek[1]->get_tulaj() == "Green");
    CHECK(foldek[1]->get_viz() == 11);
    CHECK(foldek[2]->get_tulaj() == "Lean");
    CHECK(foldek[2]->get_viz() == 11);
    string leg;
    legVizesebb(foldek,leg);
    CHECK(leg == "Mean");
    osszesTorlese(foldek);
}

TEST_CASE("3 terulet, r = 40"){
    int r = 40;
    vector<Foldterulet*> foldek;
    Idojaras* alap;
    beolvasas("t2.txt",foldek,alap,r);
    CHECK(foldek[0]->get_tulaj() == "Mean");
    CHECK(foldek[0]->get_viz() == 1);
    CHECK(foldek[1]->get_tulaj() == "Green");
    CHECK(foldek[1]->get_viz() == 2);
    CHECK(foldek[2]->get_tulaj() == "Lean");
    CHECK(foldek[2]->get_viz() == 3);
    for(int i = 0; i < 10; i ++){
        cout << "\n" << (i+1) << " kor: \n";
        szimulacio(foldek,alap,r);
    }
    system("CLS");
    CHECK(foldek[0]->get_tulaj() == "Mean");
    CHECK(foldek[0]->get_viz() == 30);
    CHECK(foldek[1]->get_tulaj() == "Green");
    CHECK(foldek[1]->get_viz() == 30);
    CHECK(foldek[2]->get_tulaj() == "Lean");
    CHECK(foldek[2]->get_viz() == 30);
    string leg;
    legVizesebb(foldek,leg);
    CHECK(leg == "Mean");
    osszesTorlese(foldek);
}

TEST_CASE("10 terulet, r = 50"){
    int r = 50;
    vector<Foldterulet*> foldek;
    Idojaras* alap;
    beolvasas("t3.txt",foldek,alap,r);
    CHECK(foldek[0]->get_tulaj() == "Mean");
    CHECK(foldek[0]->get_viz() == 1);
    CHECK(foldek[1]->get_tulaj() == "Team");
    CHECK(foldek[1]->get_viz() == 68);
    CHECK(foldek[2]->get_tulaj() == "Green");
    CHECK(foldek[2]->get_viz() == 21);
    CHECK(foldek[3]->get_tulaj() == "Lean");
    CHECK(foldek[4]->get_tulaj() == "Shean");
    CHECK(foldek[4]->get_viz() == 60);
    CHECK(foldek[5]->get_tulaj() == "Teen");
    CHECK(foldek[5]->get_viz() == 32);
    CHECK(foldek[6]->get_tulaj() == "Keen");
    CHECK(foldek[6]->get_viz() == 3);
    CHECK(foldek[7]->get_tulaj() == "Xean");
    CHECK(foldek[8]->get_viz() == 40);
    CHECK(foldek[9]->get_tulaj() == "Ween");
    for(int i = 0; i < 10; i ++){
        cout << "\n" << (i+1) << " kor: \n";
        szimulacio(foldek,alap,r);
    }
    system("CLS");
    CHECK(foldek[0]->get_viz() == 75);
    CHECK(foldek[1]->get_viz() == 193);
    CHECK(foldek[2]->get_viz() == 133);
    CHECK(foldek[3]->get_viz() == 75);
    CHECK(foldek[4]->get_viz() == 180);
    CHECK(foldek[5]->get_viz() == 146);
    CHECK(foldek[6]->get_viz() == 75);
    CHECK(foldek[7]->get_viz() == 195);
    CHECK(foldek[8]->get_viz() == 159);
    CHECK(foldek[9]->get_viz() == 101);
    string leg;
    legVizesebb(foldek,leg);
    CHECK(leg == "Xean");
    osszesTorlese(foldek);
}

TEST_CASE("10 terulet, r = 60"){
    int r = 60;
    vector<Foldterulet*> foldek;
    Idojaras* alap;
    beolvasas("t4.txt",foldek,alap,r);
    CHECK(foldek[0]->get_tulaj() == "Mean");
    CHECK(foldek[0]->get_viz() == 1);
    CHECK(foldek[1]->get_tulaj() == "Team");
    CHECK(foldek[1]->get_viz() == 68);
    CHECK(foldek[2]->get_tulaj() == "Green");
    CHECK(foldek[2]->get_viz() == 21);
    CHECK(foldek[3]->get_tulaj() == "Lean");
    CHECK(foldek[4]->get_tulaj() == "Shean");
    CHECK(foldek[4]->get_viz() == 60);
    CHECK(foldek[5]->get_tulaj() == "Teen");
    CHECK(foldek[5]->get_viz() == 32);
    CHECK(foldek[6]->get_tulaj() == "Keen");
    CHECK(foldek[6]->get_viz() == 3);
    CHECK(foldek[7]->get_viz() == 70);
    CHECK(foldek[8]->get_tulaj() == "Eeen");
    CHECK(foldek[9]->get_tulaj() == "Ween");
    for(int i = 0; i < 10; i ++){
        cout << "\n" << (i+1) << " kor: \n";
        szimulacio(foldek,alap,r);
    }
    system("CLS");
    CHECK(foldek[0]->get_viz() == 101);
    CHECK(foldek[1]->get_viz() == 218);
    CHECK(foldek[2]->get_viz() == 146);
    CHECK(foldek[3]->get_viz() == 103);
    CHECK(foldek[4]->get_viz() == 210);
    CHECK(foldek[5]->get_viz() == 172);
    CHECK(foldek[6]->get_viz() == 103);
    CHECK(foldek[7]->get_viz() == 220);
    CHECK(foldek[8]->get_viz() == 180);
    CHECK(foldek[9]->get_viz() == 119);
    string leg;
    legVizesebb(foldek,leg);
    CHECK(leg == "Xean");
    osszesTorlese(foldek);
}


#endif