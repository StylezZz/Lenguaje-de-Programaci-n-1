/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: chris
 *
 * Created on 30 de abril de 2023, 17:02
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <fstream>
using namespace std;
void leerNombres(char **&,int &,const char *);
void ordenar(char **,int ,int );
void imprimir(char **,int ,const char *);
char* leerCadena(ifstream &);
void formatearNombres(char **&nombres);
void cambiar(char **nombres,int i,int k);

#endif /* FUNCIONES_H */

