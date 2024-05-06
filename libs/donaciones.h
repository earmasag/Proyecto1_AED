
typedef struct donaciones{
	char *fecha;
	char *tipo;
	char *descripcion;
	char *valor;
	struct donaciones *next;
}Donaciones;

void registrarDonacion();