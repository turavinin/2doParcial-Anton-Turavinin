#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "prints.h"

/** \brief Imprime por consola el header de la tabla
 *
 * \return void
 *
 */
void prints_Header()
{

	int w[5] = {8, 50, 20, 15, 20};
	printf("\n|%-*s|%-*s|%-*s|%-*s|%-*s|\n", w[0],"ID", w[1],"TITULO", w[2],"AUTOR", w[3],"PRECIO", w[4],"EDITORIAL");
}

/** \brief Imprime empleado con la opci?n de incluir header o no
 *
 * \param id int
 * \param titulo char*
 * \param autor char*
 * \param precio float
 * \param editorial char*
 * \param opcionEncabezado int
 * \return void
 *
 */
void prints_Libro(int id, char* titulo, char* autor, float precio, char* editorial, int opcionEncabezado)
{
	int w[5] = {8, 50, 20, 15, 20};
	if(opcionEncabezado == 1)
	{
		printf("\n|%-*s|%-*s|%-*s|%-*s|%-*s|\n", w[0],"ID", w[1],"TITULO", w[2],"AUTOR", w[3],"PRECIO", w[4],"EDITORIAL");
	}

	printf("|%-*d|%-*s|%-*s|%-*.2f|%-*s|\n", w[0], id, w[1], titulo, w[2], autor, w[3], precio, w[4], editorial);
}
