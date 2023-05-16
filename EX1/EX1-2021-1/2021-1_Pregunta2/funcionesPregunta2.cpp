/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#define MAXLINEAS 100
#include "funcionesPregunta2.h"
using namespace std;
enum regConductor {LICENCIA,NOMBRE};
enum regFalta{INFRACCION,DESCRIPCION,MONTO};
enum Consolidado{CODLICENCIA,NOMBRECOND,AA,MM,MONTOTOTAL};
void cargarDatos(void *&conductor,void *&falta){
    ifstream archConductores("Conductores.csv",ios::in);
    ifstream archInfracciones("Infracciones.csv",ios::in);
    if(!archConductores){
        cout<<"Error no se pudo abrir el archivo Conductores.csv"<<endl;
        exit(1);
    }
    if(!archInfracciones){
        cout<<"Error no se pudo abrir el archivo Infracciones.csv"<<endl;
        exit(1);
    }
    leerConductores(conductor,archConductores);
    imprimeconductor(conductor);
    leerFaltas(falta,archInfracciones);
    imprimefalta(falta);
}

void imprimefalta(void *falta){
    void **aux = (void**)falta;
    ofstream arch("ReporteFaltas.txt",ios::out);
    if(!arch){
        cout<<"Error no se pudo abrir el archivo ReporteFaltas.txt"<<endl;
        exit(1);
    }
    arch<<"Infraccion"<<setw(10)<<right<<"Descripcion"<<setw(60)<<right<<"Monto"<<endl;
    imprimirLineas(arch,'=');
    for(int i=0;aux[i];i++){
        muestraFalta(aux[i],arch);
    }
}

void muestraFalta(void *falta,ofstream &arch){
    void **aux = (void**)falta;
    int *numFalta = (int*)aux[INFRACCION];
    char *desc = (char*)aux[DESCRIPCION];
    double *monto = (double*)aux[MONTO];
    arch<<*numFalta<<setw(10)<<right<<desc<<setw(60)<<right<<*monto<<endl;
}

void leerFaltas(void *&falta,ifstream &arch){
    void *var,**aux,*buff[200];
    int numDatos=0;
//    cout<<"Antes del while"<<endl;
    while(1){
        var = obtenerFalta(arch);
        if(var == nullptr)break;
        buff[numDatos]=var;
        numDatos++;
    }
//    cout<<"Fin del while"<<endl;
    buff[numDatos]=nullptr;
    aux = new void*[numDatos+1];
    for(int i=0;i<numDatos;i++){
        aux[i]=buff[i];
    }
    falta = aux;
}

void *obtenerFalta(ifstream &arch){
    int numFalta,*ptrNumFalta;
    char *descripcionFalta,*tipo,c;
    double montoFalta,*ptrMontoFalta;
    ptrMontoFalta = new double;
    ptrNumFalta = new int;
    void **aux;
    aux = new void*[3]{};
    
    arch>>numFalta>>c;
    if(arch.eof())return nullptr;
    descripcionFalta = leerCadena(arch);
    tipo = leerCadena(arch);
    arch>>montoFalta;
    arch.get();
//    cout<<numFalta<<" "<<descripcionFalta<<endl<<tipo<<" "<<montoFalta<<endl;
    *ptrNumFalta = numFalta;
    *ptrMontoFalta = montoFalta;
    aux[INFRACCION] = ptrNumFalta;
    aux[DESCRIPCION] = descripcionFalta;
    aux[MONTO] = ptrMontoFalta;
//    cout<<aux[INFRACCION]<<endl;
    return aux;
    
}

