%{
    #include <iostream>
    #include "parser.h"


    Nodo *raiz;
%}

%option case-insensitive
%option noyywrap

DIGITO    [0-9]
LETRA     [a-zA-ZñÑ]
DIAG      ["/"]


GUIONES   [-_]

IDENTIFICADOR {LETRA}({LETRA}|{DIGITO}|{GUIONES})*

CADENA    "\""{IDENTIFICADOR}"\""
CAADENA   "\""[^"\""]*"\""
ENTERO {DIGITO}+

DIREC   {DIAG}{CADENA}
DELIMITADOR [\t\n\f" "]

/* Rule Section */
%% 


"mkdisk"        {printf("reconoce:mkdisk %s\n",yytext); strcpy(yylval.text, yytext); return mkdisk;}
"-size"          {return c_size;}
"-unit"          {return unit;}
"-path"         {return c_path;}

{ENTERO}        {strcpy(yylval.text, yytext); printf("Numero entero: %s\n",yytext);  return numero; }

"="                 {return igual;}
{DELIMITADOR} {}
.        {printf("Error Lexico");}
  
%% 

