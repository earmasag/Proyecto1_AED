//Este archivo contiene todas las funciones que manejan el archivo TXT
#include "txt_manager.h"

//Variable global 
const char NOMBRE_ARCHIVO[] = "./txt/ARCHIVO.txt";

//Esta funcion verifica si el archivo esta creado
//Si no lo esta lo crea y lo inicia
void crearArchivo(){
    FILE *archivo;
    if ((archivo = fopen(NOMBRE_ARCHIVO,"r")) == NULL){
        if ((archivo = fopen(NOMBRE_ARCHIVO,"w")) == NULL){
            printf("Error al crear archivo\n");
            return;
        }
        else{
            char donantes[] = "DONANTES";
            char donacion[] = "DONACIONES";
            fprintf(archivo,"%s\n\n%s\n",donantes,donacion);
            fclose(archivo);
            return;
        }        
        
    }
    
}

//Esta funcion carga todos los datos de los donates en la lista de donantes
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

        if(sscanf(linea,"%i;%50[^;];%50[^;];%50[^;]",&auxStruc.cedula, auxStruc.nombre, auxStruc.telefono, auxStruc.direccion) == 4){
            HEAD = agregarDonante(HEAD,crearNodoDonante(auxStruc));
        }
    }
    free(auxStruc.direccion);
    free(auxStruc.nombre);
    free(auxStruc.telefono);
    fclose(archivo);
    return HEAD;
    
}

//Esta funcion carga todos los datos de las donaciones en la cola de donaciones
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

    auxStruct.descripcion = (char*)malloc(120);

    while (fgets(linea,sizeof(linea),archivo)){
        
        linea[strcspn(linea,"\n")] = '\0';

        if(sscanf(linea,"%i;%i;%ld;%hu;%hu;%hu;%f;%50[^0]",&auxStruct.num_donacion,&auxStruct.cedula_donante,&auxStruct.fecha,
            &auxStruct.tipo,&auxStruct.estado,&auxStruct.destino,&auxStruct.valor,auxStruct.descripcion) != 8){
        }else{
            HEAD = agregarDonacion(HEAD,crearNodoDonacion(auxStruct));
        }
    }
    fclose(archivo);
    return HEAD;

}

//Esta funcion sobre escribe el archivo con la nueva informacion añadida a las listas
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
        fprintf(archivo,"%i;%i;%ld;%hu;%hu;%hu;%f;%s\n",auxDonaciones->num_donacion, auxDonaciones->cedula_donante,
    auxDonaciones->fecha,auxDonaciones->tipo,auxDonaciones->estado,auxDonaciones->destino,auxDonaciones->valor,auxDonaciones->descripcion);
    }
    fclose(archivo);
    return 1;

}