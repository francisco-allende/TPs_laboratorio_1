#ifndef HEADMENUCALCULADORA_H_INCLUDED
#define HEADMENUCALCULADORA_H_INCLUDED
#endif // HEADMENUCALCULADORA_H_INCLUDED

/** \brief Menu de opciones. Muestra acciones a realizar. Interactua con lo que ingrese el usuario y lo valida.
 *
 * \param a int*    --> Con puntero. El primer numero que el usuario ingresa. Se reutiliza en operaciones y al mostrar resultados.
 * \param b int*    --> Con puntero. El segundo numero que el usuario ingresa. Se reutiliza en operaciones y al mostrar resultados.
 * \param flagMenuConNumeros int* --> Con puntero. 1 si se cargaron ambos numeros y los muestro en el menu, 0 para menu con A & B por default
 * \return int      --> Bandera que retorna la opcion elegida.
 *
 */
int menu(int* a, int* b, int* flagMenuConNumeros);


/** \brief Realiza las 5 operaciones matematicas. En orden: Sumar, restar, multiplicar, dividir y fatorizar. Todos los parametros de tipo resultado llevan punteros.
 *
 * \param x int                            --> Primer numero ingresado por el usuario.
 * \param z int                            --> Segundo numero ingresado por el usuario.
 * \param resultAddition int*              --> Resultado de la suma.
 * \param resultSubstract int*             --> Resultado de la resta.
 * \param resultMultiplication int*        --> Resultado de la multiplicacion.
 * \param resultDivision float*            --> Resultado de la division.
 * \param flagDivision int                 --> Da 1 si es divisible, 0 si no lo es.
 * \param resultFactorizationX long int*   --> Resultado factorizacion de X, el A del main.
 * \param flagFactorX int*                 --> Da 1 si es factorizable, 0 si no lo es
 * \param resultFactorizationY long int*   --> Resultado factorizacion de Y, el B del main.
 * \param flagFactorY int*                 --> Da 1 si es factorizable, 0 si no lo es.
 * \return void
 *
 */
void operaciones(int x, int z, int* resultAddition, int* resultSubstract, int* resultMultiplication, float* resultDivision, int* flagDivision, long int* resultFactorizationX, int* flagFactorX, long int* resultFactorizationY, int* flagFactorY);




/** \brief Para ganar prolijidad en main, el case 4 del switch llama a esta funcion que muestra resultaods
 *
 * \param x int --> Numero A
 * \param y int --> Numero B
 * \param resultAddition int --> Resultado de la suma A + B
 * \param resultSubstract int --> Resultado de la resta A + B
 * \param resultMultiplication int --> Resultado de la multiplicacion A * B
 * \param flagDivisionOk int --> Valida que sea posible la division
 * \param resultDivision float --> Resultado de la division A / B
 * \param flagFactorXOk int --> Valida que sea posible la factorizacion de A, osea X
 * \param resultFactorizationX long int --> Resultado de la factorizacion de A, osea X
 * \param flagFactorYOk int --> Valida que sea posible la factorizacion de B, osea Y
 * \param resultFactorizationY long int --> Resultado de la factorizacion de B, osea Y
 * \return void
 *
 */
void mostrarResultados(int x, int y, int resultAddition, int resultSubstract, int resultMultiplication, int flagDivisionOk, float resultDivision, int flagFactorXOk, long int resultFactorizationX, int flagFactorYOk, long int resultFactorizationY);


