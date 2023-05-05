/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;
#include "Estructuras.h"
#include "FuncionesSobrecargadas.h"

bool operator >>(ifstream &arch,struct StCurso &cur){
    char codigo[7];
    char nombre[60];
    double creditos;
    int codigoProfesor;
    char nombreProfesor[120];
    
    arch>>codigo;
    if(arch.eof()) return false;
    arch>>nombre>>creditos>>codigoProfesor>>nombreProfesor;
    
    strcpy(cur.codigoDelCurso,codigo);
    cur.codigoDelProfesor = codigoProfesor;
    cur.creditos = creditos;
    cur.ingresos =0;
    strcpy(cur.nombreDelCurso,nombre);
    strcpy(cur.nombreDelProfesor,nombreProfesor);
    cur.numeroDeAlumnos=0;
    return true;
}

bool operator >>(ifstream &arch,struct StAlumno &alum){
    int semestre;
    char car;
    int codigo;
    char nombre[120];
    char modalidad[16];
    int porcentaje;
    char grado;
    int escala;
    
    arch>>semestre;
    if(arch.eof()) return false;
    arch>>car>>codigo>>nombre;
    
    arch>>grado;
    if(grado=='G'){
        arch>>escala;
        strcpy(modalidad,"PRESENCIAL");
        alum.porcentaje=100; // 100% PRESENCIAL
    }else{
        if(grado=='S'){
            strcpy(modalidad,"SEMIPRESENCIAL");
            arch>>porcentaje>>grado>>escala;
            alum.porcentaje=porcentaje;
        }
        if(grado=='V'){
            strcpy(modalidad,"VIRTUAL");
            arch>>grado>>escala;
            alum.porcentaje=0;
        }
    }
    
    alum.codigo =codigo;
    alum.costoTotal=0;
    alum.escala=escala;
    strcpy(alum.modalidad,modalidad);
    strcpy(alum.nombre,nombre);
    alum.numeroDeCursos=0;
    alum.semestre=semestre;
    return true;
}

bool operator >>(ifstream &arch,struct StRegistroDeMatricula &reg){
    char codCurso[7];
    int semestreAlumno;
    int codigoAlumno;
    char car;
   
    arch>>codCurso;
    if(arch.eof()) return false;
    arch>>semestreAlumno>>car>>codigoAlumno;
    
    strcpy(reg.codigoDelCurso,codCurso);
    reg.codigodelAlumno=codigoAlumno;
    reg.semestreDelAlumno = semestreAlumno;
    return true;
}

void operator +=(struct StCurso *arr,struct StCurso &cur){
    int i;
    for(i=0;strcmp(arr[i].codigoDelCurso,"XXXXXX")!=0;i++);
    
    strcpy(arr[i].codigoDelCurso,cur.codigoDelCurso);
    arr[i].codigoDelProfesor = cur.codigoDelProfesor;
    arr[i].creditos = cur.creditos;
    arr[i].ingresos = cur.ingresos;
    strcpy(arr[i].nombreDelCurso,cur.nombreDelCurso);
    strcpy(arr[i].nombreDelProfesor,cur.nombreDelProfesor);
    arr[i].numeroDeAlumnos = cur.numeroDeAlumnos;
    
    strcpy(arr[i+1].codigoDelCurso,"XXXXXX");
}

void operator +=(struct StAlumno *arr,struct StAlumno &alum){
    int i;
    for(i=0;arr[i].semestre!=0;i++);
    
    arr[i].codigo=alum.codigo;
    arr[i].costoTotal = alum.costoTotal;
    arr[i].escala = alum.escala;
    strcpy(arr[i].modalidad,alum.modalidad);
    strcpy(arr[i].nombre,alum.nombre);
    arr[i].porcentaje=alum.porcentaje;
    arr[i].semestre=alum.semestre;
    
    arr[i+1].semestre =0;
}

void operator *=(struct StCurso *arr,struct StRegistroDeMatricula &reg){
    int i,flag=0,num,pos;
    for(i=0;strcmp(arr[i].codigoDelCurso,"XXXXXX")!=0;i++){
        if(strcmp(arr[i].codigoDelCurso,reg.codigoDelCurso)==0){
            // Se encontro:
            flag=1;
            pos=i;
        }
    }
    
    if(flag==1){
        // Copio data:
        num = arr[pos].numeroDeAlumnos;
        arr[pos].alumnos[num] = reg.codigodelAlumno;
        arr[pos].numeroDeAlumnos++;
    }
}

void operator *=(struct StAlumno *arr,struct StRegistroDeMatricula &reg){
    int i,flag=0,num,pos;
    for(i=0;arr[i].semestre!=0;i++){
        if(arr[i].codigo ==reg.codigodelAlumno and arr[i].semestre==reg.semestreDelAlumno){
            // Se encontro:
            flag=1;
            pos=i;
        }
    }
    
    if(flag==1){
        num= arr[pos].numeroDeCursos;
        strcpy(arr[pos].cursos[num],reg.codigoDelCurso);
        arr[pos].numeroDeCursos++;
    }
}

void operator <<(ostream &arch,const struct StCurso &cur){
    char nombre[120];
    arch<<setw(10)<<"CODIGO"<<setw(20)<<"NOMBRE"<<setw(20)<<"CREDITOS"<<endl;
    arch<<"  "<<cur.codigoDelCurso<<setw(10)<<" "<<left<<setw(20)<<cur.nombreDelCurso;
    arch<<right<<setw(5)<<cur.creditos<<endl;
    strcpy(nombre,cur.nombreDelProfesor);
    convertirFormato(nombre);
    arch<<"PROFESOR: "<<nombre<<" ["<<cur.codigoDelProfesor<<" ]"<<endl;
    arch<<"Alumnos matriculados: "<<endl;
    arch<<"Semestre "<<"Codigo"<<endl;
    
    for(int i=0;i<cur.numeroDeAlumnos;i++){
        arch<<setw(20)<<cur.alumnos[i]/10000<<setw(10)<<cur.alumnos[i]%10000<<endl;
    }
    arch<<"Numero de alumnos: "<<cur.numeroDeAlumnos<<endl;
    arch<<"Total ingresado: "<<cur.ingresos<<endl;
}

void convertirFormato(char *cadena){
    for(int i=0;cadena[i];i++){
        if(cadena[i]=='_'){
            cadena[i]=' ';
        }
    }
}
void operator <<(ostream &arch,const struct StAlumno &alum){
    arch<<"SEMESTRE "<<"CODIGO"<<" NOMBRE"<<setw(20)<<"MODALIDAD"<<setw(20)<<"ESCALA"<<endl;
    arch<<alum.semestre<<setw(10)<<alum.codigo<<setw(10)<<" "<<left<<setw(40)<<
            alum.nombre<<setw(1)<<" "<<setw(9)<<alum.modalidad;
    if(strcmp(alum.modalidad,"SEMIPRESENCIAL")==0){
        arch<<" CON "<<alum.porcentaje<<"%";
    }
    arch<<right<<setw(2)<<alum.escala<<endl;
    arch<<"Codigos de cursos matriculados: "<<endl;
    for(int i=0;i<alum.numeroDeCursos;i++){
        arch<<right<<setw(10)<<alum.cursos[i]<<endl;
    }
    arch<<"Numero de Cursos: "<<alum.numeroDeCursos<<endl;
    arch<<"Costo total: "<<alum.costoTotal<<endl;
}