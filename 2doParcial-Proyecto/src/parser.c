#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "LinkedList.h"
#include "eLibro.h"
#include "parser.h"

int parser_eLibroFromText(FILE* pFile , LinkedList* pListLibros)
{
	int exito = -1;
	int contPropiedades = 0;
	int auxEditorialId;
	char bufferLibro[CANT_PROP_ELIBRO][MAX_CHAR_ELIBRO];
	eLibro* nuevoLibro = NULL;


	fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %[^\n]\n", bufferLibro[0], bufferLibro[1], bufferLibro[2], bufferLibro[3], bufferLibro[4]);
	fflush(stdin);

	while(!feof(pFile))
	{
		contPropiedades = fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %[^\n]\n",
					             bufferLibro[0], bufferLibro[1], bufferLibro[2], bufferLibro[3], bufferLibro[4]);

		if(contPropiedades < CANT_PROP_ELIBRO)
		{
			break;
		}

		nuevoLibro = eLibro_newParametros(bufferLibro[0], bufferLibro[1], bufferLibro[2], bufferLibro[3], "0");
		if(nuevoLibro != NULL &&
		   eLibro_getEditorialByName(bufferLibro[4], &auxEditorialId) == 0 &&
		   eLibro_setEditorialId(nuevoLibro, auxEditorialId) == 0)
		{
			ll_add(pListLibros, nuevoLibro);
		}
	}

	if(ll_len(pListLibros) > 0)
	{
		exito = 0;
	}

	return exito;
}

int parser_eLibroToText(FILE* pFile, LinkedList* pListLibros)
{
	int exito = -1;
	int largoLL = ll_len(pListLibros);

	eLibro* nuevoLibro = NULL;
	int id;
	char titulo[MAX_CHAR_ELIBRO];
	char autor[MAX_CHAR_ELIBRO];
	float precio;
	int editorialId;
	char editorialNombre[MAX_CHAR_ELIBRO];

	if(pFile != NULL && pListLibros != NULL && largoLL > 0)
	{
		fprintf(pFile, "id,titulo,autor,precio,editorialId\n");
		for(int i = 0; i < largoLL; i++)
		{
			nuevoLibro = ll_get(pListLibros, i);
			eLibro_getId(nuevoLibro, &id);
			eLibro_getTitulo(nuevoLibro, titulo);
			eLibro_getAutor(nuevoLibro, autor);
			eLibro_getPrecio(nuevoLibro, &precio);
			eLibro_getEditorialId(nuevoLibro, &editorialId);
			eLibro_getEditorialNamyById(editorialId, editorialNombre);
			fprintf(pFile, "%d, %s, %s, %.1f, %s\n", id, titulo, autor, precio, editorialNombre);
		}
		exito = 0;
	}
	return exito;
}
