/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   MetodoDinamicoExacto.cpp
 * Author: AndreeEstudio
 * 
 * Created on 30 de abril de 2023, 07:31
 */

#include "MetodoDinamicoExacto.h"
#include <iomanip>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include "MetodoDinamicoExacto.h"
#define MAXLIN 100
using namespace std;

void implin(ofstream &arch,char car,int c){
    for(int i=0;i<c;i++){
        arch<<car;
    }
    arch<<endl;
   
}
void lee_cadenas(char *&cad,char *&esp,char *nomxesp){
    int i=0,j=0,k=0,l=0,m=0,cant=0;
    char n[300],e[300];
    for(i=0;nomxesp[i]!='\0';i++){
        if(nomxesp[i]==' ') j++;
    }
    
    for(k=0;nomxesp[k]!='\0';k++){
        if(nomxesp[k]==' ') cant++;
        if(cant==j){
            //aca
            e[m]=nomxesp[k];
            m++;
        }
        else{
            n[l]=nomxesp[k];
            l++;
        }
        
    }
    e[m]=n[l]='\0';
    cad=new char[strlen(n)+1];
    esp=new char[strlen(e)+1];
    strcpy(cad,n);
    strcpy(esp,e);
}
void lecturaDeMedicos(const char *nom
        ,int *&med_Codigo,char **&med_Nombre,char **&med_Especialidad
        ,double *&med_Tarifa){
        ifstream arch;
    arch.open(nom,ios::in);
    if(!arch) cout<<"Error no se puede imprimir el archivo"<<nom;
    
    int i=0,cod,ffcod[300];
    double tar,fftar[300];
    //cad es el puintero que le apunta al espacio asignado
    char *cad,*esp,*ffNom[300],*ffEsp[300],nomxesp[300];
    

    while(1){
        arch>>cod;
        if(arch.eof())break;
        arch.get();
        //ojo este es el caso especial ya que hay dos
        arch.getline(nomxesp,300,',');
        lee_cadenas(cad,esp,nomxesp);
        arch>>tar;
        fftar[i]=tar;
        ffcod[i]=cod;
        ffNom[i]=cad;
        ffEsp[i]=esp;
        i++;
    }
    med_Codigo =new int[i+1];
    med_Tarifa =new double[i+1];
    med_Nombre = new char*[i+1];
    med_Especialidad =new char*[i+1];
    for(int j=0;j<i;j++){
        med_Codigo[j]=ffcod[j];
        med_Tarifa[j]=fftar[j];
        med_Nombre[j]=ffNom[j];
        med_Especialidad[j]=ffEsp[j];
    }
    med_Codigo[i]=0;
    med_Tarifa[i]=0;
    med_Nombre[i]=nullptr;
    med_Especialidad[i]=nullptr;
    //31 lineas 
}
void lee_data(ifstream &arch,char *&xxnom){
    char ff[300];
    arch.getline(ff,300,',');
    xxnom=new char [strlen(ff)+1];
    strcpy(xxnom,ff);
}
void pruebaDeLecturaDeMedicos(const char *nom
        ,int *med_Codigo,char **med_Nombre,char **med_Especialidad
        ,double *med_Tarifa){
    ofstream ArchRe;
    ArchRe.open(nom,ios::out);
    if(!ArchRe) cout<<"Error no se puede imprimir el archivo"<<nom; 
    ArchRe<<"REPORTEE MEDICOS"<<endl;
    ArchRe<<setw(20)<<"CODIGO"
            <<setw(100)<<"NOMBRE"
            <<setw(20)<<"ESPECIAIDAD"
            <<setw(20)<<"TARIFA"<<endl<<setprecision(2)<<fixed;
    for(int i=0;med_Codigo[i];i++)
       ArchRe<<setw(20)<<med_Codigo[i]
            <<setw(100)<<med_Nombre[i]
            <<setw(20)<<med_Especialidad[i]
            <<setw(20)<<med_Tarifa[i]<<endl;
}
busca_dat(int ffdni[],int xdni,int cant){
    for(int i=0;i<cant;i++){
        if(ffdni[i]==xdni){
            return i;
        }
    }
    return -1;
}
void lecturaDeCitas(const char *nom,int *&pac_Dni,char **&pac_Nombre
                ,int **&pac_Citas){
        ifstream arch;
    arch.open(nom,ios::in);
    if(!arch) cout<<"Error no se puede imprimir el archivo"<<nom;
    
    int ffdni[300],xdni,xcita,xcitafecha,*ffcita[600],num_cit[300];
    char *xxnom,*ffnom[300];
    //no se debn repetir los pacientes 
    char car;
    int dd,mm,aa;
    for(int i=0;i<300;i++){
        ffcita[i] = new int [600];
        num_cit[i]=0;
    }
    int n=0,pos;
    int cant=0,temp;
    while(1){
        arch>>xdni;
        if(arch.eof())break;
        arch.get();
        lee_data(arch,xxnom); 
        arch>>xcita>>car>>dd>>car>>mm>>car>>aa;
        xcitafecha=aa*10000+mm*100+dd;
        if(n!=0)
            pos=busca_dat(ffdni,xdni,cant);
        
        if(pos==-1 || n==0){
            
           //aca agrega los pacientes 
            //claro esrta es la posicion d mem0ria que le aeprtenece al alumno
            //de esa posicion 
            agraga_cod_med_fecha(ffcita[cant],xcita,xcitafecha,num_cit[cant]);
            ffnom[cant]=xxnom;
            ffdni[cant]=xdni;
            
            num_cit[cant]++;
            cant++;
        }
        else{
            //aca solo le agrega la cita 
            agraga_cod_med_fecha(ffcita[pos],xcita,xcitafecha,num_cit[pos]);
            delete xxnom;//agrega 1ms
            num_cit[pos]++;
        }
        
        n++;
    }
    copiar_arr_dinamicos(pac_Dni,pac_Nombre,pac_Citas
                        ,ffdni,ffnom,ffcita,num_cit,cant);
    
}
void asigna_citas(int *&pac_Citas,int *&ffCita,int num){
    pac_Citas =new int[2*num+2];
    for(int i=0;i<num;i++){
        pac_Citas[2*i]=ffCita[2*i];
        pac_Citas[2*i+1]=ffCita[2*i+1];
        
    }
    pac_Citas[2*num]=0;
    pac_Citas[2*num+1]=0;
    
}
void copiar_arr_dinamicos(int *&pac_Dni,char **&pac_Nombre
                            ,int **&pac_Citas
                        ,int *ffdni,char **ffnom,int **ffcita
                        ,int *num_cit,int cant){
    int i;
    pac_Dni = new int  [cant+1];
    pac_Nombre =new char *[cant +1];
    pac_Citas = new int  *[cant +1];
    for(i=0;i<cant;i++){
        //aca lo debemos ver como baules los enteros inicialemnte se guardo 
        //en un baul gigante --> el cual de ese baul se gauarda en 
        //un baul donde caben exactamente los objetos
        
        pac_Dni[i]=ffdni[i];
        pac_Nombre[i]=ffnom[i];
        
        
    }
    for(i=0;i<cant;i++){
       asigna_citas(pac_Citas[i],ffcita[i],num_cit[i]);
    }
    pac_Dni[i]=0;
    pac_Nombre[i]=nullptr;
    pac_Citas[i]=nullptr;//-------------------------> ojitop
    i=0;
    for(i=0;i<cant;i++){
        delete ffcita[i];
    }
}
void agraga_cod_med_fecha(int *&ffcita,int xcita,int xcitafecha,int num_cit){
    //aca los enteros ya tiene tamano
    ffcita[num_cit*2]=xcita;
    ffcita[num_cit*2+1]=xcitafecha;
    
    
}
void pruebaDeLecturaDeCitas(const char *nom,int *pac_Dni,char **pac_Nombre
                ,int **pac_Citas){
    ofstream arch;
    arch.open(nom,ios::out);
    if(!arch) cout<<"Error no se puede imprimir el archivo"<<nom; 
    arch<<"REPORTE DE LECTURA DE CITAS"<<endl
        <<setw(10)<<"DNI"
        <<setw(10)<<"NOMBRE"<<endl;
    int *pac_citas;
    for(int i=0;pac_Dni[i];i++){
        arch<<setw(10)<<pac_Dni[i]
        <<setw(100)<<pac_Nombre[i]<<endl
        <<"CITAS POR PACIENTE"<<endl
        <<setw(10)<<"CODIGO"
        <<setw(10)<<"FECHA"<<endl;
        pac_citas=pac_Citas[i];
        for(int k=0;pac_citas[k*2];k++){
            arch<<setw(10)<<pac_citas[k*2]
            <<setw(10)<<pac_citas[k*2+1]<<endl;
        }
        implin(arch,'=',MAXLIN);
    }
        

}
int busca(int **pac_Citas,int cod){
    int *citazxgfecga,cant=0;
     for(int i=0;pac_Citas[i];i++){
        citazxgfecga=pac_Citas[i];
        for(int k=0;citazxgfecga[k*2];k++){
            if(citazxgfecga[k*2]==cod)
                cant++;
        }
    }   
    return cant;
}
int busca_med(int *med_Codigo,int cod){
    for(int i=0;med_Codigo[i];i++) if(cod==med_Codigo[i]) return i;
}
void saca_resto(int *pac_Citas,
        int *med_Codigo,double *med_Tarifa
    ,int *num_citas,double *tot_gastos){
    int pos;
        for(int k=0;pac_Citas[k*2];k++){
            pos=busca_med(med_Codigo,pac_Citas[k*2]);
            (*num_citas)++;
            *tot_gastos+=med_Tarifa[pos];
        }
}
void reporteDeIngresosMedicosYGastosDeLosPacientes(const char *nom
            ,int *med_Codigo,char **med_Nombre
            ,char **med_Especialidad,double *med_Tarifa,int *pac_Dni
            ,char **pac_Nombre,int  **pac_Citas){
  
    ofstream arch;
    arch.open(nom,ios::out);
    if(!arch) cout<<"Error no se puede imprimir el archivo"<<nom;
    arch<<"EMPRESA PRESTADORA DE SALUD"<<endl;
    implin(arch,'=',MAXLIN);
    arch<<"INGRESO DE LOS MEDICOS POR LA CITAS:"<<endl;
    implin(arch,'=',MAXLIN);
    arch<<setprecision(2)<<fixed 
        <<right<<left<<setw(5)<<"No" 
            <<setw(10)<<"Codigo"<<setw(5)<<""
            <<setw(100)<<"Nombre"<<setw(5)<<""
            <<setw(20)<<"Especialodad"<<setw(5)<<""
            <<setw(10)<<"Traifa"<<setw(5)<<""
            <<setw(10)<<"Total de Ingresos"<<endl;
    implin(arch,'-',MAXLIN);
    double tot_pac_at,tot=0;
    int cant11=0,cant2=0;
    for(int i=0;med_Codigo[i];i++){
         tot_pac_at= (double)busca(pac_Citas,med_Codigo[i])*med_Tarifa[i];
        arch<<left<<setw(5)<<i+1<<")"
                    <<setw(10)<<med_Codigo[i]<<setw(5)<<""
                    <<setw(100)<<med_Nombre[i]<<setw(5)<<""
                    <<setw(20)<<med_Especialidad[i]<<setw(5)<<""<<right
                    <<setw(10)<<med_Tarifa[i]<<setw(5)<<""
                    <<setw(10)<<tot_pac_at<<endl;
        tot+=tot_pac_at;
    }
   implin(arch,'=',MAXLIN);
    arch<<"IGASTOS DE LOS PACIENTES POR LAS CITAS:  "<<tot<<endl;
    implin(arch,'=',MAXLIN);
    arch<<setprecision(2)<<fixed 
        <<right<<left<<setw(5)<<"No" 
            <<setw(10)<<"DNI"
            <<setw(60)<<"Nombre"
            <<setw(10)<<"Numero de Citas"
            <<setw(10)<<"Total de Ingresos"<<endl; 
    int num_citas=0;
    double tot_gastos=0;
    for(int i=0;pac_Dni[i];i++){
        num_citas=0;
        tot_gastos=0;
        saca_resto(pac_Citas[i],med_Codigo,med_Tarifa,&num_citas,&tot_gastos);
        arch<<left<<setw(5)<<i+1<<")"
                    <<setw(10)<<pac_Dni[i]
                    <<setw(60)<<pac_Nombre[i]<<right
                    <<setw(10)<<num_citas
                    <<setw(10)<<tot_gastos<<endl;
       
    }
    implin(arch,'=',MAXLIN);
}