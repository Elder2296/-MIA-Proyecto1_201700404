#include <iostream>
#include <sys/stat.h>
#include <fstream>
#include <string.h>


#include "scanner.h"
#include "parser.h"
#include "nodo.h"

#include <list>

extern int yyparse();
extern Nodo *raiz;
using namespace std;

//int recorrerArbol(Nodo*);
void leerEntrada(char *);
void identifyComando(Nodo*);




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
    if(entrada[0]!='#'){
        YY_BUFFER_STATE buffer = yy_scan_string(entrada);
        
        if(yyparse()==0){
            
            cout<<"reconocio correctamente"<<endl;
            identifyComando(raiz);
        }   else{
            cout<<"no reconocio algo"<<endl;
        }

    }
    
     


}
void identifyComando(Nodo *raiz){
    cout<<"tipo "<<raiz->tipo<<endl;
    list<Nodo>::iterator pos;
    pos = raiz->hijos.begin();
    while (pos != raiz->hijos.end())
    {
        cout<<"tipo: "<<pos->tipo<<endl;
        list<Nodo>::iterator nietos;
        nietos = pos->hijos.begin();
        while (nietos!= pos->hijos.end())
        {
            cout<<"Nietos: "<<nietos->tipo<<" valor: "<<nietos->valor.c_str()<< endl;
            nietos++;
        }
        
        pos++;
    }
    
    
}