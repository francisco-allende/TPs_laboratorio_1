#include "dataSectores.h"

#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED

struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} typedef eEmployee;

#endif // EMPLEADOS_H_INCLUDED


/** \brief imprime el array de empleados de forma encolumnada
 *
 * \param lista eEmployee*
 * \param tam int
 * \param pId int*
 * \param sectores[] eSector
 * \param tamSec int
 * \return int
 *
 */
int printEmployees(eEmployee* lista, int tam, int* pId, eSector sectores[], int tamSec);

/** \brief Para indicar que todas las posiciones del array est?n vac?as, esta funci?n pone la bandera
(isEmpty) en TRUE en todas las posiciones del array.
 *
 * \param listalista eEmployee*
 * \param tam int
 * \return int
 *
 */
int initEmployees(eEmployee* lista, int tam);

/** \brief looks for a free position to save new worker's data on the array
 *
 * \param lista eEmployee*
 * \param tam int
 * \return int
 *
 */
int searchFreePosition(eEmployee* lista, int tam);


/** \brief Agrega en un array de empleados existente los valores recibidos como par?metro en la primer posici?n libre.
 *
 * \param lista eEmployee*
 * \param tam int
 * \param indiceLibre int
 * \param pId int*
 * \param tamSec int
 * \param sectores[] eSector
 * \param contador int*
 * \param acumulador float*
 * \return int
 *
 */
int addEmployee(eEmployee* lista, int tam, int indiceLibre, int* pId, int tamSec, eSector sectores[], int* contador, float* acumulador);

/** \brief validates worker's name length (up to 51)
 *
 * \param name char*
 * \return int
 *
 */
int nameLengthValidation(char* name);

/** \brief validates worker's last name length (up to 51)
 *
 * \param lastName char*
 * \return int
 *
 */
int lastNameLengthValidation(char* lastName);


/** \brief Busca un empleado recibiendo como par?metro de b?squeda su Id.
 *
 * \param lista[] eEmployee
 * \param tam int
 * \param id int*
 * \return int
 *
 */
int findEmployeeById(eEmployee* lista, int tam, int* id);


/** \brief Elimina de manera l?gica (isEmpty Flag en 1) un empleado recibiendo como par?metro su Id.
 *
 * \param lista eEmployee*
 * \param tam int
 * \param indice int
 * \param acumulador float*
 * \param contador int*
 * \return int
 *
 */
int removeEmployee(eEmployee* lista, int tam, int indice , float* acumulador, int* contador);


/** \brief prints only one employee with all his charactersitics
 *
 * \param lista eEmployee*
 * \param indice int
 * \param sectores[] eSect
 * \param tamSec int
 * \return int
 *
 */
int printEmployee(eEmployee* lista, int indice, eSector sectores[], int tamSec);


/** \brief modifies up to four characteristics of one worker (name, last name, salary and sector)
 *
 * \param lista eEmployee*
 * \param indice int
 * \param opcion int*
 * \param sectores[] eSector
 * \param tamSec int
 * \param acumulador float*
 * \return int
 *
 */
int modifyEmployee(eEmployee* lista, int indice, int* opcion, eSector sectores[], int tamSec, float* acumulador);


/** \brief saves in memory the worker's name
 *
 * \param auxEmpleado eEmployee
 * \return char
 *
 */
char ingresarNombre(eEmployee auxEmpleado);

/** \brief saves in memory the worker's last name
 *
 * \param auxEmpleado eEmployee
 * \return void
 *
 */
void ingresarApellido(eEmployee auxEmpleado);

/** \brief saves in memory the worker's salary
 *
 * \param auxEmpleado eEmployee
 * \return void
 *
 */
void ingresarSalario(eEmployee auxEmpleado);

/** \brief saves in memory the worker's sector
 *
 * \param
 * \param
 * \return
 *
 */
void ingresarSector(eEmployee auxEmpleado);


/** \brief Ordena el array de empleados por apellido y sector de manera ascendente o descendente.
 *
 * \param lista eEmployee*
 * \param tam int
 * \param opcion int*
 * \return int
 *
 */
int sortEmployees(eEmployee* lista, int tam, int* opcion);


/** \brief checks if there is at list one employee on the list
 *
 * \param lista eEmployee*
 * \param tam int
 * \return int 1 if there's at list one employee, 0 if there's none (the list is empty)
 *
 */
int listHasEmployees(eEmployee* lista, int tam);

/** \brief calculates the average salary for the report
 *
 * \param lista eEmployee*
 * \param tam int
 * \param promedio float*
 * \param acumulador float*
 * \param contador int*
 * \return int
 *
 */
int calculateAverageSalary(eEmployee* lista, int tam, float* promedio, float* acumulador, int* contador);

/** \brief determines if the employee is above or bellow the average salary
 *
 * \param lista eEmployee*
 * \param tam int
 * \param promedio float*
 * \param pId int*
 * \param sectores[] eSector
 * \param tamSec int
 * \return int
 *
 */
int aboveOrBellowAverageSalary(eEmployee* lista, int tam, float* promedio, int* pId, eSector sectores[], int tamSec);

/** \brief prints report measuring average salary, total amount and if the employees is above or bellow average
 *
 * \param lista eEmployee*
 * \param indice int
 * \param pId int*
 * \param sectores[] eSector
 * \param yesOrNot char*
 * \param tamSec int
 * \return int
 *
 */
int printEmployeesBySalary(eEmployee* lista, int indice, int* pId, eSector sectores[], char* yesOrNot, int tamSec);


/** \brief generates the tableText
 *
 * \return void
 *
 */
void tableText();

/** \brief makes console's text green
 *
 * \return void
 *
 */
void greenText();




