#include <iostream>
using namespace std;

#include "Orden.h"

int main(void)
{
    Categoria cafe("cafe");
    Producto americano("Americano", cafe, 34.50, 10, true, "00242214424");
    cout << americano.getNombre() << " " << americano.getPrecio() << " " << americano.getCantidad() << " " << americano.getDisponibilidad() << endl;
    cout << americano.getCategoria().getNombre() << endl;


    Fecha fecha(10, 12, 2020);

    Orden orden1;
    cout << orden1.getFecha().getDia() << endl;

    return 0;
};
