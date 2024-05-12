#include<time.h>
#include<stdlib.h>

enum tipo_donaciones {
	MONETARIA,
	MATERIAL,
	VOLUNTARIADO
};

enum Destino {
	ALIMENTOS,
	MEDICINAS,
	MANTENIMIENTO,
	REPARACIONES
};

enum Estado{
	NO_DISPONIBLE,
	DISPONIBLE
};

typedef struct donaciones{
	time_t fecha;
	unsigned short int tipo;
	enum Destino destino;
	enum Estado estado;
	char *descripcion;
	float valor;
	struct donaciones *next;
}Donaciones;

Donaciones* registrarDonacion();