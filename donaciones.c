#include "./libs/donaciones.h"
#include "./libs/donante.h"

extern Donante *cabeza;

void registrarDonacion() {
	int cedula_registrada,resultado=0;
    printf("Bienvenido donante!.\n");
    printf("Ingrese su cedula:");
    scanf("%d",&cedula_registrada);

    Donante *newDonante = buscar_cedula(cabeza ,cedula_registrada);
    if (newDonante!=0){
    	Donaciones *d = malloc(sizeof(Donaciones));
    	printf("Bienvenido\n");
    	d->fecha=malloc(sizeof(char));
    	while ((getchar()) != '\n');
    	printf("Ingrese la fecha de hoy: ");
    	fgets(d->fecha,100,stdin);
    	d->tipo = malloc(sizeof(char)*100);
    	printf("Que tipo de donacion es la que va a realizar?: ");
    	fgets(d->tipo,100,stdin);
    	d->descripcion = malloc(sizeof(char)*100);
    	printf("Ingrese la descripcion de su objeto(opcional): ");
    	fgets(d->descripcion,100,stdin);
    	d->valor = malloc(sizeof(char)*100);
    	printf("Ingrese el valor de su donacion: ");
    	fgets(d->valor,100,stdin);
    	getchar();
    	
	}
    else{
    	printf("Lo siento mucho usted no puede donar..., por favor registrese antes de donar.\n");
    	while((getchar()) != '\n');
    	getchar();
    	system("clear");
    	
	}

}
