#include <iostream>
#include <sys/stat.h>
#include <fstream>
#include <string.h>
#include <cstring> //compara cadenas

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
void leerMKDISK(Nodo*);
void crearArchivoMBR(string ruta);
string getDireccion(string ruta);

typedef struct {
    char partStatus; /*Estado activo e inactivo del disco*/
    char partType; /*tipo de particion*/
    char partAdjustment; /*ajuste de paticion*/
    int partInit; /*inicio del byte de particion*/
    int partSize; /*tamaño de particion (bytes)*/
    char partName[16]; /*nombre de la particion*/
} Partition;
typedef struct{
    int mbrSize; //Tamaño de disco (bytes)
    time_t mbrDate; //Fecha y hora de creacion del disco
    int mbrIdent; //Identificacion del disco
    char mbrAdjustment; //Tipo de ajuste
    Partition mbrPartition[4]; //Particiones, Maximo 4
}MBR;




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
    //cout<<"comando reconocido: "<<raiz->tipo.c_str()<<endl;
    if(strcmp(raiz->tipo.c_str(),"MKDISK")==0){
        //cout<<"RECONOCIO EL COMANDO"<<endl;
        leerMKDISK(raiz);

    }


    
    
    
    
    
}
void leerMKDISK(Nodo *nodo){
    //Numero de veces que viene en el comando
    //cout<<"ENTRO A LEER EL MKDISK"<<endl;
    int c_size = 0;
    int c_fit = 0;
    int c_unit = 0;
    int c_path = 0;
    bool repeticion = false; //cuando se repite

    int valorSize = 0;
    string valorF = "";
    string valorU = "";
    string valorPath = "";

    list<Nodo>::iterator pos;
    pos = raiz->hijos.begin();
    while (pos != raiz->hijos.end())
    {
        
        //cout<<"tipo: "<<pos->tipo<<endl;
        list<Nodo>::iterator nietos;
        nietos = pos->hijos.begin();
        while (nietos!= pos->hijos.end())
        {

            if(strcmp( nietos->tipo.c_str(),"size")==0){
                //cout<<"RECONOCIO PARAMETRO SIZE"<<endl;
                    
                if(c_size<1){
                    valorSize = atoi(nietos->valor.c_str());
                    c_size++;
                }else{
                    cout<<"El parametro SIZE ya esta repetido en el comando"<<endl;
                    repeticion = true;
                    break;
                }
            }
            else if(strcmp(nietos->tipo.c_str(),"fit")==0){
                if(c_fit<1){
                    valorF = *nietos->valor.c_str();
                    c_fit++;
                }else{
                    cout<<"El parametro FIT ya esta repetido en el comando"<<endl;
                    repeticion = true;
                    break;
                }
            }
            else if(strcmp(nietos->tipo.c_str(),"unit" )==0){
                //cout<<"RECONOCIO PARAMETRO UNIT"<<endl;
                if(c_fit<1){
                    valorU = *nietos->valor.c_str();
                    c_unit++;
                }else{
                    cout<<"El parametro UNIT ya esta repetido en el comando"<<endl;
                    repeticion = true;
                    break;
                }
            }else if(strcmp(nietos->tipo.c_str(),"path" )==0){
                //cout<<"RECONOCIO PARAMETRO PATH"<<endl;
                if(c_path<1){
                    //cout<<"rutaZ: "<<nietos->valor.c_str()<<endl;
                    valorPath = nietos->valor.c_str();
                    c_path++;
                }else{
                    cout<<"El parametro PATH ya esta repetido en el comando"<<endl;
                    repeticion = true;
                    break;
                }
            }

            
            
            nietos++;


        }
        
        pos++;
    }

    if(!repeticion){
        
                    
        if(c_path == 1 ){
            if(c_size == 1){
                MBR arch;
                int size = 1024;
                cout<<"PROCEDERA PARA CREAR ARCHIVO"<<endl;
                crearArchivoMBR(valorPath);

            }

        }
    }

}
void crearArchivoMBR(string ruta){
    string ruta_temp = getDireccion(ruta);
    string instruccion = "sudo mkdir -p \'"+ruta_temp+"\'";
    system(instruccion.c_str());
    string inst2 = "sudo chmod -R 777 \'"+ruta_temp+"\'";
    system(inst2.c_str());
    string file_path = ruta.c_str();

    FILE *file = fopen(file_path.c_str(),"wb");

    if(file = fopen(file_path.c_str(),"wb")){
        fclose(file);
    }else{
        cout<<"Error al crear el archivo"<<endl;
    }

}
string getDireccion(string ruta){
    //cout<<"rutaY: "<<ruta<<endl;
    string tem = ruta.c_str();
    //cout<<"rutaX: "<<tem<<endl;
    string car = "/";
    size_t pos = 0;
    string newruta = "";
    while ((pos = tem.find(car)) != string::npos){
        newruta += tem.substr(0,pos)+"/";
        tem.erase(0,pos+car.length());

    }
    return newruta;
    
}