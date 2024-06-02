//Archivo principal del programa

#include "txt_manager.h"
#include "donaciones.h"
#include "listaDonantes.h"
#include "donante.h"
#include "informes.h"
#include "validaciones.h"


void salir();



//menu de inicio del programa
int main(){
    //Cabeza de las estructuras
    Donante *donanteHead = NULL;
    headDonacion *donacionHead;
    int opcion;
    crearArchivo();
    donacionHead = crearHEADdonaciones();
    donanteHead = cargarListaDonantes(donanteHead);
    donacionHead = cargarListaDonaciones(donacionHead);
    
    do {   
        system("clear");
        printf("----------BIENVENIDO--AL-SISTEMA-DE-GESTION-DE-DONACIONES---------- \n");
        printf("[1]. Registrar donante \n");
        printf("[2]. Registrar donacion \n");
        printf("[3]. Administrar Donaciones \n");
        printf("[4]. Imprimir Informes \n");
        printf("[5]. Salir\n");
        printf("Elige una opcion: \n");
        printf("------------------------------------------------------------------ \n");
            
        opcion = validarNumero(2);
        switch(opcion){
            case 1:
                donanteHead = agregarDonante(donanteHead,registrarDonante(donanteHead));
                actualizarArchivo(donacionHead,donanteHead);
                break;
            case 2:
                donacionHead = agregarDonacion(donacionHead,registrarDonacion(donacionHead,donanteHead));
                actualizarArchivo(donacionHead,donanteHead);
                break;
            case 3:
                donacionHead = adminitrarDonaciones(donacionHead);
                actualizarArchivo(donacionHead,donanteHead);
                break;
            case 4:
                crearInformes(donacionHead,donanteHead);
                break;            
            case 5:
                salir();
                break;
            default:
                printf("Opcion no valida. Por favor, elige una opcion del 1 al 5.\n");//si la opcion no es valida suelta este mensaje
                getchar();
                break;
        }
    } while(opcion != 5);//ciclo para mantener el sistema

    return 0;
}


//Funcion de salida
void salir() {
    system("clear");
    printf("Saliendo del sistema.\n");
}
