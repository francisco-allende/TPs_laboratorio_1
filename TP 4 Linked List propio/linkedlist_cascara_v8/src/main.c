/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"


int menu();

int main(void)
{
    char seguir = 's';
    int opcion;

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


    do
    {
        opcion = menu();

        switch(opcion)
        {
        case 1:
            system("cls");
            startTesting(1);  // ll_newLinkedList
            break;

        case 2:
            system("cls");
            startTesting(2);  // ll_len
            break;

        case 3:
            system("cls");
            startTesting(3);  // getNode - test_getNode
            break;

        case 4:
            system("cls");
            startTesting(4);  // addNode - test_addNode
            break;

        case 5:
            system("cls");
            startTesting(5);  // ll_add
            break;

        case 6:
            system("cls");
            startTesting(6);  // ll_get
            break;
        case 7:
            system("cls");
            startTesting(7);  // ll_set
            break;

        case 8:
            system("cls");
            startTesting(8);  // ll_remove
            break;

        case 9:
            system("cls");
            startTesting(9);  // ll_clear
            break;

        case 10:
            system("cls");
            startTesting(10); // ll_deleteLinkedList
            break;

        case 11:
            system("cls");
            startTesting(11); // ll_indexOf
            break;

        case 12:
            system("cls");
            startTesting(12); // ll_isEmpty
            break;

        case 13:
            system("cls");
            startTesting(13); // ll_push
            break;

        case 14:
            system("cls");
            startTesting(14); // ll_pop
            break;

        case 15:
            system("cls");
            startTesting(15); // ll_contains
            break;

        case 16:
            system("cls");
            startTesting(16); // ll_containsAll
            break;

        case 17:
            system("cls");
            startTesting(17); // ll_subList
            break;

        case 18:
            system("cls");
            startTesting(18); // ll_clone
            break;

        case 19:
            system("cls");
            startTesting(19); // ll_sort
            break;

        case 20:
            system("cls");
            seguir = 'n';
            printf("Adios!\n\n");
            break;

        default:
            system("cls");
            printf("Opcion inexistente, vuelva a intentar\n\n");
            break;
        }
    }
    while(seguir == 's');

    return 0;
}

int menu()
{
    int opcion;

    printf("************************************\n");
    printf("******    LinkedList Menu     ******\n");
    printf("***********************************\n\n");

    printf("1) Crear una lista\n");
    printf("2) Obtener la longitud de la lista (la cantidad de elementos)\n");
    printf("3) Obtener un elemento de la lista\n");
    printf("4) Añadir un nodo a la lista\n");
    printf("5) Añadir un nodo a la lista\n");
    printf("6) Obtener un elemento de la lista\n");
    printf("7) Modificar un elemento de la lista\n");
    printf("8) Eliminar un elemento de la lista\n");
    printf("9) Eliminar todos los elementos de la lista\n");
    printf("10) Eliminar todos los elementos y a la lista en si\n");
    printf("11) Buscar el indice de un elemento\n");
    printf("12) Corroborar si la lista esta o no vacia\n");
    printf("13) Inserta un nuevo elemento en la lista en la posicion indicada\n");
    printf("14) Eliminar el elemento de la posicion indicada\n");
    printf("15) Determina si la lista contiene o no el elemento\n");
    printf("16) Determina si todos los elementos de la lista estan en la lista2\n");
    printf("17) Crear lista con nuevos elementos\n");
    printf("18) Clonar lista con nuevos elementos\n");
    printf("19) Ordenar lista\n");
    printf("20) Salir\n\n");

    printf("\n\nMarque la opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

































