#include "donante.h"
#include "listaDonantes.h"
#include "validaciones.h"

int validarCedula(Donante *cabeza, int cedula);


//extern Donante *donanteHead;

//Esta funcion recibe la cabeza de la estructura de los donantes
//Pide al usuario los datos del donante y retorna un nodo de tipo Donante
Donante *registrarDonante(Donante *donanteHead) {
	int size_nombre = 30;
	int size_tlf = 15;
	int size_dir = 120;

	//creando un puntero a mi estructura y asignando memoria 
	Donante nuevoDonante;
	
	printf("Bienvenido nuevo donante!.\n");
    printf("Ingrese sus datos por favor!.\n");

	while(getchar() != '\n');

	printf("Ingrese su cedula: ");
	char cedulaStr[15]; 

	do{
	    fgets(cedulaStr, sizeof(cedulaStr), stdin);
		
	    cedulaStr[strcspn(cedulaStr, "\n")] = '\0'; // Elimina el carácter de nueva línea

	    if(!esNumerico(cedulaStr) || !noEsBlanco(cedulaStr)){
	        printf("Entrada invalida. Por favor, ingrese un numero entero: ");
	    }
		else{
	        nuevoDonante.cedula = atoi(cedulaStr); // Convierte la cadena a un entero
	        if(validarCedula(donanteHead, nuevoDonante.cedula) != 1) {
	            printf("Cedula ya registrada. Por favor, ingrese un numero entero: ");
	        }
	    }
		
	} while(!esNumerico(cedulaStr) || !noEsBlanco(cedulaStr) || (validarCedula(donanteHead, nuevoDonante.cedula) != 1));

	printf("Ingrese su nombre: ");
	nuevoDonante.nombre = asignarValor(size_nombre);
	
	
	printf("Ingrese su telefono celular:");
	do {
	    nuevoDonante.telefono = asignarValor(size_tlf);
	    if(!esNumerico(nuevoDonante.telefono)) {
	        printf("Entrada invalida. Por favor, ingrese un numero de telefono valido: ");
	    }
	} while(!esNumerico(nuevoDonante.telefono));
	

	printf("Ingrese su direcion: ");
	nuevoDonante.direccion = asignarValor(size_dir);


	printf("Donante registrado con exito!.");

	system("clear");//limpia la pantalla
	
	return crearNodoDonante(nuevoDonante);
}



//Esta funcnion valida si la cedula ya esta registada
//retorna 0 si esta en la lista
//retorna 1 si no se encuentra
int validarCedula(Donante *cabeza, int cedula){
	if (buscar_cedula(cabeza,cedula)== NULL){
		return 1;
	} 
	return 0;
}

