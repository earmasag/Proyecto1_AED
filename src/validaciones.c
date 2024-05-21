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
        if(!esNumerico(c) || !noEsBlanco(c))
        printf("DATO INVALIDO. Intente nuevamente: ");
    } while (!esNumerico(c) || !noEsBlanco(c));

    return atoi(c);  
}

void gotoxy(int x, int y) {
  // Se valida que los valores de x e y sean válidos
  if (x < 1 || y < 1) {
    printf("Error: Las coordenadas x e y deben ser mayores o iguales a 1.\n");
    return;
  }

  // Se crea la secuencia ANSI completa
  char secuencia[20];
  sprintf(secuencia, "\e[%d;%dH", x, y);

  // Se imprime la secuencia ANSI para posicionar el cursor
  printf("%s", secuencia);
}