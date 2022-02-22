%{

/********************** 
 * Declaraciones en C *
 **********************/
  #include <iostream>
  #include "scanner.h"
  //#include "nodo.h"

    extern int yylex(void);
    //extern Nodo *raiz;

    int yyerror(const char* mens){
        std::cout<<mens<<std::endl;
        return 0;
    }

%}

/*************************
  Declaraciones de Bison *
 *************************/


%union
{
        char text[400];
        //class Nodo *nodito;
}


%start inicio;


%token <text> NUMERO
%token <text>PARA
%token <text>PARC
%token <text>SUMA
%token <text>RESTA
%token <text>MULTPLICAR
%token <text>DIVIDIR





/*Definir precedencia de operaciones*/
%left SUMA RESTA
%left MULTPLICAR DIVIDIR







%%
/***********************
 * Reglas Gramaticales *
 ***********************/

inicio: exp { };



exp : exp SUMA exp { };
    | exp RESTA exp { };
    | exp MULTPLICAR exp { };
    | exp DIVIDIR exp { };
    | NUMERO {  };

%%
/**********************
 * Codigo C Adicional *
 **********************/
