/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#define INCREMENTO 5
#include "funciones.h"
#include "Clientes.h"
using namespace std;


void CargaDePedidosYProductos(int **cli_DniTelefono,char ***&pro_CodigoDescripcion,
                              double **&pro_PrecioDescuento,char ***&ped_Codigo,
                              int ***&ped_FechaCantidad,const char*nombreArch){
    ifstream arch(nombreArch,ios::in);
    if(!arch){
        cout<<"Error no se pudo abrir el archivo "<<nombreArch<<endl;
        exit(1);
    }
    pro_CodigoDescripcion = nullptr;
    pro_PrecioDescuento = nullptr;
    int numClientes = contarClientes(cli_DniTelefono);
    inicializarPunteros(ped_FechaCantidad,ped_Codigo,numClientes);
    char *desc,*ped;
    int dniCliente,fecha,cant;
    int numDatos[1000]{},size[1000]{},numProd=0,tamProd=0;
    double descuento,precUni;
    while(1){
        ped = leerCadena(arch);
        if(arch.eof())break;
        leerDatos(arch,desc,descuento,cant,precUni,dniCliente,fecha);
        int posCliente = buscarCliente(cli_DniTelefono,dniCliente);
        if(posCliente!=-1){
            agregarPedidoCliente(ped_Codigo[posCliente],ped_FechaCantidad[posCliente],
                                size[posCliente],numDatos[posCliente],fecha,cant,ped);
        }
        int posProducto = buscarCodigo(ped,pro_CodigoDescripcion);
        if(posProducto==-1){
            //Si es -1 significa que no lo encontro entonces no es repetido
            agregarProducto(pro_CodigoDescripcion,pro_PrecioDescuento,
                            ped,desc,descuento,precUni,numProd,tamProd);
        }
    }
    
}

//char ***cli_NombreCategoria,***pro_CodigoDescripcion,***ped_Codigo;
//    int **cli_DniTelefono,***ped_FechaCantidad;
//    double **pro_PrecioDescuento;
void agregarProducto(char ***&pro_CodigoDescripcion,double **&pro_PrecioDescuento,
                     char *ped,char *descripcion,double descuento,double precUni,
                     int &numProd,int &tamProd){
    char **aux;
    aux = new char*[2];
    aux[0]=ped;
    aux[1]=descripcion;
    
    double *auxDouble;
    auxDouble = new double[2];
    auxDouble[0]=precUni;
    auxDouble[1]=descuento;
    
    if(numProd==tamProd)incrementarEspacios(pro_CodigoDescripcion,pro_PrecioDescuento,
                                            numProd,tamProd);
    pro_CodigoDescripcion[numProd]=nullptr;
    pro_CodigoDescripcion[numProd-1]=aux;
    pro_PrecioDescuento[numProd]=nullptr;
    pro_PrecioDescuento[numProd-1]=auxDouble;
    numProd++;
}

void incrementarEspacios(char ***&pro_CodigoDescripcion,double **&pro_PrecioDescuento,
                         int &numPro,int &cap){
    char ***auxC;
    double **auxD;
    
    cap+=INCREMENTO;
    if(pro_CodigoDescripcion ==nullptr){
        pro_CodigoDescripcion = new char**[cap];
        pro_PrecioDescuento = new double*[cap];
        
        pro_CodigoDescripcion[0]=nullptr;
        pro_PrecioDescuento[0]=nullptr;
        numPro=1;
    }else{
        auxC = new char**[cap];
        auxD = new double*[cap];
        for(int i=0;i<numPro;i++){
            auxC[i]=pro_CodigoDescripcion[i];
            auxD[i]=pro_PrecioDescuento[i];
        }
        delete pro_CodigoDescripcion;
        delete pro_PrecioDescuento;
        pro_CodigoDescripcion=auxC;
        pro_PrecioDescuento = auxD;
        
    }
}

int buscarCodigo(char *ped,char ***pro_CodigoDescripcion){
    if(pro_CodigoDescripcion==nullptr){
        return -1;
    }
    for(int i=0;pro_CodigoDescripcion[i];i++){
        if(strcmp(ped,pro_CodigoDescripcion[i][0])==0){
            return i;
        }
    }
    return -1;
}

void agregarPedidoCliente(char **&ped_Codigo,int **&ped_FechaCantidad,
                          int &size,int &numDatos,int fecha,int cant,char *ped){
    int *aux;
    aux = new int[2]{0};
    aux[0]=fecha;
    aux[1]=cant;
    
    if(numDatos==size)incrementarEspacios(ped_Codigo,ped_FechaCantidad,numDatos,size);
    ped_Codigo[numDatos]=nullptr;
    ped_Codigo[numDatos-1]=ped;
    ped_FechaCantidad[numDatos]=nullptr;
    ped_FechaCantidad[numDatos-1]=aux;
    numDatos++;
}

