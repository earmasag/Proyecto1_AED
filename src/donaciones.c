#include "donaciones.h"


time_t ingresarFecha();



Donaciones* registrarDonacion() {
    int cedula_registrada,resultado=0;
    printf("Bienvenido donante!.\n");
    printf("Ingrese su cedula:");
    scanf("%d",&cedula_registrada);

    Donante *newDonante = buscar_cedula(donanteHead ,cedula_registrada);

    if (newDonante != NULL){
        Donaciones auxstruc;

        printf("Bienvenido\n");
        
        auxstruc.fecha = ingresarFecha();

        printf("Seleccione el tipo de donación");
        printf("(0). Monetaria \n (1)Material \n (2)Voluntariado");
        scanf("%hd",&auxstruc.tipo);
        while (auxstruc.tipo < MONETARIA || auxstruc.tipo > VOLUNTARIADO)
        {
            printf("Dato ingresado invalido\n Intente de nuevo...");
            scanf("%hd",&auxstruc.tipo);
        }

        if(auxstruc.tipo == 0){
            printf("Cuanto dinero esta donando?:  ");
            scanf("%f", &auxstruc.valor);
        }
        else if (auxstruc.tipo == 1)
        {
            char descripcion[100];
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
    printf("%li",fecha);
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
    donacionesp->tipo = nuevaDonacion.tipo;
    donacionesp->destino = nuevaDonacion.destino;
    donacionesp->estado = nuevaDonacion.estado;
    donacionesp->fecha = nuevaDonacion.fecha;
    donacionesp->valor = nuevaDonacion.valor;
    donacionesp->descripcion = (char*)malloc(sizeof(nuevaDonacion.descripcion));
    strcpy(donacionesp->descripcion,nuevaDonacion.descripcion);

    return donacionesp;

}