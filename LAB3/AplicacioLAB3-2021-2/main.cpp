/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on 28 de abril de 2023, 0:02
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

void agregarPrestamos(struct St_Usuario *usuarios,int cantUsuarios,
                      struct St_Libro *libro,int cantLibros){
    ifstream archPedidos;
    archPedidos = abrirArchivoL("RegistroDePrestamos.txt",'T');
    int carne,dd,mm,aa,fecha;
    char tipo,codigoLibro[20],c;
    struct St_LibroPrestado prestamo;
    while(1){
        archPedidos>>carne;
        if(archPedidos.eof())break;
        archPedidos>>tipo>>codigoLibro>>dd>>c>>mm>>c>>aa;
        fecha = aa*10000 + mm*100 + dd;
        for(int j=0;j<cantUsuarios;j++){
            if(usuarios[j].carne == carne){
                prestamo.fechaRetiro = fecha;
                usuarios[j]<=fecha;
                strcpy(prestamo.codigoLib,codigoLibro);
                //La de prestamo 
                usuarios[j]+=prestamo;
            }
        }
    }
    archPedidos.close();
}

void llenarLibros(struct St_Libro *arrLibros,int cantLibros,
                  struct St_Usuario *arrUsuario,int cantUsuarios){
    ifstream archPedidos;
    archPedidos = abrirArchivoL("RegistroDePrestamos.txt",'T');
    int carne,dd,mm,aa,fecha;
    char tipo,codigoLibro[20],c;
    struct St_UsuarioPrestamo prestamo;
    while(1){
        archPedidos>>carne;
        if(archPedidos.eof())break;
        archPedidos>>tipo>>codigoLibro>>dd>>c>>mm>>c>>aa;
        fecha = aa*10000 + mm*100 + dd;
        //Ya leido el código del libro solo se debería iterar dentro del
        //for para poder saber donde ingresar dichos datos
        for(int i=0;i<cantLibros;i++){
            if(strcmp(codigoLibro,arrLibros[i].codigo)==0){
//                if(tipo=='E'){
//                    cout<<"ENTRE ESTUDIANTES: "<<codigoLibro<<"   "<<arrLibros[i].codigo<<endl;
//                }else if(tipo=='D'){
//                    cout<<"ENTRE DOCENTES: "<<codigoLibro<<"   "<<arrLibros[i].codigo<<endl;
//                }else{
//                    cout<<"ENTRE ADMINISTRATIVO: "<<codigoLibro<<"   "<<arrLibros[i].codigo<<endl;
//                }
                
                //Al saber que es el mismo codigo se le agrega al respectivo arreglo
                prestamo.carne = carne;
                prestamo.deuda = false;
                //arrLibros[i]<=fecha;
                prestamo.tipo = tipo;
                arrLibros[i]+=prestamo;
                arrLibros[i].prestados++;
            }
        }
    }
    archPedidos.close();
}



int main(int argc, char** argv) {
    ofstream archReporte;
    ifstream archLibro;
    ifstream archUsuario;
    archReporte = abrirArchivoE("ReportePrueba.txt",'T');
    archLibro = abrirArchivoL("Libros.txt",'T');
    archUsuario = abrirArchivoL("Usuarios.txt",'T');
    struct St_Libro libros[100],libro1,libro2;
    struct St_Usuario usuarios[100];
    int i=0;
    
    while(archLibro>>libros[i]){
//        archReporte<<libros[i];
        i++;
    }
    int cantLibros = i;
    i=0;
    while(archUsuario>>usuarios[i]){
        i++;
    }
    int cantUsuarios=i;
    agregarPrestamos(usuarios,cantUsuarios,libros,cantLibros);
    llenarLibros(libros,cantLibros,usuarios,cantUsuarios);
    for(int i=0;i<cantUsuarios;i++){
        archReporte<<usuarios[i];
    }
    
    for(int i=0;i<cantLibros;i++){
        archReporte<<libros[i];
    }
    
    return 0;
}

