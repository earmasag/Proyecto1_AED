#include "listaDonantes.h"


int donanteVacia(Donante *cabeza){
    if(cabeza == NULL) return 1;
    else return 0;
}

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

void imprimirDonantes(Donante *cabeza){
    Donante *aux;
    for(aux=cabeza; aux; aux = aux->next){
        printf("%i; %s; %s; %s -->\n",aux->cedula,aux->nombre, aux->telefono, aux->direccion);
    }
    printf("\n\n\n");
}