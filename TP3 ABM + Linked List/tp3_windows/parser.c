#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int todoOk = 0;

	Employee* auxEmployee = NULL;
	char buffer[4][128];
	int cant;

	if(pFile!= NULL && pArrayListEmployee != NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]); //lectura fantasma

		while(!feof(pFile))
		{
			cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]); //lectura real

			if(cant == 4)
			{
				auxEmployee = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);

				if(auxEmployee!=NULL)
				{
					if(ll_add(pArrayListEmployee, auxEmployee))
					{
						employee_delete(auxEmployee);
						break;
					}
					else
					{
						todoOk = 1;
					}
				}
				else
				{
					printf("Ups! Algo fallo en el proceso de carga de empleados.\n\n");
					break;
				}
			}
			else
			{
				printf("No se pudieron cargar correctamente todos los archivos.\n\n");
				break;
			}
		}
	}

	return todoOk;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int todoOk = 0;

	Employee* auxEmployee = NULL;
	int id; //deberia ser un puntero?
	char nombre[128];
	int sueldo;
	int horasTrabajadas;
	int cant;

	if(pFile!= NULL && pArrayListEmployee != NULL)
	{
		fscanf(pFile, "%d, %[^,], %d, %d\n", &id, nombre, &sueldo, &horasTrabajadas); //lectura fantasma

		while(!feof(pFile))
		{
			cant = fscanf(pFile, "%d, %[^,], %d, %d\n", &id, nombre, &sueldo, &horasTrabajadas); //lectura real

			if(cant == 4)
			{
				//auxEmployee = employee_newParametros(id, nombre, sueldo, horasTrabajadas);

				if(auxEmployee!=NULL)
				{
					if(ll_add(pArrayListEmployee, auxEmployee))
					{
						employee_delete(auxEmployee);
						todoOk = 1;
						break;
					}

				}
				else
				{
					printf("Ups! Algo fallo en el proceso de carga de empleados.\n\n");
					break;
				}
			}
			else
			{
				printf("No se pudieron cargar correctamente todos los archivos.\n\n");
				break;
			}
		}
	}


	return todoOk;
}
