/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PunterosGenericos.hpp
 * Author: Diego Bernardo Castilla Arnao Monteagudo - 20196342
 *
 * Created on 13 de mayo de 2023, 11:38 PM
 */

#ifndef PUNTEROSGENERICOS_HPP
#define PUNTEROSGENERICOS_HPP
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "PunterosGenericos.hpp"

void cargaproductos(void *&productos);
void * leerProducto(ifstream& arch);
char *memExacta(char *nombre);

void cargapedidos(void *&pedidos);
void* leerPedido(ifstream &arch);

void procesaclientes(void *&productos, void *&pedidos, void *&clientes);
void actualizarPedidosAtendidos(void *productos, void *pedidos);
void actualizarPedido(void *pedido, void *productos);
int validarStock(int *codPed, int*cantidadPedida, void* productos);

void asignarPedidosAClientes(void *pedidos, void *&clientes);
void* leerCliente(ifstream & arch);
void cargarPedidosCliencte(void *cli, void *pedidos);
int validarClientePedido(int dni, void *pedido);
int validarPedidoAtendido( void *pedido);
void * asignarPed(void *pedido);
void imprimereporte(void *clientes);

#endif /* PUNTEROSGENERICOS_HPP */

