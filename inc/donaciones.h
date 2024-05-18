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
	time_t fecha;
	unsigned short int tipo;
	unsigned short int destino;
	unsigned short int estado;
	float valor;
	char *descripcion;
	struct donacion *next;
}Donaciones;

typedef struct headDonacion{
	Donaciones *ini, *fin;
}headDonacion;

extern Donante *donanteHead;

Donaciones *crearNodoDonacion(Donaciones nuevaDonacion);
Donaciones* registrarDonacion();

#endif
