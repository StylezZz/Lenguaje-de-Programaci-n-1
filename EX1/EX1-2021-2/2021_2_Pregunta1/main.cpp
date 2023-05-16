/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on 16 de mayo de 2023, 0:34
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "BibliotecaCargaLibros_Y_Usuarios.h"
#include "BibliotecaControlDePrestamos.h"

int main(int argc, char** argv) {
    char **codLibro,*tipoUs,**nombreUs,***codLibPrest;
    int *cantLibros,*carneUs,**fechPrest;
    cargarLibros(codLibro,cantLibros);
    mostrarLibros(codLibro,cantLibros,"ReporteLibros1.txt");
    cargarUsuarios(carneUs,tipoUs,nombreUs);
    mostrarUsuarios(carneUs,tipoUs,nombreUs);
    
    cargarPrestamos(fechPrest,codLibPrest,carneUs);
    mostrarLibrosPrestados(fechPrest,codLibPrest,carneUs,tipoUs,"ReporteDePrestamos1.txt");
    procesarSolicitudes(carneUs,tipoUs,nombreUs,fechPrest,codLibPrest,codLibro,cantLibros);
    cout<<"Se termino de procesar solicitudes"<<endl;
//    mostrarLibrosPrestados(fechPrest,codLibPrest,carneUs,tipoUs,"ReporteDePrestamos2.txt");    
//    mostrarLibros(codLibro,cantLibros,"ReporteLibros2.txt");
    return 0;
}

