#include "donaciones.h"
#include "listaDonaciones.h"
#include "txt_manager.h"

time_t ingresarFecha();

/*
    Recibe por parametro un puntero a la estructura de donaciones
    Pide los datos al usuario para registrar las donación
*/
Donaciones* registrarDonacion(headDonacion *HEAD) {

    int cedula;
    vaciarBuffer();
    printf("Bienvenido donante!.\n");
    printf("Ingrese su cedula:");
    cedula = validarNumero(20);

    Donante *donador = buscar_cedula(donanteHead ,cedula);

    if (donador != NULL){
        Donaciones auxstruc;
        auxstruc.cedula_donante = donador->cedula;

        printf("Bienvenido\n");
        
        auxstruc.fecha = ingresarFecha();
        do{
            printf("Seleccione el tipo de donación\n");
            printf("(0).Monetaria \n(1).Material \n(2).Voluntariado\n");
            auxstruc.tipo = validarNumero(2);
            if(auxstruc.tipo < 0  || auxstruc.tipo > 2)
                printf("Dato ingresado invalido\n Intente de nuevo...");   
        }while (auxstruc.tipo < 0  || auxstruc.tipo > 2);

        if(auxstruc.tipo == 0){
            vaciarBuffer();
            printf("Cuanto dinero esta donando?:  ");
            auxstruc.valor = validarNumero(10);    
            auxstruc.descripcion = (char*)malloc(sizeof(char));
            strcpy(auxstruc.descripcion," ");

        }
        else if (auxstruc.tipo == 1){
            char descripcion[100];
            vaciarBuffer();
            printf("Que material esta donando?");

            fgets(descripcion,100,stdin);
            auxstruc.descripcion = (char*)malloc(strlen(descripcion) + 1);
            if (auxstruc.descripcion == NULL) {
                printf("Error al asignar memoria.\n");
                return NULL;
            }
            strcpy(auxstruc.descripcion,descripcion);

            printf("Que cantidad?");
            auxstruc.valor = validarNumero(10);
        }
        else{
            char descripcion[100];
            vaciarBuffer();
            printf("EN que puede ayudar?");

            fgets(descripcion,100,stdin);
            auxstruc.descripcion = (char*)malloc(strlen(descripcion)*sizeof(char));
            if (auxstruc.descripcion == NULL) {
                printf("Error al asignar memoria.\n");
                return NULL;
            }
            strcpy(auxstruc.descripcion,descripcion);
            auxstruc.valor = 0;

        }
        auxstruc.next = NULL;
        auxstruc.estado = 1;      
        auxstruc.num_donacion = numeroDonacion(HEAD);
        auxstruc.destino = 0;
        return crearNodoDonacion(auxstruc);

    }
    else{
        printf("Lo siento mucho usted no puede donar..., por favor registrese antes de donar.\n");
        getchar();
        system("clear");
        
    }

}


time_t ingresarFecha(){

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


headDonacion *adminitrarDonaciones(headDonacion *HEAD){
    int num_donacion;
    Donaciones *edit_donacion;
    int salida = 1;
    extern char destinos[][20];
    extern char tipo_donacion[][15];
    extern char estados[][20];
    char strFecha[20];
    struct tm *fecha;
    do
    {
        vaciarBuffer();
        printf("Por favor,\nIngrese el numero de donación que desea editar: ");
        num_donacion = validarNumero(15);
        edit_donacion = buscarDonacion(HEAD, num_donacion);

        if(edit_donacion == NULL){
            printf("No se encontro el numero numero de doncacion ingreado\n");
            printf("Desea intentar de nuevo?  (1)SI (0)NO\n");
            do{
                salida = validarNumero(2);
                if(salida != 0 && salida != 1)
                    printf("DATO INVALIDO. Intente de nuevo ");
                
            }while(salida != 0 && salida != 1);
            if(salida == 0) return HEAD;
        }
        else if(edit_donacion->estado == 0){
            printf("La donación escogida no esta disponible, ya ha sido asignada\n");
            printf("Desea intentar de nuevo?  (1)SI (0)NO\n");
            do{
                salida = validarNumero(2);
                if(salida != 0 && salida != 1)
                    printf("DATO INVALIDO. Intente de nuevo ");
            }while(salida != 0 && salida != 1);
            if(salida == 0) return HEAD;
        }
        
    } while (edit_donacion == NULL || edit_donacion->estado == 0);

	
    fecha = localtime(&edit_donacion->fecha);
    strftime(strFecha,sizeof(strFecha),"%d/%m/%Y",fecha);
    printf("----------DONACION SELECCIONADA----------\n");
    printf("N° DONACION    CEDULA   NOMBRE  FECHA TIPO  DESTINO   ESTADO   VALOR/CANTIDAD  DESCRIPCION\n");
    printf("%i  %i  %s  %s  %s  %s   %f  %s \n", edit_donacion->num_donacion, edit_donacion->cedula_donante, 
        strFecha, tipo_donacion[edit_donacion->tipo],destinos[edit_donacion->destino], estados[edit_donacion->estado],edit_donacion->valor,
        edit_donacion->descripcion);

    printf("A que esta destinada la donacion?\n");
    for(int i = 1; i < 6;i++){
        printf("(%i) %s\n",i,destinos[i]);
    }
    do{
        edit_donacion->destino = validarNumero(2);
        if(edit_donacion->destino < 1 || edit_donacion->destino > 6)
            printf("DATO INVALIDO. Intente de nuevo");
    }while(edit_donacion->destino < 1 || edit_donacion->destino > 6);
    edit_donacion->estado = 0;
    return HEAD;    
}