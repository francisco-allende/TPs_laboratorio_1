#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "empleados.h"

#define NO 0
#define SI 1

int salaryValidation(float salary)
{
    int todoOk = 0;

    if(salary > 0 && salary < 1000000)
    {
        if(!isdigit(salary))
        {
            todoOk = 1;
        }
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


int validarChar(char* cadena, int minimo, int maximo)
{

    //Validar si un string tiene letras o numeros y su length
    int todoOk = 0;
    int esNum;
    int esChar = 0;
    int length = strlen(cadena);

    if(length >= minimo && length < maximo)
    {
        esChar = esSoloLetras(cadena);
        esNum = esNumerico(cadena);


        if(!esNum && esChar)
        {
            todoOk = 1;
        }
        else
        {
            printf("No se pueden ingresar numeros\n\n");
        }
    }
    else
    {
        printf("\n");
        printf("No puede superar los %d caracteres ni ser igual o menor a %d \n", maximo, minimo);
        printf("\n\n");
        esChar = 0;
    }


    return todoOk;
}

int esSoloLetras(char str[])
{
    int i = 0;


    while(str[i] != '\0')
    {
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


/*
int soloLetras(char cadena[])
{
    int error=0;
    int i=0;

    if(cadena!=NULL)
    {
        while(cadena[i]!='\0')
        {
            if(!isalpha(cadena[i]) && cadena[i]!=' ')
            {
                error=-1;

                while(error<0)
                {
                    printf("Solo puede ingresar letras. Inténtelo de nuevo: ");
                    fflush(stdin);
                    scanf("%s", cadena);
                    error=0;
                    i=0;
                }
            }
            else
            {
                i++;
            }
        }
    }
    return error;
}


int validarCadena(char cadena[], char mensaje[], char mensajeError[], int min, int max)
{
    int error = -1;
	char aux[100];

	if(cadena != NULL && mensaje != NULL && mensajeError != NULL && min > 0 && max > min)
	{
		printf("%s", mensaje);
		fflush(stdin);
		gets(aux);
		soloLetras(aux);

		while(strlen(aux) <= min || strlen(aux) >= max)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			gets(aux);
			soloLetras(aux);
		}

		strcpy(cadena, aux);
		error=0;
	}

	return error;
}

int validarCaracter(char* caracter, char mensaje[], char mensajeError[], char caracterValido1, char caracterValido2)
{
    int error = -1;
    char caracterIngresado;

	if(caracter != NULL && mensaje != NULL && mensajeError != NULL)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%c", &caracterIngresado);
		caracterIngresado = toupper(caracterIngresado);

		while(caracterIngresado != caracterValido1 && caracterIngresado != caracterValido2)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%c", &caracterIngresado);
			caracterIngresado = toupper(caracterIngresado);
		}

        *caracter = caracterIngresado;
		error = 0;
	}

	return error;
}

int soloNumeros(char* numeros)
{
	int error = 0;

	if(strlen(numeros) > 0)
    {
        for(int i = 0; i < strlen(numeros); i++)
        {
            if(!isdigit(numeros[i]))
            {
                if(!i && numeros[0] == '-')
                {
                    error = 0;
                }
                else
                {
                    error = 1;
                }
            }
        }
    }
    else
    {
        error=1;
    }

	return error;
}

int validarEntero(int* numero, char mensaje[], char mensajeError[], int min, int max)
{
    int error = -1;
    char numeroIngresado[20];

	if(numero != NULL && mensaje != NULL && mensajeError != NULL && min < max)
	{
		printf("%s", mensaje);
		gets(numeroIngresado);
		fflush(stdin);

        while(soloNumeros(numeroIngresado) || atoi(numeroIngresado) <= min || atoi(numeroIngresado) >= max)
		{
			printf("%s", mensajeError);
			gets(numeroIngresado);
			fflush(stdin);
		}

        *numero = atoi(numeroIngresado);
		error = 0;
	}

	return error;
}
*/





