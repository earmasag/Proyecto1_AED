//Este archivo contiene todas la funciones que manipulas la lista donantes
#include "listaDonantes.h"

//Retoner 1 si la cabeza de la lista esta vacia
//de lo contraio 0
int donanteVacia(Donante *cabeza){
    if(cabeza == NULL) return 1;
    else return 0;
}

//Agrega un nodo donante a la lista
Donante *agregarDonante(Donante *cabeza, Donante *nuevo){
    if(donanteVacia(cabeza)){
        cabeza = nuevo;
        nuevo->next = NULL;
        return cabeza;
    }
    Donante *aux, *prev = NULL;
    for(aux = cabeza;aux && (nuevo->cedula > aux->cedula);aux = aux->next) prev = aux;
    nuevo->next = aux;
    if(prev == NULL){
        cabeza = nuevo;
    } else {
        prev->next = nuevo;
    }
    return cabeza;
}

//Busca en la lista por el campo cedula
//si la encuentra retorna el nodo de la coincidencia
//de lo contrario retorna null
Donante* buscar_cedula(Donante *cabeza,int buscar_cedula){

	Donante *actual = cabeza;//variable para moverte por la lista
	while (actual != NULL){
		if (actual->cedula == buscar_cedula){//comparando hasta encontrar la cedula
			return actual;//retorna el nodo donde esta la cedula
		}
		actual = actual->next;//se mueve en la lista
	}
	return NULL;//si no encuentra retorna null

}

//Crea un nodo donante a partir de una estructura estatica
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

//Imprime la lista a partir de la cabeza
void imprimirDonantes(Donante *cabeza){
    Donante *aux;
    for(aux=cabeza; aux; aux = aux->next){
        printf("%i; %s; %s; %s -->\n",aux->cedula,aux->nombre, aux->telefono, aux->direccion);
    }
    printf("\n\n\n");
}