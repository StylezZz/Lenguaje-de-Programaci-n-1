/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funcionesAuxiliares.h
 * Author: chris
 *
 * Created on 29 de abril de 2023, 14:28
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H
 
void leerDatosExactos(int *&,int &);
void imprimirDatos(const int *,int);
void leeDatosExactosSt(char *&);
void leerNombres(char **&nombres,int &numDatos,const char *arch);
void ordenar(char **nombres,int izq,int derecha );
void imprimir(char **nombres,int numDatos,const char *arch);
#endif /* FUNCIONESAUXILIARES_H */

