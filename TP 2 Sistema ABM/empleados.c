#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleados.h"

#define NO 0
#define SI 1

int menu(int* opcion)
{
    int todoOk = 0;

    if(opcion != NULL)
    {
        system("cls");
        greenText();
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
        while(!nameLengthValidation(auxEmpleado.name))
        {
            printf("Nombre demasiado largo. Vuelva a intenar: ");
            fflush(stdin);
            gets(auxEmpleado.name);
        }

        printf("Ingrese el apellido del empleado/a: ");
        fflush(stdin);
        gets(auxEmpleado.lastName);
        while(!lastNameLengthValidation(auxEmpleado.lastName))
        {
            printf("Apellido demasiado largo. Vuelva a intenar: ");
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

        //acumulo edady cuento para el informe salarial
        *acumulador+= (float) auxEmpleado.salary;
        (*contador)++;

        auxEmpleado.isEmpty = NO;
        lista[indiceLibre] = auxEmpleado;

        todoOk = 1;
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
            if(lista[i].id == *id)
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

int askForId(int* id)
{
    int todoOk = 0;
    if(id != NULL)
    {
        printf("Ingrese el id del empleado/a para continuar con la operacion: ");
        fflush(stdin);
        scanf("%d", id);
        while(!idRangeValidation(id))
        {
            printf("Id del empleado/a fuera del rango valido 1000 - 2000. Reingrese el id: ");
            fflush(stdin);
            scanf("%d", id);
        }

        todoOk = 1;
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
        while(!validateOptionModifing(opcion))
        {
            printf("Opcion incorrecta, ingrese dato de nuevo: ");
            fflush(stdin);
            scanf("%d", opcion);
        }

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
                while(!nameLengthValidation(auxEmpleado.name))
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
                while(!lastNameLengthValidation(auxEmpleado.lastName))
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






