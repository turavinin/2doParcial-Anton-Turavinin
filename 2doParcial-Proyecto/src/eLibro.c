#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "bibliotecaUTN-validaciones.h"
#include "eLibro.h"

eLibro* eLibro_new()
{
	eLibro* newLibro = NULL;
	newLibro = (eLibro*) malloc(sizeof(eLibro));

	if(newLibro != NULL)
	{
		eLibro_setId(newLibro, 0);
		eLibro_setTitulo(newLibro, " ");
		eLibro_setAutor(newLibro, " ");
		eLibro_setPrecio(newLibro, 0);
		eLibro_setEditorialId(newLibro, 0);
	}

	return newLibro;
}

eLibro* eLibro_newParametros(char* idStr, char* tituloStr,char* autorStr, char* precioStr, char* editorialIdStr)
{
	eLibro* newLibro = eLibro_new();

	if(newLibro != NULL)
	{
		eLibro_setId(newLibro, atoi(idStr));
		eLibro_setTitulo(newLibro, tituloStr);
		eLibro_setAutor(newLibro, autorStr);
		eLibro_setPrecio(newLibro, atof(precioStr));
		eLibro_setEditorialId(newLibro, atoi(editorialIdStr));
	}

	return newLibro;
}

int eLibro_setId(eLibro* this, int id)
{
	int exito = -1;

	if(this != NULL)
	{
		if(id > 0)
		{
			(*this).id = id;
			exito = 0;
		}
	}

	return exito;
}

int eLibro_getId(eLibro* this, int* id)
{
	int exito = -1;

	if(this != NULL)
	{
		*id = (*this).id;
		exito = 0;
	}

	return exito;
}

int eLibro_setTitulo(eLibro* this, char* titulo)
{
	int exito = -1;

	if(this != NULL && strlen(titulo) > 0)
	{
		strcpy((*this).titulo, titulo);
		exito = 0;
	}

	return exito;
}

int eLibro_getTitulo(eLibro* this, char* titulo)
{
	int exito = -1;

	if(this != NULL)
	{
		strcpy(titulo, (*this).titulo);
		exito = 0;
	}

	return exito;
}

int eLibro_setAutor(eLibro* this, char* autor)
{
	int exito = -1;

	if(this != NULL && strlen(autor) > 0)
	{
		strcpy((*this).autor, autor);
		exito = 0;
	}

	return exito;
}

int eLibro_getAutor(eLibro* this, char* autor)
{
	int exito = -1;

	if(this != NULL)
	{
		strcpy(autor, (*this).autor);
		exito = 0;
	}

	return exito;
}

int eLibro_setPrecio(eLibro* this, float precio)
{
	int exito = -1;

	if(this != NULL && precio > 0)
	{
		(*this).precio = precio;
		exito = 0;
	}

	return exito;
}

int eLibro_getPrecio(eLibro* this, float* precio)
{
	int exito = -1;

	if(this != NULL)
	{
		*precio = (*this).precio;
		exito = 0;
	}

	return exito;
}

int eLibro_setEditorialId(eLibro* this, int editorialId)
{
	int exito = -1;

	if(this != NULL)
	{
		(*this).editorialId = editorialId;
		exito = 0;
	}

	return exito;
}

int eLibro_getEditorialId(eLibro* this, int* editorialId)
{
	int exito = -1;

	if(this != NULL)
	{
		*editorialId = (*this).editorialId;
		exito = 0;
	}

	return exito;
}

int eLibro_getEditorialByName(char* editorialNombre, int* id)
{
	int exito = -1;
	int exitoInterno = -1;
	char auxNameUpper[MAX_CHAR_ELIBRO];
	char editoriales[6][MAX_CHAR_ELIBRO] =
	{
			{"PLANETA"},
			{"SIGLO XXI EDITORES"},
			{"PEARSON"},
			{"MINOTAURO"},
			{"SALAMANDRA"},
			{"PENGUIN BOOKS"}
	};

	if(editorialNombre != NULL)
	{
		exitoInterno = utn_StringToUpper(editorialNombre, auxNameUpper);
		if(exitoInterno == 0)
		{
			for(int i = 0; i < 6; i++)
			{
				if(strcmp(auxNameUpper, editoriales[i]) == 0)
				{
					*id = i + 1;
					exito = 0;
					break;
				}
			}
		}
	}

	return exito;
}

int eLibro_getEditorialNamyById(int id, char* editorialName)
{
	int exito = -1;
	char editoriales[6][MAX_CHAR_ELIBRO] =
	{
			{"PLANETA"},
			{"SIGLO XXI EDITORES"},
			{"PEARSON"},
			{"MINOTAURO"},
			{"SALAMDRA"},
			{"PENGUIN BOOKS"}
	};

	for(int i = 0; i < 6; i++)
	{
		if(i + 1 == id)
		{
			strcpy(editorialName, editoriales[i]);
			exito = 0;
		}
	}

	return exito;
}

int eLibro_OrdenaAutorAscen(void* autorPrimero, void* autorSegundo)
{
	int exito = -1;

	if(strcmp((*(eLibro*)autorPrimero).autor, (*(eLibro*)autorSegundo).autor) > 0)
	{
		exito = 1;
	}

	return exito;
}


int eLibro_CalculaDescuentos(eLibro* this)
{
	int exito = -1;
	int idEditoarial;

	if(this != NULL)
	{
		idEditoarial = (*this).editorialId;
		switch(idEditoarial)
		{
		case 1:
			if((*this).precio >= 300)
				(*this).precio = (*this).precio - ((*this).precio * 0.20);
			break;
		case 2:
			if((*this).precio <= 200)
				(*this).precio = (*this).precio - ((*this).precio * 0.10);
			break;
		}
	}

	return exito;
}
