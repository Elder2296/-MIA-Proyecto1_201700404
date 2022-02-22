%{
	#include <iostream>
	#include "parser.h"	
    //Nodo *raiz;
	
%}

%option case-insensitive
%option noyywrap


DIGITO [0-9]
NUMERO {DIGITO}


%%


 /*********************
  * Reglas y Acciones *
 **********************/

{NUMERO} {strcpy(yylval.text, yytext); return NUMERO;}
"mkdisk" {printf("reconoce parcentesis abre"); return MKDISK;}



"(" 	{ return(PARA);}
")" 	{printf("reconoce parcentesis cierra"); return(PARC);}
"+" 	{printf("reconoce parcentesis suma"); return(SUMA);}
"-" 	{printf("reconoce parcentesis resta"); return(RESTA);}
"*" 	{printf("reconoce parcentesis multi"); return(MULTPLICAR);}
"/" 	{printf("reconoce parcentesis diagonal"); return(DIVIDIR);}
[\t\r\f] {}
" "		{}
 
.            {std::cout <<yytext <<" Error Lexico" << std::endl;}
%%
