/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: chris
 *
 * Created on 9 de mayo de 2023, 22:25
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <fstream>
using namespace std;
void CargaDePedidosYProductos(int **cli_DniTelefono,char ***&pro_CodigoDescripcion,
                              double **&pro_PrecioDescuento,char ***&ped_Codigo,
                              int ***&ped_FechaCantidad,const char*nombreArch);
void agregarProducto(char **&pro_CodigoDescripcion,double *&pro_PrecioDescuento,
                     char *ped,char *descripcion,double descuento,double precUni,
                     int &numProd,int &tamProd);
int contarClientes(int **cli_DniTelefono);
void inicializarPunteros(int ***&ped_FechaCantidad,char ***&ped_Codigo,int numClientes);
char *leerCadena(ifstream &arch);
void leerDatos(ifstream &arch,char *&descripcion,double &descuento,int &cant,double &precUni,
               int &dniCliente,int &fecha);
int buscarCliente(int **cli_DniTelefono,int dniCliente);
void incrementarEspacios(char **&ped_Codigo,int **&ped_FechaCantidad,int &numDatos,int &cap);
void agregarPedidoCliente(char **&ped_Codigo,int **&ped_FechaCantidad,
                          int &size,int &numDatos,int fecha,int cant,char *ped);
int buscarCodigo(char *ped,char ***pro_CodigoDescripcion);
void agregarProducto(char ***&pro_CodigoDescripcion,double **&pro_PrecioDescuento,
                     char *ped,char *descripcion,double descuento,double precUni,
                     int &numProd,int &tamProd);
void incrementarEspacios(char ***&pro_CodigoDescripcion,double **&pro_PrecioDescuento,
                         int &numPro,int &cap);
void imprimirLineas(ofstream &arch,char c);
void imprimirFecha(ofstream &arch, int fecha);
void imprimirPedidos(ofstream &arch,char **pedCodigo,int **pedFechaCantidad);
void ReporteDePedidosYProductos(int **cli_DniTelefono,char ***pro_CodigoDescripcion,
                                double **pro_PrecioDescuento,char ***ped_Codigo,
                                int ***ped_FechaCantidad,const char *nombreArch);
void imprimirEncabezado(ofstream &arch);
void ReporteRelacionDePedidos(int **cli_DniTelefono,char ***cli_NombreCategoria,
                              char ***pro_CodigoDescripcion,double **pro_PrecioDescuento,
                              char ***ped_Codigo,int ***ped_FechaCantidad,
                              const char *nombreArch);
void imprimirProductos(ofstream &arch,char **ped_Codigo,
                       int **ped_FechaCantidad,char ***pro_CodigoDescripcion,
                       double **pro_PrecioDescuento);

#endif /* FUNCIONES_H */

