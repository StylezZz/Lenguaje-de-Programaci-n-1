/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 28 de abril de 2023, 09:48 AM
 */

#include <cstdlib>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream archCurso, archAlumno, archRegistro;
    ofstream archReporte,archReporte2;
    
    AperturaDeUnArchivoDeTextosParaLeer(archCurso, "Cursos.txt");
    AperturaDeUnArchivoDeTextosParaLeer(archAlumno, "Alumnos.txt");
    AperturaDeUnArchivoDeTextosParaLeer(archRegistro, "Matricula.txt");
    
    AperturaDeUnArchivoDeTextosParaEscribir(archReporte, "ReporteCursos.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archReporte2, "ReporteAlumnos.txt");

    
    struct StAlumno alumnos[5];
    struct StCurso cursos[5];
    struct StRegistroDeMatricula registros[5];
    
    // LECTURA:
    archCurso>>cursos[0];
    archCurso>>cursos[1];
    
    archAlumno>>alumnos[0];
    archAlumno>>alumnos[1];

    
    archRegistro>>registros[0];
    archRegistro>>registros[1];

    
    // AGREGACION:
    // 1
    strcpy(cursos[2].codigoDelCurso,"XXXXXX"); // Para el final
    struct StCurso datoCur;
    strcpy(datoCur.codigoDelCurso,"INF263");
    datoCur.codigoDelProfesor=49516360;
    datoCur.creditos=4.25;
    datoCur.ingresos=0;
    strcpy(datoCur.nombreDelCurso,"Turbomaquinas_Y_Maquinas_De_Desplazamiento_Positivo");
    strcpy(datoCur.nombreDelProfesor,"DELGADO_GONZALES_GUILLERMO_ALFONSO");
    datoCur.numeroDeAlumnos=0;
    cursos+=datoCur;
    
    
    // 2
    alumnos[2].semestre=0;
    struct StAlumno datoAlum;
    datoAlum.codigo=1260;
    datoAlum.costoTotal=0;
    datoAlum.escala=3;
    strcpy(datoAlum.modalidad,"VIRTUAL");
    strcpy(datoAlum.nombre,"DEL_POZO/QUIO/CESAR");
    datoAlum.numeroDeCursos=0;
    datoAlum.porcentaje=0;
    datoAlum.semestre=20212;
    alumnos+=datoAlum;

    // 3
    struct StRegistroDeMatricula datoReg;
    strcpy(datoReg.codigoDelCurso,"INF263");
    datoReg.codigodelAlumno=7344;
    datoReg.semestreDelAlumno=20212;
    cursos*=datoReg;
    
    alumnos*=datoReg;
    
    // IMPRESION:
    archReporte<<cursos[0];
    archReporte<<cursos[1];
    archReporte<<cursos[2];
    
    
    archReporte2<<alumnos[0];
    archReporte2<<alumnos[1];
    
    return 0;
}

