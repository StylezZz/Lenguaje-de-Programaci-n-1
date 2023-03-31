/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.h
 * Author: alulab14
 *
 * Created on 31 de marzo de 2023, 08:10 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void imprimirResumen(int cantCursos,double cantCreditosAprobados,double cantCreditosDesaprobados,
                    double cantCreditos,int sumaNotas,int sumaNotasApro,
        int cantCursosError);

void sacarFecha(int &dia,int &mes,int &anio,int fecha);
void imprimoCurso(int pos,char *codCurso,double cantCreditos,int nota,int fechaUltEva,
        int yearIngreso,int falla);

void leerCurso(char *codCurso,double &cantCreditos,int &nota,int &fechaUltEva);

void imprimirSegundaCabecera();
void formatearNombre(char *nombre);
void imprimirCabeceraAlumno(char *nombreAlumno,int codigoAlum,int yearIngreso);
void imprimirLineas(char c);

void imprimirCabecera();

#endif /* FUNCIONES_H */

