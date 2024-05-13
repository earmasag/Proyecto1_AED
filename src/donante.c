// donante.c
#include "donante.h"

char *asignarValor(int max_char);



Donante *registrarDonante() {
	int size_nombre = 30;
	int size_tlf = 15;
	int size_dir = 120;

	//creando un puntero a mi estructura y asignando memoria 
	Donante *donantep = (Donante*) malloc(sizeof(Donante));
	printf("Bienvenido nuevo donante!.\n");
    printf("Ingrese sus datos por favor!.\n");

    printf("Ingrese su cedula: ");
	scanf("%i",&donantep->cedula); 

	while ((getchar() != '\n'));

	fflush(stdin);
	printf("Ingrese su nombre: ");

	donantep->nombre = asignarValor(size_nombre);
	
	printf("Ingrese su telefono celular:");
	donantep->telefono = asignarValor(size_tlf);

	printf("Ingrese su direcion: ");
	donantep->direccion = asignarValor(size_dir);

	printf("Donante registrado con exito!.");

	system("clear");//limpia la pantalla
	
	return donantep;
}

char *asignarValor(int max_char){
	char *asignar;
	char valor[max_char];
	fflush(stdin);
	fgets(valor,max_char,stdin);
	asignar = (char*)malloc(strlen(valor));
	strcpy(asignar,valor);
	return asignar;
}

