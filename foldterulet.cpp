#include "foldterulet.h"

Foldterulet* Foldterulet::letrejon(char ch, const std::string tul, int v){
    switch(ch){
        case 'p':return new Puszta(tul,v);
        case 'z':return new Zold(tul,v);
        case 't':return new Tavas(tul,v);
    }
    return nullptr;
}