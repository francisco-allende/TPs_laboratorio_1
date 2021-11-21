#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Employee.h"


//**************    Constructores   ********************

Employee* employee_new()
{
	Employee* newEmployee = NULL;

	newEmployee = (Employee*) malloc(sizeof(Employee));

	if(newEmployee != NULL)
	{
		newEmployee->id = 0;
		strcpy(newEmployee->nombre, "nn");
		newEmployee->horasTrabajadas = 0;
		newEmployee->sueldo = 0;
	}

	return newEmployee;
}

//agrego el empleado que paso por parametro
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* salarioStr)
{
	Employee* newEmployee = employee_new();

	if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && salarioStr != NULL)
	{
		if(!(employee_setId(newEmployee, atoi(idStr))
				&& employee_setNombre(newEmployee, nombreStr)
				&& employee_setHorasTrabajadas(newEmployee, atoi(horasTrabajadasStr))
				&& employee_setSueldo(newEmployee, atoi(salarioStr))
		))
		{
			free(newEmployee);
			newEmployee = NULL;
		}
	}

	return newEmployee;
}

//**************    Setters     ********************

int employee_setId(Employee* this, int id)
{
	int todoOk = 0;

	if(this != NULL)
	{
		this->id = id;

		todoOk = 1;
	}

	return todoOk;
}


int employee_setNombre(Employee* this, char* nombre)
{
	int todoOk = 0;

	if(this != NULL && nombre != NULL)
	{
		if(strlen(nombre) >= 2 && strlen(nombre) < 128)
		{
			strcpy(this->nombre, nombre);

			todoOk = 1;
		}
	}

	return todoOk;
}

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
	int todoOk = 0;

	if(this != NULL)
	{
		this->horasTrabajadas = horasTrabajadas;

		todoOk = 1;
	}

	return todoOk;
}


int employee_setSueldo(Employee* this, int sueldo)
{
	int todoOk = 0;

	if(this != NULL)
	{
		this->sueldo = sueldo;

		todoOk = 1;
	}

	return todoOk;
}

//**************    Getters     ********************

int employee_getId(Employee* this, int* id)
{
	int todoOk = 0;

	if(this != NULL && id != NULL)
	{
		*id = this->id;

		todoOk = 1;
	}

	return todoOk;
}

int employee_getNombre(Employee* this, char* nombre)
{
	int todoOk = 0;

	if(this != NULL && nombre!= NULL)
	{
		//nombre = this->nombre;
		//strcpy(nombre, this->nombre);
		strcpy(this->nombre, nombre);

		todoOk = 1;
	}

	return todoOk;
}

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
	int todoOk = 0;

	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;

		todoOk = 1;
	}

	return todoOk;
}


int employee_getSueldo(Employee* this, int* sueldo)
{
	int todoOk = 0;

	if(this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;

		todoOk = 1;
	}

	return todoOk;
}

/*********** Destructor ************/
void employee_delete(Employee* employee)
{
	free(employee);
}

/*********** Mis funciones ***********/
int employee_print(Employee* emp)
{
	int todoOk = 0;

	if(emp != NULL)
	{
		printf("%d %15s   %d\t   %d \n",
				emp->id,
				emp->nombre,
				emp->horasTrabajadas,
				emp->sueldo);

		todoOk = 1;
	}

	return todoOk;

}





