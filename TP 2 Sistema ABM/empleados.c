#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleados.h"
#include "validaciones.h"
#include "otrasFunciones.h"

#define NO 0
#define SI 1
#define MIN 2
#define MAX 25

int initEmployees(eEmployee* lista, int tam)
{
    int todoOk = 0;

    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            lista[i].isEmpty = SI;
        }

        todoOk = 1;
    }

    return todoOk;
}

int searchFreePosition(eEmployee* lista, int tam)
{
    int indiceLibre = -1;

    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == SI)
            {
                indiceLibre = i;
                break;
            }
        }
    }

    return indiceLibre;
}

int addEmployee(eEmployee* lista, int tam, int indiceLibre, int* pId, int tamSec, eSector sectores[], int* contador, float* acumulador)
{
    int todoOk = 0;
    eEmployee auxEmpleado;

    if(lista != NULL && tam > 0 && indiceLibre >= 0 && pId != NULL)
    {
        greenText();
        system("cls");
        printf("*** Carga de empleado/a al Sistema ****\n\n");

        lista[indiceLibre] = auxEmpleado;

        auxEmpleado.id = (*pId)++;

        printf("Ingrese el nombre del empleado/a: ");
        fflush(stdin);
        gets(auxEmpleado.name);
        while(!validarChar(auxEmpleado.name, MIN, MAX))
        {
            printf("Incorrecto, vuelva a intentar: ");
            fflush(stdin);
            gets(auxEmpleado.name);
        }

        printf("Ingrese el apellido del empleado/a: ");
        fflush(stdin);
        gets(auxEmpleado.lastName);
        while(!validarChar(auxEmpleado.lastName, MIN, MAX))
        {
            printf("Incorrecto, vuelva a intentar, vuelva a intenar: ");
            fflush(stdin);
            gets(auxEmpleado.lastName);
        }


        printf("Ingrese el salario del empleado/a: ");
        fflush(stdin);
        scanf("%f", &auxEmpleado.salary);
        while(!salaryValidation(auxEmpleado.salary))
        {
            printf("Ese salario no es real. Vuelva a intentar: ");
            fflush(stdin);
            scanf("%f", &auxEmpleado.salary);
        }

        printf("\n\nSiendo: \n");
        printf("Contaduria\t\t 111 \n");
        printf("Marketing\t\t 222 \n");
        printf("Programacion\t\t 333 \n");
        printf("Gerencia\t\t 444 \n");
        printf("Limpieza\t\t 555 \n");
        printf("Seguridad\t\t 666 \n\n");
        printf("Ingrese el sector laboral del empleado/a: ");
        fflush(stdin);
        scanf("%d", &auxEmpleado.sector);

        while(!sectorValidation(auxEmpleado.sector, tamSec, sectores))
        {
            printf("Ese sector es inexistente. Vuelva a intentar: ");
            fflush(stdin);
            scanf("%d", &auxEmpleado.sector);
        }

        todoOk = 1;

        //acumulo edady cuento para el informe salarial
        *acumulador+= (float) auxEmpleado.salary;
        (*contador)++;

        auxEmpleado.isEmpty = NO;
        lista[indiceLibre] = auxEmpleado;
    }

    return todoOk;
}

int findEmployeeById(eEmployee* lista, int tam, int* id)
{
    greenText();
    int indice = -1;

    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].id == *id && !lista[i].isEmpty)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}

int removeEmployee(eEmployee* lista, int tam, int indice , float* acumulador, int* contador)
{
    int todoOk = 0;
    if(lista != NULL && tam > 0 && indice > -1)
    {
        lista[indice].isEmpty = 1;

        //resto el salario del acumulador y bajo el contador para que calcule bien el promedio salarial en el informe
        *acumulador = (float) (*acumulador - lista[indice].salary);
        (*contador)--;

        todoOk = 1;
    }

    return todoOk;
}


