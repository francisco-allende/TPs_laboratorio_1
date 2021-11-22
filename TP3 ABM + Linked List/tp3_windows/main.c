#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "misFunciones.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
 *****************************************************/

int main()
{
	setbuf(stdout, NULL);
	int option = 0;
	int flagFileTxt = 0;
	int flagFileBin = 0;

	LinkedList* listaEmpleados = ll_newLinkedList();


	do{
		switch(option = menu(option))
		{
		case 1:
			if(!flagFileTxt)
			{
				if(!controller_loadFromText("data.csv", listaEmpleados))
				{
					printf("No se pudieron cargar todos los datos en texto correctamente\n\n");
				}
				else
				{
					system("cls");
					printf("\n***\t Carga del archivo de texto exitosa! ***\n\n");
					flagFileTxt = 1;
				}
			}
			else
			{
				printf("El archivo ya fue cargado. Solo se puede cargar una vez.\n\n");
			}
			break;

		case 2:
			if(!flagFileBin && flagFileTxt)
			{
				if(!controller_loadFromBinary("data.bin", listaEmpleados))
				{
					printf("No se pudieron cargar todos los datos en binario correctamente\n\n");
				}
				else
				{
					system("cls");
					printf("\n***\t Carga del archivo binario exitosa! ***\n\n");
					flagFileBin = 1;
				}
			}
			else
			{
				printf("Antes asegurese de dos cosas: \n\n");
				printf("1) Cargue el archivo de texto antes (opcion 1)\n");
				printf("2) El archivo binario solo se puede cargar una vez.\n\n");
			}
			break;

		case 3:
			if(flagFileTxt)
			{
				if(!controller_addEmployee(listaEmpleados))
				{
					printf("No se pudo dar de alta al nuevo empleado\n");
				}
			}
			else
			{
				printf("Asegurese antes de cargar los datos (opcion 1 o 2)\n\n");
			}
			break;

		case 4:
			if(flagFileTxt)
			{
				if(!controller_editEmployee(listaEmpleados))
				{
					printf("Operacion cancelada o error al modificar los datos del empleado\n");
				}
				else
				{
					system("cls");
					printf("*** Modificacion de datos exitosa!! ***\n");
				}
			}
			else
			{
				printf("Asegurese antes de cargar los datos (opcion 1 o 2)\n\n");
			}
			break;

		case 5:
			if(flagFileTxt)
			{
				if(!controller_removeEmployee(listaEmpleados))
				{
					printf("Error. No se pudo borrar al empleado\n\n");
				}
				else
				{
					system("cls");
					printf("Empleado borrado con exito\n\n");
				}
			}
			else
			{
				printf("Asegurese antes de cargar los datos (opcion 1 o 2)\n\n");
			}
			break;

		case 6:
			if(flagFileTxt)
			{
				if(!controller_ListEmployee(listaEmpleados))
				{
					printf("Hubo un problema al listar los empleados.\n\n");
				}
			}
			else
			{
				printf("Asegurese antes de cargar los datos (opcion 1 o 2)\n\n");
			}
			break;

		case 7:
			if(flagFileTxt)
			{
				if(!controller_sortEmployee(listaEmpleados))
				{
					printf("El ordenamiento fue cancelado o algo fallo en el proceso\n");
				}
				else
				{
					system("cls");
					printf("\n\n*** Ordenamiento exitoso! ***\n\n");
				}
			}
			else
			{
				printf("Asegurese antes de cargar los datos (opcion 1 o 2)\n\n");
			}
			break;

		case 8:
			if(flagFileTxt)
			{
				if(!controller_saveAsText("data.csv", listaEmpleados))
				{
					printf("Error. No se pudo guardar el archivo modo texto\n");
				}
				else
				{
					system("cls");
					printf("*** Archivo guardado con exito! ***\n");
				}
			}
			else
			{
				printf("Asegurese antes de cargar los datos (opcion 1 o 2)\n\n");
			}
			break;

		case 9:
			if(flagFileTxt)
			{
				if(!controller_saveAsBinary("data.bin", listaEmpleados))
				{
					printf("Error. No se pudo guardar el archivo modo binario\n");
				}
				else
				{
					system("cls");
					printf("\n\n*** Archivo guardado en modo binario con exito!! \n\n ***");
				}
			}
			else
			{
				printf("Asegurese antes de cargar los datos (opcion 1 o 2)\n\n");
			}
			break;

		case 10:
			printf("Adios!");
			break;

		default:
			printf("Error, esa opcion es inexistente. Vuelvalo a intentar \n");
			break;
		}
	}while(option != 10);

	//libero espacio en memoria
	ll_deleteLinkedList(listaEmpleados);
	free(listaEmpleados);

	return EXIT_SUCCESS;;
}


