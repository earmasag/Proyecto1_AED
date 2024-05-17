#include "txt_manager.h"


const char NOMBRE_ARCHIVO[] = "./txt/ARCHIVO.txt";
//extern Donante *donanteHead;

Donante *cargarListaDonantes(Donante *HEAD){
    FILE *archivo;
    char linea[100];
    if((archivo = fopen(NOMBRE_ARCHIVO,"r")) == NULL){
        printf("Error al abrir el archivo\n");
        return NULL;
    }
    Donante auxStruc;
    auxStruc.nombre = (char*)malloc(20);
    auxStruc.telefono = (char*)malloc(15);
    auxStruc.direccion = (char*)malloc(30);
    fgets(linea,sizeof(linea),archivo);
    while (strcmp(fgets(linea,sizeof(linea),archivo),"\n") != 0){
        linea[strcspn(linea,"\n")] = '\0';

        if(sscanf(linea,"%i;%50[^;];%50[^;];%50[^;]",&auxStruc.cedula, auxStruc.nombre, auxStruc.telefono, auxStruc.direccion) != 4){
            printf("Error al leer la linea: ");
            printf("%s-----\n",linea);
            
        }else{
            HEAD = agregarDonante(HEAD,crearNodoDonante(auxStruc));
            printf("%i, %s, %s, %s...\n",auxStruc.cedula, auxStruc.nombre, auxStruc.telefono, auxStruc.direccion);
        }

    }
    free(auxStruc.direccion);
    free(auxStruc.nombre);
    free(auxStruc.telefono);
    return HEAD;
    
}

