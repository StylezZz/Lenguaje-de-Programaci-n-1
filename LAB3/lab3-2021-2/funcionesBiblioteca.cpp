/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "Estructuras.h"
#include "funcionesBiblioteca.h"
#define MAXLINEAS 100
using namespace std;

ofstream abrirArchivoE(const char *nombre,char modo){
    ofstream arch;
    if (modo='T')arch.open(nombre,ios::out);
    else arch.open(nombre,ios::out|ios::binary);
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo "<<nombre;
        exit(1);
    }
    return arch;
}

ifstream abrirArchivoL(const char *nombre,char modo){
    ifstream arch;
    if (modo='T')arch.open(nombre,ios::in);
    else arch.open(nombre,ios::in|ios::binary);
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo "<<nombre;
        exit(1);
    }
    return arch;
}

//Lee un libro de un archivo de textos 
//  VG01047       Lenguaje_de_programacion_C++        12      325.75
bool operator >>(ifstream &in,struct St_Libro &libro){
    char codigo[20],titulo[200];
    int stock;
    double precio;
    in>>codigo;
    if(in.eof()){
        return false;
    }
    in>>titulo>>stock>>precio;
    strcpy(libro.titulo,titulo);
    strcpy(libro.codigo,codigo);
    libro.stock = stock;
    libro.precio = precio;
    return true;
}

void formatearNombre(char *nombre){
    //Primero quitar el ultimo _ para luego hacer el cambio
    int pos;
    for(int i=0;nombre[i];i++){
        if(nombre[i]=='_'){
            pos=i;
        }
    }
    nombre[pos]=' ';
    //Ahora formateamos todo el nombre
    //Buscamos el ultimo caracter _ para cambiarlo por -
    for(int i=0;nombre[i];i++){
        if(nombre[i]=='_'){
            pos=i;
        }
    }
    nombre[pos]='-';
    
    //Formateo del nombre
    for(int i=0;nombre[i];i++){
        if(nombre[i]=='_'){
            nombre[i]='/';
        }
    }
    
}

//Lee un usuario del archivo de textos 
//carné:NumeroTipo - nombre
//30018447E CUEVA_FUENTES_CINTHIA_DELIA

bool operator >>(ifstream &in,struct St_Usuario &usu){
    int carne;
    char tipo,nombre[150];
    in>>carne;
    if(in.eof()){
        return false;
    }
    in>>tipo>>nombre;
    if(tipo=='A'){
        strcpy(usu.tipo,"ADMINISTRATIVO");
    }else if(tipo=='E'){
        strcpy(usu.tipo,"ESTUDIANTE");
    }else{
        strcpy(usu.tipo,"DOCENTE");
    }
    usu.carne = carne;
    formatearNombre(nombre);
    strcpy(usu.nombre,nombre);
    usu.numLibPrest = 0;
    strcpy(usu.condicion,"INHABILITADO");
    return true;
}

void operator +=(struct St_Usuario &usu,
                 struct St_LibroPrestado pres){
    int i = usu.numLibPrest;
    usu.libPrest[i].deuda = pres.deuda;
    usu.libPrest[i].fechaRetiro = pres.fechaRetiro;
    strcpy(usu.libPrest[i].codigoLib,pres.codigoLib);
    usu.numLibPrest++;
}

void operator +=(struct St_Libro &lib,
                 struct  St_UsuarioPrestamo ped){
    int i;
    if(ped.tipo == 'E'){
        i = lib.cantEst;
        lib.estudiantes[i].carne = ped.carne;
        lib.estudiantes[i].fechaRetiro = ped.fechaRetiro;
        lib.estudiantes[i].deuda = ped.deuda;
        lib.estudiantes[i].tipo = ped.tipo;
        lib.cantEst++;
    }else if (ped.tipo=='A'){
        i=lib.cantAdm;
        lib.administrativos[i].carne = ped.carne;
        lib.administrativos[i].fechaRetiro = ped.fechaRetiro;
        lib.administrativos[i].deuda = ped.deuda;
        lib.administrativos[i].tipo = ped.tipo;
        lib.cantAdm++;
    }else{
        i=lib.cantDoc;
        lib.docentes[i].carne = ped.carne;
        lib.docentes[i].fechaRetiro = ped.fechaRetiro;
        lib.docentes[i].deuda = ped.deuda;
        lib.docentes[i].tipo = ped.tipo;
        lib.cantDoc++;
    }
}

int numeroDeDias(int fecha1,int fecha2){
    // fecha1 y fecha2 están en el formato aaaammdd
    int dd1,mm1,aa1, dd2,mm2,aa2;
    int cont=0, aux;
    if(fecha1 < fecha2) {
        aux = fecha1;
        fecha1 = fecha2;
        fecha2 = aux;
    }
    fTodma(fecha1, dd1,mm1,aa1);
    fTodma(fecha2, dd2,mm2,aa2);
    while(dd1!=dd2 or mm1!=mm2 or aa1!=aa2){
        dd1--; cont++;
        if (dd1==0){
            mm1--;
            if(mm1==0){
                aa1--;
                mm1=12;
            }
            dd1 = diasDelMes(mm1,aa1);
        }
    }
    return cont;
}

void fTodma(int fecha, int &dd, int &mm, int &aa){
    aa = fecha / 10000;
    fecha = fecha % 10000;
    mm = fecha /100;
    dd = fecha % 100;
}

