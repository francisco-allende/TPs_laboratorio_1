/*
 ============================================================================
 Name        : main.c
 Author      : Francisco Allende
 Division    : A
 Materia	 : Laboratorio 1
 Entrega	 : TP 1 en C
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "headMenuCalculadora.h"
#define VACIA 0
#define LLENA 1

int main(){
    int a, b;
    int resultSuma, resultResta, resultMultiplicacion;
    long int resultFactorizacionA, resultFactorizacionB;
    float resultDivision;
    int flagDivisionOk = VACIA;
    int flagFactorAOk= VACIA;
    int flagFactorBOk = VACIA;
    int opcionMenu;
    int flagOpcionUno = VACIA;
    int flagOpcionDos = VACIA;
    int flagOpcionTres = VACIA;
    int flagMenuConNumeros = VACIA;
    char seguir = 's';

    do
    {
        opcionMenu = menu(&a, &b, &flagMenuConNumeros);
        switch(opcionMenu)
        {
            case 1:
                printf("Ingrese su numero A: ");
                fflush(stdin);
                scanf("%d", &a);
                flagOpcionUno = LLENA;
                break;
            case 2:
                if(flagOpcionUno)
                {
                    printf("Ingrese el numero B: ");
                    fflush(stdin);
                    scanf("%d", &b);
                    flagOpcionDos = LLENA;
                    flagMenuConNumeros = LLENA;
                }
                else{
                    printf("Error, Asegurese de haber cargado antes el primer numero \n\n");
                }
                break;
            case 3:
                if(flagOpcionUno && flagOpcionDos)
                {
                    operaciones(a, b, &resultSuma, &resultResta, &resultMultiplicacion, &resultDivision, &flagDivisionOk, &resultFactorizacionA, &flagFactorAOk, &resultFactorizacionB, &flagFactorBOk);
                    flagOpcionTres = LLENA;
                }
                else{
                    printf("Error, Asegurese de antes haber cargado los dos numeros \n\n");
                }
                break;
            case 4:
                if(flagOpcionUno && flagOpcionDos && flagOpcionTres)
                {
                    mostrarResultados(a, b, resultSuma, resultResta, resultMultiplicacion, resultDivision, flagDivisionOk, flagFactorAOk, resultFactorizacionA, flagFactorBOk, resultFactorizacionB);

                    //Vacio banderas para reiniciar el programa
                    flagOpcionUno = VACIA;
                    flagOpcionDos = VACIA;
                    flagOpcionTres = VACIA;
                    flagMenuConNumeros = VACIA;
                }
                else{
                    printf("Error. No se pueden mostrar los resultados si faltan numeros o no se realizaron las operaciones \n\n");
                }
                    break;
            case 5:
                seguir = 'n';
                printf("Adios! \n\n");
                break;
            default:
                printf("Error, esa opcion es inexistente. Vuelvalo a intentar \n");
                break;
        }
        printf("\n");
        system("pause");
    }
    while(seguir == 's');

	return EXIT_SUCCESS;
}