int modifyEmployee(eEmployee* lista, int indice, int* opcion, eSector sectores[], int tamSec, float* acumulador)
{
    int todoOk = 0;
    eEmployee auxEmpleado;
    char seguir;

    if(lista != NULL && indice > -1 && *opcion > 0 && *opcion < 5)
    {
        do
        {
            auxEmpleado = lista[indice];

            system("cls");
            greenText();

            switch(*opcion)
            {
            case 1:
                printf("Ingrese el nuevo nombre: ");
                fflush(stdin);
                gets(auxEmpleado.name);
                while(!validarChar(auxEmpleado.name, MIN, MAX))
                {
                    printf("Nombre demasiado largo. Vuelva a intenar: ");
                    fflush(stdin);
                    gets(auxEmpleado.name);
                }
                break;

            case 2:
                printf("Ingrese el nuevo apellido del empleado/a: ");
                fflush(stdin);
                gets(auxEmpleado.lastName);
                while(!validarChar(auxEmpleado.lastName, MIN, MAX))
                {
                    printf("Apellido demasiado largo. Vuelva a intenar: ");
                    fflush(stdin);
                    gets(auxEmpleado.lastName);
                }
                break;

            case 3:
                printf("Ingrese el nuevo salario del empleado/a: ");
                fflush(stdin);
                scanf("%f", &auxEmpleado.salary);
                while(!salaryValidation(auxEmpleado.salary))
                {
                    printf("Ese salario no es real. Vuelva a intentar: ");
                    fflush(stdin);
                    scanf("%f", &auxEmpleado.salary);
                }
                //modifico para el informe salarial
                *acumulador -= (float) lista[indice].salary;
                *acumulador += (float) auxEmpleado.salary;
                break;

            case 4:
                printf("\n\nSiendo: \n");
                printf("Contaduria\t\t 111 \n");
                printf("Marketing\t\t 222 \n");
                printf("Programacion\t\t 333 \n");
                printf("Gerencia\t\t 444 \n");
                printf("Limpieza\t\t 555 \n");
                printf("Seguridad\t\t 666 \n\n");
                printf("Ingrese el nuevo sector laboral del empleado/a: ");
                fflush(stdin);
                scanf("%d", &auxEmpleado.sector);
                while(!sectorValidation(auxEmpleado.sector, tamSec, sectores))
                {
                    printf("Ese sector es inexistente. Vuelva a intentar: ");
                    fflush(stdin);
                    scanf("%d", &auxEmpleado.sector);
                }
                break;
            }

            lista[indice] = auxEmpleado;
            todoOk = 1;


            printf("Desea seguir? s/n: ");
            fflush(stdin);
            scanf("%c", &seguir);
            while(!validateSeguir(seguir))
            {
                printf("Caracter invalido. Intente de nuevo con s/n: ");
                fflush(stdin);
                scanf("%c", &seguir);
            }
            if(seguir == 's')
            {
                askForOptionToModify(opcion);
            }
            if(seguir == 'n')
            {
                tableText();
                printEmployee(lista, indice, sectores, tamSec);
                printf("\n\n  *** Modificacion de datos del empleado/a exitosa! ***\n\n");
            }
        }
        while(seguir == 's');
    }

    return todoOk;
}


int sortEmployees(eEmployee* lista, int tam, int* opcion)
{
    int todoOk = 0;
    int criterio = *opcion;

    eEmployee auxEmployee;

    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i < tam -1; i++)
        {
            for(int j = i + 1; j < tam; j++)
            {
                if(criterio == 1)
                {
                    if(
                        (lista[i].sector > lista[j].sector) ||
                        (lista[i].sector == lista[j].sector &&
                         stricmp(lista[i].lastName, lista[j].lastName) > 0) //ordena de manera ascendente
                    )
                    {
                        auxEmployee = lista[i];
                        lista[i] = lista[j];
                        lista[j] = auxEmployee;
                    }
                }
                if(criterio == 2)
                {
                    if(
                        (lista[i].sector < lista[j].sector) ||
                        (lista[i].sector == lista[j].sector &&
                         stricmp(lista[i].lastName, lista[j].lastName) < 0) //ordeno descendente
                    )
                    {
                        auxEmployee = lista[i];
                        lista[i] = lista[j];
                        lista[j] = auxEmployee;
                    }
                }
            }
        }
    }

    todoOk = 1;

    return todoOk;
}

int listHasEmployees(eEmployee* lista, int tam)
{
    int todoOk = 0;

    if(lista != NULL && tam  > 0)
    {
        for(int i = 0; i < tam; i++)
        {
                if(!lista[i].isEmpty)
                {
                    todoOk = 1;
                    break;
                }
        }
    }

    return todoOk;
}











