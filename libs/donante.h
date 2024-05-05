#include<string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct donaciones{
	char *fecha;
	char *tipo;
	char *descripcion;
	char *valor;
	struct donaciones *next;
}Donaciones;

typedef struct donante{
	char *nombre;
	int cedula;
	char *telefono;
	char *direccion;
	struct donante *next;
}Donante;

void registrarDonante();
void registrarDonacion();
Donante* buscar_cedula(Donante *cabeza,int buscar_cedula);
void agregarDonante(Donante **Cabeza,char *nombreNuevo,int cedula,char *direccion);
void mostrarLista(Donante *cabeza);
void salir();


