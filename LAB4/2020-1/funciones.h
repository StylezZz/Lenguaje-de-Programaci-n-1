/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.h
 * Author: alulab14
 *
 * Created on 2 de mayo de 2023, 04:24 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <fstream>
using namespace std;
void imprimeLinea(ofstream &arch,int cant,char c);
void imprimeCursos(char **cursos,ofstream &arch);
void leerAlumnos(int *&,char **&,char ***&);
char *leerCadena(ifstream &);
void imprimirAlumnos(int *,char **);
void leerCursos(int *,char ***&);
void espacios(char **&cursos,int num);
void agregarCurso(char **&cursos,int &num,char *codigoCurso);
int buscarAlumno(int *codigos,int codBus);
void imprimirReporte(int *codigos,char **nombres,char ***cursos);
#endif /* FUNCIONES_H */

