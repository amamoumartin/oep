#pragma once

#include <string>

class Puszta;
class Zold;
class Tavas;

class Idojaras{
    private:
        int para;
    public:
        virtual Idojaras* valtoztat(Puszta *p) = 0;
        virtual Idojaras* valtoztat(Zold *p) = 0;
        virtual Idojaras* valtoztat(Tavas *p) = 0;
        virtual std::string get_tipus() const = 0;
        virtual ~Idojaras() {}
        int get_para() {return para;}
        void set_para(int ujPara){this->para = ujPara;}
        static Idojaras* keszit(int &kezdPara,int &r);
};

class Napos : public Idojaras{
    public:
        static Napos* instance();
        Idojaras* valtoztat(Puszta *p) override;
        Idojaras* valtoztat(Zold *p) override;
        Idojaras* valtoztat(Tavas *p) override;
        std::string get_tipus() const override {return "Napos";}
        void static torol(){
            if(_instance != nullptr){
                delete _instance;
            }
            _instance = nullptr;
        }
    private:
        Napos(){}
        static Napos* _instance;
};

class Felhos : public Idojaras{
    public:
        static Felhos* instance();
        Idojaras* valtoztat(Puszta *p) override;
        Idojaras* valtoztat(Zold *p) override;
        Idojaras* valtoztat(Tavas *p) override;
        std::string get_tipus() const override {return "Felhos";}
        void static torol(){
            if(_instance != nullptr){
                delete _instance;
            }
            _instance = nullptr;
        }
    private:
        Felhos(){}
        static Felhos* _instance;
};

class Esos : public Idojaras{
    public:
        static Esos* instance();
        Idojaras* valtoztat(Puszta *p) override;
        Idojaras* valtoztat(Zold *p) override;
        Idojaras* valtoztat(Tavas *p) override;
        std::string get_tipus() const override {return "Esos";}
        void static torol(){
            if(_instance != nullptr){
                delete _instance;
            }
            _instance = nullptr;
        }
    private:
        Esos(){}
        static Esos* _instance;
};