void incrementarEspacios(char **&ped_Codigo,int **&ped_FechaCantidad,int &numDatos,int &cap){
    int **auxFechaCantidad;
    char **auxCodigo;
    
    cap+=INCREMENTO;
    if(ped_Codigo==nullptr){
        ped_Codigo = new char*[cap]{};
        ped_FechaCantidad= new int*[cap]{};
        numDatos=1;
    }else{
        auxCodigo = new char*[cap]{};
        auxFechaCantidad = new int*[cap]{};
        
        for(int i=0;i<numDatos;i++){
            auxCodigo[i]=ped_Codigo[i];
            auxFechaCantidad[i]=ped_FechaCantidad[i];
        }
        delete ped_Codigo;
        delete ped_FechaCantidad;
        ped_Codigo = auxCodigo;
        ped_FechaCantidad = auxFechaCantidad;
    }
}


int buscarCliente(int **cli_DniTelefono,int dniCliente){
    for(int i=0;cli_DniTelefono[i];i++){
        if(cli_DniTelefono[i][0]==dniCliente){
            return i;
        }
    }
    return -1;
}

void leerDatos(ifstream &arch,char *&descripcion,double &descuento,int &cant,double &precUni,
               int &dniCliente,int &fecha){
    char c;
    int dd,mm,aa;
    descripcion = leerCadena(arch);
    arch>>cant;
    if(arch.fail()){
        arch.clear();
        arch.get();
        arch>>descuento>>c>>cant>>c;
    }else{
        descuento =0;
        arch.get();
    }
    arch>>precUni>>c>>dniCliente>>c>>dd>>c>>mm>>c>>aa;
    fecha = dd +mm*100 +aa*10000;
}

char *leerCadena(ifstream &arch){
    char buffer[200],*cad;
    arch.getline(buffer,200,',');
    cad = new char[strlen(buffer)+1];
    strcpy(cad,buffer);
    return cad;
}

void inicializarPunteros(int ***&ped_FechaCantidad,char ***&ped_Codigo,int numClientes){
    ped_Codigo = new char**[numClientes+1]{};
    ped_FechaCantidad = new int**[numClientes+1]{};
    
    for(int i=0;i<numClientes;i++){
        ped_Codigo[i]=nullptr;
        ped_FechaCantidad[i]=nullptr;
    }
}

int contarClientes(int **cli_DniTelefono){
    int i=0;
    while(cli_DniTelefono[i]){
        i++;
    }
    return i;
}



void ReporteDePedidosYProductos(int **cli_DniTelefono,char ***pro_CodigoDescripcion,
                                double **pro_PrecioDescuento,char ***ped_Codigo,
                                int ***ped_FechaCantidad,const char *nombreArch){
    ofstream arch(nombreArch,ios::out);
    if(!arch){
        cout<<"Error no se pudo abrir el archivo "<<nombreArch<<endl;
        exit(1);
    }
    
    arch<<"Reporte Pedidos"<<endl;
    imprimirLineas(arch,'=');
    for(int i=0;cli_DniTelefono[i];i++){
        arch<<setw(15)<<"DNI COMPRADOR: "<<setw(10)<<cli_DniTelefono[i][0]<< setw(10)
            <<setw(10)<<cli_DniTelefono[i][1]<<endl;
        imprimirLineas(arch,'-');
        arch<<right<<setw(8)<<"CODPROD"<<setw(15)<<"FECHA"<<setw(15)<<"CANTIDAD"<<endl;
        if(ped_Codigo[i]){
            imprimirPedidos(arch,ped_Codigo[i],ped_FechaCantidad[i]);
        }
    }
    
    arch<<endl<<"Reporte de Productos"<<endl;
    imprimirLineas(arch,'=');
    arch << left << setw(75) << "COD PRODUCTO: " << setw(10) << "PRECIO" <<
            setw(15) << "DESCUENTO" << endl;
    for(int i=0;pro_CodigoDescripcion[i];i++){
        arch << right << setw(3) << i + 1 << ")  ";
        arch << left << setw(15) << pro_CodigoDescripcion[i][0] << 
                setw(50) << pro_CodigoDescripcion[i][1] <<
                right << setw(10) << pro_PrecioDescuento[i][0] <<
                setw(10) << pro_PrecioDescuento[i][1] << endl;
    }
}

void imprimirPedidos(ofstream &arch,char **pedCodigo,int **pedFechaCantidad){
    if(pedFechaCantidad){
        for(int i=0;pedFechaCantidad[i];i++){
            arch<<right<<setw(3)<<i+1<<") "<<setw(10)<<pedCodigo[i]<<" ";
            imprimirFecha(arch,pedFechaCantidad[i][0]);
            arch<<"   "<<setw(10)<<pedFechaCantidad[i][1]<<endl;
        }
        imprimirLineas(arch,'=');
    }
}

