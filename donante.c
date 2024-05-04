// donante.c
#include "donante.h"

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

void agregarDonante(Donante **cabeza,char *nombreNuevo,int cedulaNueva,char *direccionNueva,Donaciones *pDonaciones){//funcion para agregar un nodo a la lista
	Donante *nuevoDonante = malloc(sizeof(Donante));//creando un nuevo nodo y asignando memoria
	nuevoDonante->nombre = nombreNuevo;
	nuevoDonante->cedula = cedulaNueva;
	nuevoDonante->direccion = direccionNueva;
	nuevoDonante->pDonaciones = NULL;//asignando los campos a los nuevos nodos
	nuevoDonante->next = *cabeza;//asignando la direccion de memoria del anterior nodo 
	*cabeza=nuevoDonante;//colocando el nuevo nodo como cabeza
}
void mostrarLista(Donante *cabeza) {
    Donante *actual = cabeza;
    while (actual != NULL) {
        printf("%s",actual->nombre);  // Esta funcion es temporal sirve para verificar que los datos se guarden correctamente
        printf("%d\n",actual->cedula);
        printf("%s\n",actual->direccion);
        printf("%s\n",actual->pDonaciones);
        actual = actual->next;
    }
    
}
void registrarDonante() {
    int i=0;
    Donante *p=malloc(sizeof(Donante)*100);//creando un puntero a mi estructura y asignando memoria 
	
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
	agregarDonante(&cabecera,p[i].nombre,p[i].cedula,p[i].direccion,p[i].pDonaciones);//agregando el donante a la lista
	printf("Donante registrado con exito!.");
	i++;//se incrementa el indicie para un futuro registro tengo pensado crear una funcion y dependiendo del archivo incrementar el indice pero mas adelante
	getchar();//se pausa hasta que se presione una tecla
	system("cls");//limpia la pantalla
}

void registrarDonacion() {
	int cedula_registrada,resultado=0;
    printf("Bienvenido donante!.\n");
    printf("Ingrese su cedula:");
    scanf("%d",&cedula_registrada);
    Donante *newDonante = buscar_cedula(cabecera,cedula_registrada);
    if (newDonante!=0){
    	Donaciones *d = malloc(sizeof(Donaciones)*100);
    	/*typedef struct donaciones{
		char *fecha;
		char *tipo;
		char *descripcion;
		char *valor;*/
		
    	getchar();
	}
    else{
    	printf("Lo siento mucho usted no puede donar..., por favor registrese antes de donar.");
    	getchar();
	}
	system("cls");//cambiar cuando se cambie a linux ya que en linux el comando es clear
}

void salir() {
    printf("Saliendo del sistema.\n");
}

