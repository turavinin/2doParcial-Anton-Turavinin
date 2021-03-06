#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "Controller.h"
#include "bibliotecaUTN-validaciones.h"
#include "eLibro.h"
#include "LinkedList.h"
#include "parser.h"
#include "prints.h"

#define MAX_ERRORES 3
#define MAX_CHAR 200

int controller_ListLibros(LinkedList* pListLibros)
{
	int exito = -1;
	int largoLL = ll_len(pListLibros);

	eLibro* libro;
	int id;
	char titulo[MAX_CHAR];
	char autor[MAX_CHAR];
	float precio;
	int editorialId;
	char editorialNombre[MAX_CHAR];

	prints_Header();
	for(int i = 0; i < largoLL; i++)
	{
		libro = ll_get(pListLibros, i);
		eLibro_getId(libro, &id);
		eLibro_getTitulo(libro, titulo);
		eLibro_getAutor(libro, autor);
		eLibro_getPrecio(libro, &precio);
		eLibro_getEditorialId(libro, &editorialId);
		eLibro_getEditorialNamyById(editorialId, editorialNombre);

		prints_Libro(id, titulo, autor, precio, editorialNombre, 0);
	}

	return exito;
}
int controller_loadFromText(LinkedList* pListLibros)
{
	int exito = -1;
	char path[MAX_CHAR];
	FILE* archivo;

	exito = utn_getPathLimited(path,
							  "| Ingrese el path del archivo (./Datos.csv): ",
							  "| -- Ingreso incorrecto --\n",
							  MAX_CHAR, MAX_ERRORES);

	if(pListLibros != NULL && exito == 0)
	{
		exito = -1;
		archivo = fopen(path, "r");
		if(archivo != NULL)
		{
			exito = parser_eLibroFromText(archivo, pListLibros);
			fclose(archivo);
		}
	}

	if(exito == 0)
		printf("| CARGA REALIZADA CON EXITO ---- \n");
	else
		printf("\n ---- NO FUE POSIBLE CARGAR LOS DATOS ---- \n");


	return exito;
}
int controller_sortAutores(LinkedList* pListLibros)
{
	int exito = -1;

	if(pListLibros != NULL)
	{
		exito = ll_sort(pListLibros, eLibro_OrdenaAutorAscen, 1);
	}
	return exito;
}
int controller_calcularDescuentos(LinkedList* pListLibros)
{
	int exito = -1;
	void (*pFunc);

	if(pListLibros != NULL && ll_len(pListLibros) > 0)
	{
		pFunc = eLibro_CalculaDescuentos;
		ll_map(pListLibros, pFunc);
		exito = 0;
	}

	return exito;
}
int controller_generarArchivoMapeado(LinkedList* pListLibros)
{
	int exito = -1;

	FILE* archivo;
	char path[MAX_CHAR];

	if(pListLibros != NULL && ll_len(pListLibros) > 0)
	{
		exito = utn_getPathLimited(path,
								  "| Ingrese el path para el archivo de mapeo (./mapeado.csv): ",
								  "| -- Ingreso incorrecto --\n",
								  MAX_CHAR, MAX_ERRORES);

		archivo = fopen(path, "w");

		if(exito == 0 && archivo != NULL)
		{
			exito = parser_eLibroToText(archivo, pListLibros);
			fclose(archivo);
		}
	}
	return exito;
}

