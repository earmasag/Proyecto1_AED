//Este archivo contiene todas las funciones que imprimen lso reportes por pantalla
#include "informes.h"

void informeDestinos(headDonacion *HEAD);
void informeMateriales(headDonacion *HEAD);
void detalleDonaciones(headDonacion *headDonaciones, Donante *headDonante);
void informePorDonantes(headDonacion *headDonacion, Donante *headDonante);

char destinos[][20] = {"No destinado","Alimento", "Medicinas", "Mantenimiento", "Reparaciones", "Otras"};
char tipo_donacion[][15] = {"Monetaria", "Materiales", "Voluntariado"};
char estados[][20] = {"No Disponible", "Disponible"};

//Funcion que pide al usuario que elija el infome que quiere
void crearInformes(headDonacion *headDonacion, Donante *headDonante){
    system("clear");
    int op;
    do{
        vaciarBuffer();
        printf("Que infomre desea imprimir?\n");
        printf("(1)Destinos de donaciones.\n");
        printf("(2)Materiales donados.\n");
        printf("(3)Todas las donaciones.\n");
        printf("(4)Donaciones por Donante\n");
        op = validarNumero(3);
        switch (op){
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
            printf("Opcion no valida. Por favor, elige una opcion del 1 al 4.\n");//si la opcion no es valida suelta este mensaje
            getchar();
            break;
        }
        getchar();
        getchar();
    }while(op < 1 || op > 4);
}

//Este informe imprime el destino de las donaciones
//Monetarias y Materiales
void informeDestinos(headDonacion *HEAD){
    if(!HEAD) return;
    system("clear");
    Donaciones *aux;
    printf("------INFORME: DESTINO DE DONACIONES MATERIALES Y MONETARIAS---------\n\n");
    printf("N° DONACION |  TIPO DE DONACION |  DESTINO\n");
    for(aux = HEAD->ini; aux; aux = aux->next){
        if(aux->tipo < 2)
        printf("      %-5i |  %-15s  |  %-15s\n", aux->num_donacion, tipo_donacion[aux->tipo], destinos[aux->destino]);        
    }
}

//Listado de artículos donados, cantidad, fecha de recepción.
void informeMateriales(headDonacion *HEAD){
    if(!HEAD) return;
    system("clear");
    Donaciones *aux;
    printf("-------------INFORME: ARTICULOS DONADOS -----------\n\n");
    printf("N°DONACION |   FECHA    |    ARTICULO                  | CANTIDAD|\n");

    for(aux = HEAD->ini; aux; aux = aux->next){
        if(aux->tipo == 1){
            
            char strFecha[20];
            struct tm *fecha;
            fecha = localtime(&aux->fecha);
            strftime(strFecha,sizeof(strFecha),"%d/%m/%Y",fecha);
            printf("      %-5i|%-12s|%-30s|%-9.2f|\n",aux->num_donacion, strFecha, aux->descripcion, aux->valor);
                       
        }
    }

}

//Listado de todas las donaciones
void detalleDonaciones(headDonacion *headDonaciones, Donante *headDonante){
    if(!headDonaciones || !headDonante) return;
    system("clear");
    Donaciones *auxDonaciones;
    Donante *auxDonante;
    char strFecha[20];
    struct tm *fecha;
    printf("-----------------INFORME: TODAS LAS DONACIONES--------------\n\n");       
    printf(" N° DONACION |  CEDULA  |     NOMBRE     |    FECHA   |     TIPO      ");
    printf("|   DESTINO   |    ESTADO    |VALOR/CANTIDAD|     DESCRIPCION    |\n");
    for(auxDonaciones = headDonaciones->ini; auxDonaciones; auxDonaciones = auxDonaciones->next){

        fecha = localtime(&auxDonaciones->fecha);
        strftime(strFecha,sizeof(strFecha),"%d/%m/%Y",fecha);

        auxDonante = buscar_cedula(headDonante,auxDonaciones->cedula_donante);

        printf("    %-9i|%-10i|%-16s|%-12s|%-15s|%-13s|%-14s|%-14.2f|%-20s|\n", auxDonaciones->num_donacion, 
        auxDonante->cedula, auxDonante->nombre, strFecha, tipo_donacion[auxDonaciones->tipo],
        destinos[auxDonaciones->destino], estados[auxDonaciones->estado],auxDonaciones->valor,
        auxDonaciones->descripcion);
    }

}


//Listado que imprime todas las donaciones del donante que
//ingrese el usuario
void informePorDonantes(headDonacion *headDonacion, Donante *headDonante){
    int cedula;
    Donante *auxDonante;
    Donaciones *auxDonaciones;
    char strFecha[20];
    struct tm *fecha;
    system("clear");
    printf("Escriba la cedula del donante a buscar: ");
    cedula = validarNumero(15);
    system("clear");
    if((auxDonante = buscar_cedula(headDonante,cedula)) == NULL){
        printf("Donante no encontrado o Donante no posee donaciones\n");
        return;
    }
    printf("-------------INFORME: DONACIONES POR DONANTES-----------\n\n");
    printf(" N° DONACION |    CEDULA    |         NOMBRE        |    FECHA   |     TIPO      ");
    printf("|   DESTINO   |    ESTADO    |VALOR/CANTIDAD|     DESCRIPCION    |\n");
    for(auxDonaciones = headDonacion->ini; auxDonaciones; auxDonaciones = auxDonaciones->next){
        if(auxDonaciones->cedula_donante == cedula){
            fecha = localtime(&auxDonaciones->fecha);
            strftime(strFecha,sizeof(strFecha),"%d/%m/%Y",fecha);
            printf("    %-9i|%-14i|%-23s|%-12s|%-15s|%-13s|%-14s|%-14.2f|%-20s|\n", auxDonaciones->num_donacion, auxDonante->cedula, auxDonante->nombre,
            strFecha, tipo_donacion[auxDonaciones->tipo],destinos[auxDonaciones->destino], estados[auxDonaciones->estado],auxDonaciones->valor,
            auxDonaciones->descripcion);
        }
    }
}