/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: chris
 *
 * Created on 1 de mayo de 2023, 21:24
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <fstream>
using namespace std;
void cargarMedicos(char **&,char **&,double *&);
void reporteMedicos(char **,char **,double *);
void reporteDeIngresos(char **,char **,double *);
void imprimirLineas(ofstream &,char);
void cargarPacientes(char *,int *&,char **&,double *&,int *&);
void reporteDelMedico(char *,char **,char **,double *,char *,char **,double *,
                      int *,ofstream &);
void liberarEspacios(char *&,char **&,double *&,int *&);
#endif /* FUNCIONES_H */

