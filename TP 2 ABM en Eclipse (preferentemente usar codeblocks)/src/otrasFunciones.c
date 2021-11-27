#include <stdio.h>
#include <stdlib.h>
#include "otrasFunciones.h"
#include "validaciones.h"


int menu(int* opcion)
{
    int todoOk = 0;

    if(opcion != NULL)
    {
        system("cls");
        printf("*****************************************\n");
        printf("*\tABM Arroba Developments S.A \t*\n");
        printf("*****************************************\n\n");
        printf("1 - Alta empleado\n");
        printf("2 - Baja empleado\n");
        printf("3 - Modificar datos de empleado\n");
        printf("4 - Listar empleados\n");
        printf("5 - Salir\n\n");
        printf("Ingrese opcion: ");
        fflush(stdin);
        scanf("%d", opcion);

        todoOk = 1;
    }

    return todoOk;
}


int askForId(int* id)
{
    int todoOk = 0;
    if(id != NULL)
    {
        printf("Ingrese el id del empleado/a para continuar con la operacion: ");
        fflush(stdin);
        scanf("%d", id);

        if(!idRangeValidation(id))
        {
            printf("Id del empleado/a fuera del rango valido 1000 - 2000. Reingrese el id: ");
            fflush(stdin);
            scanf("%d", id);
            if(!idRangeValidation(id))
            {
                printf("Fuera de rango. Volvemos al menu principal \n\n");
            }
            else
            {
                todoOk = 1;
            }
        }
        else
        {
            todoOk = 1;
        }
    }

    return todoOk;
}


int askForOptionToModify(int* opcion)
{
    int todoOk = 0;
    if(opcion != NULL)
    {
        printf("Se modifica un dato a la vez.\nSiendo: \n\n");
        printf("Nombre:\t   1\n");
        printf("Apellido:  2\n");
        printf("Salario:   3\n");
        printf("Sector:\t   4\n\n");
        printf("Ingrese el dato a modificar segun el numero de opcion: ");
        fflush(stdin);
        scanf("%d", opcion);

        if(!validateOptionModifing(opcion))
        {
            printf("Opcion incorrecta, ingrese dato de nuevo: ");
            fflush(stdin);
            scanf("%d", opcion);

            if(!validateOptionModifing(opcion))
            {
                  printf("Opcion incorrecta. Volvemos al menu principal \n\n");
            }
            else
            {
                todoOk = 1;
            }
        }
        else
        {
            todoOk = 1;
        }

        todoOk = 1;
    }

    return todoOk;
}


int subMenu(int* opcion)
{
    int subOpcion;
    int todoOk = 0;

    if(opcion != NULL)
    {
        system("cls");
        printf("*** Ordenar Listado ***\n\n");
        printf("Siendo:\n");
        printf("Orden ascendente (De la A a la Z)\t 1\n");
        printf("Orden descendente (De la Z a la A)\t 2\n");
        printf("Informar por promedio de salarios\t 3\n\n");
        printf("Ingrese su opcion: ");
        fflush(stdin);
        scanf("%d", &subOpcion);
        while(subOpcion != 1 && subOpcion != 2 && subOpcion != 3)
        {
            printf("Numero incorrecto. \n");
            fflush(stdin);
            scanf("%d", &subOpcion);
        }

        *opcion = subOpcion;

        todoOk = 1;
    }

    return todoOk;
}


