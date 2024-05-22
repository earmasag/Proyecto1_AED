//Este archivo contiene todas las funciones que manipulas la cola de Donaciones
#include "listaDonaciones.h"

//Esta funcion retorna el numero del ultimo registro
//de la estrutura de donaciones +1
int numeroDonacion(headDonacion *HEAD){
    if(!HEAD->ini) return -1;

    return HEAD->fin->num_donacion + 1;
}

//Esta funcion inicializa la coda de donaciones
headDonacion *crearHEADdonaciones(){
    headDonacion *HEAD;
    HEAD = (headDonacion*)malloc(sizeof(headDonacion));
    HEAD->ini = NULL;
    HEAD->fin = NULL;
    return HEAD;
}

//retorna 1 si la cabeza de la lista o el inicio estan vacios
//reotorna 0 de lo contrario
int donacionesVacia(headDonacion *cabeza){
    if(!cabeza || !cabeza->ini) return 1;
    else return 0;
}

//Esta funcion agrega un dodo de donacion
//al final de la cola y retorna la cabeza de la cola
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

//Esta funcion imprime la cola a partir de la cabeza
void imprimirDonaciones(headDonacion *HEAD){
    Donaciones *aux;
    for(aux = HEAD->ini;aux; aux = aux->next){
        printf("%d;%i,%li;%i;%i;%i;%f;%s--->  \n",aux->num_donacion,aux->cedula_donante,aux->fecha,
            aux->tipo,aux->estado,aux->destino,aux->valor,aux->descripcion);
    }
    printf("\n");
}

//Busca una donacion a partir de su numero de donación
//retorna el nodo de la donacion si la encuentra 
//de lo contrario retorna null
Donaciones *buscarDonacion(headDonacion *HEAD, int index){
    
    Donaciones *aux;
    for(aux = HEAD->ini; aux; aux = aux->next){
        if(aux->num_donacion == index){
            return aux;
        }
    }
    return NULL;
}

//Esta funcion recibe una estructura estatica para convertirla
//en un nodo que se pueda añadir a la lista
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


//Esta funcion imprime las donaciones disponibles de la cola
//Si no ha retorna 0
int donacionesDisponibles(headDonacion *HEAD){
    Donaciones *aux;
    int siHay = 0;
    for(aux = HEAD->ini; aux ; aux = aux->next){
        if(aux->estado){
            printf(" %i |",aux->num_donacion);
            siHay = 1;
        }
    }
    if(siHay){
        printf("\n");
        return siHay;
    }else{
        return siHay;
    }
    
}