int calculateAverageSalary(eEmployee* lista, int tam, float* promedio, float* acumulador, int* contador)
{
    int todoOk = 0;

    if(lista != NULL && tam > 0)
    {
        *promedio = (float) *acumulador / *contador;

        todoOk = 1;
    }

    return todoOk;
}

int aboveOrBellowAverageSalary(eEmployee* lista, int tam, float* promedio, int* pId, eSector sectores[], int tamSec)
{
    int todoOk = 0;
    char yesOrNot[6];
    char yes[6] = "Si";
    char no[6]= "No";
    char igual[6] = "Igual";

    if(lista != NULL && tam >0 && promedio > 0)
    {
        greenText();
        system("cls");
        printf("     LISTA EMPLEADOS ARROBA DEVELOPMENTS    \n\n");
        printf("*********************************************************************************************\n");
        printf("ID           Nombre          Apellido    Salario         Sector   Supera el salario promedio\n");
        printf("********************************************************************************************\n\n");

        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == NO)
            {
                if(lista[i].salary > *promedio)
                {
                    strcpy(yesOrNot, yes);

                    if(!printEmployeesBySalary(lista, i, pId, sectores, yesOrNot, tamSec))
                    {
                        printf("No se pudo realizar el informe correctamente\n\n");
                    }
                }
                else if(lista[i].salary < *promedio)
                {
                    strcpy(yesOrNot, no);

                    if(!printEmployeesBySalary(lista, i, pId, sectores, yesOrNot, tamSec))
                    {
                        printf("No se pudo realizar el informe correctamente\n\n");
                    }
                }
                else if(lista[i].salary == *promedio)
                {
                    strcpy(yesOrNot, igual);

                    if(!printEmployeesBySalary(lista, i, pId, sectores, yesOrNot, tamSec))
                    {
                        printf("No se pudo realizar el informe correctamente\n\n");
                    }
                }
            }
        }

        todoOk = 1;
    }


    return todoOk;
}

int printEmployeesBySalary(eEmployee* lista, int indice, int* pId, eSector sectores[], char* yesOrNot, int tamSec)
{
    greenText();
    int todoOk = 0;

    /*
    char descripcion[51];

     if(!cargarDescripcionSector(sectores, tamSec, lista[indice].sector, descripcion))
    {
        printf("Hubo un error al intentar mostrar la descripcion en texto de cada sector. \n\n");
    }
    */

    if(lista != NULL && indice > -1 && sectores != NULL)
    {
        printf("%3d %15s %15s    %.2f    %12s %6s\n",
               lista[indice].id,
               lista[indice].name,
               lista[indice].lastName,
               lista[indice].salary,
               sectores[indice].descripcion,
               yesOrNot
              );

        todoOk = 1;
    }

    return todoOk;
}

int printEmployees(eEmployee* lista, int tam, int* pId, eSector sectores[], int tamSec)
{
    int todoOk = 0;

    if(lista != NULL && tam > 0 )
    {
        greenText();
        tableText();

        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == NO)
            {
                printEmployee(lista, i, sectores, tamSec);
            }
        }
        printf("\n\n");

        todoOk = 1;
    }

    return todoOk;
}

int printEmployee(eEmployee* lista, int indice, eSector sectores[], int tamSec)
{
    greenText();
    int todoOk = 0;
    char descripcion[51];

    if(!cargarDescripcionSector(sectores, tamSec, lista[indice].sector, descripcion))
    {
        printf("Hubo un error al intentar mostrar la descripcion en texto de cada sector. \n\n");
    }

    if(lista != NULL && indice > -1)
    {
        printf("%3d %15s %15s    %9.2f    %12s \n",
               lista[indice].id,
               lista[indice].name,
               lista[indice].lastName,
               lista[indice].salary,
               descripcion
              );

        todoOk = 1;
    }

    return todoOk;
}

void tableText()
{
    system("cls");
    printf("     LISTA EMPLEADOS ARROBA DEVELOPMENTS    \n\n");
    printf("*********************************************************************\n");
    printf("ID           Nombre          Apellido    Salario         Sector \n");
    printf("*********************************************************************\n\n");
}

void greenText()
{
    printf("\033[1;32m");
}






