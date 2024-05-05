// donante.c
#include "./libs/donante.h"


Donante *cabecera = NULL;//creando una lista vacia (se declara como variable global para que las funciones puedan acceder a la lista y modificarla)

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
void agregarDonante(Donante **cabeza,char *nombreNuevo,int cedulaNueva,char *direccionNueva){
	Donante *nuevoDonante = (Donante*)(sizeof(Donante));//creando un nuevo nodo y asignando memoria
	nuevoDonante->nombre = nombreNuevo;
	nuevoDonante->cedula = cedulaNueva;
	nuevoDonante->direccion = direccionNueva;
	nuevoDonante->next = *cabeza;//asignando la direccion de memoria del anterior nodo 
	*cabeza=nuevoDonante;//colocando el nuevo nodo como cabeza
}

void mostrarLista(Donante *cabeza) {

}

void registrarDonante() {
    int i=0;
    Donante *p= (Donante*) malloc(sizeof(Donante)*100);//creando un puntero a mi estructura y asignando memoria 
	
	printf("Bienvenido nuevo donante!.\n");
    printf("Ingrese sus datos por favor!.\n");
    
	p[i].nombre=malloc(sizeof(char)*100);//asignando memoria al campo nombre que es de tipo char
	while ((getchar()) != '\n'); // Limpia la linea antes del fgets() de entrada
	printf("Ingrese su nombre: ");
	fgets(p[i].nombre,100,stdin);
	printf("Ingrese su cedula: ");
	scanf("%d",&p[i].cedula);
	p[i].telefono = malloc(sizeof(char)*100);
	printf("Ingrese su telefono celular:");
	scanf("%s",p[i].telefono);
	p[i].direccion = malloc(sizeof(char)*100);
	while ((getchar()) != '\n');
	printf("Ingrese su direcion: ");
	fgets(p[i].direccion,100,stdin);
	agregarDonante(&cabecera,p[i].nombre,p[i].cedula,p[i].direccion);//agregando el donante a la lista
	printf("Donante registrado con exito!.");
	i++;//se incrementa el indicie para un futuro registro tengo pensado crear una funcion y dependiendo del archivo incrementar el indice pero mas adelante
	getchar();//se pausa hasta que se presione una tecla
	system("clear");//limpia la pantalla
}

void registrarDonacion() {
	int cedula_registrada,resultado=0;
    printf("Bienvenido donante!.\n");
    printf("Ingrese su cedula:");
    scanf("%d",&cedula_registrada);
    Donante *newDonante = buscar_cedula(cabecera,cedula_registrada);
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
    	mostrarLista(cabecera);
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
