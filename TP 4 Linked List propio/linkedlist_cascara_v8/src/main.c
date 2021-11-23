#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
//#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "misFunciones.h"


int main()
{
    /*
    startTesting(1);  // ll_newLinkedList
    startTesting(2);  // ll_len
    startTesting(3);  // getNode - test_getNode
    startTesting(4);  // addNode - test_addNode
    startTesting(5);  // ll_add
    startTesting(6);  // ll_get
    startTesting(7);  // ll_set
    startTesting(8);  // ll_remove
    startTesting(9);  // ll_clear
    startTesting(10); // ll_deleteLinkedList
    startTesting(11); // ll_indexOf
    startTesting(12); // ll_isEmpty
    startTesting(13); // ll_push
    startTesting(14); // ll_pop
    startTesting(15); // ll_contains
    startTesting(16); // ll_containsAll
    startTesting(17); // ll_subList
    startTesting(18); // ll_clone
    startTesting(19); // ll_sort
    */

    int option = 0;
    int TxtLoaded = 0;
    int BinLoaded = 0;
    char msjCarga[140] = "Asegurese antes de cargar los datos (opcion 1 o 2)\n\n";

    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listSalariesOver31k = NULL;
    LinkedList* listaCopia = NULL;
    LinkedList* listaCortada = NULL;



    do
    {
        switch(menu())
        {
        case 1:
            if(ll_isEmpty(listaEmpleados))
            {
                if(!controller_loadFromText("data.csv", listaEmpleados))
                {
                    printf("No se pudieron cargar todos los datos en texto correctamente\n\n");
                }
                else
                {
                    system("cls");
                    printf("\n***\t Carga del archivo de texto exitosa! ***\n\n");
                    TxtLoaded = 1;
                }
            }
            else
            {
                printf("El archivo ya fue cargado. Solo se puede cargar una vez.\n\n");
            }
            break;

        case 2:
            if(!BinLoaded && TxtLoaded && !ll_isEmpty(listaEmpleados))
            {
                if(!controller_loadFromBinary("data.bin", listaEmpleados))
                {
                    printf("Ups! Hubo un error. Dos cosas pudieron haber pasado: \n");
                    printf("1) Si el archivo binario no existe, crearlo  (opcion 9)\n");
                    printf("2) No se pudieron cargar todos los datos en binario correctamente\n\n");
                }
                else
                {
                    system("cls");
                    printf("\n***\t Carga del archivo binario exitosa! ***\n\n");
                    BinLoaded = 1;
                }
            }
            else
            {
                printf("Antes asegurese de: \n\n");
                printf("1) Cargar el archivo de texto (opcion 1)\n");
                printf("2) Si el archivo binario no existe, crearlo  (opcion 9)\n");
                printf("3) En caso de que ya haya sido creado y cargado, el archivo binario solo se puede cargar una vez.\n\n");
            }
            break;

        case 3:
            if(!ll_isEmpty(listaEmpleados))
            {
                if(!controller_addEmployee(listaEmpleados))
                {
                    printf("No se pudo dar de alta al nuevo empleado\n");
                }
            }
            else
            {
                printf("%s ", msjCarga);
            }
            break;

        case 4:
            if(!ll_isEmpty(listaEmpleados))
            {
                if(!controller_editEmployee(listaEmpleados))
                {
                    printf("Operacion cancelada o error al modificar los datos del empleado\n");
                }
                else
                {
                    system("cls");
                    printf("*** Modificacion de datos exitosa!! ***\n");
                }
            }
            else
            {
                printf("%s ", msjCarga);
            }
            break;

        case 5:
            if(!ll_isEmpty(listaEmpleados))
            {
                if(!controller_removeEmployee(listaEmpleados))
                {
                    printf("Error. No se pudo borrar al empleado\n\n");
                }
                else
                {
                    system("cls");
                    printf("Empleado borrado con exito\n\n");
                }
            }
            else
            {
                printf("%s ", msjCarga);
            }
            break;

        case 6:
            if(!ll_isEmpty(listaEmpleados))
            {
                if(!controller_ListEmployee(listaEmpleados))
                {
                    printf("Hubo un problema al listar los empleados.\n\n");
                }
            }
            else
            {
                printf("%s ", msjCarga);
            }
            break;

        case 7:
            if(!ll_isEmpty(listaEmpleados))
            {
                if(!controller_sortEmployee(listaEmpleados))
                {
                    printf("El ordenamiento fue cancelado o algo fallo en el proceso\n");
                }
                else
                {
                    system("cls");
                    printf("\n\n*** Ordenamiento exitoso! ***\n\n");
                }
            }
            else
            {
                printf("%s ", msjCarga);
            }
            break;

        case 8:
            if(!ll_isEmpty(listaEmpleados))
            {
                if(!controller_saveAsText("data.csv", listaEmpleados))
                {
                    printf("Error. No se pudo guardar el archivo modo texto\n");
                }
                else
                {
                    system("cls");
                    printf("*** Archivo guardado con exito! ***\n");
                }
            }
            else
            {
                printf("%s ", msjCarga);
            }
            break;

        case 9:
            if(!ll_isEmpty(listaEmpleados) || !TxtLoaded)
            {
                if(!controller_saveAsBinary("data.bin", listaEmpleados))
                {
                    printf("Error. No se pudo guardar el archivo modo binario\n");
                }
                else
                {
                    system("cls");
                    printf("\n\n*** Archivo guardado en modo binario con exito!! \n\n ***");
                }
            }
            else
            {
                printf("%s ", msjCarga);
            }
            break;

        case 10:
            if(!ll_isEmpty(listaEmpleados))
            {
                listSalariesOver31k = ll_filter(listaEmpleados, employee_filterSalariesOver31k);
                controller_ListEmployee(listSalariesOver31k);
            }
            else
            {
                printf("%s ", msjCarga);
            }
            break;

        case 11:
            if(!ll_isEmpty(listaEmpleados))
            {
                if(!controller_clearList(listaEmpleados))
                {
                    printf("No se pudo borrar el contenido de la lista\n");
                }
                else
                {
                    system("cls");
                    printf("\n\n*** Lista vaciada con exito ***\n\n");
                }
            }
            else
            {
                printf("%s ", msjCarga);
            }
            break;

        case 12:
            if(!ll_isEmpty(listaEmpleados))
            {
                listaCopia = ll_clone(listaEmpleados);
                if(listaCopia == NULL)
                {
                    printf("Error, no se pudo crear la copia\n");
                }
                else
                {
                    printf("***\n Lista copiada con exito! ***\n");

                    if(ll_containsAll(listaEmpleados, listaCopia) == 1) //corroboro que la copia sea fiel a la original
                    {
                        printf("Copia fiel, ambas listas coinciden!\n");
                    }
                    else if(!ll_containsAll(listaEmpleados, listaCopia))
                    {
                        printf("No coinciden ambas listas\n");
                    }
                    else
                    {
                        printf("No se pudo realizar la operacion\n");
                    }
                }
            }
            else
            {
                printf("%s ", msjCarga);
            }
            break;

        case 13:
            if(!ll_isEmpty(listaEmpleados))
            {
                listaCortada = controller_cutList(listaEmpleados);

                if(listaCortada != NULL)
                {
                    controller_ListEmployee(listaCortada);
                    printf("\n*** Lista cortada con exito! ***\n");
                }
                else
                {
                    printf("\n Error, no se pudo cortar una nueva lista \n");
                }
            }
            else
            {
                printf("%s ", msjCarga);
            }
            break;

        case 14:
            if(!ll_isEmpty(listaEmpleados))
            {
                if(!controller_removeByIndex(listaEmpleados))
                {
                    printf("No se pudo borrar al empleado\n");
                }
                else
                {
                    printf("\n\n*** Corroboracion exitosa. El empleado no se encuentra en la lista original ***\n\n");
                }
            }
            else
            {
                printf("%s ", msjCarga);
            }
            break;

        case 15:
            printf("\n\nAdios!\n\n");
            option = -1;
            break;

        default:
            printf("Error, esa opcion es inexistente. Vuelvalo a intentar \n");
            break;
        }

        system("pause");
    }
    while(option != -1);

    //libero espacio en memoria
    ll_deleteLinkedList(listaEmpleados);
    ll_deleteLinkedList(listSalariesOver31k);
    ll_deleteLinkedList(listaCopia);
    ll_deleteLinkedList(listaCortada);
    free(listaEmpleados);

    return 0;
}




