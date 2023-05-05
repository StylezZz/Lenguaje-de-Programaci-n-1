/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.h
 * Author: alulab14
 *
 * Created on 2 de mayo de 2023, 10:21 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <fstream>
using namespace std;
void leerDatosExactos(int *&,int &);
void imprimirDatos(int *,int );
void imprimirDatos(int *);
void leerDatosExactos(int *&);
void imprimirCursos(char **);
void reporteDeAlumnos(int *,char **,char ***);
void cargarAlumnos(int *&,char **&,char ***&);
char **leeCurso(ifstream &);
char *leeCadena(ifstream &);
char *leeCa(ifstream &);

#endif /* FUNCIONES_H */

