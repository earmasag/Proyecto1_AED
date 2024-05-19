#include "txt_manager.h"
#include "donaciones.h"
#include "listaDonantes.h"
//#include "donante.h"

void salir();

Donante *donanteHead = NULL;
headDonacion *donacionHead = NULL;

int main() {
    int opcion;
    donanteHead = cargarListaDonantes(donanteHead);
    donacionHead = cargarListaDonaciones(donacionHead);

    do {
    	printf("----------BIENVENIDO--AL-SISTEMA-DE-GESTION-DE-DONACIONES---------- \n");//case para las opciones de registro de donantes y donaciones
        printf("[1]. Registrar donante \n");
        printf("[2]. Registrar donacion \n");
        printf("[3]. Salir\n");
        printf("Elige una opcion: \n");
        printf("------------------------------------------------------------------ \n");
        scanf("%d", &opcion);
		system("clear");//comando de la libria de stdlib para limpiar la pantalla
        switch(opcion) {
            case 1:
                registrarDonante(donanteHead);
                
                break;
            case 2:
                registrarDonacion();
                break;
            case 3:
                salir();
                break;
            default:
                printf("Opcion no valida. Por favor, elige una opcion del 1 al 3.\n");//si la opcion no es valida suelta este mensaje
                break;
        }
    } while(opcion != 3);//ciclo para mantener el sistema

    return 0;
}

void salir() {
    printf("Saliendo del sistema.\n");
}
