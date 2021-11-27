#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleados.h"
#include "dataWarehouse.h"

#define TAM 10
#define NO 0

char firstNames[TAM][21] =
{
    "Francisco",
    "Martin",
    "Florencia",
    "Lorena",
    "Jose",
    "Lucrecia",
    "Nestor",
    "Ramona",
    "Tamara",
    "Brian"
};

char lastNames[TAM][21] =
{
    "Zelaya",
    "Arruabarrena",
    "Macring",
    "Richimuzzi",
    "Gonzalez",
    "Milstein",
    "Chaicovsky",
    "Alibaba",
    "Zapata",
    "Kardashian"
};

float salaries[TAM] =
{
    55250.25,
    55250.25,
    50725.00,
    75000.60,
    75000.60,
    75000.60,
    120000.10,
    34725.00,
    34725.00,
    45000.50
};

int sectors[TAM] =

{
    111,
    111,
    222,
    333,
    333,
    333,
    444,
    555,
    555,
    666,
};

//for que hardcodea personas. Instancio mis estrucutras y los cargo con mi bbdd.
//uso el contador para validar.
//el id es por referencia para usar el ++. No se porque tiene que estar en ese parentesis si o si Lo declare en main

int hardcodearEmpleados(eEmployee* lista, int tam, int* pId)
{
    int contador = -1;
    if(lista != NULL && tam > 0 && pId != NULL)
    {
        contador = 0;
        for(int i = 0; i < tam; i++)
        {
            lista[i].id = *pId;
            (*pId)++;
            strcpy(lista[i].name, firstNames[i]);
            strcpy(lista[i].lastName, lastNames[i]);
            lista[i].salary = salaries[i];
            lista[i].sector = sectors[i];
            lista[i].isEmpty = NO;
            contador++;
        }
    }

    return contador;
}

