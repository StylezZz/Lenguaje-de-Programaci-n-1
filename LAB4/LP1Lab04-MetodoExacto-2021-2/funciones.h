/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: chris
 *
 * Created on 2 de mayo de 2023, 14:09
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <fstream>
using namespace std;
void CargaDeClientes(int *&cli_DNI,char **&cli_Nombre,char *&cli_Categoria);
void formatearNombre(char *&nombre,char &cat);
char* leerCadena(ifstream &in);
void ReporteDeClientes(int *cli_DNI,char **&cli_Nombre,char *&cli_Categoria);

#endif /* FUNCIONES_H */

