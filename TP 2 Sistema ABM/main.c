#include <stdio.h>
#include <stdlib.h>
#include "empleados.h"
#include "dataSectores.h"

#define VACIA 0
#define LLENA 1
#define TAM 20
#define TAMSEC 6


int main()
{
    int opcion;
    int flagAltaCargada;
    int freePosition;
    int indiceEmpleadoBaja;
    int idIngresado;
    int indiceEmpleadoModificar;
    int subOpcion;
    float promedio = 0;
    float acumulador = 0;
    int contador = 0;

    int banderaInit = 0;
    int id = 1000;
    char seguir = 's';
    eEmployee arrayEmployee[TAM];
    eSector arraySectores[TAMSEC];

    //cargo cada id con su sector
    hardcodearSectores(arraySectores, TAMSEC);

    do
    {
        if(menu(&opcion))
        {
            switch(opcion)
            {
            case 1:
                if(banderaInit == 0)
                {
                    if(!initEmployees(arrayEmployee, TAM))
                    {
                        printf("Ups! Hubo un error al inicilizar el programa. Intente de nuevo.\n\n");
                    }

                    banderaInit = 1;
                }

                if((freePosition = searchFreePosition(arrayEmployee, TAM)) != -1)
                {
                    printf("\nTenemos lugar libre para un nuevo empleado!\n\n");
                    system("pause");
                    if(!addEmployee(arrayEmployee, TAM, freePosition, &id, TAMSEC, arraySectores, &contador, &acumulador))
                    {
                        printf("Algo fallo al cargar el empleado/a. Intente de nuevo.");
                    }
                    else
                    {
                        system("cls");
                        tableText();
                        printEmployee(arrayEmployee, freePosition, arraySectores, TAMSEC);
                        printf("\n\n\t*** Alta de empleado/a exitosa! ***\n\n");
                    }
                }
                else
                {
                    printf("Lo sentimos, no hay lugar libre para cargar un nuevo empleado/a. \n");
                }

                flagAltaCargada = LLENA;
                break;

            case 2:
                if(flagAltaCargada)
                {
                    system("cls");
                    printf("\n\n************ Baja empleado/a ************\n\n");
                    printEmployees(arrayEmployee, TAM, &id, arraySectores, TAMSEC);

                    if(askForId(&idIngresado))
                    {
                        indiceEmpleadoBaja = findEmployeeById(arrayEmployee, TAM, &idIngresado);

                        if(indiceEmpleadoBaja != -1)
                        {

                            if(!removeEmployee(arrayEmployee, TAM, indiceEmpleadoBaja, &acumulador, &contador))
                            {
                                printf("No se pudo dar de baja el empleado/a. Vuelva a intentar \n\n");
                            }
                            else
                            {
                                tableText();
                                printEmployee(arrayEmployee, indiceEmpleadoBaja, arraySectores, TAMSEC);
                                printf("\n\n\t*** Baja de empleado/a exitosa! ***\n\n");
                            }
                        }
                        else
                        {
                            printf("No se pudo encontrar ningun empleado/a con ese id\n\n");
                        }
                    }
                }
                else
                {
                    printf("Error, Asegurese de haber cargado al menos un empleado\n\n");
                }
                break;

            case 3:
                if(flagAltaCargada)
                {
                    system("cls");
                    printf("\n\n************ Modificar datos de un empleado/a ************\n\n");
                    printEmployees(arrayEmployee, TAM, &id, arraySectores, TAMSEC);

                    if(askForId(&idIngresado))
                    {
                        indiceEmpleadoModificar = findEmployeeById(arrayEmployee, TAM, &idIngresado);

                        if(indiceEmpleadoModificar != -1)
                        {
                            tableText();
                            printEmployee(arrayEmployee, indiceEmpleadoModificar, arraySectores, TAMSEC);
                            printf("\n\n");

                            if(askForOptionToModify(&opcion))
                            {
                                indiceEmpleadoModificar = findEmployeeById(arrayEmployee, TAM, &idIngresado);

                                if(!modifyEmployee(arrayEmployee, indiceEmpleadoModificar, &opcion, arraySectores, TAMSEC, &acumulador))
                                {
                                    printf("No se pudo modificar los datos del empleado/a");
                                }
                                else
                                {
                                    printf("\n\n\t*** Modificacion exitosa! ***\n\n");
                                }
                            }
                        }
                        else
                        {
                            printf("\n\nNo se pudo encontrar ningun empleado/a con ese id\n\n");
                        }
                    }
                }
                else
                {
                    printf("Error, Asegurese de haber cargado al menos un empleado\n\n");
                }
                break;

            case 4:
                if(flagAltaCargada)
                {
                    if(!subMenu(&subOpcion))
                    {
                        printf("Hubo un error al intentar cargar la opcion de listado\n");
                    }
                    else
                    {
                        if(subOpcion == 3)
                        {
                            if(!calculateAverageSalary(arrayEmployee, TAM, &promedio, &acumulador, &contador))
                            {
                                printf("No se pudo realizar el informe por salarios.\n\n");
                            }
                            else
                            {
                                if(!aboveOrBellowAverageSalary(arrayEmployee, TAM, &promedio, &id, arraySectores, TAMSEC))
                                {
                                    printf("No se pudo calcular quien gana mas o menos que el promedio\n\n");
                                }
                                else
                                {
                                    if(contador != 0)
                                    {
                                        printf("\n\nPromedio salarios: %.2f \n\n", promedio);
                                        printf("Total salarios: %.2f", acumulador);
                                        printf("\n\n\t*** Informe por promedio salarial exitoso! ***\n\n");
                                    }
                                }
                            }
                        }
                        else
                        {
                            if(!sortEmployees(arrayEmployee, TAM, &subOpcion))
                            {
                                printf("Hubo un error al intentar ordenar el listado\n");
                            }
                            else
                            {
                                if(!printEmployees(arrayEmployee, TAM, &id, arraySectores, TAMSEC))
                                {
                                    printf("Hubo un error al mostrar el listado\n");
                                }
                            }
                        }
                    }
                }
                else
                {
                    printf("Error. Asegurese de haber cargado al menos un empleado\n\n");
                }
                break;

            case 5:
                seguir = 'n';
                printf("\n\nAdios! \n\n");
                break;
            default:
                printf("Error, esa opcion es inexistente. Vuelvalo a intentar \n");
                break;
            }
        }
        else
        {
            printf("Hubo un error al mostrar el menu.\n");
            seguir = 'n';
        }

        system("pause");
    }
    while(seguir == 's');

    return 0;
}
