#ifndef txt_manager
#define txt_manager

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "donante.h"
#include "listaDonantes.h"
#include "listaDonaciones.h"
#include "donaciones.h"

void crearArchivo();
Donante *cargarListaDonantes(Donante *HEAD);
headDonacion *cargarListaDonaciones(headDonacion *HEAD);

int guadarDonacion(Donaciones nuevaDonacion);
int actualizarArchivo(headDonacion *headDonacion, Donante *headDonante);
#endif
