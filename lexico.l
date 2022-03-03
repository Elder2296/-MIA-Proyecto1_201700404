%{
    #include <iostream>
    #include "parser.h"


    Nodo *raiz;
%}

%option case-insensitive
%option noyywrap

letra       [a-zA-ZÑñáéíóúÁÉÍÓÚ]
numero      [0-9]+
caracter    ({letra}|{numero})
guion       ("-"|"–")


id          ({letra}|{numero})({letra}|{numero}|"_")*
idpath      {id}(" "{id})*
cadena      "\""{id}"\""
extension   "."{id}
path        "\""?("/"{idpath})*("/"{idpath}{extension}?)"\""?







/* Rule Section */
%% 


"mkdisk"            {printf("reconoce:mkdisk %s\n",yytext); strcpy(yylval.text, yytext); return mkdisk;}
"size"             { strcpy(yylval.text, yytext); return c_size;}
"unit"             {return c_unit;}
"path"             {return c_path;}

{numero}            {strcpy(yylval.text, yytext); printf("Numero entero: %s\n",yytext);  return numero; }

"="                 {return igual;}
{path}              {strcpy(yylval.text, yytext); printf("La ruta es: %s\n",yytext); return ruta;}
{letra}             {strcpy(yylval.text, yytext); return letra;}
{cadena}            {strcpy(yylval.text, yytext); return cadena;}
{guion}             {strcpy(yylval.text, yytext); return guion;}

[[:blank:]] {}

    .   {std::cout <<"Error De Escritura(Lexico)! [: "<<yytext <<" :]" << std::endl;}

  
%% 

