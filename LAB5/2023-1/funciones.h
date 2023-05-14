/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: chris
 *
 * Created on 11 de mayo de 2023, 8:47
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <fstream>
using namespace std;

void lecturaAlumnos(const char *nombreArch,int *&alumno_Codigo,
        char **&alumno_Nombre,char *&alumno_Modalidad,int *&alumno_Porcentaje
            ,int *&alumno_Escala,char ***&alumno_cursos);
void aumentarEspacios(int *&alumno_Codigo,char **&alumno_Nombre,char *&alumno_Modalidad,
                   int *&alumno_Porcentaje,int *&alumno_Escala,
        char ***&alumno_cursos,int &numDat,int &cap);
void InicializarIncre(int *&alumno_Codigo,char **&alumno_Nombre,char *&alumno_Modalidad,
                   int *&alumno_Porcentaje,int *&alumno_Escala,char ***&alumno_cursos,int cap);

char *leerCadena(ifstream &arch);
void guardarAlu(int *&alumno_Codigo,char **&alumno_Nombre,char *&alumno_Modalidad,
                   int *&alumno_Porcentaje,int *&alumno_Escala,char ***&alumno_cursos,int &numDat,
                int codAlu,char *nomb,char modalidad,int porcentaje,int escala);
void pruebaLecturaAlumnos(const char *nombreArch,int *alumno_Codigo,
        char **alumno_Nombre,char *alumno_Modalidad,int *alumno_Porcentaje
            ,int *alumno_Escala,char ***alumno_cursos);
void lecturaCursos(const char *nombreArch,int *alumno_Codigo,int *alumno_Escala,
        char **&curso_Nombre,double *&curso_Creditos,int ***&curso_Alumnos,char ***&alumno_cursos);
int obtenerCantAlumnos(int *alumno_Codigo);
int verificarCursoRepetido(char **curso_Nombre,char *nomb,int numDat);
int buscarCurso(char **curso_Nombre,char *nomb,int numDat);
void aumentarEspaciosCursos(char **&curso_Nombre,double *&curso_Creditos
                    ,int ***&curso_Alumnos,int *&arrCantAlu,int *&arrCapAlu,int &numDat,int &cap);
int buscarAlumno(int *alumno_Codigo,int cod);
void llenarCursoAlumno(int **&CursoAlu,int &cantAlu,int &capAlu,int *Alumno,int posCurso);
void aumentarEspaciosCursosAlumno(int **&CursoAlu,int &cantAlu,int &capAlu);
void aumentarEspaciosALUMNOXCURSO(char **&aluCurso,
                   int &cap,int &cantidad);
void llenarALUMNOCURSOS(char **&alumnoCurso,char *nomb,int &capaluCurso,int &numCursoAlu);
#endif /* FUNCIONES_H */

