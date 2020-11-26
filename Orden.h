#ifndef ORDEN_H
#define ORDEN_H

#include "Producto.h"
#include "Fecha.h"

class Orden
{
    public:
        //Constructores
        Orden();
        Orden(Producto nProducto, Fecha nFecha, string nNombre, string nDireccion, string nColonia, string nMunicipio);

        //getters
        Producto getProducto();
        Fecha getFecha();
        string getNombre();
        string getDireccion();
        string getColonia();
        string getMunicipio();

        //setters
        void setProducto(Producto nProducto);
        void setFecha(Fecha nFecha);
        void setNombre(string nNombre);
        void setDireccion(string nDireccion);
        void setColonia(string nColonia);
        void setMunicipio(string nMunicipio);

    private:
        Producto producto;
        Fecha fecha;
        string nombre;
        string direccion;
        string colonia;
        string municipio;
};

//Constructores
Orden::Orden()
{
    Producto nProducto;
    producto = nProducto;
    Fecha nFecha;
    fecha = nFecha;
    nombre = "N/A";
    direccion = "N/A";
    colonia = "N/A";
    municipio = "N/A";
}

Orden::Orden(Producto nProducto, Fecha nFecha, string nNombre, string nDireccion, string nColonia, string nMunicipio)
{
    producto = nProducto;
    fecha = nFecha;
    nombre = nNombre;
    direccion = nDireccion;
    colonia = nColonia;
    municipio = nMunicipio;
}

//Getters
Producto Orden::getProducto()
{
    return producto;
}

Fecha Orden::getFecha()
{
    return fecha;
}

string Orden::getNombre()
{
    return nombre;
}

string Orden::getDireccion()
{
    return direccion;
}

string Orden::getColonia()
{
    return colonia;
}

string Orden::getMunicipio()
{
    return municipio;
}


//Setters
void Orden::setProducto(Producto nProducto)
{
    producto = nProducto;
}

void Orden::setFecha(Fecha nFecha)
{
    fecha = nFecha;
}

void Orden::setNombre(string nNombre)
{
    nombre = nNombre;
}

void Orden::setDireccion(string nDireccion)
{
    direccion = nDireccion;
}

void Orden::setColonia(string nColonia)
{
    colonia = nColonia;
}

void Orden::setMunicipio(string nMunicipio)
{
    municipio = nMunicipio;
}

#endif // ORDEN_H

