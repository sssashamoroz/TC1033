#include <iostream>
#include <fstream>
using namespace std;

#include "Orden.h"

//funciones del programa
void cargaProductos(Producto productosARR[], int &productCount);
void muestraProductos(Producto productosARR[], int productCount);
void restock(Producto productosARR[], int productCount);
void agregarOrden(Orden ordenARR[], Producto productosARR[], int productCount, int &orderCount);
int buscaProducto(Producto productosARR, int productCount);
void muestraOrdenes(Orden ordenARR[], Producto productosARR[], int productCount, int orderCount);

int main(void)
{
    char opcion;
    Producto productoARR[20];
    Orden ordenARR[20];
    int cantidadProductos;
    int cantidadOrden;
    cargaProductos(productoARR, cantidadProductos);

    //while loop condition variable
    bool run;
    run = true;

    cout << "BIENVENIDO A BEBIDAS.COM" << endl;
    cout << "*************************" << endl; 

    while (run)
    {
        cout << "Seleccione de la siguiente lista: " << endl;
        cout << "a) Mostrar productos" << endl;
        cout << "b) Reaprovisionar productos" << endl;
        cout << "c) Agregar orden" << endl;
        cout << "d) Ver ordenes" << endl;
        cout << "t) Terminar programa" << endl;
        cout << "--> ";
        cin >> opcion;
        switch(opcion)
        {
            case 'a':
                muestraProductos(productoARR, cantidadProductos);
                break;

            case 'b':
                restock(productoARR, cantidadProductos);
                break;

            case 'c':
                agregarOrden(ordenARR, productoARR, cantidadProductos, cantidadOrden);
                break;

	    case 'd':
		muestraOrdenes(ordenARR, productoARR, cantidadProductos, cantidadOrden);
		break;
		
            case 't':
                run = false;
                break;

	    default:
		cout << "Favor de ingresar un valor valido" << endl;
		break;
        }
        
        //restock(productoARR, cantidadProductos);
    }
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
    while (file >> nombreProducto >> nombreCatergoria >> precio >> cantidad >> SKU)
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
        cout << "Catergoria del producto: " << productosARR[i].getCategoria().getNombre() << endl;
        cout << "Nombre del producto: " << productosARR[i].getNombre() << "  // Precio: " << productosARR[i].getPrecio() << endl;
        cout << "Disponible a la venta: " << productosARR[i].getCantidad() << endl;
        cout << "SKU: " << productosARR[i].getSKU() << endl;
        cout << "  " << endl;
    }  
};

int buscaProducto(Producto productosARR[], int productCount)
{
    string producto;
    int posicionProducto;

    bool verdadero = true;
    while (verdadero)
    {
        cout << endl;
        cout << "Productos Disponibles: " << endl;
        for(int i = 0; i < productCount; i++)
        {
            cout << productosARR[i].getNombre() << endl;
        }

        cout << "Favor de ingresar nombre de producto:" << endl;
        cout << "--> ";
        cin >> producto;

        for(int i=0; i < productCount; i++)
        {
            if (productosARR[i].getNombre() == producto)
            {
                verdadero = false;
                posicionProducto = i;
                break;
            }
            else if (productCount == i+1)
            {
                cout << "No hay un producto que se llame: " << producto << ". Favor de ingresar el nombre exacto.";
            }
        }
    }
    return posicionProducto;
};

void restock(Producto productosARR[], int productCount)
{   
    int cantidad;
    //buscar el index del producto
    int posicionProducto;
    posicionProducto = buscaProducto(productosARR, productCount);

    cout << "¿Cuántos productos quieres agregar a: " << productosARR[posicionProducto].getNombre() << "?" << endl;
    cout << "--> ";
    cin >> cantidad;
    productosARR[posicionProducto].addCantidad(cantidad);
    cout << "¡Movimiento Exitoso!";
}

void agregarOrden(Orden ordenARR[], Producto productosARR[], int productCount, int &orderCount) 
{
    int cantidad;
    int posicionProducto;

    string nombre;
    string direccion;
    string colonia;
    string municipio;
    int dd;
    int mm;
    int aaaa;

    posicionProducto = buscaProducto(productosARR, productCount);

    cout << "¿Cuántos " << productosARR[posicionProducto].getNombre() << " se ordenaron?" << endl;
    cout << "--> ";
    cin >> cantidad;

    bool revisar = productosARR[posicionProducto].subCantidad(cantidad);

    if (revisar == false)
	{
	    return;
	}	

    //int tamano = sizeof(ordenARR) / sizeof(ordenARR[0])

    cout << "Nombre del cliente: ";
    cin >> nombre;
    ordenARR[orderCount].setNombre(nombre);
    cout << "Dirección: ";
    cin >> direccion;
    ordenARR[orderCount].setDireccion(direccion);
    cout << "Colonia: ";
    cin >> colonia;
    ordenARR[orderCount].setColonia(colonia);
    cout << "Municipio: ";
    cin >> municipio;
    ordenARR[orderCount].setColonia(municipio);
    cout << "Día en el que se ordenó el producto: ";
    cin >> dd;
    cout << "Mes en el que se ordenó el producto: ";
    cin >> mm;
    cout << "Año en el que se ordenó el producto: ";
    cin >> aaaa;

    Fecha nFecha(dd,mm,aaaa); //DUda AFA
    ordenARR[orderCount].setFecha(nFecha);

    
    Producto nProducto;
    ordenARR[orderCount].setProducto(productosARR[posicionProducto]);
    
    orderCount++;

    cout << "¡Movimiento Exitoso!" << endl;
}

void muestraOrdenes(Orden ordenARR[], Producto productosARR[], int productCount, int orderCount)
{
    if (orderCount - 1 == -1)
    {
	   cout << "No hay ninguna orden registrada en el sistema." << endl;
	   return;
    }
    
    for(int i = 0; i < orderCount; i++)
    {
           cout << "ORDEN " << i+1 << endl;
	   cout << ordenARR[i].getProducto().getNombre() << endl;       
    } 

}

