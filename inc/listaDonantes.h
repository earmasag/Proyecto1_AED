#ifndef listaDonantes
#define listaDonantes
#include "donante.h"

int donanteVacia(Donante *cabeza);
Donante *agregarDonante(Donante *cabeza, Donante *nuevo);
Donante *buscar_cedula(Donante *cabeza,int buscar_cedula);
void imprimirDonantes(Donante *cabeza);

#endif
