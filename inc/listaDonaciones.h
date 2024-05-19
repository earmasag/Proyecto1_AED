#ifndef listaDonaciones
#define listaDonaciones

#include "donaciones.h"

int donacionesVacia(headDonacion *cabeza);
headDonacion *agregarDonacion(headDonacion *HEAD, Donaciones *nuevaDonacion);
void imprimirDonaciones(headDonacion *HEAD);
headDonacion *crearHEADdonaciones();
Donaciones *buscarDonacion(headDonacion *HEAD, int index);


#endif