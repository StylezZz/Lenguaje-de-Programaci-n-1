/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones_Parte_1.cpp
 * Author: jean-
 * 
 * Created on 15 de mayo de 2023, 01:24 AM
 */

#include "funciones_Parte_1.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#define INCREMENTO 5

char *leerCadenaBuff(char *cad){
      char *aux;
      aux = new char [strlen(cad)+1];
      strcpy(aux,cad);
      return aux;
}
char *leerCadenaArch(ifstream &arch,char c){
      char buff[300],*aux;
      arch.getline(buff,300,c);
      aux = leerCadenaBuff(buff);
      return aux;
}
//60509,AMPICILINA 125MG SUSP 90ML,58.65
void CargarMedicamentos(int *&med_Codigo,char **&med_Descripcion,double *&med_Precio,
        const char *name){
      ifstream arch(name,ios::in);
      if(!arch){
            cout<<"No se pudo abrir el archivo "<<name<<endl;
            exit(1);
      }
      int codMedicina;
      char *descMedicina;
      double precioMedicina;
      int numDat=0,tamanio=0;
      
      med_Codigo=nullptr;
      med_Descripcion=nullptr;
      med_Precio=nullptr;
      
      while(true){
            arch >> codMedicina;
            if(arch.eof())break;
            leerMedicina(arch,descMedicina,precioMedicina);
            agregarMedicina(med_Codigo,med_Descripcion,med_Precio,numDat,tamanio,
                    codMedicina,descMedicina,precioMedicina);
      }
      
      
}
void leerMedicina(ifstream &arch,char *&descMedicina,double &precioMedicina){
      arch.get(); //coma
      descMedicina = leerCadenaArch(arch,',');
      arch >> precioMedicina; 
}
void agregarMedicina(int *&med_Codigo,char **&med_Descripcion,double *&med_Precio,
        int &numDat,int &tamanio,int codMedicina,char *descMedicina,double precioMedicina){
      
      if(numDat==tamanio) aumentarEspacios(med_Codigo,med_Descripcion,med_Precio,
              numDat,tamanio);
      
      med_Codigo[numDat-1]=codMedicina;
      med_Descripcion[numDat-1]=descMedicina;
      med_Precio[numDat-1]=precioMedicina;
      
      med_Codigo[numDat]=0;
      med_Descripcion[numDat]=nullptr;
      med_Precio[numDat]=0;
      
      numDat++;      
}
void aumentarEspacios(int *&med_Codigo,char **&med_Descripcion,double *&med_Precio,
       int &numDat,int &tamanio){
      int *auxCodigo;
      char **auxDesc;
      double *auxPrecio;
      tamanio+=INCREMENTO;
      
      if(med_Codigo==nullptr){
            med_Codigo = new int [tamanio];
            med_Descripcion = new char *[tamanio];
            med_Precio = new double [tamanio];
            
            med_Codigo[0]=0;
            med_Descripcion[0]=nullptr;
            med_Precio[0]=0;
            
            numDat=1;
      }else{
            auxCodigo = new int [tamanio];
            auxDesc = new char *[tamanio];
            auxPrecio = new double [tamanio];
            
            for(int i=0;i<numDat;i++){
                  auxCodigo[i]=med_Codigo[i];
                  auxDesc[i]=med_Descripcion[i];
                  auxPrecio[i]=med_Precio[i];
            }
            delete med_Codigo;
            delete med_Descripcion;
            delete med_Precio;
            
            med_Codigo = auxCodigo;
            med_Descripcion=auxDesc;
            med_Precio=auxPrecio;
      }
      
}
void PruebaDeCargaDeMedicamentos(int *med_Codigo,char **med_Descripcion,
        double *med_Precio,const char *name){
      ofstream repo(name,ios::out);
      if(!repo){
            cout<<"No se pudo abrir el archivo "<<name<<endl;
            exit(1);
      }
      
      repo <<fixed << setprecision(2)<<left;
      for(int i=0;med_Codigo[i];i++){
            repo<<setw(15)<<med_Codigo[i]<<setw(50)<<med_Descripcion[i]
                    <<setw(10)<<med_Precio[i]<<endl;
      }
}


