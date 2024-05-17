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
	enum Destino destino;
	enum Estado estado;
	char *descripcion;
	float valor;
	struct donacion *next;
}Donaciones;

Donaciones* registrarDonacion();

#endif
