#ifndef OTRASFUNCIONES_H_
#define OTRASFUNCIONES_H_



#endif /* OTRASFUNCIONES_H_ */


/** \brief Menu principal de opciones
 *
 * \param opcion int*
 * \return int opcion marcada por el usuario
 *
 */
int menu(int* opcion);

/** \brief pregunta por el id del usuario segun la accion a realizar
 *
 * \param id int*
 * \return int si se pudo encontrar al empleado retorna 1
 *                        sino pudo encontrarlo retorna 0
 *
 */
int askForId(int* id);

/** \brief menu del modificador con la opcion a modificar
 *
 * \param opcion int*
 * \return int retorna la opcion marcada que se quiere modificar
 *
 */
int askForOptionToModify(int* opcion);

/** \brief menu para ordenar el listado
 *
 * \param opcion int*
 * \return int retorna la opcion elegida
 *
 */
int subMenu(int* opcion);
