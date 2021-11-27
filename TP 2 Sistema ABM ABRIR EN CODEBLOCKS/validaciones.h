#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED



#endif // VALIDACIONES_H_INCLUDED

/** \brief validates worker's salary
 *
 * \param salary float
 * \return int
 *
 */
int salaryValidation(float salary);


/** \brief validates worker's sector
 *
 * \param sector int
 * \param tamSec int
 * \param sectores[] eSector
 * \return int
 *
 */
int sectorValidation(int empleadoSector, int tamSec, eSector sectores[]);

/** \brief validates id's range (1000 to 2000)
 *
 * \param id int*
 * \return int
 *
 */
int idRangeValidation(int* id);

/** \brief validates if the option to modify is correct
 *
 * \param opcion int*
 * \return int
 *
 */
int validateOptionModifing(int* opcion);

/** \brief validates that seguir char is a proper valid char (s/n)
 *
 * \param seguir char
 * \return int
 *
 */
int validateSeguir(char seguir);

/** \brief valida que sea una cadena de caracteres solo con caracteres y del largo adecuado
 *
 * \param cadena char*
 * \param minimo int
 * \param maximo int
 * \return int
 *
 */
int validarChar(char* cadena, int minimo, int maximo);

/** \brief valida que sea solo letras
 *
 * \param
 * \param
 * \return
 *
 */

int esSoloLetras(char str[]);

/** \brief valida si hay o no numeros en la cadena
 *
 * \param str[] char
 * \return int
 *
 */
int esNumerico(char str[]);
