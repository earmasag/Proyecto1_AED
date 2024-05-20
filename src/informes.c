#include "informes.h"

void informeDestinos(headDonacion *HEAD);
void informeMateriales(headDonacion *HEAD);
void detalleDonaciones(headDonacion *headDonaciones, Donante *headDonante);
void informePorDonantes(headDonacion *headDonacion, Donante *headDonante);

char destinos[][20] = {"Alimento", "Medicinas", "Mantenimiento", "Reparaciones", "Otras"};
char tipo_donacion[][15] = {"Monetaria", "Materiales", "Voluntariado"};
char estados[][20] = {"No Disponible", "Disponible"};


void crearInformes(headDonacion *headDonacion, Donante *headDonante){
    int op;
    do{
    printf("Que infomre desea imprimir?\n");
    printf("(1)Destinos de donaciones.\n");
    printf("(2)Materiales donados.\n");
    printf("(3)Todas las donaciones.\n");
    printf("(4)Donaciones por Donante\n");
    scanf("%i",&op);
    if(op < 1 || op > 4) 
    printf("Ingreso una dato invalido\nEscriba una de las opciones\n");

    }while(op < 1 || op > 4);

    switch (op)
    {
    case 1:
        informeDestinos(headDonacion);
        break;
    case 2:
        informeMateriales(headDonacion);
        break;
    case 3:
        detalleDonaciones(headDonacion,headDonante);
        break;
    case 4:
        informePorDonantes(headDonacion,headDonante);
        break;
    default:
        break;
    }
}    


void informeDestinos(headDonacion *HEAD){
    if(!HEAD) return;


    Donaciones *aux;
    printf("N° DONACION    TIPO DE DONACION    DESTINO\n");
    for(aux = HEAD->ini; aux; aux = aux->next){
        if(aux->tipo < 2)
        printf("%i   %s   %s\n", aux->num_donacion, tipo_donacion[aux->tipo], destinos[aux->destino]);        
    }
}

void informeMateriales(headDonacion *HEAD){
    if(!HEAD) return;
    Donaciones *aux;
    printf("N°DONACION  FECHA  ARTICULO CANTIDAD\n");

    for(aux = HEAD->ini; aux; aux = aux->next){
        if(aux->tipo == 1){
            
            char strFecha[20];
            struct tm *fecha;
            fecha = localtime(&aux->fecha);
            strftime(strFecha,sizeof(strFecha),"%d/%m/%Y",fecha);
            printf("%i    %s    %s     %F\n",aux->num_donacion, strFecha, aux->descripcion, aux->valor);
                       
        }
    }

}

void detalleDonaciones(headDonacion *headDonaciones, Donante *headDonante){
    if(!headDonaciones || !headDonante) return;



    Donaciones *auxDonaciones;
    Donante *auxDonante;
    char strFecha[20];
    struct tm *fecha;
            
    printf("N° DONACION    CEDULA   NOMBRE  FECHA TIPO  DESTINO   ESTADO   VALOR/CANTIDAD  DESCRIPCION\n");
    for(auxDonaciones = headDonaciones->ini; auxDonaciones; auxDonaciones = auxDonaciones->next){

            fecha = localtime(&auxDonaciones->fecha);
            strftime(strFecha,sizeof(strFecha),"%d/%m/%Y",fecha);

            auxDonante = buscar_cedula(headDonante,auxDonaciones->cedula_donante);

            printf("%i  %i  %s  %s  %s  %s  %s   %f  %s \n", auxDonaciones->num_donacion, auxDonante->cedula, auxDonante->nombre,
            strFecha, tipo_donacion[auxDonaciones->tipo],destinos[auxDonaciones->destino], estados[auxDonaciones->estado],auxDonaciones->valor,
            auxDonaciones->descripcion);
    }

}

void informePorDonantes(headDonacion *headDonacion, Donante *headDonante){
    int cedula;
    Donante *auxDonante;
    Donaciones *auxDonaciones;
    char strFecha[20];
    struct tm *fecha;

    printf("Escoja el donate que desea buscar\n");
    scanf("%i", &cedula);

    if((auxDonante = buscar_cedula(headDonante,cedula)) == NULL){
        printf("Donante no encontrado o Donante no posee donaciones\n");
        return;
    }
    
    for(auxDonaciones = headDonacion->ini; auxDonaciones; auxDonaciones = auxDonaciones->next){

        if(auxDonaciones->cedula_donante == cedula){
            fecha = localtime(&auxDonaciones->fecha);
            strftime(strFecha,sizeof(strFecha),"%d/%m/%Y",fecha);
            printf("%i  %i  %s  %s  %s  %s  %s   %f  %s \n", auxDonaciones->num_donacion, auxDonante->cedula, auxDonante->nombre,
            strFecha, tipo_donacion[auxDonaciones->tipo],destinos[auxDonaciones->destino], estados[auxDonaciones->estado],auxDonaciones->valor,
            auxDonaciones->descripcion);
        }
    }
}