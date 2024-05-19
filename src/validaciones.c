#include "validaciones.h"
#include <ctype.h>

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