void CargarConsultas(int ***&consultas_int,char ***&consultas_char,const char *name){
      ifstream arch(name,ios::in);
      if(!arch){
            cout<<"No se pudo abrir el archivo "<<name<<endl;
            exit(1);
      }
      int numDat=0;
      /*12/02/2023,51642949,Miranda/Alfonso,EU90564,41379,5
    *                                              ,30796,5
    *                                              ,86158,23
    *                                              ,47697,22
    *                                              ,53846,17
    *                                              ,31883,19
    *                                              ,47697,30
       */
      int dd,fecha,dniPac,posPac;
      char *nombPac,*codMedico;
      
      int buffDni[300],buffFecha[300],*buffMedicamentos[300],cantMedicamento[300],
              cantMedicos[300];
      char *buffNombre[300],**buffMedicos[300];
      
      for(int i=0;i<300;i++){
            buffDni[i]=0;
            buffFecha[i]=0;
            cantMedicamento[i]=0;
            buffMedicamentos[i]=nullptr;
            buffNombre[i]=nullptr;
            buffMedicos[i]=nullptr;
            cantMedicos[i]=0;
      }
      while(true){
            arch >> dd;
            if(arch.eof())break;
            leerCabeza(arch,dd,fecha,dniPac,nombPac,codMedico);
            posPac=buscarPaciente(dniPac,buffDni);
            if(posPac==-1){ //Nuevo Paciente
                  agregarPaciente(arch,buffDni[numDat],buffFecha[numDat],
                          buffMedicamentos[numDat],cantMedicamento[numDat],
                          buffMedicos[numDat],cantMedicos[numDat],
                          buffNombre[numDat],dniPac,fecha,nombPac,codMedico);
                  numDat++;
            }else{
                  actualizarPaciente(arch,buffFecha[posPac],
                          buffMedicamentos[posPac],cantMedicamento[posPac],
                          buffMedicos[posPac],cantMedicos[posPac],
                          fecha,codMedico);
            }
      }
      
      pasarAMemoriaExacta(consultas_int,consultas_char,numDat,
              buffDni,buffFecha,buffMedicamentos,cantMedicamento,
              buffMedicos,cantMedicos,buffNombre);
      
      
//      for(int i=0;i<numDat;i++){
//          cout <<setw(15)<< buffDni[i]<<setw(15)<< buffFecha[i]<<setw(50) << buffNombre[i]<<endl;
//          for(int a=0;a<cantMedicos[i];a++){
//              cout<<setw(30)<<buffMedicos[i][a]<<endl;
//          }
//          for(int b=0;b<cantMedicamento[i];b++){
//              cout<<buffMedicamentos[i][b*2]<<" con "<<buffMedicamentos[i][b*2+1]<<endl;
//          }
//      }
      
      
      
      
}
void pasarAMemoriaExacta(int ***&consultas_int,char ***&consultas_char,int numDat,
        int *buffDni,int *buffFecha,int **buffMedicamentos,int *cantMedicamento,
        char ***buffMedicos,int *cantMedicos,char **buffNombre){
    
    consultas_int = new int **[numDat+1];
    consultas_char = new char **[numDat+1];
    
    for(int i=0;i<numDat;i++){
        cargarPaciente(consultas_int[i],consultas_char[i],buffDni[i],buffFecha[i],
                buffMedicamentos[i],cantMedicamento[i],buffMedicos[i],cantMedicos[i],
                buffNombre[i]);
    }
    consultas_int[numDat]=nullptr;
    consultas_char[numDat]=nullptr;
}
void cargarPaciente(int **&consultas_int,char **&consultas_char,int buffDni,int buffFecha,
        int *buffMedicamentos,int cantMedicamento,char **buffMedicos,int cantMedicos,
        char *buffNombre){
      int cantidad_int = 2 + cantMedicamento;
      int cantidad_char = 1 + cantMedicos;
      consultas_int = new int *[cantidad_int+1];
      consultas_char = new char *[cantidad_char+1];
      
      consultas_int[0]=new int;
      *consultas_int[0]=buffDni;
      
      consultas_int[1]=new int;
      *consultas_int[1]=buffFecha;
      
      for(int i=2;i<cantidad_int;i++){
            consultas_int[i]= new int [2];
            cargarPaqueteMedicina(consultas_int[i],buffMedicamentos[(i-2)*2],buffMedicamentos[(i-2)*2+1]);
      }
      delete buffMedicamentos;
      consultas_int[cantidad_int]=nullptr;
      
      consultas_char[0] = leerCadenaBuff(buffNombre);
      for(int i=1;i<cantidad_char;i++){
            consultas_char[i]= leerCadenaBuff(buffMedicos[i-1]);
      }
      delete buffMedicos;
      consultas_char[cantidad_char]=nullptr;
}
void cargarPaqueteMedicina(int *&consultas_int,int buffMedicina,int buffcantidad){
      consultas_int[0]=buffMedicina;
      consultas_int[1]=buffcantidad;
}
void actualizarPaciente(ifstream &arch,int &buffFecha,
        int *&buffMedicamentos,int &cantMedicamento,
        char **&buffMedicos,int &cantMedicos,
        int fecha,char *codMedico){
    
    if(buffFecha<fecha) buffFecha = fecha; //Para colocar el mas reciente
    char c;
    int codMedicamento,cantidad,posMedicamento,posMedico;
    while(c!='\n'){
        arch>>codMedicamento>>c>>cantidad;
        posMedicamento = buscarMedicamento(codMedicamento,buffMedicamentos);
        c = arch.get();
        if(posMedicamento==-1){
            buffMedicamentos[cantMedicamento*2]=codMedicamento;
            buffMedicamentos[cantMedicamento*2+1]=cantidad;
            cantMedicamento++;
            buffMedicamentos[cantMedicamento*2]=0;
            buffMedicamentos[cantMedicamento*2+1]=0;
        }else{
            buffMedicamentos[cantMedicamento*2+1]+=cantidad;
        }
    }
    
    posMedico = buscarMedico(codMedico,buffMedicos);
    if(posMedico==-1){
        buffMedicos[cantMedicos]=codMedico;
        cantMedicos++;
        buffMedicos[cantMedicos]=nullptr;
    }
}
int buscarMedico(char *codMedico,char **buffMedicos){
    if(buffMedicos==nullptr) return -1;
    for(int i=0;buffMedicos[i];i++){
        if(strcmp(codMedico,buffMedicos[i])==0)return i;
    }
    return -1;
}
int buscarMedicamento(int codMedicamento,int *buffMedicamentos){
    if(buffMedicamentos==nullptr) return -1;
    for(int i=0;buffMedicamentos[2*i];i++){
        if(codMedicamento == buffMedicamentos[i*2])return i;
    }
    return -1;
}
void agregarPaciente(ifstream &arch,int &buffDni,int &buffFecha,
        int *&buffMedicamentos,int &cantMedicamento,
        char **&buffMedicos,int &cantMedicos,
        char *&buffNombre,int dniPac,int fecha,char *nombPac,char *codMedico){
    char c;
    int codMedicamento,cantidad;
    buffDni = dniPac;
    buffFecha = fecha;
    
    buffMedicamentos = new int [500];
    while(c!='\n'){
        arch>>codMedicamento>>c>>cantidad;
        c = arch.get();
        buffMedicamentos[cantMedicamento*2]=codMedicamento;
        buffMedicamentos[cantMedicamento*2+1]=cantidad;
        cantMedicamento++;
    }
    buffMedicamentos[cantMedicamento*2]=0;
    buffMedicamentos[cantMedicamento*2+1]=0;
    
    buffNombre=nombPac;
    buffMedicos = new char *[500];
    buffMedicos[cantMedicos]=codMedico;
    cantMedicos++;
    buffMedicos[cantMedicos]=nullptr;
}
int buscarPaciente(int dniPac,int *buffDni){
      for(int i=0;buffDni[i];i++){
            if(dniPac==buffDni[i]) return i;
      }
      return -1;
}
void leerCabeza(ifstream &arch,int dd,int &fecha,int &dniPac,char *&nombPac,
        char *&codMedico){
      char c;
      int mm,aa;
      arch>>c>>mm>>c>>aa>>c>>dniPac>>c;
      nombPac = leerCadenaArch(arch,',');
      codMedico = leerCadenaArch(arch,',');
      fecha = dd+mm*100+aa*10000;
}

void PruebaDeCargaDeConsultas(int ***consultas_int,char ***consultas_char,const char *name){
       cout<<endl<<"Ahora con la wbd exacta"<<endl;
      char **paciente_Char;
      int **paciente_Int;
      for(int i=0;consultas_int[i];i++){
            paciente_Int = consultas_int[i];
            paciente_Char = consultas_char[i];
            cout <<setw(15)<< *paciente_Int[0]<<setw(15)<< *paciente_Int[1]
                    <<setw(50) << paciente_Char[0]<<endl;
            for(int a=1;paciente_Char[a];a++){
                  cout<<setw(30)<<paciente_Char[a]<<endl;
            }
            for(int b=2;paciente_Int[b];b++){
                  cout<<paciente_Int[b][0]<<" con "<<paciente_Int[b][1]<<endl;
            }
      }
}