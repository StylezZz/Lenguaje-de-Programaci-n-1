/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 *  Codigo: 20203371
 *  Nombre: Gabriel Omar Duran Ruiz
 */

#include <iomanip>
#include <iostream>
#include <cstring>
#include <fstream>
#include "MetodoDinamicoExacto.h"
#define MAXCANTLINEA 120
using namespace std;


void AbrirArchivoLectura(ifstream &arch,const char *nombArch){
    arch.open(nombArch,ios::in);
    if(!arch){
        cout<<"ERROR, no se pudo abrir el archivo "<<nombArch;
        exit(1);
    }
}

void AbrirArchivoEscritura(ofstream &arch,const char *nombArch){
    arch.open(nombArch,ios::out);
    if(!arch){
        cout<<"ERROR, no se pudo abrir el archivo "<<nombArch;
        exit(1);
    }
}
//506117,EDGAR MUNOZ VERGEL Urologia,337.03
//codigo nombre especialidad tarifa
void lecturaDeMedicos(const char *nombArch,int *&med_Codigo,char **&med_Nombre,
        char **&med_Especialidad,double *&med_Tarifa){
    ifstream arch;
    AbrirArchivoLectura(arch,nombArch);
    double buffTarifa[200],tarifa;
    int buffCodigo[200],codigo,numDat=0;
    char *buffNomb[200],*buffEspecialidad[200],c,*nomb,*esp,buff[100];
    while(1){
        arch>>codigo>>c;
        if(arch.eof())break;
        leeNombEsp(nomb,esp,arch);
        //arch.getline(buff,100,',');
        arch>>tarifa;
        buffCodigo[numDat]=codigo;
        buffNomb[numDat]=nomb;
        buffEspecialidad[numDat]=esp;
        buffTarifa[numDat]=tarifa;
        numDat++;
    }
    copiarArreglosCrearDinamicosMed(med_Codigo,med_Nombre,med_Especialidad,med_Tarifa,
            buffCodigo,buffNomb,buffEspecialidad,buffTarifa,numDat);
}

void leeNombEsp(char *&nomb,char *&esp,ifstream &arch){
    char buff[150],auxEsp[80];
    arch.getline(buff,150,',');
    int i,j,k,longitud;
    for(i=0;buff[i];i++);

    for(j=i;j>=0;j--)if(buff[j]==' ')break;
    buff[j]=0;
    for(k=0;buff[j+1+k];k++){
        auxEsp[k]=buff[j+1+k];
    }
    auxEsp[k]=0;
    nomb = new char [strlen(buff)+1];
    strcpy(nomb,buff);
    esp = new char [strlen(auxEsp)+1];
    strcpy(esp,auxEsp);
}
void copiarArreglosCrearDinamicosMed(int *&med_Codigo,char **&med_Nombre,
        char **&med_Especialidad,double *&med_Tarifa,int *buffCodigo,char **buffNomb,
        char **buffEspecialidad,double *buffTarifa,int numDat){
    med_Codigo =  new int [numDat+1]{};
    med_Nombre =  new char *[numDat+1]{};
    med_Especialidad =  new char *[numDat+1]{};
    med_Tarifa = new double [numDat+1]{};
    for(int i=0;i<numDat;i++){
        med_Codigo[i]=buffCodigo[i];
        med_Nombre[i]=buffNomb[i];
        med_Especialidad[i]=buffEspecialidad[i];
        med_Tarifa[i]=buffTarifa[i];
    }
    med_Codigo[numDat]=0;
}


void pruebaDeLecturaMedicos(const char *nombArch,int *med_Codigo,char **med_Nombre,
        char **med_Especialidad,double *med_Tarifa){
    ofstream arch;
    AbrirArchivoEscritura(arch,nombArch);
    arch<<setw(60)<<right<<"VERIFICACION LECTURA MEDICOS"<<endl;
    arch<<setw(10)<<left<<"CODIGO"<<setw(60)<<left<<"NOMBRE MEDICO"<<setw(30)<<
            left<<"ESPECIALIDAD"<<left<<"TARIFA"<<endl;
    for(int i=0;med_Codigo[i];i++){
        arch<<setw(10)<<left<<med_Codigo[i]<<setw(60)<<left<<med_Nombre[i]<<
                setw(30)<<left<<med_Especialidad[i]<<setw(12)<<right<<
                setprecision(2)<<fixed<<med_Tarifa[i]<<endl;
    }
}
//43704548,Vizcardo/Maribel,892133,9/09/2022
//codPac nomb codMed fecha
//NO REPETIR PACIENTES
//CUIDADO CON LOS ARREGLOS NO INICIALIZADOS EN 0
// CARGAR
// codPac nombPac  pacCitas
void lecturaDeCitas(const char *nombArch,int *&pac_Dni,char **&pac_Nombre,int **&pac_Citas){
    ifstream arch;
    AbrirArchivoLectura(arch,nombArch);
    int buffCodPac[350]={},codPac,codMed,cantCit[350]={},pos,numDat=0,fecha,*buffPacCitas[350];
    char *buffNombPac[350],c,*nomb,buff[100];
    for(int i=0;i<350;i++)buffPacCitas[i] = new int [600];
    while(1){
        arch>>codPac>>c;
        if(arch.eof())break;
        nomb=leeCadena(arch,c);
        arch>>codMed>>c;
        leerFecha(arch,fecha);
        pos=buscarPaciente(codPac,buffCodPac,numDat);
        if(pos!=-1){
            agregarCitaAPaciente(buffCodPac[pos],buffNombPac[pos],
                    buffPacCitas[pos],cantCit[pos],codMed,fecha,nomb);
        }else{
            registrarNuevoPaciente(buffCodPac,buffNombPac,buffPacCitas,
                    codPac,nomb,codMed,fecha,numDat,cantCit);
        }
        cout<<"Llegue";
    }
    cout<<"Llegue2";
    copiarArreglosCrearDinamicosCitas(pac_Dni,pac_Nombre,pac_Citas,buffCodPac,
            buffNombPac,buffPacCitas,cantCit,numDat);
    for(int i=0;i<350;i++)delete buffPacCitas[i];
}

