/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: chris
 *
 * Created on 11 de abril de 2023, 11:12
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void imprimirLineas(char c);
void leerPrimeraLinea(char *pediatria,char *ginecologia,int &fecha);
void sacarFecha(int fecha,int &dd,int &mm,int &aa);
void imprimirEncabezado(char *pediatria,char *ginecologia,int fecha);
void formatearEspecialidad(char *nombreCompleto,char *especialidad);
bool validarEspecialidad(char *especialidad,char *pediatria,char *ginecologia);

#endif /* FUNCIONES_H */

