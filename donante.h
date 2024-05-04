// donante.h
#ifndef DONANTE_H //esta linea verifica si donante_h a sido definido, si no ha sido incluido como es el caso entrara al codigo
#define DONANTE_H//aqui ya se define como tal donante_h
//donante_h se esta utilizando como un macro
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct donaciones{
	char *fecha;
	char *tipo;
	char *descripcion;
	char *valor;
}Donaciones;

typedef struct donante{
	char *nombre;
	int cedula;
	char *telefono;
	char *direccion;
	struct donante *next;
	Donaciones *pDonaciones;
}Donante;

void registrarDonante();
void registrarDonacion();
Donante* buscar_cedula(Donante *cabeza,int buscar_cedula);
void agregarDonante(Donante **Cabeza,char *nombreNuevo,int cedula,char *direccion,Donaciones *pDonaciones);
void mostrarLista(Donante *cabeza);
void salir();

#endif//aqui termina el bloque de codigo definido para donante_h

