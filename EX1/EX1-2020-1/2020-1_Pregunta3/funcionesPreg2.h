/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funcionesPreg2.h
 * Author: chris
 *
 * Created on 14 de mayo de 2023, 1:24
 */

#ifndef FUNCIONESPREG2_H
#define FUNCIONESPREG2_H
#include <fstream>
using namespace std;

void leerSesiones(void *&);
void imprimirSesiones(void *);
void* leerSesion(ifstream &arch);
int *obtenerSesiones(ifstream &arch);
char *asignarCadenaExacta(char *cadena);
void formatoHorario(int datoNum,ofstream &arch);
void imprimirHoras(int *horas,ofstream &arch);
void imprimirSesion(void *sesion,int num,ofstream &arch);
void imprimirSesiones(void *sesiones);

#endif /* FUNCIONESPREG2_H */

