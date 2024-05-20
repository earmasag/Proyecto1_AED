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
    fclose(archivo);
    return HEAD;
    
}

headDonacion *cargarListaDonaciones(headDonacion *HEAD){
    char linea[120];

    FILE *archivo;

    if((archivo = fopen(NOMBRE_ARCHIVO,"r")) == NULL){
        printf("Error al abrir el archivo\n");
        return NULL;
    }


    Donaciones auxStruct;
    
    while (strcmp(linea,"DONACIONES\n"))
        fgets(linea,sizeof(linea),archivo);

    printf("Linea::  %s",linea);

    auxStruct.descripcion = (char*)malloc(120);

    while (fgets(linea,sizeof(linea),archivo)){
        printf("Linea::  %s",linea);
        linea[strcspn(linea,"\n")] = '\0';

        if(sscanf(linea,"%i;%i;%li;%hu;%hu;%hu;%f;%50[^0]",&auxStruct.num_donacion,&auxStruct.cedula_donante,&auxStruct.fecha,
            &auxStruct.tipo,&auxStruct.estado,&auxStruct.destino,&auxStruct.valor,auxStruct.descripcion) != 8){
            printf("Error al leer la linea: ");
            printf("%s-----\n",linea);
        }else{
            HEAD = agregarDonacion(HEAD,crearNodoDonacion(auxStruct));
        }
    }
    return HEAD;

}

int numeroDonacion(){
    FILE *archivo;
    if((archivo = fopen(NOMBRE_ARCHIVO,"r")) == NULL){
        printf("Error al abrir el archivo");
        return -1;
    }
    char ultimaLinea[200], linea[200];
    int numero;
    while(fgets(linea,sizeof(linea),archivo)){
        strcpy(ultimaLinea,linea);
    }
    sscanf(ultimaLinea,"%i;",&numero);
    return numero + 1;

}

int guadarDonacion(Donaciones nuevaDonacion){
    FILE *archivo;
    if((archivo = fopen(NOMBRE_ARCHIVO,"a")) == NULL){
        printf("Error al abri el archivo\n");
        return -1;
    }
    fseek(archivo,0,SEEK_END);
    fprintf(archivo,"%i;%i;%li;%hu;%hu;%hu;%f;%s\n",nuevaDonacion.num_donacion,nuevaDonacion.cedula_donante,
    nuevaDonacion.fecha,nuevaDonacion.tipo,nuevaDonacion.estado,nuevaDonacion.destino,nuevaDonacion.valor,nuevaDonacion.descripcion);
    fclose(archivo);
    return 1;
}

int actualizarArchivo(headDonacion *headDonacion, Donante *headDonante){
    FILE *archivo;
    if((archivo = fopen(NOMBRE_ARCHIVO,"w")) == NULL){
        printf("Error al abrir el archivo\n");
        return -1;
    }
    Donante *auxDonante;
    fprintf(archivo,"DONANTES\n");
    for(auxDonante = headDonante; auxDonante; auxDonante = auxDonante->next){
        fprintf(archivo,"%i;%s;%s;%s\n",auxDonante->cedula,auxDonante->nombre,auxDonante->telefono,auxDonante->direccion);
    }
    fprintf(archivo,"\nDONACIONES\n");
    Donaciones *auxDonaciones;
    for(auxDonaciones = headDonacion->ini; auxDonaciones; auxDonaciones = auxDonaciones->next){
        fprintf(archivo,"%i;%i;%li;%hu;%hu;%hu;%f;%s\n",auxDonaciones->num_donacion, auxDonaciones->cedula_donante,
    auxDonaciones->fecha,auxDonaciones->tipo,auxDonaciones->estado,auxDonaciones->destino,auxDonaciones->valor,auxDonaciones->descripcion);
    }
    fclose(archivo);
    return 1;

}