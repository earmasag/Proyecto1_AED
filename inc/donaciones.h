#ifndef donaciones
#define donaciones
#include<time.h>
#include<stdlib.h>
#include "donante.h"
#include "listaDonantes.h"


enum tipo_donaciones {
	MONETARIA,
	MATERIAL,
	VOLUNTARIADO
};

enum Destino {
	NO,
	ALIMENTOS,
	MEDICINAS,
	MANTENIMIENTO,
	REPARACIONES
};

enum Estado{
	NO_DISPONIBLE,
	DISPONIBLE
};

typedef struct donacion{
	int num_donacion;
	int cedula_donante;
	time_t fecha;
	unsigned short int tipo;
	unsigned short int destino;
	unsigned short int estado;
	float valor;
	char *descripcion;
	struct donacion *next;
}Donaciones;

typedef struct {
	Donaciones *ini, *fin;
}headDonacion;

extern Donante *donanteHead;

//char destinos[][20] = {"Alimento", "Medicinas", "Mantenimiento", "Reparaciones", "Otras"};

Donaciones *crearNodoDonacion(Donaciones nuevaDonacion);
Donaciones* registrarDonacion();
headDonacion *adminitrarDonaciones(headDonacion *HEAD);

#endif
