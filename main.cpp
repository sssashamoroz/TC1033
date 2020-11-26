#include <iostream>
#include <fstream>
using namespace std;

#include "Orden.h"
void cargaProductos(Producto productosARR[], int &productCount);
void muestraProductos(Producto productosARR[], int productCount);


int main(void)
{
    Producto productoARR[20];
    int cantidadProductos;

    cargaProductos(productoARR, cantidadProductos);
    cout << productoARR[0].getNombre() << endl;
    cout << productoARR[0].getPrecio() << endl;
    cout << productoARR[0].getCantidad() << endl;

    return 0;
};


//funcion carga datos del archivo, almanece en arreglo indicado.
void cargaProductos(Producto productosARR[], int &productCount)
{
    //definir variables
    string nombreProducto;
    string nombreCatergoria;
    double precio;
    int cantidad;
    string SKU;

    ifstream file;
    file.open("Productos.txt");

    productCount = 0;
    while ( file >> nombreProducto >> nombreCatergoria >> precio >> cantidad >> SKU)
    {
        productosARR[productCount].setNombre(nombreProducto);
        productosARR[productCount].setCategoria(nombreCatergoria);
        productosARR[productCount].setPrecio(precio);
        productosARR[productCount].setCantidad(cantidad);
        productosARR[productCount].setSKU(SKU);
        productCount++;
    }

    file.close();
};

void muestraProductos(Producto productosARR[], int productCount)
{
    for(int i=0; i < productCount; i++)
    {
        cout << productosARR[productCount].getPrecio() << endl;
    }
}