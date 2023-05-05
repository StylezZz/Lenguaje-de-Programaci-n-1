/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#define MAXLINEAS 100
#include "funciones.h"
using namespace std;

char *leerCadena(ifstream &arch){
    char buffer[200],*cad;
    arch.getline(buffer,200,',');
    cad = new char[strlen(buffer)+1];
    strcpy(cad,buffer);
    return cad;
}

char* leerCadenaFinal(ifstream &arch){
    char buffer[200],*cad;
    arch.getline(buffer,200,'\n');
    cad = new char[strlen(buffer)+1];
    strcpy(cad,buffer);
    return cad;
}

void formatearNombre(char *cadena){
    for(int i=0;cadena[i];i++){
        if(cadena[i]=='_'){
            cadena[i]=' ';
        }
    }
}

void cargarCursos(char **&codCursos,char **&cursos,double *&creditos,
                    int *&idProfes,char **&profNombres){
    ifstream arch("Cursos.txt",ios::in);
    if(!arch){
        cout<<"Error en la apertura del archivo Alumnos.txt"<<endl;
        exit(1);
    }
    int buffIdProfes[200],numDatos=0,auxCodigoProfe;
    double bufferCreditos[200],auxCredito;
    char *bufferCodigo[200],*bufferNombres[200],*buffCursosNombre[200],*codCur,*nombreCur;
    char c,*nombreProfe;
    
    while(1){
        codCur = leerCadena(arch);
        if(arch.eof())break;
        nombreCur = leerCadena(arch);
        arch>>auxCredito>>c>>auxCodigoProfe>>c;
        nombreProfe = leerCadenaFinal(arch);
        formatearNombre(nombreCur);
        formatearNombre(nombreProfe);
        bufferCodigo[numDatos]=codCur;
        buffCursosNombre[numDatos]=nombreCur;
        bufferCreditos[numDatos]=auxCredito;
        buffIdProfes[numDatos]=auxCodigoProfe;
        bufferNombres[numDatos]=nombreProfe;
        numDatos++;
    }
    codCursos = new char*[numDatos+1];
    cursos= new char*[numDatos+1];
    creditos = new double[numDatos+1];
    idProfes = new int[numDatos+1];
    profNombres= new char*[numDatos+1];
    
    for(int i=0;i<numDatos;i++){
        codCursos[i]=bufferCodigo[i];
        cursos[i]=buffCursosNombre[i];
        creditos[i]=bufferCreditos[i];
        idProfes[i]=buffIdProfes[i];
        profNombres[i]=bufferNombres[i];
    }
    
    codCursos[numDatos]=nullptr;
    cursos[numDatos]=nullptr;
    creditos[numDatos]=0.0;
    idProfes[numDatos]=0;
    profNombres[numDatos]=nullptr;
}

void imprimirLineas(ofstream &arch,char c){
    for(int i=0;i<MAXLINEAS;i++){
        arch<<c;
    }
    arch<<endl;
}

//char **codCursos,**profNombres,**cursos;
//    double *creditos;
//    int *idProfes;
void reporteCursos(char **codCursos,char **cursos,double *creditos,
                   int *idProfes,char **profNombres){
    ofstream arch("ReporteCursos.txt",ios::out);
    if(!arch){
        cout<<"Error no se pudo abrir ReporteCursos.txt"<<endl;
        exit(1);
    }
    
    arch<<setw(30)<<left<<"REPORTE DE CURSOS"<<endl;
    imprimirLineas(arch,'=');
    
    for(int i=0;codCursos[i];i++){
        arch<<setw(10)<<left<<codCursos[i]<<setw(50)<<right<<cursos[i];
        arch<<setw(10)<<right<<creditos[i]<<endl<<setw(10)<<left<<idProfes[i]<<setw(50)<<
                right<<profNombres[i]<<endl;
        imprimirLineas(arch,'-');
    }
    
}

void formatoNombre(char *nombre){
    for(int i=0;nombre[i];i++){
        if(nombre[i]=='/' or nombre[i]=='_' or nombre[i]=='-'){
            nombre[i]=' ';
        }
    }
}

void cargarAlumnos(int *&semestre,int *&codigoAlumno,char **&nombreAlumno,
                   char *&modalidad,double *&porcentaje,int *&escala){
    ifstream arch("Alumnos.txt",ios::in);
    if(!arch){
        cout<<"Error no se pudo abrir el archivo Alumnos.txt"<<endl;
        exit(1);
    }
    int buffSemestre[200],buffEscala[200],numDatos=0,buffCodigoAlumno[200];
    char *buffNombreAlumno[200],buffModalidad[200],*auxNombre,grado,auxModalidad;
    char c;
    double buffPorcentaje[200],auxPorcentaje;
    int auxSemestre,auxCodigoAlumno,auxEscala;
    while(1){
        arch>>auxSemestre;
        if(arch.eof())break;
        arch.get();
        arch>>auxCodigoAlumno;
        arch.get();
        auxNombre = leerCadena(arch);
        formatoNombre(auxNombre);
        arch>>grado;
        if(grado=='G'){
            arch>>auxEscala;
            auxModalidad = 'P';
            auxPorcentaje = 100; //100% presencial
        }else if(grado=='S'){
            auxModalidad = 'S';
            arch>>c>>auxPorcentaje>>c>>grado>>auxEscala;
        }else if(grado =='V'){
            auxModalidad='V';
            arch>>c>>grado>>auxEscala;
            auxPorcentaje =0;
        }
        buffSemestre[numDatos]= auxSemestre;
        buffCodigoAlumno[numDatos]=auxCodigoAlumno;
        buffNombreAlumno[numDatos]=auxNombre;
        buffEscala[numDatos]=auxEscala;
        buffModalidad[numDatos]=auxModalidad;
        buffPorcentaje[numDatos]=auxPorcentaje;
        numDatos++;
    }
    
    semestre = new int[numDatos+1];
    codigoAlumno = new int[numDatos+1];
    nombreAlumno = new char*[numDatos+1];
    modalidad = new char[numDatos+1];
    porcentaje = new double[numDatos+1];
    escala = new int[numDatos+1];
    
    for(int i=0;i<numDatos;i++){
        semestre[i]=buffSemestre[i];
        codigoAlumno[i]=buffCodigoAlumno[i];
        nombreAlumno[i]=buffNombreAlumno[i];
        escala[i]=buffEscala[i];
        modalidad[i]=buffModalidad[i];
        porcentaje[i]=buffPorcentaje[i];
    }
    
    semestre[numDatos]=0;
}

//    int *semestre,*codigoAlumno,*escala;
//    char **nombreAlumno,*modalidad;
//    double *porcentaje;
void imprimirAlumnos(int *semestre,int *codigoAlumno,char **nombreAlumno,
                     char *modalidad,double *porcentaje,int *escala){
    ofstream arch("ReporteFinal.txt",ios::out);
    if(!arch){
        cout<<"Error no se puede abrir el archivo ReporteFinal.txt"<<endl;
        exit(1);
    }
    arch<<"Reporte de Alumnos"<<endl;
    imprimirLineas(arch,'=');
    for(int i=0;semestre[i];i++){
        arch<<setw(10)<<left<<semestre[i]<<setw(10)<<left<<codigoAlumno[i]<<setw(60)<<
                right<<nombreAlumno[i]<<setw(20)<<right<<modalidad[i]<<setw(20)<<right
                <<porcentaje[i]<<setw(20)<<right<<escala[i]<<endl;
    }
}