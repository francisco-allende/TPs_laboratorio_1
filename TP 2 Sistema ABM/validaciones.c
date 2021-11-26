#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleados.h"

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


/******************* Validate char ******************************/


int validarChar(char* cadena)
{

    //Validar si un string tiene letras o numeros y su length
    int length = 0;
    int esNum;
    int esChar = 0;

    while(!esChar)
    {
        printf("Ingresar un cadena: ");
        fflush(stdin);
        gets(cadena);
        length = strlen(cadena);

        if(length > 0 && length < 21)
        {
            esChar = esSoloLetras(cadena);
            esNum = esNumerico(cadena);


            if(esNum)
            {
                printf("\n");
                printf("No puede ingresar numeros, intentelo de nuevo");
                printf("\n\n");
            }
        }
        else
        {
            printf("\n");
            printf("No puede superar los 20 caracteres ni ser igual a cero");
            printf("\n\n");
            esChar = 0;
        }
        system("pause");
        system("cls");
    }

    printf("\n");
    printf("%s", cadena);
    printf("\n\n");
    system("pause");

    return 0;
}

int esSoloLetras(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        //acepto espacio
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z')) //que no sea un espacio y que no este entre a y z y que no este entre A y Z
        {
            return 0; //No es una letra
        }

         i++;
    }
    return 1; //Si es una letra

}

int esNumerico(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
        {
            return 0; //no es numerico, no se hayaron numeros
        }
        i++;
    }
    return 1; //hace referencia a que si es numerico
}






