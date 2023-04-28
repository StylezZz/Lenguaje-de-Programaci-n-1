/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funcionesBiblioteca.h
 * Author: chris
 *
 * Created on 26 de abril de 2023, 12:22
 */

#ifndef FUNCIONESBIBLIOTECA_H
#define FUNCIONESBIBLIOTECA_H

//Función adicional
void formatearNombre(char *nombreEsp,char *esp);

//Lectura 1
bool operator >>(ifstream &in,struct StMedico &med);

//Lectura 2
bool operator >>(ifstream &in,struct StPaciente &pac);

//Lectura 3
int operator >>(ifstream &in,struct StCita &cita);

//Busqueda
bool operator <=(struct StCita &cita, struct StMedico *arrMedicos);

//Agregación
void operator +=(struct StPaciente &pac,struct StCita cita);

//Gastos
void operator ++(struct StPaciente &pac);

//Función de impresión de fechas
void imprimeFecha(ofstream &arch,int fecha);

//Impresión
void operator <<(ofstream &out,struct StPaciente pac);

#endif /* FUNCIONESBIBLIOTECA_H */

