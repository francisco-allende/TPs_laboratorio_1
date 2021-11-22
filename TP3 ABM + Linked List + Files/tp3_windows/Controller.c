#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"
#include "misFunciones.h"


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
		FILE* fTxt = fopen(path, "r"); //abro en modo lectura

		if(fTxt != NULL)
		{
			todoOk = parser_EmployeeFromText(fTxt, pArrayListEmployee);
			fclose(fTxt);
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
	int todoOk = 0;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		FILE* fBin = fopen(path, "rb"); //abro en modo lectura binaria

		if(fBin != NULL)
		{
			todoOk = parser_EmployeeFromBinary(fBin, pArrayListEmployee);
			fclose(fBin);
		}
	}

	return todoOk;
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

	int newEmployeeId = 0;
	char nombre[128];
	char sueldo[30];
	char horasTrabajadas[30];

	if(pArrayListEmployee != NULL)
	{
		system("cls");
		printf("***\t Alta de empleado\t ***\n\n");

		newEmployee = employee_new(); //instancio al empleado y los campos de su estructura

		if(newEmployee != NULL)
		{
			//id dinamico
			newEmployeeId =  controller_getLastId(pArrayListEmployee); //consigo el id del ultimo empleado
			newEmployeeId++; //sumo uno
			employee_setId(newEmployee, newEmployeeId); //se lo atribuyo a mi nuevo empleado

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


			if(ll_add(pArrayListEmployee, newEmployee) != -1)//añado el nuevo empleado a la lista y valido
			{
				printf("\n\n Alta del empleado con exito. Nuevo empleado cargado:\n\n ");
				printf("**********************************************\n");
				printf("ID\t Nombre      Horas Trabajadas Sueldo\n");
				printf("**********************************************\n\n");
				employee_print(newEmployee);
				todoOk = 1;
			}
		}
	}

	return todoOk;
}

int controller_getLastId(LinkedList* pArrayListEmployee)
{
	int id = -1;
	Employee* auxId = NULL;
	int tam = ll_len(pArrayListEmployee); //tam de la lista

	if(pArrayListEmployee != NULL)
	{
		auxId = ll_get(pArrayListEmployee, tam-1); //uso el tam como indice
		printf("Aguarde, estamos ordenando el listado. El empleado ingresado sera ubicado al final de la lista\n");
		ll_sort(pArrayListEmployee, employee_sortId, 1);//ordeno en indice ascendente para ubicar al nuevo empleado
		id = auxId->id;
	}

	return id;
}

