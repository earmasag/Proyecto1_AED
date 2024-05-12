// donante.c
#include "donante.h"

void asignarValor(int max_char, char *asignar);
//creando una lista vacia (se declara como variable global para que las funciones puedan acceder a la lista y modificarla)
extern Donante *cabeza;

Donante* buscar_cedula(Donante *cabeza, int buscarCedula){
	Donante *actual = cabeza;//variable para moverte por la lista
	while (actual != NULL){
		if (actual->cedula == buscarCedula){//comparando hasta encontrar la cedula
			return actual;//retorna el nodo donde esta la cedula
		}
		actual = actual->next;//se mueve en la lista
	}
	return NULL;//si no encuentra retorna null
}
//delimitadores usar para archivos

//funcion para agregar un nodo a la lista


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
	asignarValor(size_nombre, donantep->nombre);
	

	printf("Ingrese su telefono celular:");
	asignarValor(size_tlf, donantep->telefono);

	printf("Ingrese su direcion: ");
	asignarValor(size_dir, donantep->direccion);

	printf("Donante registrado con exito!.");

	system("clear");//limpia la pantalla
	system("pause");
	return donantep;
}

void asignarValor(int max_char, char *asignar){
	char valor[max_char];
	fflush(stdin);
	fgets(valor,max_char,stdin);
	asignar = (char*)malloc(strlen(valor));
	strcpy(asignar,valor);

}


