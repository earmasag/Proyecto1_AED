#include "donante.h"

char *asignarValor(int max_char);

Donante *registrarDonante() {
	int size_nombre = 30;
	int size_tlf = 15;
	int size_dir = 120;

	//creando un puntero a mi estructura y asignando memoria 
	Donante nuevoDonante;

	printf("Bienvenido nuevo donante!.\n");
    printf("Ingrese sus datos por favor!.\n");

	while(getchar() != '\n');

    printf("Ingrese su cedula: ");
	while (scanf("%i",&nuevoDonante.cedula) != 1) {
         // Limpiar el buffer de entrada
        printf("Entrada inválida. Por favor, ingrese un número entero: ");
    }

	while ((getchar() != '\n'));

	printf("Ingrese su nombre: ");
	nuevoDonante.nombre = asignarValor(size_nombre);
	
	printf("Ingrese su telefono celular:");
	nuevoDonante.telefono = asignarValor(size_tlf);

	printf("Ingrese su direcion: ");
	nuevoDonante.direccion = asignarValor(size_dir);


	printf("Donante registrado con exito!.");

	system("clear");//limpia la pantalla
	
	return crearNodoDonante(nuevoDonante);
}

char *asignarValor(int max_char){
	char *asignar;
	char valor[max_char];
	fflush(stdin);
	fgets(valor,max_char,stdin);
	asignar = (char*)malloc(strlen(valor) + 1);
	if (asignar == NULL) {
        printf("Error al asignar memoria.\n");
        return NULL;
    }
	strcpy(asignar,valor);
	return asignar;
}

Donante *crearNodoDonante(Donante nuevoDonante){
	Donante *donantep = (Donante*) malloc(sizeof(Donante));
	if (donantep == NULL) {
        printf("Error al asignar memoria.\n");
        return NULL;
    }
	donantep->cedula = nuevoDonante.cedula;
	donantep->nombre = (char*)malloc(sizeof(nuevoDonante.nombre));
	strcpy(donantep->nombre,nuevoDonante.nombre);
	donantep->telefono = (char*)malloc(sizeof(nuevoDonante.telefono));
	strcpy(donantep->telefono,nuevoDonante.telefono);
	donantep->direccion = (char*)malloc(sizeof(nuevoDonante.direccion));
	strcpy(donantep->direccion,nuevoDonante.direccion);
	donantep->next = NULL;
	return donantep;

}