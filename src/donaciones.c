#include "donaciones.h"

time_t ingresarFecha();

extern Donante *donanteHead;

Donaciones* registrarDonacion() {
	int cedula_registrada,resultado=0;
    printf("Bienvenido donante!.\n");
    printf("Ingrese su cedula:");
    scanf("%d",&cedula_registrada);

    Donante *newDonante = buscar_cedula(donanteHead ,cedula_registrada);

    if (newDonante!=0){
    	Donaciones *d = (Donaciones*)(sizeof(Donaciones));
    	printf("Bienvenido\n");
    	
    	
    	d->fecha = ingresarFecha();

		printf("Seleccione el tipo de donación");
		printf("(0). Monetaria \n (1)Material \n (2)Voluntariado");
		scanf("%hd",&d->tipo);
		while (d->tipo < MONETARIA || d->tipo > VOLUNTARIADO)
		{
			printf("Dato ingresado invalido\n Intente de nuevo...");
			scanf("%hd",&d->tipo);
		}

		if(d->tipo == 0){
			printf("Cuanto dinero esta donando?:  ");
			scanf("%f", &d->valor);
		}
		else if (d->tipo == 1)
		{
			char descripcion[100];
			printf("Agregue una descripción");
			fgets(descripcion,100,stdin);
			d->descripcion = (char*)malloc(strlen(descripcion));
			strcpy(d->descripcion,descripcion);

		}
		d->next = NULL;
		d->estado = 1;  	

	}
    else{
    	printf("Lo siento mucho usted no puede donar..., por favor registrese antes de donar.\n");
		
		while(getchar() != '\n');
		getchar();
    	system("clear");
    	
	}

}


time_t ingresarFecha(){

	while ((getchar() != '\n'));
    char fecha_str[50]; // Suponemos que la fecha no será más larga que 50 caracteres
    struct tm fecha_tm = {0};
	time_t fecha;
	int dia,mes,ano;
	do
	{
	// Leer la fecha como una cadena de texto
    printf("Ingrese la fecha (formato DD/MM/AAAA): ");
    fgets(fecha_str, sizeof(fecha_str), stdin);

    // Eliminar el carácter de nueva línea final de la cadena
    fecha_str[strcspn(fecha_str, "\n")] = '\0';
	printf("%s",fecha_str);

    // Convertir la cadena de texto a una estructura tm
    if (sscanf(fecha_str, "%d/%d/%d", &dia, &mes, &ano) != 3) {
        printf("Formato de fecha incorrecto\n");   
    }
	fecha_tm.tm_mday = dia;
	fecha_tm.tm_mon = mes-1;
	fecha_tm.tm_year = ano - 1900;

    // Convertir la estructura tm a time_t
    fecha = mktime(&fecha_tm);

    // Verificar si la conversión fue exitosa
    if (fecha == -1) {
        printf("Fecha fuera de rango\n");
    }

	} while ((fecha == -1) || sscanf(fecha_str, "%d/%d/%d", &dia, &mes, &ano) != 3);
	
	return fecha;

}