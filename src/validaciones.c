#include "validaciones.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

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

void vaciarBuffer(){
    while (getchar() != '\n');    
}

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
