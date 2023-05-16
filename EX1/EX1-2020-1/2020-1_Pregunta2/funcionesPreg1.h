/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funcionesPreg1.h
 * Author: chris
 *
 * Created on 14 de mayo de 2023, 0:54
 */

#ifndef FUNCIONESPREG1_H
#define FUNCIONESPREG1_H
#include <fstream>
using namespace std;

void leerDatos(char ***&cursos,int *&codProfesores,char **&profesores);
void imprimirDatos(char ***cursos,int *codProfesores,char **profesores);
void incrementarEspacios(char ***&cursos,int &numCur,int &cap);
char *leerCadenaFin(ifstream &arch);
char *leerCadena(ifstream &arch);
void incrementarEspacios2(int *&codProfesores,char **&profesores,int &numDat,int &cap);

#endif /* FUNCIONESPREG1_H */

