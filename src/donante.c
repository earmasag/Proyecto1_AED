#include "donante.h"

char *asignarValor(int max_char);
int validarCedula(Donante *cabeza, int cedula){
	if (buscar_cedula(cabeza,cedula)== NULL){
		return 1;
	} 
	return 0;
}
int esNumerico(char *str) {
    while(*str != '\0') {
        if(*str < '0' || *str > '9') { // Si el carácter no es un dígito, retorna 0 (falso)
            return 0;
        }
        str++;
    }
    return 1; // Si todos los caracteres son dígitos, retorna 1 (verdadero)
}
int noEsBlanco(char *str) {
    while(*str != '\0') {
        if(!isspace((unsigned char)*str)) { // Si el carácter no es un espacio en blanco, retorna 1 (verdadero)
            return 1;
        }
        str++;
    }
    return 0; // Si todos los caracteres son espacios en blanco, retorna 0 (falso)
}


Donante *registrarDonante(Donante *donanteHead) {
	int size_nombre = 30;
	int size_tlf = 15;
	int size_dir = 120;

	//creando una variable a mi estructura
	Donante nuevoDonante;

	printf("Bienvenido nuevo donante!.\n");
    printf("Ingrese sus datos por favor!.\n");

	while(getchar() != '\n');

 	printf("Ingrese su cedula: ");
	char cedulaStr[12]; // Asumiendo que la cédula no tiene más de 10 dígitos, más el carácter de nueva línea y el carácter nulo
	do {
	    fgets(cedulaStr, sizeof(cedulaStr), stdin);
	    cedulaStr[strcspn(cedulaStr, "\n")] = 0; // Elimina el carácter de nueva línea
	    if(!esNumerico(cedulaStr) || !noEsBlanco(cedulaStr)) {
	        printf("Entrada invalida. Por favor, ingrese un numero entero: ");
	    } else {
	        nuevoDonante.cedula = atoi(cedulaStr); // Convierte la cadena a un entero
	        if(validarCedula(donanteHead, nuevoDonante.cedula) != 1) {
	            printf("Cedula ya registrada. Por favor, ingrese un numero entero: ");
	        }
	    }
	} while(!esNumerico(cedulaStr) || !noEsBlanco(cedulaStr) || validarCedula(donanteHead, nuevoDonante.cedula) != 1);


	while ((getchar() != '\n'));

	printf("Ingrese su nombre: ");
	do {
	    nuevoDonante.nombre = asignarValor(size_nombre);
	    if(!noEsBlanco(nuevoDonante.nombre)) {
	        printf("Entrada invalida. Por favor, ingrese un nombre valido: ");
	    }
	} while(!noEsBlanco(nuevoDonante.nombre));
	
	printf("Ingrese su telefono celular:");
	do {
	    nuevoDonante.telefono = asignarValor(size_tlf);
	    if(!esNumerico(nuevoDonante.telefono) || !noEsBlanco(nuevoDonante.telefono)) {
	        printf("Entrada invalida. Por favor, ingrese un numero de telefono valido: ");
	    }
	} while(!esNumerico(nuevoDonante.telefono) || !noEsBlanco(nuevoDonante.telefono));
	
	printf("Ingrese su direccion: ");
	do {
	    nuevoDonante.direccion = asignarValor(size_dir);
	    if(!noEsBlanco(nuevoDonante.direccion)) {
	        printf("Entrada invalida. Por favor, ingrese una direccion valida: ");
	    }
	} while(!noEsBlanco(nuevoDonante.direccion));



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
