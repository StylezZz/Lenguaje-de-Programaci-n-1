/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "funciones.h"
#include "Persona.h"
using namespace std;

void operator *(struct Persona &per, double porc){
    per.sueldo *= (1+porc/100.0);
}

//double operator +(const struct Persona &per1,
//                          const struct Persona &per2){
//    return per1.sueldo + per2.sueldo;
//}

struct Persona operator +(const struct Persona &per1,
                          const struct Persona &per2){
    struct Persona per{
        20202020,"Gustavo",0
    };
    per.sueldo = per2.sueldo + per1.sueldo;
    return per;
}
