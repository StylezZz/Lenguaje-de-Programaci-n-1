/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#define MAXLINEAS 100
#include "BibCargaConductores.h"
#include "BibCargaFaltas.h"
using namespace std;

//char **conductor,***placa;
//    int *licencia,***falta,***fecha;
void cargarFaltas(int *licencia,char ***placa,int ***&falta,int ***&fecha){
    ifstream arch("RegistroDeFaltas.csv",ios::in);
    if(!arch){
        cout<<"Error no se pudo abrir el archivo RegistroDeFaltas.csv"<<endl;
        exit(1);
    }
    int numConductores = 0;
    for(numConductores=0;licencia[numConductores];numConductores++);
    
    falta = new int**[numConductores+1]{};
    fecha = new int**[numConductores+1]{};
    
    falta[numConductores]=nullptr;
    fecha[numConductores]=nullptr;
    
    int **buffFalta[800],**buffFecha[800],numDatos=0;
    int auxLicencia,dd,mm,aa,numFalta,auxFecha;
    char c,*placaAux;
    while(1){
        arch>>auxLicencia>>c;
        if(arch.eof())break;
        placaAux = leerCadena(arch);
        arch>>dd>>c>>mm>>c>>aa>>c>>numFalta;
        auxFecha= dd + mm*100+aa*10000;
        int posLicencia = buscarLicencia(auxLicencia,licencia);
        if(posLicencia!=-1){
            agregarDatos(falta[posLicencia],fecha[posLicencia],placa[posLicencia],
                    placaAux,auxFecha,auxLicencia,numFalta);
        }
    }
    for(int i=0;i<numConductores;i++){
        if(falta[i]!=nullptr){
            reducirMemoria(falta[i],fecha[i],placa[i]);
        }
    }
}

void reducirMemoria(int **&falta,int **&fecha,char **placa){
    int **arrFaltas,**arrFechas;
    int numInfracciones=0;
    for(numInfracciones=0;falta[numInfracciones];numInfracciones++);
    for(int i=0;i<numInfracciones;i++){
        if(falta[i]!=nullptr){
            reducir(falta[i],fecha[i]);
        }
    }
    arrFaltas = new int*[numInfracciones+1];
    arrFechas = new int*[numInfracciones+1];
    
    for(int i=0;i<numInfracciones;i++){
        arrFaltas[i]=falta[i];
        arrFechas[i]=fecha[i];
    }
    
    arrFaltas[numInfracciones]=nullptr;
    arrFechas[numInfracciones]=nullptr;
    delete fecha;
    delete falta;
    fecha = arrFechas;
    falta = arrFaltas;
}

void reducir(int *&falta,int *&fecha){
    int *arrFalta,*arrFecha;
    int numFaltas = falta[0];
    arrFalta = new int[numFaltas+1];
    arrFecha = new int[numFaltas];
    
    for(int i=0;i<numFaltas;i++){
        arrFalta[i]=falta[i];
        if(i<numFaltas){
            arrFecha[i]=fecha[i];
        }
    }
    delete fecha;
    delete falta;
    fecha= arrFecha;
    falta = arrFalta;
}

void agregarDatos(int **&falta,int **&fecha,char **placa,
        char *placaAux,int auxFecha,int auxLicencia,int numFalta){
    int posPlaca;
    posPlaca = buscarPlaca(placaAux,placa);
    if(posPlaca!=-1){
        if(falta==nullptr){
            //No se crea la estructura
            falta = new int*[50]{};
            fecha = new int*[50]{};
        }
        if(falta[posPlaca]==nullptr){
            falta[posPlaca]=new int[50]{};
            fecha[posPlaca]=new int[50]{};
            
            falta[posPlaca][falta[posPlaca][0]+1]=numFalta;
            fecha[posPlaca][falta[posPlaca][0]]=auxFecha;
            falta[posPlaca][0]=1;
        }else{
            falta[posPlaca][falta[posPlaca][0]+1]=numFalta;
            fecha[posPlaca][falta[posPlaca][0]]=auxFecha;
            falta[posPlaca][0]++;
        }
    }
}

int buscarPlaca(char *cad,char **placas){
    for(int i=0;placas[i];i++){
        if(strcmp(cad,placas[i])==0){
            return i;
        }
    }
    return -1;
}

int buscarLicencia(int cod,int *arreglo){
    for(int i=0;arreglo[i];i++){
        if(cod==arreglo[i])return i;
    }
    return -1;
}

char *leerCadena(ifstream &arch){
    char buff[200],*cad;
    arch.getline(buff,200,',');
    cad = new char[strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}
    
void imprimirLineas(ofstream &arch,char c){
    for(int i=0;i<MAXLINEAS;i++)arch<<c;
    arch<<endl;
}

void reporteFaltas(int *licencia,char **conductor,char ***placa,int ***falta,
        int ***fecha){
    ofstream archReporte("Reporte.txt",ios::out);
    if(!archReporte){
        cout<<"Error no se puede abrir el archivo Reporte.txt"<<endl;exit(1);
    }
    archReporte.precision(2);
    archReporte<<fixed;
    
    int fecha1,fechaN;
    double montoTotal;
    
    //Falta achicar memoria
    for(int i=0;conductor[i];i++){
        archReporte<<"Conductor: "<<conductor[i]<<endl;
        archReporte<<"Licencia No.: "<<licencia[i]<<endl;
        imprimirLineas(archReporte,'=');
        archReporte<<"Infracciones cometidas:"<<endl;
        imprimirLineas(archReporte,'=');
        archReporte<<"No."<<setw(15)<<"Placa"<<setw(15)<<"Cantidad"<<setw(30)<<"Monto total a pagar"<<setw(20)<<"Fecha 1"
                <<setw(15)<<"Fecha N"<<endl;
        if(falta[i]!=nullptr){ //Solo si existe faltas
            for(int k=0;falta[i][k];k++){
                if(falta[i][k]!=nullptr){ //Solo si existen faltas con esa palca
                    montoTotal=obtenerMontoTotal(falta[i][k],fecha[i][k],fecha1,fechaN);
                    archReporte<<setw(2)<<k+1<<")"<<setw(17)<<placa[i][k]<<setw(9)<<falta[i][k][0]
                            <<setw(26)<<montoTotal<<setw(29)<<fecha1<<setw(15)<<fechaN<<endl;
                }
            }
        }
        imprimirLineas(archReporte,'=');
    }
    
}

double obtenerMontoTotal(int *falta,int *fecha,int &fecha1,int &fechaN){
    double montoTotal=0.0;
    fecha1=fecha[0];
    //Los codigos de las faltas estan a partir de la posicion 1
    for(int i=1;i<falta[0];i++){
        montoTotal+=obtenerMontoMulta(falta[i]);
    }
    fechaN=fecha[falta[0]-1];
    return montoTotal;
}

double obtenerMontoMulta(int codInfraccionArch){
    ifstream archInfracciones("Infracciones.csv",ios::in);
    if(!archInfracciones){
        cout<<"ERROR: NO se puede abrir el archivo Infracciones.csv"<<endl;
        exit(1);
    }
    
    int codInfraccionAux;
    char descripcion[500],gravedad[50];
    double monto;
    
    while(1){
        archInfracciones>>codInfraccionAux;
        if(archInfracciones.eof()) break;
        archInfracciones.get();
        archInfracciones.getline(descripcion,500,',');
        archInfracciones.getline(gravedad,50,',');
        archInfracciones>>monto;
        if(codInfraccionArch==codInfraccionAux) return monto;
    }
    return 0.0;
}
