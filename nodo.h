#ifndef NODO_H
#define NODO_H
#include <string>
#include <iostream>
#include <list>
using namespace std;


class Nodo
{
public:
    Nodo(string tipo, string valor);
    
    string tipo;
    string valor;
    int linea;
    int columna;
    int tipo_;
    string cadenaDot;
    list<Nodo> hijos;
    int getTipo();
    void add(Nodo n);
};



#endif // NODO_H
