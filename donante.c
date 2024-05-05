// donante.c
#include "./libs/donante.h"

//creando una lista vacia (se declara como variable global para que las funciones puedan acceder a la lista y modificarla)
extern Donante *cabeza;

Donante* buscar_cedula(Donante *cabeza, int buscarCedula){
	Donante *actual = cabeza;//variable para moverte por la lista
	while (actual != NULL){
		if (actual->cedula == buscarCedula){//comparando hasta encontrar la cedula
			return actual;//retorna el nodo donde esta la cedula
		}
		actual = actual->next;//se mueve en la lista
	}
	return NULL;//si no encuentra retorna null
}
//delimitadores usar para archivos

//funcion para agregar un nodo a la lista
Donante *agregarDonante(Donante *cabeza,Donante *nuevo_donante){
	Donante *auxp;
	if(cabeza == NULL) return nuevo_donante;

	for(auxp = cabeza;auxp->next != NULL; auxp=auxp->next){
		if(nuevo_donante->cedula > auxp->cedula){
			nuevo_donante->next = auxp->next;
			auxp->next = nuevo_donante;
			return cabeza;
		}
	}

}


Donante *registrarDonante() {
	int size_nombre = 30;
	int size_tlf = 10;
	int size_dir = 50;
	//creando un puntero a mi estructura y asignando memoria 
	Donante *donantep = (Donante*) malloc(sizeof(Donante));
	printf("Bienvenido nuevo donante!.\n");
    printf("Ingrese sus datos por favor!.\n");
     
	fflush(stdin);
	printf("Ingrese su nombre: ");
	fgets(donantep->nombre,size_nombre,stdin);
	fflush(stdin);

	printf("Ingrese su cedula: ");
	scanf("%i",&donantep->cedula);

	printf("Ingrese su telefono celular:");
	fgets(donantep->telefono,size_tlf,stdin);
	fflush(stdin);

	printf("Ingrese su direcion: ");
	fgets(donantep->direccion,size_dir,stdin);

	printf("Donante registrado con exito!.");

	system("clear");//limpia la pantalla
	system("pause");
	return donantep;
}

void registrarDonacion() {
	int cedula_registrada,resultado=0;
    printf("Bienvenido donante!.\n");
    printf("Ingrese su cedula:");
    scanf("%d",&cedula_registrada);

    Donante *newDonante = buscar_cedula(cabeza ,cedula_registrada);
    if (newDonante!=0){
    	Donaciones *d = malloc(sizeof(Donaciones)*100);
    	printf("Bienvenido\n");
    	d->fecha=malloc(sizeof(char)*100);
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

void salir() {
    printf("Saliendo del sistema.\n");
}

