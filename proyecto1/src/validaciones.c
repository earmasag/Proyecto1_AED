//Este archivo tiene las funciones de validacion de entrada de datos
#include "validaciones.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//Verifica que la entrada es numerica
int esNumerico(char *str) {
    while(*str != '\0') {
        if(*str < '0' || *str > '9') { // Si el carácter no es un dígito, retorna 0 (falso)
            return 0;
        }
        str++;
    }
    return 1; // Si todos los caracteres son dígitos, retorna 1 (verdadero)
}

//Verifica si la entrada no es un espacio vacio
int noEsBlanco(char *str) {
    while(*str != '\0') {
        if(!isspace((unsigned char)*str)) { // Si el carácter no es un espacio en blanco, retorna 1 (verdadero)
            return 1;
        }
        str++;
    }
    return 0; // Si todos los caracteres son espacios en blanco, retorna 0 (falso)
}

//Limpia el buffer
void vaciarBuffer(){
    while (getchar() != '\n');    
}

//Esta funcion es propia del archivo
//Se usa para asignar valores a los punteros char* de las estructuras
char *asignarValor(int max_char){
	char *asignar;
	char valor[max_char];
	fflush(stdin);
	fgets(valor,max_char,stdin);
	valor[strcspn(valor, "\n")] = 0; // Esta línea elimina el carácter de nueva línea
	asignar = (char*)malloc(strlen(valor)*sizeof(char));
	if (asignar == NULL) {
        printf("Error al asignar memoria.\n");
        return NULL;
    }
	strcpy(asignar,valor);
	return asignar;
}

//Pide un dato como tipo char lo evalua
//Si es un numero retora el valor del numero
int validarNumero(int tamano){
    char c[tamano];

    do{
        fgets(c,sizeof(c),stdin);
        c[strcspn(c,"\n")] = '\0';
        if(!esNumerico(c) || !noEsBlanco(c)){
            printf("DATO INVALIDO. Intente nuevamente: \n");
        }
    } while (!esNumerico(c) || !noEsBlanco(c));

    return atoi(c);  
}
