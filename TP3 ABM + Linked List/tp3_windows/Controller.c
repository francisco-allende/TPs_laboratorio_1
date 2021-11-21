#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"


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

	if(path != NULL && pArrayListEmployee != NULL)
	{
		FILE* f = fopen(path, "r"); //abro en modo lectura

		if(f!=NULL)
		{
			todoOk = parser_EmployeeFromText(f, pArrayListEmployee);
			//todoOk = 1;
			fclose(f);
		}
		else
		{
			printf("No se pudo cargar el archivo\n");
		}
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
	Employee* newEmployee = NULL; //el empleado a dar de alta

	char id[10];
	char nombre[128];
	char sueldo[30];
	char horasTrabajadas[30];

	if(pArrayListEmployee != NULL)
	{
		printf("***\t Alta de empleado\t ***\n\n");

		//instancio al empleado y los campos de su estructura
		newEmployee = employee_new();

		if(newEmployee != NULL)
		{
			printf("Ingrese el id del empleado: ");
			fflush(stdin);
			gets(id);

			while(!employee_setId(newEmployee, atoi(id)))
			{
				printf("Id fuera de rango, intente con otro\n");
				gets(id);
			}

			printf("Ingrese el nombre del empleado: ");
			fflush(stdin);
			gets(nombre);
			while(!employee_setNombre(newEmployee, nombre))
			{
				printf("Nombre fuera de rango, intente de nuevo\n");
				fflush(stdin);
				gets(nombre);
			}

			printf("Ingrese las horas trabajadas por el empleado: ");
			fflush(stdin);
			gets(horasTrabajadas);

			while(!employee_setHorasTrabajadas(newEmployee, atoi(horasTrabajadas)))
			{
				printf("horas trabajadas fuera de rango, intente de nuevo\n");
				gets(horasTrabajadas);
			}

			printf("Ingrese el sueldo del empleado: ");
			fflush(stdin);
			gets(sueldo);

			while(!employee_setSueldo(newEmployee, atoi(sueldo)))
			{
				printf("sueldo fuera de rango, intente de nuevo\n");
				gets(sueldo);
			}

			//cargo los valores por parametro a cada campo del nuevo empleado
			newEmployee = employee_newParametros(id, nombre, horasTrabajadas, sueldo);

			//añado el nuevo empleado a la lista y valido
			if(ll_add(pArrayListEmployee, newEmployee) != -1)
			{
				printf("\n\n Alta del empleado con exito. Nuevo empleado cargado:\n\n ");
				printf("**********************************************\n");
				printf("ID\t Nombre      Horas Trabajadas Sueldo\n");
				printf("**********************************************\n\n");
				employee_print(newEmployee);
				todoOk = 1;
			}

		}
		printf("\n\n");

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
	int todoOk = 0;
	Employee* emp = NULL;
	int id;
	int opcion;
	int indice;
	char newName[128];
	int newHorasTrabajadas;
	int newSueldo;


	if(pArrayListEmployee != NULL)
	{

		//busco el indice en la lista el empleado a modificar
		printf("Ingrese el id del empleado al cual se le modificaran los datos: \n");
		scanf("%d", &id);

		indice = controller_getEmployeeById(pArrayListEmployee, id);

		while(indice == -1)
		{
			printf("No se pudo encontrar el id. Intente con otro: ");
			scanf("%d", &id);
			indice = controller_getEmployeeById(pArrayListEmployee, id);
		}

		emp = ll_get(pArrayListEmployee, indice);

		if(emp != NULL)
		{
			printf("Empleado/a a modificar: \n");
			employee_print(emp);

			opcion = submenuModify();

			//segun la opcion, cargo los nuevos valores al empleado/a
			switch(opcion)
			{
			case 1:
				printf("Ingrese el nuevo nombre del empleado/a: \n");
				fflush(stdin);
				gets(newName);

				while(!employee_setNombre(pArrayListEmployee, newName))
				{
					printf("Nombre fuera de rango, vuelva a intentar: \n");
					fflush(stdin);
					gets(newName);
				}

				strcpy(emp->nombre, newName);

				break;

			case 2:
				printf("Ingrese la nueva cantidad de horas trabajadas del empleado/a: \n");
				scanf("%d", &newHorasTrabajadas);

				while(!employee_setHorasTrabajadas(pArrayListEmployee, newHorasTrabajadas))
				{
					printf("Horas Trabajadas fuera de rango, vuelva a intentar: \n");
					scanf("%d", &newHorasTrabajadas);
				}

				emp->horasTrabajadas = newHorasTrabajadas;

				break;

			case 3:
				printf("Ingrese el nuevo sueldo del empleado/a: \n");
				scanf("%d", &newSueldo);

				while(!employee_setSueldo(pArrayListEmployee, newSueldo))
				{
					printf("Sueldo fuera de rango, vuelva a intentar: \n");
					scanf("%d", &newSueldo);
				}

				emp->sueldo = newSueldo;


				break;
			}

			system("cls");
			printf("*** Empleado con datos modificados ***\n\n");
			employee_print(emp);
			todoOk = 1;
		}
		else
		{
			printf("Hubo un error intentando obtener el empleado\n");
		}
	}

	return todoOk;
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
	int todoOk = 0;
	int indice;
	int id;
	Employee* emp = NULL;

	if(pArrayListEmployee != NULL)
	{
		//busco el indice en la lista el empleado a dar de baja
		printf("Ingrese el id del empleado al cual desea eliminar: \n");
		scanf("%d", &id);

		indice = controller_getEmployeeById(pArrayListEmployee, id);

		while(indice == -1)
		{
			printf("No se pudo encontrar el id. Intente con otro: ");
			scanf("%d", &id);
			indice = controller_getEmployeeById(pArrayListEmployee, id);
		}

		printf("Empleado/a a borrar: \n");
		emp = ll_get(pArrayListEmployee, indice);
		employee_print(emp);

		//borro el empleado enviando el indice y validado el retorno
		if(ll_remove(pArrayListEmployee, indice) != -1)
		{
			todoOk = 1;
		}
		else
		{
			printf("Hubo un error al intentar borrar al empleado\n\n");
		}
	}

	return todoOk;
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
	int todoOk = 0;
	int tam = ll_len(pArrayListEmployee);
	Employee* aux = NULL;

	if(pArrayListEmployee != NULL && tam > 0)
	{
		system("cls");
		printf("****************************************\n");
		printf("ID	Nombre		Horas Tranajadas	Sueldo\n");
		printf("****************************************\n\n");

		for(int i = 0; i < tam; i++)
		{
			aux = ll_get(pArrayListEmployee, i);
			employee_print(aux);
		}

		todoOk = 1;
	}

	return todoOk;
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

	int todoOk = 0;
	/*
	Employee* emp = NULL;
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;
	int tam = ll_len(pArrayListEmployee);

	if(path != NULL && pArrayListEmployee != NULL)
	{
		FILE* f = fopen(path, "w"); //lo abro en modo escritura txt

		if(f != NULL)
		{
			for(int i = 0; i < tam; i++)
			{
				emp = ll_get(pArrayListEmployee, i); //me traigo un empleado por iteracion

				employee_getId(emp, &id);
				employee_getNombre(emp, nombre);
				employee_getHorasTrabajadas(emp, &horasTrabajadas);
				employee_getSueldo(emp, &sueldo);

				fprintf(f, "%d, %s, %d, %d\n", id, nombre, horasTrabajadas, sueldo);
			}

			todoOk = 1;
		}
		else
		{
			printf("No se pudo abrir ni crear el archivo\n");
		}

		fclose(f);
	}
	*/

	return todoOk;

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


int controller_getEmployeeById(LinkedList* lista, int id)
{
	Employee* emp = NULL;
	int tam = ll_len(lista);
	int indice = -1;

	if(lista != NULL)
	{
		for(int i = 0; i < tam; i++)
		{
			emp = ll_get(lista, i);

			if(id == emp->id)
			{
				indice = ll_indexOf(lista, emp);
			}
		}
	}

	return indice;
}