int controller_getEmployeeById(LinkedList* lista, int id)
{
	int indice = -1;
	Employee* emp = NULL;
	int tam = ll_len(lista);

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
	char newName[128];
	int newHorasTrabajadas;
	int newSueldo;
	int indice;


	if(pArrayListEmployee != NULL)
	{
		system("cls");
		printf("***\t Moidifcar datos de un empleado\t ***\n\n");

		printf("Ingrese el id del empleado al cual se le modificaran los datos: \n");
		scanf("%d", &id);

		indice = controller_getEmployeeById(pArrayListEmployee, id); //obtengo el indice del empleado segun id y valido

		while(indice == -1)
		{
			printf("No se pudo encontrar el id. Intente con otro: ");
			scanf("%d", &id);
			indice = controller_getEmployeeById(pArrayListEmployee, id);
		}

		emp = ll_get(pArrayListEmployee, indice); //me retorna el empleado con el indice de getEmployeeById

		if(emp != NULL)
		{
			printf("Empleado/a a modificar: \n");
			employee_print(emp);

			switch(submenuModify())
			{
			case 1:
				printf("Ingrese el nuevo nombre del empleado/a: \n");
				fflush(stdin);
				gets(newName);
				while(!employee_setNombre(emp, newName))
				{
					printf("Nombre fuera de rango, vuelva a intentar: \n");
					fflush(stdin);
					gets(newName);
				}

				strcpy(emp->nombre, newName);
				todoOk = 1;
				break;

			case 2:
				printf("Ingrese la nueva cantidad de horas trabajadas del empleado/a: \n");
				scanf("%d", &newHorasTrabajadas);
				while(!employee_setHorasTrabajadas(emp, newHorasTrabajadas))
				{
					printf("Horas Trabajadas fuera de rango, vuelva a intentar: \n");
					scanf("%d", &newHorasTrabajadas);
				}

				emp->horasTrabajadas = newHorasTrabajadas;
				todoOk = 1;
				break;

			case 3:
				printf("Ingrese el nuevo sueldo del empleado/a: \n");
				scanf("%d", &newSueldo);
				while(!employee_setSueldo(emp, newSueldo))
				{
					printf("Sueldo fuera de rango, vuelva a intentar: \n");
					scanf("%d", &newSueldo);
				}

				emp->sueldo = newSueldo;
				todoOk = 1;
				break;

			case 4:
				printf("Modificacion cancelada\n");
				todoOk = 0;
				break;
			}

			system("cls");
			printf("*** Empleado con datos modificados ***\n\n");
			employee_print(emp);
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
	int opcion;
	Employee* emp = NULL;

	if(pArrayListEmployee != NULL)
	{
		system("cls");
		printf("***\t Baja de empleado\t ***\n\n");

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

		printf("Esta seguro/a de que desea eliminar al empleado? \n");
		printf("1) Si, seguro/a.\n");
		printf("2) No, cancelar operacion.\n");
		printf("\n\nMarque su opcion: ");
		scanf("%d", &opcion);
		while(opcion != 1 && opcion != 2)
		{
			printf("Opcion incorrecta, ingrese 1 o 2: ");
			scanf("%d", &opcion);
		}

		if(opcion == 1)
		{
			//borro el empleado enviando el indice y validado el retorno
			if(ll_remove(pArrayListEmployee, indice) != -1)
			{
				todoOk = 1;
			}
		}
		else
		{
			printf("\n\n*** Modificacion cancelada ***\n\n");
			todoOk = 0;
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
	Employee* aux = NULL;
	int tam = ll_len(pArrayListEmployee);


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
	int todoOk = 0;
	int opcion;
	int criterio;
	char msj[140] = "Aguarde! Estamos ordenando la lista. Esto podria demorar unos segundos...\n\n";

	if(pArrayListEmployee != NULL)
	{
		system("cls");
		printf("\n\n***\t Ordenar listado de empleado\t ***\n\n");

		opcion = subMenuOrdenar();
		criterio = subMenuCriterio();

		switch(opcion)
		{
		case 1:
			if(criterio == 1) //criterio = 1 ascendente, 2 descendente
			{
				printf("%s ", msj);
				ll_sort(pArrayListEmployee, employee_sortId, 1); //ll_sort. 1 es ascendente, 0 descedente
				controller_ListEmployee(pArrayListEmployee);
			}
			else if(criterio == 2)
			{
				printf("%s ", msj);
				ll_sort(pArrayListEmployee, employee_sortId, 0);
				controller_ListEmployee(pArrayListEmployee);
			}
			todoOk = 1;
			break;

		case 2:
			if(criterio == 1)
			{
				printf("%s ", msj);
				ll_sort(pArrayListEmployee, employee_sortName, 1);
				controller_ListEmployee(pArrayListEmployee);
			}
			else
			{
				printf("%s ", msj);
				ll_sort(pArrayListEmployee, employee_sortName, 0);
				controller_ListEmployee(pArrayListEmployee);
			}
			todoOk = 1;
			break;


		case 3:
			if(criterio == 1)
			{
				printf("%s ", msj);
				ll_sort(pArrayListEmployee, employee_sortHours, 1);
				controller_ListEmployee(pArrayListEmployee);
			}
			else
			{
				printf("%s ", msj);
				ll_sort(pArrayListEmployee, employee_sortHours, 0);
				controller_ListEmployee(pArrayListEmployee);
			}
			todoOk = 1;
			break;

		case 4:
			if(criterio == 1)
			{
				printf("%s ", msj);
				ll_sort(pArrayListEmployee, employee_sortSalary, 1);
				controller_ListEmployee(pArrayListEmployee);
			}
			else
			{
				printf("%s ", msj);
				ll_sort(pArrayListEmployee, employee_sortSalary, 0);
				controller_ListEmployee(pArrayListEmployee);
			}
			todoOk = 1;
			break;

		case 5:
			printf("\n\n*** Ordenamiento cancelado ***\n\n");
			todoOk = 1;
			break;
		}
	}

	return todoOk;
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
	Employee* emp = NULL;

	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;
	int tam = ll_len(pArrayListEmployee);

	if(path != NULL && pArrayListEmployee != NULL)
	{
		FILE* f = fopen(path, "w"); //lo abro en modo escritura txt
		emp = employee_new(); //instancio al empleado para cargar bien los getters

		if(f != NULL && emp != NULL)
		{
			printf("\n\n***\t Guardar archivo (modo texto)\t ***\n\n");
			fprintf(f, "id,nombre,horasTrabajadas,sueldo\n"); //cargo la data de las columnas

			for(int i = 0; i < tam; i++)
			{
				emp = ll_get(pArrayListEmployee, i); //me traigo un empleado por iteracion

				if(emp != NULL)
				{
					employee_getId(emp, &id);
					employee_getNombre(emp, nombre);
					employee_getHorasTrabajadas(emp, &horasTrabajadas);
					employee_getSueldo(emp, &sueldo);

					fprintf(f, "%d,%s,%d,%d\n", id, nombre, horasTrabajadas, sueldo);
					todoOk = 1;
				}
			}
		}

		fclose(f);
	}

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
	int todoOk = 0;
	Employee* emp = NULL;

	int cant;
	int tam = ll_len(pArrayListEmployee);

	if(path != NULL && pArrayListEmployee != NULL)
	{
		FILE* f = fopen(path, "wb"); //modo escritura binaria para guardar datos
		emp = employee_new();

		if(f != NULL && emp != NULL)
		{
			printf("***\t Guardar archivo (modo binario)\t ***\n\n");

			for(int i = 0; i < tam; i++)
			{
				emp = ll_get(pArrayListEmployee, i);

				if(emp != NULL)
				{
					cant = fwrite(emp, sizeof(Employee), 1, f);

					if(cant)
					{
						todoOk = 1;
					}
					else
					{
						todoOk = 0;
						break;
					}
				}
			}
		}

		fclose(f);
	}

	return todoOk;

}
