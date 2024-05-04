#include<string.h>
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
	Donaciones *pDonaciones;
}Donante;

void registrarDonante();
void registrarDonacion();
Donante* buscar_cedula(Donante *cabeza,int buscar_cedula);
void agregarDonante(Donante **Cabeza,char *nombreNuevo,int cedula,char *direccion,Donaciones *pDonaciones);
void mostrarLista(Donante *cabeza);
void salir();

#endif//aqui termina el bloque de codigo definido para donante_h
