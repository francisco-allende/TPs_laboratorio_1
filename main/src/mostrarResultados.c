#include <stdio.h>
#include <stdlib.h>
#include "headMenuCalculadora.h"

void mostrarResultados(int x, int y, int resultAddition, int resultSubstract, int resultMultiplication, int flagDivisionOk, float resultDivision, int flagFactorXOk, long int resultFactorizationX, int flagFactorYOk, long int resultFactorizationY)
{
    printf("\nEl resultado de %d + %d es %d \n", x, y, resultAddition);
    printf("El resultado de %d - %d es %d \n", x, y, resultSubstract);
    printf("El resultado de %d * %d es %d \n", x, y, resultMultiplication);

    if(flagDivisionOk)
    {
        printf("El resultado de %d / %d es %.2f \n", x, y, resultDivision);
    }
    else{
        printf("No se puede dividir por cero \n");
    }
    if(flagFactorXOk)
    {
        printf("El factorial de %d es de %ld \n", x, resultFactorizationX);
    }
    else{
            printf("No se pudo realizar la factorizacion de %d \n", x);
    }
    if(resultFactorizationY)
    {
        printf("El factorial de %d es de %ld \n\n", y, resultFactorizationY);
    }
    else{
        printf("No se pudo realizar la factorizacion de %d \n", y);
    }
}






