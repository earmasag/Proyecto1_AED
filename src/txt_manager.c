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
    fclose(archivo);
    return HEAD;
    
}

Donaciones *cargarListaDonaciones(Donaciones *HEAD){
    printf("cargando arhcivo...\n");
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

        if(sscanf(linea,"%i;%li;%hu;%hu;%hu;%f;%50[^0]",&auxStruct.num_donacion,&auxStruct.fecha,
            &auxStruct.tipo,&auxStruct.estado,&auxStruct.destino,&auxStruct.valor,auxStruct.descripcion) != 7){
            printf("Error al leer la linea: ");
            printf("%s-----\n",linea);
        
        }else{
            //HEAD = agregarDonante(HEAD,crearNodoDonacion(auxStruct));
            printf("%d;%li;%i;%i;%i;%f;%s...\n",auxStruct.num_donacion,auxStruct.fecha,
            auxStruct.tipo,auxStruct.estado,auxStruct.destino,auxStruct.valor,auxStruct.descripcion);
        }
    }
    return HEAD;

}

void agregar_donantes_y_donaciones(Donaciones *donaciones, Donante *donantes, char *nombre_archivo) {
    // Leer todo el archivo en la memoria
    FILE *archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s\n", nombre_archivo);
        return;
    }
    fseek(archivo, 0, SEEK_END);
    long size = ftell(archivo);
    char *contenido = malloc(size + 1);
    rewind(archivo);
    fread(contenido, 1, size, archivo);
    contenido[size] = '\0';
    fclose(archivo);

    // Separar el contenido en las secciones DONANTES y DONACIONES
    char *seccion_donantes = strtok(contenido, "\nDONACIONES\n");
    char *seccion_donaciones = strtok(NULL, "");

    // Agregar los nuevos donantes y donaciones
    Donante *donante_actual = donantes;
    while (donante_actual != NULL) {
        char donante[100];
        sprintf(donante, "%d;%s;%s;%s\n", donante_actual->cedula, donante_actual->nombre, donante_actual->telefono, donante_actual->direccion);
        strcat(seccion_donantes, donante);
        donante_actual = donante_actual->next;
    }

    Donaciones *donacion_actual = donaciones;
    while (donacion_actual != NULL) {
        char fecha[20];
        strftime(fecha, 20, "%Y-%m-%d %H:%M:%S", localtime(&(donacion_actual->fecha)));
        char donacion[100];
        sprintf(donacion, "%d;%s;%hu;%hu;%hu;%.2f;%s\n", donacion_actual->num_donacion, fecha, donacion_actual->tipo, donacion_actual->destino, donacion_actual->estado, donacion_actual->valor, donacion_actual->descripcion);
        strcat(seccion_donaciones, donacion);
        donacion_actual = donacion_actual->next;
    }

    // Reescribir el archivo con los nuevos datos
    archivo = fopen(nombre_archivo, "w");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s\n", nombre_archivo);
        free(contenido);
        return;
    }
    fprintf(archivo, "%s\nDONACIONES\n%s", seccion_donantes, seccion_donaciones);
    fclose(archivo);

    free(contenido);
}
