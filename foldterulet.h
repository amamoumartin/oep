#pragma once

#include <string>
#include <iostream>
#include "idojaras.h"

class Foldterulet{
    protected:
        std::string _tulaj;
        int _vizMennyiseg;
        Foldterulet(const std::string &str, int v = 0){
            this->_tulaj = str;
            this->_vizMennyiseg = v;
            //_tulaj(str), _vizMennyiseg(v);
        }
    public:
        std::string get_tulaj() const {return _tulaj;}
        int get_viz() const{return _vizMennyiseg;}
        void vizValtozas(int v){
            _vizMennyiseg += v;
            if(_vizMennyiseg < 0){
                _vizMennyiseg = 0;
            }
        }
        virtual Foldterulet* ellenoriz(bool &b) = 0;
        virtual void get_adatok(){}
        virtual void valtozik(Idojaras* & id) = 0;
        virtual int pluszPara() = 0;
        virtual ~Foldterulet() {}
        static Foldterulet* letrejon(char ch, const std::string tul, int v);
};

class Puszta: public Foldterulet{
    public:
        Puszta(const std::string &tul, int v = 0):Foldterulet(tul,v){}
        Foldterulet* ellenoriz(bool &b) override{
            if (this->get_viz() > 15){
                std::string tulaja = this->get_tulaj();
                int vize = this->get_viz();
                delete this;
                b = false;
                return (Foldterulet :: letrejon('z',tulaja,vize));
            }
            b = true;
            return this;
        }
        void get_adatok() override{
            std::cout << "Tulajdonos: " << _tulaj << "\tFoldtipus: Puszta\tVizmennyiseg: " << _vizMennyiseg << std::endl;
        }
        int pluszPara() override{ return 3;}
        void valtozik(Idojaras* &id) override{
            id = id->valtoztat(this);
        }
};

class Zold: public Foldterulet{
    public:
        Zold(const std::string &tul, int v = 0):Foldterulet(tul,v){}
        Foldterulet* ellenoriz(bool &b) override{
            std::string tulaja = this->get_tulaj();
            int vize = this->get_viz();
            if (this->get_viz() > 50){
                delete this;
                b = false;
                return (Foldterulet :: letrejon('t',tulaja,vize));
            }
            else if(this->get_viz() < 16){
                delete this;
                b = false;
                return (Foldterulet :: letrejon('p',tulaja,vize));
            }
            b = true;
            return this;
        }
        void get_adatok() override{
            std::cout << "Tulajdonos: " << _tulaj << "\tFoldtipus: Zold\t\tVizmennyiseg: " << _vizMennyiseg << std::endl;
        }
        int pluszPara() override{ return 7;}
        void valtozik(Idojaras* &id) override{
            id = id->valtoztat(this);
        }
};

class Tavas: public Foldterulet{
    public:
        Tavas(const std::string &tul, int v = 0):Foldterulet(tul,v){}
        Foldterulet* ellenoriz(bool &b) override{
            if (this->get_viz() < 51){
                std::string tulaja = this->get_tulaj();
                int vize = this->get_viz();
                delete this;
                b = false;
                return (Foldterulet :: letrejon('z',tulaja,vize));
            }
            b = true;
            return this;
        }
        void get_adatok() override{
            std::cout << "Tulajdonos: " << _tulaj << "\tFoldtipus: Tavas\tVizmennyiseg: " << _vizMennyiseg << std::endl;
        }
        int pluszPara() override{ return 10;}
        void valtozik(Idojaras* &id) override{
            id = id->valtoztat(this);
        }
};