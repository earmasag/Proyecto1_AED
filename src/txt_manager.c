#include "txt_manager.h"

const char NOMBRE_ARCHIVO[] = "./txt/ARCHIVO.txt";

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
    auxStruc.direccion = (char*)malloc)(30);
    while (fgets(linea,sizeof(linea),archivo)){
        if(sscanf(linea,"%i;%s;%s,%s",&auxStruc.cedula,&auxStruc.nombre, &auxStruc.telefono, &auxStruc.direccion) != 4){
            printf("Error al leer la linea\n");
            
        }
    }
    
}

