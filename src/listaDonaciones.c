#include "listaDonaciones.h"



headDonacion *crearHEADdonaciones(){
    headDonacion *HEAD;
    HEAD = (headDonacion*)malloc(sizeof(headDonacion));
    HEAD->ini = NULL;
    HEAD->fin = NULL;
    return HEAD;
}

int donacionesVacia(headDonacion *cabeza){
    if(cabeza->ini == NULL) return 1;
    else return 0;
}

headDonacion *agregarDonacion(headDonacion *HEAD, Donaciones *nuevaDonacion){
    if(donacionesVacia(HEAD)){
        HEAD->fin = nuevaDonacion;
        HEAD->ini = nuevaDonacion;
        nuevaDonacion->next = NULL;
        return HEAD;
    }
    HEAD->fin->next = nuevaDonacion;
    HEAD->fin = nuevaDonacion;
    nuevaDonacion->next = NULL;
    return HEAD;
}

void imprimirDonaciones(headDonacion *HEAD){
    Donaciones *aux;
    for(aux = HEAD->ini;aux; aux = aux->next){
        printf("%d;%i,%li;%i;%i;%i;%f;%s--->  \n",aux->num_donacion,aux->cedula_donante,aux->fecha,
            aux->tipo,aux->estado,aux->destino,aux->valor,aux->descripcion);
    }
    printf("\n");
}

Donaciones *buscarDonacion(headDonacion *HEAD, int index){
    
    Donaciones *aux;
    for(aux = HEAD->ini; aux; aux = aux->next){
        if(aux->num_donacion == index){
            return aux;
        }
    }
    return NULL;
}