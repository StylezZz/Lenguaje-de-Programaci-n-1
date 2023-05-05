/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesSobrecargadas.h
 * Author: alulab14
 *
 * Created on 28 de abril de 2023, 09:42 AM
 */

#ifndef FUNCIONESSOBRECARGADAS_H
#define FUNCIONESSOBRECARGADAS_H

bool operator >>(ifstream &,struct StCurso &);
bool operator >>(ifstream &,struct StAlumno &);
bool operator >>(ifstream &,struct StRegistroDeMatricula &);
void operator +=(struct StCurso *,struct StCurso &);
void operator +=(struct StAlumno *,struct StAlumno &);
void operator *=(struct StCurso *,struct StRegistroDeMatricula &);
void operator *=(struct StAlumno *,struct StRegistroDeMatricula &);
void operator <<(ostream &,const struct StCurso &);
void convertirFormato(char *);
void operator <<(ostream &,const struct StAlumno &);


#endif /* FUNCIONESSOBRECARGADAS_H */