void imprimirFecha(ofstream &arch, int fecha){
    int dd, mm, aa;
    dd = fecha%100;
    fecha /= 100;
    mm = fecha%100;
    aa = fecha/100;
    arch << right << setfill('0') << setw(2) << dd << "/" << 
            setw(2) << mm << "/" 
            << setw(4) << left << aa << setfill(' ');
}

void imprimirLineas(ofstream &arch,char c){
    for(int i=0;i<100;i++)arch<<c;
    arch<<endl;
}

//char ***cli_NombreCategoria,***pro_CodigoDescripcion,***ped_Codigo;
//    int **cli_DniTelefono,***ped_FechaCantidad;
//    double **pro_PrecioDescuento;
void ReporteRelacionDePedidos(int **cli_DniTelefono,char ***cli_NombreCategoria,
                              char ***pro_CodigoDescripcion,double **pro_PrecioDescuento,
                              char ***ped_Codigo,int ***ped_FechaCantidad,
                              const char *nombreArch){
    ofstream arch(nombreArch,ios::out);
    if(!arch){
        cout<<"Error no se pudo abrir el archivo "<<nombreArch<<endl;
        exit(1);
    }
    imprimirEncabezado(arch);
    for(int i=0;cli_DniTelefono[i];i++){
        imprimirLineas(arch,'=');
        arch << left << setw(15) << "DNI" << setw(50) << "Nombre" << setw(15) <<
                "Categoria" << "Telefono" << endl;
        arch << setw(15) << cli_DniTelefono[i][0] << setw(50) << cli_NombreCategoria[i][0] << 
                setw(15) << cli_NombreCategoria[i][1] << cli_DniTelefono[i][1] << endl;
        imprimirLineas(arch,'-');
        arch<<"PRODUCTOS ADQUIRIDOS"<<endl;
        imprimirLineas(arch,'-');
        arch<<setw(5)<<"     " <<
                setw(10)<<"Codigo"<<
                setw(55)<<"Descripcion"<<
                setw(8)<<"P.U."<<
                setw(11)<<"Cantidad"<<
                setw(8)<<"Total"<<
                setw(12)<<"Descuento %"<<
                setw(10)<<"A Pagar"<<
                setw(13)<<"Descuento"<<
                setw(10)<<"Fecha"<<endl;
        imprimirLineas(arch,'-');
        imprimirProductos(arch,ped_Codigo[i],ped_FechaCantidad[i],pro_CodigoDescripcion,pro_PrecioDescuento);
        imprimirLineas(arch,'-');
    }
}

void imprimirProductos(ofstream &arch,char **ped_Codigo,
                       int **ped_FechaCantidad,char ***pro_CodigoDescripcion,
                       double **pro_PrecioDescuento){
    if(ped_FechaCantidad){
        double total,pagar;
        double totalPagar=0,totalDescuento=0;
        for(int i=0;ped_Codigo[i];i++){
            arch << right << setw(3) << i + 1 << ")  ";
            arch << left << setw(10) << ped_Codigo[i];
            int pos = buscarCodigo(ped_Codigo[i],pro_CodigoDescripcion);
            arch << setw(50) << pro_CodigoDescripcion[pos][1] << right <<
                    setw(10) << pro_PrecioDescuento[pos][0] << 
                    setw(10) << ped_FechaCantidad[i][1];
            total  = pro_PrecioDescuento[pos][0]*ped_FechaCantidad[i][1];
            arch << setw(10) << total << 
                    setw(10) << pro_PrecioDescuento[pos][1];
            pagar = total * (1-pro_PrecioDescuento[pos][1]/100);
            arch << setw(10) << pagar <<
                    setw(10) << total * (pro_PrecioDescuento[pos][1]/100) << "  ";
            totalDescuento +=  total * (pro_PrecioDescuento[pos][1]/100);
//            arch << setw(10) << ped_FechaCantidad[i][0] << endl;
            imprimirFecha(arch, ped_FechaCantidad[i][0]);
            arch << endl;
            totalPagar += pagar;
        }
        imprimirLineas(arch,'-');
        arch<<setw(106)<<"TOTAL"<<setw(10)<<totalPagar<<setw(10)<<totalDescuento<<endl;
    }
}

void imprimirEncabezado(ofstream &arch){
    arch<<setw(50)<<right<<"EMPRESA COMERCIALIZADORA DE ABARROTES"<<endl;
    imprimirLineas(arch,'=');
    arch<<"GASTOS DE LOS CLIENTES REGISTRADOS:"<<endl;
    
}
