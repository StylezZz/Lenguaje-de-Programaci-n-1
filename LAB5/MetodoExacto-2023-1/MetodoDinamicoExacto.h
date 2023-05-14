/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MetodoDinamicoExacto.h
 * Author: alulab14
 *
 * Created on 5 de mayo de 2023, 08:06 AM
 */

#ifndef METODODINAMICOEXACTO_H
#define METODODINAMICOEXACTO_H
#include <fstream>
using namespace std;
void lecturaAlumnos(const char*nombreArch,int*&alumno_Codigo,char**&alumno_Nombre,char*&alumno_Modalidad,int*&alumno_Porcentaje,int*&alumno_Escala);
void pruebaLecturaAlumnos(const char*nombreArch,int*alumno_Codigo,char**alumno_Nombre,char*alumno_Modalidad,int*alumno_Porcentaje,int*alumno_Escala);
void lecturaCursos(const char*nombreArch,int*alumno_Codigo,int*alumno_Escala,char**&curso_Nombre,double*&curso_Credito,int**&curso_Alumnos);
void pruebaDeLecturaCursos(const char*nombreArch,char**curso_Nombre,double*curso_Credito,int**curso_Alumnos);
void reporteDeRecaudacionPorModalidad(const char*nombreArch,int*alumno_Codigo,char*alumno_Modalidad,int*alumno_Porcentaje,char**alumno_Nombre,char**curso_Nombre,double*curso_Credito,int**curso_Alumnos);


char*leeCadena(ifstream&arch);
int se_encuentra_curso(char*curso,char**buffCursos,int limite);
void insertarAlumno(int codigo,int*alumno_Codigo,int*alumno_Escala,char*curso,char**buffCursos,int**buffCursosAlumnos,int*cantAlumnos);
int se_encuentra_alumno(int codigo,int*alumno_Codigo);
char*cadenaExacta(char*cad);
void guardarDatosAlumno(int*&alumno_Codigo,char**&alumno_Nombre,char*&alumno_Modalidad,int*&alumno_Porcentaje,int*&alumno_Escala,int*buffCodigo,int*buffEscala,char*buffModalidad,char**buffNombre,int*buffProcentaje,int cant_alumnos);
void recortarAlumnos(int cant_cursos,int**curso_Alumnos,int*cantAlumnos);
void imprimir_linea(char c,ofstream&arch);
#endif /* METODODINAMICOEXACTO_H */
