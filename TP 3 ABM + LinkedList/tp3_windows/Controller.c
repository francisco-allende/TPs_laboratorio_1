#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	int flag = 1;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		char buffer[4][25];
		int cant;
		int cont = 0;

		Employee* emp = (Employee*) malloc(sizeof(emp));


		if(emp == NULL)
		{
			printf("No se consiguio espacio en memoria\n\n");
			exit(1);
		}


		FILE* f = fopen("data.csv", "r");
		if(f == NULL)
		{
			printf("No existe el archivo.\n");
		}

		//cargo los datos del csv con una matriz string buffer y luego los cargo a mis estructura
		while(!feof(f))
		{
			cant = fscanf(f, "%[^,], %[^,], %[^,], %[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

			if(cant != 4)
			{
				flag = 0;
				break;
			}

			emp->id = atoi(buffer[0]);
			strcpy(emp->nombre, buffer[1]);
			emp->horasTrabajadas = atoi(buffer[2]);
			emp->sueldo = atoi(buffer[3]);

			ll_add(pArrayListEmployee, emp);

			printf("%d %15s %d\t %d \n",
					emp->id,
					emp->nombre,
					emp->horasTrabajadas,
					emp->sueldo
			);
			cont++;
		}

		//valido para el return que se hayan cargado bien mis 4 datos
		if(flag)
		{
			todoOk = 1;
		}

		employee_delete(emp);
		fclose(f);
	}

	return todoOk;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int todoOk = 0;

	if(pArrayListEmployee != NULL)
	{

		char id[6];
		char nombre[128] = "jose";
		char horasTrabajadas[6] = "12";
		char sueldo[10] = "1500";

		Employee* aux = (Employee*) malloc(sizeof(aux));

		if(aux == NULL)
		{
			printf("No se pudo conseguir memoria\n");
			exit(1);
		}

		aux = employee_new();

		printf("Ingrese el id del empleado: ");
		fflush(stdin);
		gets(id);
/*
		printf("Ingrese el nombre del empleado: ");
		fflush(stdin);
		gets(nombre);

		printf("Ingrese las horas trabajadas por el empleado: ");
		fflush(stdin);
		gets(horasTrabajadas);

		printf("Ingrese el sueldo del empleado: ");
		fflush(stdin);
		gets(sueldo);*/

		aux = employee_newParametros(id, nombre, horasTrabajadas, sueldo);

		strcpy(aux->nombre, nombre);
		aux->horasTrabajadas = atoi(horasTrabajadas);
		aux->sueldo = atoi(sueldo);

		printf("%d, %s, %d, %d \n",
				aux->id,
				aux->nombre,
				aux->horasTrabajadas,
				aux->sueldo);

		//ll_add(listaEmpleados, aux);
		//aux = ll_get(listaEmpleados, 1);
		employee_print(aux);

		printf("\n\n");

		todoOk = 1;
	}

	return todoOk;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	return 1;
}