void agregarCitaAPaciente(int &codPac,char *nombPac,int *&citasPac,int &numCit,
        int codMed,int fecha,char *&nomb){
    citasPac[numCit*2]=codMed;
    citasPac[(numCit*2)+1]=fecha;
    numCit++;
}

void copiarArreglosCrearDinamicosCitas(int *&pac_Dni,char **&pac_Nombre,
        int **&pac_Citas,int *buffCodPac,char **buffNombPac,int **buffPacCitas,
        int *cantCit,int numDat){
    pac_Dni = new int [numDat+1]{};
    pac_Nombre = new char *[numDat+1]{};
    pac_Citas = new int *[numDat+1]{};
    for(int i=0;i<numDat;i++){
        pac_Dni[i]=buffCodPac[i];
        pac_Nombre[i]=buffNombPac[i];
        pac_Citas[i] =  new int [(2*cantCit[i])+2]{};
        llenarPacCitas(pac_Citas[i],buffPacCitas[i],cantCit[i]);
    }
}

void llenarPacCitas(int *pacCitas,int *buffPacCitas,int cantCit){
    for(int i=0;i<cantCit;i++){
        pacCitas[2*i]=buffPacCitas[2*i];
        pacCitas[(2*i)+1]=buffPacCitas[(2*i)+1];
    }
}

void registrarNuevoPaciente(int *buffCodPac,char **buffNombPac,int **buffPacCitas,
                    int codPac,char *nomb,int codMed,int fecha,int &numDat,int *cantCit){
    buffCodPac[numDat]=codPac;
    buffNombPac[numDat]=nomb;
    buffPacCitas[numDat][0]=codMed;
    buffPacCitas[numDat][1]=fecha;
    cantCit[numDat]=1;
    numDat++;
}
void leerFecha(ifstream &arch,int &fecha){
    int dd,mm,aa;
    char c;
    arch>>dd>>c>>mm>>c>>aa;
    fecha=dd+mm*100+aa*10000;
}
int buscarPaciente(int codPac,int *buffCodPac,int numDat){
    for(int i=0;i<numDat;i++){
        if(codPac==buffCodPac[i])return i;
    }
    return -1;
}
char *leeCadena(ifstream &arch,int c){
    char buff[80],*cad;
    arch.getline(buff,80,c);
    cad = new char (strlen(buff)+1);
    strcpy(cad,buff);
    return cad;
}
void pruebaDeLecturaDeCitas(const char *nombArch,int *pac_Dni,char **pac_Nombre,int **pac_Citas){
    ofstream arch;
    AbrirArchivoEscritura(arch,nombArch);
    arch<<setw(60)<<right<<"VERIFICACION LECTURA CITAS"<<endl;
    arch<<setw(10)<<left<<"DNI"<<setw(60)<<left<<"NOMBRE "<<endl;
    for(int i=0;pac_Dni[i];i++){
        arch<<setw(10)<<left<<pac_Dni[i]<<setw(60)<<left<<pac_Nombre[i]<<endl;
        arch<<"CITAS DEL PACIENTE:"<<endl;
        imprimeCitasPaciente(pac_Citas[i],arch);
    }
}
void imprimeCitasPaciente(int *pac_Citas,ofstream &arch){
    for(int i=0;pac_Citas[2*i];i++){
        arch<<setw(10)<<left<<pac_Citas[2*i]<<left<<pac_Citas[(2*i)+1]<<endl;
    }
}
void reporteDeIngresosMedicosYGastosDeLosPacientes(const char *nombArch,
            int *med_Codigo,char **med_Nombre,char **med_Especialidad,
        double *med_Tarifa,int *pac_Dni,char **pac_Nombre,int **pac_Citas){
    ofstream arch;
    AbrirArchivoEscritura(arch,nombArch);
    imprimeCabeceraIngresos(arch);
    imprimeCabeceraMedicos(arch);
    imprimeCabeceraPacientes(arch);
    for(int i=0;pac_Dni[i];i++){
        arch<<setw(2)<<right<<i+1<<")  "<<setw(10)<<left<<pac_Dni[i]<<setw(60)<<
                left<<pac_Nombre[i]<<setw(10)<<right<<endl;
    }
}

void imprimeCabeceraIngresos(ofstream &arch){
    arch<<setw(70)<<right<<"EMPRESA PRESTADORA DE SALUD"<<endl;
    imprimeLinea(arch,MAXCANTLINEA,'=');
    arch<<left<<"INGRESO DE LOS MEDICOS POR LAS CITAS"<<endl;
    imprimeLinea(arch,MAXCANTLINEA,'=');
    arch<<"No.  "<<setw(10)<<left<<"Codigo"<<setw(70)<<left<<"Nombre"<<
            setw(30)<<left<<"Especialidad"<<setw(20)<<left<<"Tarifa"<<
            "Total de ingresos"<<endl;
    imprimeLinea(arch,MAXCANTLINEA,'-');
}

void imprimeLinea(ofstream &arch,int cant,char c){
    for(int i=0;i<cant;i++)arch<<c;
    arch<<endl;
}

void imprimeCabeceraMedicos(ofstream &arch){
    
}

void imprimeCabeceraPacientes(ofstream &arch){
    
}