#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

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

int menu(int opcion);

int main()
{
	setbuf(stdout, NULL);
    int option = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    /*
    Employee* aux = NULL;

    aux = employee_new();
    //pasar a texto con buffer y todo eso
    //aux = employee_newParametros(1, "jose", 10, 22000);

    aux->id = 1;
    strcpy(aux->nombre, "jose");
    aux->horasTrabajadas = 10;
    aux->sueldo = 22000;

	printf("%d, %s, %d, %d \n",
				aux->id,
				aux->nombre,
				aux->horasTrabajadas,
				aux->sueldo);

    //ll_add(listaEmpleados, aux);
    //aux = ll_get(listaEmpleados, 1);
    employee_print(aux);

    printf("\n\n");
    */



     do{
    	switch(option = menu(option))
    		{
            	case 1:
            		if(!controller_loadFromText("data.csv", listaEmpleados))
            		{
            			printf("No se pudieron cargar todos los datos correctamente\n\n");
            		}
            		else
            		{
            			printf("\n***\t Carga exitosa! ***\n\n");
            		}

            		break;

            	case 2:
            		controller_loadFromBinary("data.csv", listaEmpleados);
            		break;

            	case 3:
            		controller_addEmployee(listaEmpleados);
            		break;

            	case 4:
            		controller_editEmployee(listaEmpleados);
            		break;

            	case 5:
            		controller_removeEmployee(listaEmpleados);
            		break;

            	case 6:
            		controller_ListEmployee(listaEmpleados);
            		break;

            	case 7:
            		controller_sortEmployee(listaEmpleados);
            		break;

            	case 8:
            		controller_saveAsText("data.csv", listaEmpleados);
            		break;

            	case 9:
            		controller_saveAsBinary("data.csv", listaEmpleados);
            		break;

            	case 10:
            		printf("Adios!");
            		break;

            	default:
            		printf("Error, esa opcion es inexistente. Vuelvalo a intentar \n");
            		break;
    		}
    }while(option != 10);


     ll_deleteLinkedList(listaEmpleados);
     //employee_delete(aux);

     free(listaEmpleados);
     //free(aux);



    return EXIT_SUCCESS;;
}

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