int diasDelMes(int mm, int aa){
    switch(mm){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2: 
            if(aa%4==0 && (aa%100!=0 || aa%400==0))
		return 29;
            return 28;
    }
}

void operator <=(struct St_Usuario &usuario,
                 int fecha){
    for(int i=0;i<usuario.numLibPrest;i++){
        char c;
        int diasPasados = numeroDeDias(usuario.libPrest[i].fechaRetiro,fecha);
        int diasPermitidos = 0;
        if(strcmp(usuario.tipo,"ESTUDIANTE")==0){
            c='E';
        }else if(strcmp(usuario.tipo,"DOCENTE")==0){
            c='D';
        }else if(strcmp(usuario.tipo,"ADMINISTRATIVO")==0){
            c='A';
        }
        switch(c){
            case 'D':
                diasPermitidos = 15;
                break;
            case 'E':
                diasPermitidos = 7;
                break;
            case 'A':
                diasPermitidos = 3;
                break;
        }
        if(diasPasados>diasPermitidos){
            strcpy(usuario.condicion,"INHABILITADO");
            usuario.libPrest[i].deuda = true;
        }else{
            strcpy(usuario.condicion,"HABILITADO");
            usuario.libPrest[i].deuda = true;
        }
    }
}

void operator <=(struct St_Libro &libro,int fecha){
     for (int i = 0; i < libro.cantEst; i++) {
            int dias = numeroDeDias(libro.estudiantes[i].fechaRetiro, fecha);
            if (dias > 7) {
                libro.estudiantes[i].deuda = true;
            }
            else {
                libro.estudiantes[i].deuda = false;
            }
        
    }
    for (int i = 0; i < libro.cantDoc; i++) {
        int dias = numeroDeDias(libro.docentes[i].fechaRetiro, fecha);
            if (dias > 7) {
                libro.docentes[i].deuda = true;
            }
            else {
                libro.docentes[i].deuda = false;
            }
    }
    for (int i = 0; i < libro.cantAdm; i++) {
        int dias = numeroDeDias(libro.docentes[i].fechaRetiro, fecha);
            if (dias > 7) {
                libro.docentes[i].deuda = true;
            }
            else {
                libro.docentes[i].deuda = false;
            }
    }
}

void imprimeFecha(ofstream &arch,int fecha){
    int dd,mm,aa;
    dd=fecha%100;
    fecha/=100;
    mm=fecha%100;
    aa=fecha/100;
    arch<<"				   "<<setfill('0')<<setw(2)<<right<<dd<<"/"<<setw(2)<<right<<mm<<"/"
            <<setw(4)<<right<<aa<<setfill(' ');
}

void imprimeLibro(ofstream &out,struct St_LibroPrestado lib,char *condicion){
    out<<setw(20)<<left<<lib.codigoLib;
    imprimeFecha(out,lib.fechaRetiro);
    if(lib.deuda){
        out<<"Deuda"<<endl;
    }else{
        out<<endl;
    }
}

void imprimeLinea(ofstream &arch,int cant,char c){
    for(int i=0;i<cant;i++)arch<<c;
    arch<<endl;
}

void operator <<(ofstream &out,struct St_Usuario &usuario){
    out<<left<<usuario.carne<<endl;
    out<<usuario.nombre<<endl;
    out<<usuario.tipo<<endl;
    out<<usuario.condicion<<endl;
    for(int i=0;i<usuario.numLibPrest;i++){
        imprimeLibro(out,usuario.libPrest[i],usuario.condicion);
        
    }
    out<<endl;
}

void imprimirLineas(ofstream &out,char c){
    for(int i=0;i<MAXLINEAS;i++){
        out<<c;
    }
    out<<endl;
}

void imprimirDetalle(int pos,ofstream &out,struct St_UsuarioPrestamo *usuario,int cant){
    if(pos==1){
        out<<"DOCENTES:"<<endl;
        imprimirLineas(out,'-');
    }else if(pos==2){
        out<<"ESTUDIANTES:"<<endl;
        imprimirLineas(out,'-');
    }else if(pos==3){
        out<<"ADMINISTRATIVOS:"<<endl;
        imprimirLineas(out,'-');
    }
    if(cant!=0){
        out<<"No."<<setw(18)<<right<<"Carne"<<setw(30)<<right<<"Fecha de retiro"
               <<setw(18)<<right<<"Observacion"<<endl; 
        for(int i=0;i<cant;i++){
            out<<i+1<<")"<<setw(20)<<right<<usuario[i].carne;
            imprimeFecha(out,usuario[i].fechaRetiro);
            if(usuario[i].deuda){
                out<<"      Deuda"<<endl;
            }else{
                out<<endl;
            }
        }
    }
}

void operator <<(ofstream &out, struct St_Libro &libro){
    out<<"Titulo: "<<libro.titulo<<endl;
    out<<"Codigo: "<<libro.codigo<<setw(21)<<right<<"Precio: "<<libro.precio<<endl;
    out<<"Stock:  "<<libro.stock<<setw(29)<<right<<"Prestados: "<<libro.prestados<<endl;
    imprimirLineas(out,'=');
    out<<"Usuarios que lo tienen en su poder:"<<endl;
    imprimirLineas(out,'-');
    imprimirDetalle(1,out,libro.docentes,libro.cantDoc);
    imprimirLineas(out,'-');
    imprimirDetalle(2,out,libro.estudiantes,libro.cantEst);
    imprimirLineas(out,'-');
    imprimirDetalle(3,out,libro.administrativos,libro.cantAdm);
}

