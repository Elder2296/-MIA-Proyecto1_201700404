%{
    #include <iostream>
    #include "scanner.h"
    #include "nodo.h"

    extern char *yytext;
    extern Nodo *raiz;


    using namespace std;

    int yyerror(const char* mens){
    std::cout<<mens<<std::endl;
    return 0;
    }

%}



%union {
    char text[400];
    class Nodo *NoneTerminal;
}




%token <text> numero c_path igual  mkdisk c_size  unit 


/*None Terminals*/
%type <NoneTerminal> INICIO;
%type <NoneTerminal> COMANDO MKDISK PAR_MKDISK;


%start INICIO;
%%
INICIO: COMANDO { raiz=$$;};

COMANDO:            mkdisk MKDISK        {$$ = new Nodo("MKDISK",""); $$->add(*$2); }
                    ;

MKDISK:             MKDISK PAR_MKDISK {$$=$1; $$->add(*$2);}
                    |   PAR_MKDISK { $$= new Nodo("parametros","");  $$->add(*$1);}
;

PAR_MKDISK:         c_size igual numero {$$ = new Nodo("size",$3);}
               
                    ;
%% 

