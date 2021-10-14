#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"

#define NO 0
#define SI 1

int nameLengthValidation(char* name)
{
    int todoOk = 0;

    int cantidad = strlen(name);
    if(cantidad <= 51)
    {
        todoOk = 1;
    }

    return todoOk;
}

int lastNameLengthValidation(char* lastName)
{
    int todoOk = 0;

    int cantidad = strlen(lastName);
    if(cantidad <= 51)
    {
        todoOk = 1;
    }

    return todoOk;
}

int salaryValidation(float salary)
{
    int todoOk = 0;
    if(salary > 0 && salary < 1000000)
    {
        todoOk = 1;
    }

    return todoOk;
}


int sectorValidation(int empleadoSector, int tamSec, eSector sectores[])
{
    int todoOk = 0;
    for(int i = 0; i < tamSec; i++)
    {
        if(empleadoSector == sectores[i].id)
        {
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}


int idRangeValidation(int* id)
{
    int todoOk = 0;
    if(*id >= 1000 && *id <= 2000)
    {
        todoOk = 1;
    }

    return todoOk;
}

int validateOptionModifing(int* opcion)
{
    int todoOk = 0;
    if(*opcion == 1 || *opcion == 2 || *opcion == 3 || *opcion == 4)
    {
        todoOk = 1;
    }

    return todoOk;
}

int validateSeguir(char seguir)
{
    int todoOk = 0;

    if(seguir == 's' || seguir == 'n')
    {
        todoOk = 1;
    }

    return todoOk;
}



