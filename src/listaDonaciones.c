#include "listaDonaciones.h"

int numeroDonacion(headDonacion *HEAD){
    if(!HEAD->ini) return -1;

    return HEAD->fin->num_donacion + 1;
}

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

Donaciones *crearNodoDonacion(Donaciones nuevaDonacion){

    Donaciones *donacionesp;
    if((donacionesp = (Donaciones*)malloc(sizeof(Donaciones))) == NULL){
        printf("Error al asignar memoria\n");
        return NULL;
    }
    
    donacionesp->num_donacion = nuevaDonacion.num_donacion;
    donacionesp->cedula_donante = nuevaDonacion.cedula_donante;
    donacionesp->tipo = nuevaDonacion.tipo;
    donacionesp->destino = nuevaDonacion.destino;
    donacionesp->estado = nuevaDonacion.estado;
    donacionesp->fecha = nuevaDonacion.fecha;
    donacionesp->valor = nuevaDonacion.valor;
    donacionesp->descripcion = (char*)malloc(sizeof(nuevaDonacion.descripcion));
    strcpy(donacionesp->descripcion,nuevaDonacion.descripcion);

    return donacionesp;

}