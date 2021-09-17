#include <stdio.h>
#include <stdlib.h>
#include "headMenuCalculadora.h"

//Mi menu va a recibir por parametros A y B de main y le asigno valores desde el puntero.
int menu(int* a, int* b, int* flagMenuConNumeros)
{
    int opcion = 0;

    if(*flagMenuConNumeros)
    {
        system("cls");
        printf("Bienvenido/a a mi primer calculadora en C\n\n");
        printf("1. Ingresar 1er operando. Usted ingreso: %d \n", *a);
        printf("2. Ingresar 2do operando. Usted ingreso: %d \n", *b);
        printf("3. Calcular todas las operaciones \n");
            printf("  a. Calcular la suma (%d + %d) \n", *a, *b);
            printf("  b. Calcular la resta (%d - %d) \n",  *a, *b);
            printf("  c. Calcular la division (%d / %d) \n",  *a, *b);
            printf("  d. Calcular la multiplicacion (%d * %d) \n",  *a, *b);
            printf("  e. Calcular el factorial (%d!) (%d!) \n",  *a, *b);
        printf("4. Informar todos los resultados \n");
        printf("5. Salir \n\n");
    }
    else{
        system("cls");
        printf("Bienvenido/a a mi primer calculadora en C\n\n");
        printf("1. Ingresar 1er operando (A)\n");
        printf("2. Ingresar 2do operando (B)\n");
        printf("3. Calcular todas las operaciones \n");
            printf("  a. Calcular la suma (A+B) \n");
            printf("  b. Calcular la resta (A-B) \n");
            printf("  c. Calcular la division (A/B) \n");
            printf("  d. Calcular la multiplicacion (A*B) \n");
            printf("  e. Calcular el factorial (A!) (B!) \n");
        printf("4. Informar todos los resultados \n");
        printf("5. Salir \n\n");
    }
    printf("Opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    return opcion;
}
