/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 31 de marzo de 2023, 08:09 AM
 */

#include <cstdlib>
#include <iostream>
#include "funciones.h"
#include <iomanip>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    imprimirCabecera();
    int codigoAlum,yearIngreso,nota,fechaUltEva,pos=1,flag=0,cantCursos=0;
    char nombreAlumno[100],codCurso[50],caracter;
    double cantCreditos,cantCreditosAprobados=0,cantCreditosDesaprobados=0,totalCreditos=0;
    int falla=0,cantAlumnos=0,sumaNotas=0,sumaNotasApro=0,cantCursosError=0;
    
    while(1){
        cin>>codigoAlum>>caracter>>yearIngreso>>nombreAlumno;
        if(cin.eof())break;
        if(cin.fail()){
            //Sigue leyendo cursos 
            //De la lectura de leerCurso, se deberá guardar la nota y la nota apro
            cin.clear();
            leerCurso(codCurso,cantCreditos,nota,fechaUltEva);
            sumaNotas+=nota;
            totalCreditos += cantCreditos;
            if(nota>=11){
                sumaNotasApro+=nota;
                cantCreditosAprobados+= cantCreditos;
            }else{
                cantCreditosDesaprobados+=cantCreditos;
            }
            imprimoCurso(pos,codCurso,cantCreditos,nota,fechaUltEva,yearIngreso,falla);
            pos++;
            if(falla==1){
                cantCursosError++;
            }else{
                cantCursos++;
            }
        }else{
            //Lee otro alumno
            if(flag!=0){
                imprimirResumen(cantCursos,cantCreditosAprobados,cantCreditosDesaprobados,
                    cantCreditos,sumaNotas,sumaNotasApro,cantCursosError);
            }
            imprimirCabeceraAlumno(nombreAlumno,codigoAlum,yearIngreso);
            flag=1;
            cantAlumnos++;
            pos=0;
        }
    }
    cout<<endl;
    imprimirLineas('=');
    cout<<"TOTAL DE ALUMNOS REGISTRADOS: "<<cantAlumnos;
    
    
    return 0;
}

