#include "listaDonantes.h"


int donanteVacia(Donante *cabeza){
    if(cabeza == NULL) return 1;
    else return 0;
}

Donante *agregarDonante(Donante *cabeza, Donante *nuevo){
    if(donanteVacia(cabeza)){
        cabeza = nuevo;
        nuevo->next = NULL;
        printf("%s",nuevo->nombre);
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

void imprimir(Donante *cabeza){
    Donante *aux;
    for(aux=cabeza;aux;aux->next){
        printf("%i; %s; %s; %s -->\n",aux->cedula,aux->nombre, aux->telefono, aux->direccion);
    }
}