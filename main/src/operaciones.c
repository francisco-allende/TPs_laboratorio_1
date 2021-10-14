#include <stdio.h>
#include <stdlib.h>
#include "headMenuCalculadora.h" //Incluyo mi .h con los prototipos de funciones
#define LLENA 1

void operaciones(int x, int y, int* resultAddition, int* resultSubstract, int* resultMultiplication, float* resultDivision, int* flagDivison, long int* resultFactorizationX, int* flagFactorX, long int* resultFactorizationY, int* flagFactorY)
{
    //3)
    if(resultAddition != NULL)
    {
        *resultAddition = x + y;
    }
    if(resultSubstract != NULL)
    {
        *resultSubstract = x - y;
    }
    if(resultMultiplication != NULL)
    {
        *resultMultiplication = x * y;
    }

    if(resultDivision != NULL && x != 0 && y != 0)
    {
        *resultDivision = (float) x / y;
        *flagDivison = LLENA;

    }
    //Factorizo
    *resultFactorizationX = LLENA;
    if(resultFactorizationX != NULL && x >= 0)
    {
        for(int i=1; i<=x; i++)
        {
            *resultFactorizationX *= i;
        }
        *flagFactorX = LLENA;
    }

    *resultFactorizationY = LLENA;
    if(resultFactorizationY != NULL && y >= 0)
    {
        for(int j=1; j<=y; j++)
        {
            *resultFactorizationY *= j;
        }
        *flagFactorY = LLENA;
    }
}






