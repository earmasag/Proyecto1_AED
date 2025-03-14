#include "donaciones.h"
#include "listaDonaciones.h"
#include "txt_manager.h"

time_t ingresarFecha();

//  Recibe por parametro un puntero a la estructura de donaciones
//  Pide los datos al usuario para registrar las donación
Donaciones* registrarDonacion(headDonacion *HEAD,Donante *donanteHead) {

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
                printf("Dato ingresado invalido\n Intente de nuevo... ");   
        }while (auxstruc.tipo < 0  || auxstruc.tipo > 2);

        if(auxstruc.tipo == 0){
            vaciarBuffer();
            printf("Cuanto dinero esta donando?: \n");
            auxstruc.valor = validarNumero(10);    
            auxstruc.descripcion = asignarValor(2);
            strcpy(auxstruc.descripcion," ");

        }
        else if (auxstruc.tipo == 1){
            char descripcion[100];
            vaciarBuffer();
            printf("Que material esta donando?\n");

            auxstruc.descripcion = asignarValor(strlen(descripcion));
            strcpy(auxstruc.descripcion,descripcion);

            printf("Que cantidad?\n");
            auxstruc.valor = validarNumero(10);
        }
        else{
            char descripcion[100];
            vaciarBuffer();
            printf("En que puede ayudar?\n");

            fgets(descripcion,100,stdin);
            auxstruc.descripcion = asignarValor(strlen(descripcion));
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
        return NULL;
    }

}

//Funcion para uso de la libreria
//Pide una cadana de texto en formato DD/MM/AAAA
//y retorno un dato tipo time_t correspondiente a la fecha
time_t ingresarFecha(){

    char fecha_str[50]; // Suponemos que la fecha no será más larga que 50 caracteres
    struct tm fecha_tm = {0};
    time_t fecha;
    int dia,mes,ano;

    do{
        do{
            // Leer la fecha como una cadena de texto
            printf("Ingrese la fecha (formato DD/MM/AAAA): ");
            fgets(fecha_str, sizeof(fecha_str), stdin);

            // Eliminar el carácter de nueva línea final de la cadena
            fecha_str[strcspn(fecha_str, "\n")] = '\0';

            // Convertir la cadena de texto a una estructura tm
            if (sscanf(fecha_str, "%d/%d/%d", &dia, &mes, &ano) != 3) {
                printf("Formato de fecha incorrecto\n");   
            }
            if(dia < 0 || dia > 31 || mes < 0 || mes > 12)
                printf("Formato de fecha incorrecto\n"); 
        }while(dia < 0 || dia > 31 || mes < 0 || mes > 12);
        


        fecha_tm.tm_mday = dia;
        fecha_tm.tm_mon = mes-1;
        fecha_tm.tm_year = ano - 1900;

        // Convertir la estructura tm a time_t
        fecha = mktime(&fecha_tm);

        // Verificar si la conversión fue exitosa
        if (fecha == -1) {
            printf("Fecha fuera de rango\n");
        }

    }while ((fecha == -1) || sscanf(fecha_str, "%d/%d/%d", &dia, &mes, &ano) != 3);
    
    return fecha;

}

//Esta funcion recibe la cabeza de la estructura de donaciones
//Pide al usuario que introduzca el numero de la donación que esta desea 
//destinar y destinarla y retorna la cabeza de la estructura
headDonacion *adminitrarDonaciones(headDonacion *HEAD){
    int num_donacion;
    Donaciones *edit_donacion, *aux;
    int salida = 1;
    extern char destinos[][20];
    extern char tipo_donacion[][15];
    extern char estados[][20];
    char strFecha[20];
    struct tm *fecha;
    do
    {
        vaciarBuffer();
        printf("Numero de donaciones disponibles \n");

        if(!donacionesDisponibles(HEAD)){
            system("clear");
            printf("No hay donaciones disponibles\n\n");
            getchar();
            return HEAD;
        }

        printf("Por favor,\nIngrese el numero de donación que desea editar: ");
        

        num_donacion = validarNumero(15);
        edit_donacion = buscarDonacion(HEAD, num_donacion);
        
        

        if(edit_donacion == NULL){
            printf("\nNo se encontro el numero numero de doncacion ingreado\n");
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

	system("clear");
    fecha = localtime(&edit_donacion->fecha);
    strftime(strFecha,sizeof(strFecha),"%d/%m/%Y",fecha);
    printf("                       ----------DONACION SELECCIONADA----------\n\n");
    printf(" N° DONACION |    CEDULA    |    FECHA   |     TIPO      ");
    printf("|   DESTINO   |    ESTADO    |VALOR/CANTIDAD|     DESCRIPCION    |\n");
    printf("    %-9i|%-14i|%-12s|%-15s|%-13s|%-14s|%-14.2f|%-20s|\n", edit_donacion->num_donacion, 
        edit_donacion->cedula_donante, strFecha, tipo_donacion[edit_donacion->tipo],destinos[edit_donacion->destino],
        estados[edit_donacion->estado],edit_donacion->valor,edit_donacion->descripcion);

    printf("\nA que esta destinada la donacion?\n");
    for(int i = 1; i < 6;i++){
        printf("(%i) %s\n",i,destinos[i]);
    }
    do{
        edit_donacion->destino = validarNumero(2);
        if(edit_donacion->destino < 1 || edit_donacion->destino > 6)
            printf("DATO FUERA DE RANGO. Intente de nuevo");
    }while(edit_donacion->destino < 1 || edit_donacion->destino > 6);
    edit_donacion->estado = 0;
    vaciarBuffer();
    return HEAD;    
}