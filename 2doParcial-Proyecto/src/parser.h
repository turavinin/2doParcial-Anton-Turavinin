#ifndef PARSER_H_
#define PARSER_H_

/** \brief Parsea los datos los datos de los libros desde el archivo data.csv (modo texto).
 *
 * \param pFile char*
 * \param pListLibros LinkedList*
 * \return int
 *
 */
int parser_eLibroFromText(FILE* pFile , LinkedList* pListLibros);

/** \brief Parsea los datos los datos de los libros al archivo data.csv (modo texto).
 *
 * \param pFile char*
 * \param pFile LinkedList*
 * \return int
 *
 */
int parser_eLibroToText(FILE* pFile, LinkedList* pListLibros);

#endif
