#include "txt_manager.h"
#include "donaciones.h"
#include "listaDonantes.h"
#include "donante.h"

void salir();

Donante *donanteHead = NULL;
headDonacion *donacionHead;

int main() {
    int opcion;
    donacionHead = crearHEADdonaciones();
    donanteHead = cargarListaDonantes(donanteHead);
    donacionHead = cargarListaDonaciones(donacionHead);

    imprimirDonaciones(donacionHead);
    imprimirDonantes(donanteHead);    

    do {
    	printf("----------BIENVENIDO--AL-SISTEMA-DE-GESTION-DE-DONACIONES---------- \n");//case para las opciones de registro de donantes y donaciones
        printf("[1]. Registrar donante \n");
        printf("[2]. Registrar donacion \n");
        printf("[3]. Administrar Donaciones \n");
        printf("[4]. Salir\n");
        printf("Elige una opcion: \n");
        printf("------------------------------------------------------------------ \n");
        scanf("%d", &opcion);
		system("clear");//comando de la libria de stdlib para limpiar la pantalla
        switch(opcion) {
            case 1:
                donanteHead = (donanteHead,registrarDonante());
                
                break;
            case 2:
                registrarDonacion(donacionHead);
                break;
            case 3:
                adminitrarDonaciones(donacionHead);
                break;
            case 4:
                salir();
                break;
            default:
                printf("Opcion no valida. Por favor, elige una opcion del 1 al 3.\n");//si la opcion no es valida suelta este mensaje
                break;
        }
    } while(opcion != 4);//ciclo para mantener el sistema

    return 0;
}

void salir() {
    printf("Saliendo del sistema.\n");
}

