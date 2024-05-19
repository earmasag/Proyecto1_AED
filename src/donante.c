#include "donante.h"
#include "listaDonantes.h"
#include "validaciones.h"

int validarCedula(Donante *cabeza, int cedula);
char *asignarValor(int max_char);


extern Donante *donanteHead;

Donante *registrarDonante() {
	int size_nombre = 30;
	int size_tlf = 15;
	int size_dir = 120;

	//creando un puntero a mi estructura y asignando memoria 
	Donante nuevoDonante;

	printf("Bienvenido nuevo donante!.\n");
    printf("Ingrese sus datos por favor!.\n");

	while(getchar() != '\n');

	printf("Ingrese su cedula: ");
	char cedulaStr[12]; // Asumiendo que la cédula no tiene más de 10 dígitos, más el carácter de nueva línea y el carácter nulo
	do {
	    fgets(cedulaStr, sizeof(cedulaStr), stdin);
	    cedulaStr[strcspn(cedulaStr, "\n")] = 0; // Elimina el carácter de nueva línea
	    if(!esNumerico(cedulaStr) || !noEsBlanco(cedulaStr)){
	        printf("Entrada invalida. Por favor, ingrese un numero entero: ");
	    }else{
	        nuevoDonante.cedula = atoi(cedulaStr); // Convierte la cadena a un entero
	        if(validarCedula(donanteHead, nuevoDonante.cedula) != 1) {
	            printf("Cedula ya registrada. Por favor, ingrese un numero entero: ");
	        }
	    }
		while(getchar() != '\n');
	} while(!esNumerico(cedulaStr) || !noEsBlanco(cedulaStr) || validarCedula(donanteHead, nuevoDonante.cedula) != 1);


	while ((getchar() != '\n'));

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

char *asignarValor(int max_char){
	char *asignar;
	char valor[max_char];
	fflush(stdin);
	fgets(valor,max_char,stdin);
	valor[strcspn(valor, "\n")] = 0; // Esta línea elimina el carácter de nueva línea
	asignar = (char*)malloc(strlen(valor) + 1);
	if (asignar == NULL) {
        printf("Error al asignar memoria.\n");
        return NULL;
    }
	strcpy(asignar,valor);
	return asignar;
}

int validarCedula(Donante *cabeza, int cedula){
	if (buscar_cedula(cabeza,cedula)== NULL){
		return 1;
	} 
	return 0;
}

Donante *crearNodoDonante(Donante nuevoDonante){
	Donante *donantep = (Donante*) malloc(sizeof(Donante));
	if (donantep == NULL) {
        printf("Error al asignar memoria.\n");
        return NULL;
    }
	donantep->cedula = nuevoDonante.cedula;
	donantep->nombre = (char*)malloc(sizeof(nuevoDonante.nombre));
	strcpy(donantep->nombre,nuevoDonante.nombre);
	donantep->telefono = (char*)malloc(sizeof(nuevoDonante.telefono));
	strcpy(donantep->telefono,nuevoDonante.telefono);
	donantep->direccion = (char*)malloc(sizeof(nuevoDonante.direccion));
	strcpy(donantep->direccion,nuevoDonante.direccion);
	donantep->next = NULL;

	return donantep;

}