char *leerCadena(ifstream &arch){
    char buff[600],*cad;
    arch.getline(buff,600,',');
    cad = new char[strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}

void imprimeconductor(void *conductor){
    ofstream arch("ReporteConductores.txt",ios::out);
    arch<<"Licencia"<<setw(20)<<right<<"Nombre"<<endl;
    imprimirLineas(arch,'=');
    void **aux = (void**)conductor;
    for(int i=0;aux[i];i++){
        imprimirUnConductor(aux[i],arch);
    }
}

void imprimirUnConductor(void *conductor,ofstream &arch){
    void **aux = (void**)conductor;
    int *licencia = (int*)aux[LICENCIA];
    char *nombre = (char*)aux[NOMBRE];
    arch<<*licencia<<"  "<<setw(20)<<left<<nombre<<endl;
}

void imprimirLineas(ofstream &arch,char c){
    for(int i=0;i<MAXLINEAS;i++)arch<<c;
    arch<<endl;
}

void leerConductores(void *&conductores,ifstream &arch){
    void *var,*buffConductores[200],**cond;
    int numDatos=0;
    while(1){
        var = obtenerConductor(arch);
        if(var==nullptr)break;
        buffConductores[numDatos]=var;
        numDatos++;
    }
    buffConductores[numDatos]=nullptr;
    cond = new void*[numDatos+1];
    numDatos++;
    for(int i=0;i<numDatos;i++){
        cond[i]=buffConductores[i];
    }
    conductores = cond;
}

void *obtenerConductor(ifstream &arch){
    void **aux;
    aux = new void*[2];
    
    int auxLicencia,*ptrLicencia;
    char *nombre,c;
    
    arch>>auxLicencia>>c;
    if(arch.eof())return nullptr;
    nombre = leerCadenaFin(arch);
    ptrLicencia = new int;
    *ptrLicencia = auxLicencia;
    aux[LICENCIA]=ptrLicencia;
    aux[NOMBRE]=nombre;
    return aux;
}

char *leerCadenaFin(ifstream &arch){
    char buff[200],*cad;
    arch.getline(buff,200,'\n');
    cad = new char[strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}

void registraFaltas(void *&consolidado,void *conductor,void *falta){
    ifstream arch("RegistroDeFaltas.csv",ios::in);
    if(!arch){
        cout<<"Error no se pudo abrir el archivo RegistroDeFaltas.csv"<<endl;
        exit(1);
    }
    void *var,*buffConsolidados[1000],**auxConsolidado;
    int numConsolidados=0,auxLicencia,dd,mm,aa,codInfraccion;
    char *placa,c;
    cout<<"Antes del while"<<endl;
    while(1){
        arch>>auxLicencia>>c;
        if(arch.eof())break;
        placa = leerCadena(arch);
        arch>>dd>>c>>mm>>c>>aa>>c>>codInfraccion;
        int fecha = dd + mm*100 + aa*10000;
        cout<<auxLicencia<<" "<<placa<<" "<<dd<<" "<<mm<<" "<<aa<<" "<<codInfraccion<<endl;
        asignarDatosFalta(buffConsolidados,conductor,falta,auxLicencia,mm,aa,codInfraccion,numConsolidados);
        numConsolidados++;
    }
    cout<<"Despues del while"<<endl;
    buffConsolidados[numConsolidados]=nullptr;
    numConsolidados++;
    auxConsolidado = new void*[numConsolidados];
    for(int i=0;i<numConsolidados;i++){
        auxConsolidado[i]=buffConsolidados[i];
    }
    consolidado = auxConsolidado;
}

//enum Consolidado{CODLICENCIA,NOMBRECOND,AA,MM,MONTOTOTAL};
void asignarDatosFalta(void **buffConsolidados,void *conductor,
        void *falta,int auxLicencia,int mm,int aa,int codInfraccion,int numConsolidados){
    void **auxFalta = (void**)falta;
    int posInfraccion,pos;
    cout<<"Antes de buscar"<<endl;
    pos = buscarConductorEnConsolidado(buffConsolidados,auxLicencia,mm,aa);
    cout<<"Despues de buscar"<<endl;
    if(pos==-1){
        cout<<"No lo encontro "<<auxLicencia<<endl;
        //No lo encontro entonces lo crea
        void **registroNuevo;
        registroNuevo = new void*[5]{};
        int *ptrLicencia,*ptr_mm,*ptr_aa;
        char *nombre;
        double *monto;
        ptrLicencia = new int;
        ptr_mm = new int;
        ptr_aa = new int;
        nombre = retornarNombre(conductor,auxLicencia);
        monto = new double {};
        *ptrLicencia = auxLicencia;
        *ptr_aa = aa;
        *ptr_mm = mm;
        *monto = 0;
        
        registroNuevo[CODLICENCIA]=ptrLicencia;
        registroNuevo[NOMBRECOND]=nombre;
        registroNuevo[AA]= ptr_aa;
        registroNuevo[MM]=ptr_mm;
        registroNuevo[MONTOTOTAL]=monto;
        
        buffConsolidados[numConsolidados]=registroNuevo;
    }else{
        //Si la encuentra entonces entonces se acumula las faltas
        void **auxEncontrado = (void**)buffConsolidados[pos];
        double *montoEncontrado = (double*)auxEncontrado[MONTOTOTAL];
        posInfraccion = buscarFalta(codInfraccion,falta);
        void **auxFaltaEncontrado = (void**)auxFalta[posInfraccion];
        double *montoInfraccion = (double*)auxFaltaEncontrado[MONTO];
        *montoEncontrado+= *montoInfraccion;
    }
}

int buscarFalta(int cod,void *falta){
    void **auxFalta = (void **)falta;
    for(int i=0;auxFalta[i];i++){
        void **aux = (void **)auxFalta[i];
        int *codInfra = (int*)aux[INFRACCION];
        if(*codInfra == cod){
            return i;
        }
    }
    return -1;
}

int buscarConductorEnConsolidado(void **consolidadoBuff,int licenciaArch,int mmArch,int aaArch){
    
    cout<<"Antes de recorrer"<<endl;
    for(int i=0;consolidadoBuff[i]!=nullptr;i++){
        void **registroConsolidado=(void **)consolidadoBuff[i];
        //enum Consolidado{CODLICENCIA,NOMBRECOND,AA,MM,MONTOTOTAL};
        int *licencia=(int *)registroConsolidado[CODLICENCIA];
        int *aa=(int *)registroConsolidado[CODLICENCIA];
        int *mm=(int *)registroConsolidado[CODLICENCIA];
        if(*licencia==licenciaArch && *aa==aaArch && *mm==mmArch) return i;
    }
    return -1;
}

char *retornarNombre(void *conductor,int licenciaAux){
    void **aux = (void**)conductor;
    for(int i=0;aux[i];i++){
        void **registro = (void**)aux[i];
        int *licencia = (int*)registro[LICENCIA];
        char *nombre = (char*)registro[NOMBRE];
        if(*licencia == licenciaAux){
            char *ptrAux;
            ptrAux = new char[strlen(nombre)+1];
            strcpy(ptrAux,nombre);
            return nombre;
        }
    }
    return nullptr;
}

    
void imprime(void *consolidado){
    
}












