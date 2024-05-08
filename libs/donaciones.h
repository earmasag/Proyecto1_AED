#include<time.h>

enum tipo_donaciones {
	MENETARIAS,
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
	enum tipo_donaciones tipo;
	char *descripcion;
	char *valor;
	enum Destino destino;
	enum Estado estado;
	struct donaciones *next;
}Donaciones;

void registrarDonacion();