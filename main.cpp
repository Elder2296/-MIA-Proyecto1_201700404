#include <iostream>
#include <sys/stat.h>
#include <fstream>
#include <string.h>

#include "nodo.h"
#include "scanner.h"
#include "parser.h"
#include <list>

extern int yyparse();
extern Nodo *raiz;
using namespace std;

//int recorrerArbol(Nodo*);
void leerEntrada(char *);



enum Choice
{
    OPSUMA = 1,
    OPRESTA = 2,
    OPMULTIPLICAR = 3,
    OPDIVIDIR = 4,
    OPNUMERO = 5,

};


int main()
{

    /*list<string> nombres;
    nombres.push_back("Juan");
    nombres.push_back("Oscar");
    nombres.push_back("Samantha");
    nombres.push_back("Angela");
    nombres.push_back("Wilder");
    nombres.push_back("Carlos");
    nombres.push_back("Oscar");
    cout<<"Hola mundo"<<endl;*/

    while(true){
        char input[500];
        printf(">> ");
        fgets(input,sizeof (input),stdin);
        leerEntrada(input);
        memset(input,0,400);
    }
}

void leerEntrada(char entrada[400]){
    string variable="cadnea y espacio";
    
    //yy_scan_string(entrada);
    YY_BUFFER_STATE buffer = yy_scan_string(entrada);
    
    if(yyparse()==0){
        cout<<"reconocio correctamente"<<endl;
    }   else{
        cout<<"no reconocio algo"<<endl;
    } 


}

/*
int recorrerArbol(Nodo* raiz){

    switch (raiz->tipo_) {
        case OPNUMERO:
        {
            return stoi(raiz->valor) ;
            
            break;
        }

        case OPSUMA:
        {
            Nodo izq = raiz->hijos.front();
            Nodo der = raiz->hijos.back();
            int a = recorrerArbol(&izq);
            int b = recorrerArbol(&der);
            return a + b;
            
        }

        case OPRESTA:
        {
            Nodo izq = raiz->hijos.front();
            Nodo der = raiz->hijos.back();
            int a = recorrerArbol(&izq);
            int b = recorrerArbol(&der);
            
        }


        case OPMULTIPLICAR:
        {
            Nodo izq = raiz->hijos.front();
            Nodo der = raiz->hijos.back();
            int a = recorrerArbol(&izq);
            int b = recorrerArbol(&der);
            
        }


        case OPDIVIDIR:
        {
            Nodo izq = raiz->hijos.front();
            Nodo der = raiz->hijos.back();
            int a = recorrerArbol(&izq);
            int b = recorrerArbol(&der);
            
        }


        default:
        {
            cout << "No lo se"<<endl;
            return 0;
        

        }

    }

}


*/