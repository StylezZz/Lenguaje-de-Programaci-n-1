/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funcionesBiblioteca.h
 * Author: alulab14
 *
 * Created on 27 de abril de 2023, 10:19 AM
 */

#ifndef FUNCIONESBIBLIOTECA_H
#define FUNCIONESBIBLIOTECA_H
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "Estructuras.h"
#include "funcionesBiblioteca.h"
using namespace std;
ofstream abrirArchivoE(const char *nombre,char modo);
ifstream abrirArchivoL(const char *nombre,char modo);

//Lee un libro de un archivo de textos 
//  VG01047       Lenguaje_de_programacion_C++        12      325.75
bool operator >>(ifstream &in,struct St_Libro &libro);

void formatearNombre(char *nombre);
//Lee un usuario del archivo de textos 
//carné:NumeroTipo - nombre
//30018447E CUEVA_FUENTES_CINTHIA_DELIA

bool operator >>(ifstream &in,struct St_Usuario &usu);

void operator +=(struct St_Usuario &usu,
                 struct St_LibroPrestado pres);
void operator +=(struct St_Libro &lib,
                 struct  St_UsuarioPrestamo ped);
int numeroDeDias(int fecha1,int fecha2);

void fTodma(int fecha, int &dd, int &mm, int &aa);

int diasDelMes(int mm, int aa);

void operator <=(struct St_Usuario &usuario,
                 int fecha);

void operator <=(struct St_Libro &libro,int fecha);

void imprimeFecha(ofstream &arch,int fecha);
void imprimeLibro(ofstream &out,struct St_LibroPrestado lib,char *condicion);

void imprimeLinea(ofstream &arch,int cant,char c);

void operator <<(ofstream &out,struct St_Usuario &usuario);

void imprimirLineas(ofstream &out,char c);

void imprimirDetalle(int pos,ofstream &out,struct St_UsuarioPrestamo *usuario,int cant);
void operator <<(ofstream &out, struct St_Libro &libro);

#endif /* FUNCIONESBIBLIOTECA_H */

