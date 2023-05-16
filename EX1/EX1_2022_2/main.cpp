/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jeanpierr Suarez Facundo
 * Codigo: 20196346
 *
 * Created on 15 de mayo de 2023, 01:18 AM
 */

#include <iostream>
#include <iomanip>
#include "funciones_Parte_1.h"
using namespace std;

int main(int argc, char** argv) {
      int *med_Codigo,***consultas_int;
      double *med_Precio;
      char **med_Descripcion,***consultas_char;
      
      CargarMedicamentos(med_Codigo, med_Descripcion,med_Precio,"Medicinas-Preg01.csv");
      PruebaDeCargaDeMedicamentos(med_Codigo, med_Descripcion,med_Precio,"PruebaMedicinas.txt");
      
      CargarConsultas(consultas_int,consultas_char,"Consultas-Preg01.csv");
      PruebaDeCargaDeConsultas(consultas_int,consultas_char,"PruebaConsultas.txt");
      
      //Parte void
//      void *medicinas,*citas;
//      cargamedicinas(medicinas);
      
      return 0;
}

