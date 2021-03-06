#ifndef ELIBRO_H_
#define ELIBRO_H_
#define MAX_CHAR_ELIBRO 128
#define CANT_PROP_ELIBRO 5


typedef struct
{
	int id;
	char titulo[MAX_CHAR_ELIBRO];
	char autor[MAX_CHAR_ELIBRO];
	float precio;
	int editorialId;
}eLibro;

/** \brief Inicializa a la estructura libro.
 *
 * \return eLibro*
 *
 */
eLibro* eLibro_new();

/** \brief Inicializa con parametros a la estructura libro.
 *
 * \param idStr char*
 * \param tituloStr char*
 * \param autorStr char*
 * \param precioStr char*
 * \param editorialIdStr char*
 * \return eLibro*
 *
 */
eLibro* eLibro_newParametros(char* idStr, char* tituloStr,char* autorStr, char* precioStr, char* editorialIdStr);

/** \brief Le asigna un ID al libro.
 *
 * \param this eLibro*
 * \param id int
 * \return int (-1 => fallo // 0 => exito)
 *
 */
int eLibro_setId(eLibro* this, int id);
/** \brief Obtiene el ID del libro.
 *
 * \param this eLibro*
 * \param id int*

 * \return int (-1 => fallo // 0 => exito)
 *
 */
int eLibro_getId(eLibro* this, int* id);

/** \brief Le asigna un TITULO al libro.
 *
 * \param this eLibro*
 * \param titulo char*
 * \return int (-1 => fallo // 0 => exito)
 *
 */
int eLibro_setTitulo(eLibro* this, char* titulo);
/** \brief Obtiene el TITULO del libro.
 *
 * \param this eLibro*
 * \param titulo char*
 * \return int (-1 => fallo // 0 => exito)
 *
 */
int eLibro_getTitulo(eLibro* this, char* titulo);

/** \brief Le asigna un AUTOR al libro.
 *
 * \param this eLibro*
 * \param autor char*
 * \return int (-1 => fallo // 0 => exito)
 *
 */
int eLibro_setAutor(eLibro* this, char* autor);
/** \brief Obtiene el AUTOR del libro.
 *
 * \param this eLibro*
 * \param autor char*
 * \return int (-1 => fallo // 0 => exito)
 *
 */
int eLibro_getAutor(eLibro* this, char* autor);

/** \brief Le asigna un PRECIO al libro.
 *
 * \param this eLibro*
 * \param precio float
 * \return int (-1 => fallo // 0 => exito)
 *
 */
int eLibro_setPrecio(eLibro* this, float precio);
/** \brief Obtiene el PRECIO del libro.
 *
 * \param this eLibro*
 * \param precio float*
 * \return int (-1 => fallo // 0 => exito)
 *
 */
int eLibro_getPrecio(eLibro* this, float* precio);

/** \brief Le asigna un EDITORIAL ID al libro.
 *
 * \param this eLibro*
 * \param editorialId int
 * \return int (-1 => fallo // 0 => exito)
 *
 */
int eLibro_setEditorialId(eLibro* this, int editorialId);
/** \brief Obtiene el EDITORIAL ID del libro.
 *
 * \param this eLibro*
 * \param editorialId int*
 * \return int (-1 => fallo // 0 => exito)
 *
 */
int eLibro_getEditorialId(eLibro* this, int* editorialId);

/** \brief Obtiene el EDITORIAL ID del libro a partir del NOMBRE DE EDITORIAL.
 *
 * \param editorialNombre char*
 * \param id int*
 * \return int (-1 => fallo // 0 => exito)
 *
 */
int eLibro_getEditorialByName(char* editorialNombre, int* id);
/** \brief Obtiene el NOMBRE DE EDITORIAL del libro a partir del EDITORIAL ID.
 *
 * \param id int
 * \param editorialName char*
 * \return int (-1 => fallo // 0 => exito)
 *
 */
int eLibro_getEditorialNamyById(int id, char* editorialName);

/** \brief Funcion criterio para ordenar la lista de libros segun autor ascendentemente
 *
 * \param autorPrimero void*
 * \param autorSegundo void*
 * \return int (-1 => fallo // 0 => exito)
 *
 */
int eLibro_OrdenaAutorAscen(void* autorPrimero, void* autorSegundo);

/** \brief Funcion criterio para calcular el descuento de los libros
 *
 * \param this eLibro*
 * \return int (-1 => fallo // 0 => exito)
 *
 */
int eLibro_CalculaDescuentos(eLibro* this);

#endif
