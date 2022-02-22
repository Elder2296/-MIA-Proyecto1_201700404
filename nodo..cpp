#include "nodo.h"

using namespace std;

Nodo::Nodo(string t, string v){
    
    tipo =t;
    valor = v;
    tipo_ = getTipo();
    hijos = list<Nodo>();
}

int Nodo::getTipo()
{
    if(this->tipo=="makdisk")return 1;
    return 0;
}

void Nodo::add(Nodo n){
    hijos.push_back(n);
}




