#include "donaciones.h"
#include "listaDonaciones.h"
#include "txt_manager.h"

time_t ingresarFecha();


Donaciones* registrarDonacion(headDonacion *HEAD) {
    int cedula_registrada,resultado=0;
    printf("Bienvenido donante!.\n");
    printf("Ingrese su cedula:");
    scanf("%d",&cedula_registrada);

    Donante *donador = buscar_cedula(donanteHead ,cedula_registrada);

    if (donador != NULL){
        Donaciones auxstruc;
        auxstruc.cedula_donante = donador->cedula;
        printf("Bienvenido\n");
        
        auxstruc.fecha = ingresarFecha();

        printf("Seleccione el tipo de donación\n");
        printf("(1).Monetaria \n (2)Material \n (3)Voluntariado\n");
        scanf("%hd",&auxstruc.tipo);

        while (auxstruc.tipo < 1  || auxstruc.tipo > 3){
            printf("Dato ingresado invalido\n Intente de nuevo...");
            scanf("%hd",&auxstruc.tipo);
        }

        if(auxstruc.tipo == 1){
            printf("Cuanto dinero esta donando?:  ");
            scanf("%f", &auxstruc.valor);
            auxstruc.descripcion = (char*)malloc(sizeof(char));
            strcpy(auxstruc.descripcion," ");
        }
        else if (auxstruc.tipo == 2 || auxstruc.tipo == 3){
            char descripcion[100];
            while(getchar() != '\n');
            printf("Agregue una descripción");
            fgets(descripcion,100,stdin);
            auxstruc.descripcion = (char*)malloc(strlen(descripcion) + 1);
            if (auxstruc.descripcion == NULL) {
                printf("Error al asignar memoria.\n");
                return NULL;
            }
            strcpy(auxstruc.descripcion,descripcion);

        }
        auxstruc.next = NULL;
        auxstruc.estado = 1;      
        auxstruc.num_donacion = numeroDonacion();
        

        return crearNodoDonacion(auxstruc);

    }
    else{
        printf("Lo siento mucho usted no puede donar..., por favor registrese antes de donar.\n");
        
        while(getchar() != '\n');
        getchar();
        system("clear");
        
    }

}


time_t ingresarFecha(){

    while ((getchar() != '\n'));
    char fecha_str[50]; // Suponemos que la fecha no será más larga que 50 caracteres
    struct tm fecha_tm = {0};
    time_t fecha;
    int dia,mes,ano;
    do
    {
    // Leer la fecha como una cadena de texto
    printf("Ingrese la fecha (formato DD/MM/AAAA): ");
    fgets(fecha_str, sizeof(fecha_str), stdin);

    // Eliminar el carácter de nueva línea final de la cadena
    fecha_str[strcspn(fecha_str, "\n")] = '\0';
    //printf("%s",fecha_str);

    // Convertir la cadena de texto a una estructura tm
    if (sscanf(fecha_str, "%d/%d/%d", &dia, &mes, &ano) != 3) {
        printf("Formato de fecha incorrecto\n");   
    }
    fecha_tm.tm_mday = dia;
    fecha_tm.tm_mon = mes-1;
    fecha_tm.tm_year = ano - 1900;

    // Convertir la estructura tm a time_t
    fecha = mktime(&fecha_tm);
    //printf("%li",fecha);
    // Verificar si la conversión fue exitosa
    if (fecha == -1) {
        printf("Fecha fuera de rango\n");
    }

    } while ((fecha == -1) || sscanf(fecha_str, "%d/%d/%d", &dia, &mes, &ano) != 3);
    
    return fecha;

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


headDonacion *adminitrarDonaciones(headDonacion *HEAD){
    int num_donacion;
    Donaciones *edit_donacion;
    int salida = 1;
    char destinos[][20] = {"Alimento", "Medicinas", "Mantenimiento", "Reparaciones", "Otras"};
    do
    {
        printf("Por favor,\nIngrese el numero de donación que desea editar: ");
        scanf("%i",&num_donacion);

        edit_donacion = buscarDonacion(HEAD, num_donacion);

        if(edit_donacion == NULL){
            printf("No se encontro el numero numero de doncacion ingreado\n");
            printf("Desea intentar de nuevo?  (1)SI (0)NO\n");
            scanf("%i",&salida);
            if (salida == 0) return HEAD;
        }
        
    } while (edit_donacion == NULL);

    printf("A que esta destinada la donacion?\n");
    for(int i = 0; i < 5;i++){
        printf("(%i) %s\n",i+1,destinos[i]);
    }
    scanf("%hu", &edit_donacion->destino);
    edit_donacion->estado = 0;
    imprimirDonaciones(HEAD);
    getchar();
    return HEAD;    
}