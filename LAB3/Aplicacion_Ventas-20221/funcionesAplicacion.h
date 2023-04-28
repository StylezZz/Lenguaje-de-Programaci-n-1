/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funcionesAplicacion.h
 * Author: chris
 *
 * Created on 26 de abril de 2023, 10:21
 */

#ifndef FUNCIONESAPLICACION_H
#define FUNCIONESAPLICACION_H
void mostrarClientes(struct Estructura_ClienteRegistrado *arrClientes);
void mostrarProductos(struct Estructura_ProductosEnAlmacen *arrProd);
void leerClientes(struct Estructura_ClienteRegistrado *arrClientes);

void cargarPedidosLeerProductos(struct Estructura_ProductosEnAlmacen *arrProductos,
                                struct Estructura_ClienteRegistrado *arrClientes);
void llenarClientesAlmacen(struct Estructura_ClienteRegistrado *arrClientes,
                           struct Estructura_ProductosEnAlmacen *arrProductos,
                           char *codigoPro,char *descripcion,double descuento,
                           double cantidad,double precioUnitario,int dni,int fecha);

void cargarPedidoCliente(struct Estructura_ClienteRegistrado &cli,char *codigoPro,
                         double cantidad,int fecha);
void mostrarReporte(struct Estructura_ClienteRegistrado *arrClientes,
                    struct Estructura_ProductosEnAlmacen *arrProductos);



#endif /* FUNCIONESAPLICACION_H */

