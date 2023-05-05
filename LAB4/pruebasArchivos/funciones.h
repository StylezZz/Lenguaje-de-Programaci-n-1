/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: chris
 *
 * Created on 4 de mayo de 2023, 15:51
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void cargarCursos(char **&codCursos,char **&cursos,double *&creditos,
                    int *&idProfes,char **&profNombres);
void reporteCursos(char **codCursos,char **cursos,double *creditos,
                   int *idProfes,char **profNombres);
void cargarAlumnos(int *&semestre,int *&codigoAlumno,char **&nombreAlumno,
                   char *&modalidad,double *&porcentaje,int *&escala);
void imprimirAlumnos(int *semestre,int *codigoAlumno,char **nombreAlumno,
                     char *modalidad,double *porcentaje,int *escala);
#endif /* FUNCIONES_H */

