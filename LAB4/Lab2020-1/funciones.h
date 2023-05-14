/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: chris
 *
 * Created on 1 de mayo de 2023, 0:14
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <fstream>
using namespace std;

void leerAlumnos(int *&,char **&,char ***&);
void imprimirAlumnos(int *,char **);
char * leerCadena(ifstream &,char);
void limpiaCadena(ifstream &);
void leerCursos(int *,char ***&);
void imprimirReporte(int *,char **,char ***);
void agregarDatos(char **&cursos,int num);
int buscarEntero(int codAlumno,int *codigo);
void imprimeCursos(char **cursos,ofstream &arch);
#endif /* FUNCIONES_H */

