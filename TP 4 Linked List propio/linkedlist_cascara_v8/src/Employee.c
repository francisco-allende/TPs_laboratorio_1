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
        strcpy(nombre, this->nombre);

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
        printf("%d %12s     %d\t\t     %d\n",
               emp->id,
               emp->nombre,
               emp->horasTrabajadas,
               emp->sueldo);

        todoOk = 1;
    }

    return todoOk;
}


int employee_sortId(void* empOne, void* empTwo)
{
    int criterio = 0;
    int idEmpOne;
    int idEmpTwo;

    Employee* auxEmpUno = (Employee*) empOne;
    Employee* auxEmpTwo = (Employee*) empTwo;

    if(empOne != NULL && empTwo != NULL)
    {
        employee_getId(auxEmpUno, &idEmpOne);
        employee_getId(auxEmpTwo, &idEmpTwo);

        if(idEmpOne > idEmpTwo)
        {
            criterio = 1;
        }
        else if(idEmpOne < idEmpTwo)
        {
            criterio = -1;
        }
    }

    return criterio;
}

int employee_sortName(void* empOne, void* empTwo)
{
    int criterio = 0;
    char nameEmpOne[128];
    char nameEmpTwo[128];

    Employee* auxEmpUno = (Employee*) empOne;
    Employee* auxEmpTwo = (Employee*) empTwo;

    if(empOne != NULL && empTwo != NULL)
    {
        employee_getNombre(auxEmpUno, nameEmpOne);
        employee_getNombre(auxEmpTwo, nameEmpTwo);

        if(strcmp(nameEmpOne, nameEmpTwo) > 0)
        {
            criterio = 1;
        }
        else if(strcmp(nameEmpOne, nameEmpTwo) < 0)
        {
            criterio = -1;
        }
    }
    return criterio;
}

int employee_sortHours(void* empOne, void* empTwo)
{
    int criterio = 0;
    int hoursEmpOne;
    int hoursEmpTwo;

    Employee* auxEmpUno = (Employee*) empOne;
    Employee* auxEmpTwo = (Employee*) empTwo;

    if(empOne != NULL && empTwo != NULL)
    {
        employee_getHorasTrabajadas(auxEmpUno, &hoursEmpOne);
        employee_getHorasTrabajadas(auxEmpTwo, &hoursEmpTwo);

        if(hoursEmpOne > hoursEmpTwo)
        {
            criterio = 1 ;
        }
        else if(hoursEmpOne < hoursEmpTwo)
        {
            criterio = -1;
        }
    }
    return criterio;
}

int employee_sortSalary(void* empOne, void* empTwo)
{
    int criterio = 0;
    int salaryEmpOne;
    int salarayEmpTwo;

    Employee* auxEmpUno = (Employee*) empOne;
    Employee* auxEmpTwo = (Employee*) empTwo;

    if(empOne != NULL && empTwo != NULL)
    {
        employee_getSueldo(auxEmpUno, &salaryEmpOne);
        employee_getSueldo(auxEmpTwo, &salarayEmpTwo);

        if(salaryEmpOne > salarayEmpTwo)
        {
            criterio = 1;
        }
        else if(salaryEmpOne < salarayEmpTwo)
        {
            criterio = -1;
        }
    }
    return criterio;
}

int employee_filterSalariesOver31k(void* pElement)
{
    int retorno = 0;
    Employee* aux = NULL;

    if(pElement != NULL)
    {
        aux = (Employee*) pElement;
        if(aux != NULL)
        {
            if(aux->sueldo > 31104)
            {
                retorno = 1;
            }
        }
    }

    return retorno;
}




