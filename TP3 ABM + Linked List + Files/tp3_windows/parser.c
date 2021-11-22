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
					if(!ll_add(pArrayListEmployee, auxEmployee))
					{
						todoOk = 1;
					}
					else
					{
						employee_delete(auxEmployee);
						todoOk = 0;
						break;
					}
				}
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

	if(pFile!= NULL && pArrayListEmployee != NULL)
	{
		while(!feof(pFile))
		{
			auxEmployee = employee_new(); //instancio en cada iteracion los empleados que cargo

			if(auxEmployee != NULL)
			{
				if(fread(auxEmployee, sizeof(Employee), 1, pFile))
				{
					employee_print(auxEmployee);

					if(!ll_add(pArrayListEmployee, auxEmployee))
					{
						todoOk = 1;
					}
					else
					{
						employee_delete(auxEmployee);
						todoOk = 0;
						break;
					}
				}
			}
		}
	}

	return todoOk;
}
