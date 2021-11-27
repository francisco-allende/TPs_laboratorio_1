#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataSectores.h"

#define TAMSEC 6

int ids[TAMSEC] = {111, 222, 333, 444, 555, 666};

char descripciones[TAMSEC][51] =
{
    "Contaduria",
    "Marketing",
    "Programacion",
    "Gerencia",
    "Limpieza",
    "Seguridad"
};

void hardcodearSectores(eSector sectores[], int tamSec)
{
    if(sectores != NULL && tamSec > 0)
    {
        for(int i = 0; i < tamSec; i++)
        {
            sectores[i].id = ids[i];
            strcpy(sectores[i].descripcion, descripciones[i]);
        }
    }
}


int cargarDescripcionSector(eSector sectores[], int tamSer, int idSector, char* descripcion)
{
    int todoOk = 0;

    if(sectores != NULL && tamSer > 0 && descripcion != NULL)
    {
        for(int i = 0; i < tamSer; i++)
        {
            if(sectores[i].id == idSector)
            {
                strcpy(descripcion, sectores[i].descripcion);
                break;
            }
        }

        todoOk = 1;
    }
    return todoOk;
}


