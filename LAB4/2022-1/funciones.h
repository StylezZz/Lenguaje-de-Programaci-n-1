/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: chris
 *
 * Created on 4 de mayo de 2023, 11:42
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <fstream>
using namespace std;
void CargaDeClientes(int *&,char **&,char *&);
void ReporteDeClientes(int *,char **,char *);
void imprimirLineas(ofstream &,char);
void agregarDatosCliente(int *&codProFecha,int codigo,int fecha,double *&cantidadPed,
                         double cant,int &numDatos);
void CargaDePedidosYProductos(int *cli_DNI,int *&pro_Codigo,
        char **&pro_Descripcion,double *&pro_Descuento,double *&pro_Precio,
        int **&cli_CodigoProFechaPedido,double **&cli_CantidadPedido);
void agregarProducto(int &bufferCodigo,int auxCodigoProducto,char *&bufferDescripcion,
                     char *auxDescripcion,double &descuento,double desc,double &Precio,
                     double &pre,int &numDatos);
void copiarArreglosDinamicos(int *&pro_Codigo,char **&pro_Descripcion,
        double *&pro_Descuento,double *&pro_Precio,int **&cli_CodigoProFechaPedido,
        double **&cli_CantidadPedido,int numDat,int *buff_proCod,char **descripcion,
        double *descuento,double *precio,int *cli_DNI,int i,double **cantPed,
        int **buffCodProFecha,int *numPedidos);
void asignarValoresCliente(int *&codProFecha,int *&buffCodProFecha,
            double *&cantPed, double  *&buffCantPed,int num);
void ReporteDePedidosYProductos(int *cli_DNI,int *pro_Codigo,
        char **pro_Descripcion,double *pro_Descuento,double *pro_Precio,
        int **cli_CodigoProFechaPedido,double **cli_CantidadPedido);
#endif /* FUNCIONES_H */

