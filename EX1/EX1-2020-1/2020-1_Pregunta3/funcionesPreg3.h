/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funcionesPreg3.h
 * Author: chris
 *
 * Created on 14 de mayo de 2023, 2:09
 */

#ifndef FUNCIONESPREG3_H
#define FUNCIONESPREG3_H
#include <fstream>
using namespace std;

void reporteCargaHorariaDeProf(char ***cursos,int *codProfesores,
        char **profesores,void *sesiones);
void imprimirSesiones(int codProfe,void *sesion, char ***cursos,ofstream &arch,
        int posI);
void imprimirHorasProfesor (int *horas, int numAl, ofstream &arch);
void formatoHorarioProfesor (int datoNum, ofstream &arch, int &totalHoras);
int buscarCurso(char *cadena,char ***cursos);
void encabezadoProfesor(int numero,char *nombre,ofstream &arch);

#endif /* FUNCIONESPREG3_H */

