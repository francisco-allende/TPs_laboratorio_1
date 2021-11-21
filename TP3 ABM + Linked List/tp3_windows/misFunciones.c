#include <stdio.h>
#include <stdlib.h>
#include "misFunciones.h"

int menu(int opcion)
{
	if(opcion > -1)
	{
		system("cls");
		printf("*****************************************\n");
		printf("*\t 		Menu TP3 \t*\n");
		printf("*****************************************\n\n");
		printf("1 - Cargar datos empleados desde un CSV modo TEXTO\n");
		printf("2 - Cargar datos empleados desde un CSV modo BINARIO\n");
		printf("3 - Alta de empleado\n");
		printf("4 - Modificar datos de un empleado\n");
		printf("5 - Baja de un empleado\n");
		printf("6 - Listar empleados\n");
		printf("7   Ordenar empleado\n");
		printf("8 - Guardar los datos de los empleados en el archivo CSV (modo TEXTO).\n");
		printf("9 - Guardar los datos de los empleados en el archivo CSV (modo BINARIO).\n");
		printf("10 - Salir\n\n");

		printf("Ingrese opcion: ");
		fflush(stdin);
		scanf("%d", &opcion);
	}

	return opcion;
}

int submenuModify()
{
	int opcion;

	//el id no se puede modificar porque es asignado automaticamente e inmodificable
	printf("Que dato desea modificar del empleado/a?\n\n");
	printf("1) Nombre\n");
	printf("2) Horas trabajadas\n");
	printf("3) Sueldo\n\n");

	printf("Marque la opcion que corresponda: \n");
	scanf("%d", &opcion);
	while(opcion > 3 || opcion < 1)
	{
		printf("Opcion incorrecta. Intente de nuevo: \n");
		scanf("%d", &opcion);
	}

	system("cls");

	return opcion;
}

