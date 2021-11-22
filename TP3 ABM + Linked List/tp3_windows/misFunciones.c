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
	printf("3) Sueldo\n");
	printf("4) Cancelar modificacion\n\n");

	printf("Marque la opcion que corresponda: \n");
	scanf("%d", &opcion);
	while(opcion > 4 || opcion < 1)
	{
		printf("Opcion incorrecta. Intente de nuevo: \n");
		scanf("%d", &opcion);
	}
	system("cls");

	return opcion;
}

int subMenuOrdenar()
{
	int opcion;

	printf("Seleccione como quiere ordenar el listado: \n\n");
	printf("1. Ordenar por ID\n");
	printf("2. Ordenar por nombre\n");
	printf("3. Ordenar por horas trabajadas\n");
	printf("4. Ordenar por sueldo\n");
	printf("5. Cancelar ordenamiento\n");

	printf("\nOpcion seleccionada: \n");
	scanf("%d", &opcion);
	while(opcion > 5 || opcion < 1)
	{
		printf("Error, opcion inexistente. Vuelva a intentar: \n");
		scanf("%d", &opcion);
	}

	return opcion;
}

int subMenuCriterio()
{
	int criterio;

	printf("Seleccione el criterio de ordenamiento del listado: \n\n");
	printf("1) Criterio ascendente\n");
	printf("2) Criterio descendente\n");
	printf("\nOpcion seleccionada: \n");
	scanf("%d", &criterio);
	while( criterio  !=1 && criterio != 2)
	{
		printf("Error, opcion inexistente. Vuelva a intentar: \n");
		scanf("%d", &criterio);
	}

	return criterio;
}

