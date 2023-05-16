/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Alonso Oswaldo Acosta Gonzales
 * Codigo del Alumno: 20170809
 * Created on 25 de mayo de 2021, 09:42 AM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "FuncionesEx01_20211_Preg02.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
    void *conductor, *falta, *consolidado;
    
    cargadatos(conductor,falta);
    registrafaltas(consolidado,conductor,falta);
    imprime(consolidado);
    
    return 0;
}

