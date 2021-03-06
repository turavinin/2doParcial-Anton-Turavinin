#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "bibliotecaUTN-validaciones.h"
#include "Controller.h"
#include "LinkedList.h"



int main(void) {
	setbuf(stdout, NULL);

	// Variables
	int opcionMenu;
	int exitoFuncion;

	// LinkedList eLibro
	LinkedList* listaLibros = ll_newLinkedList();

	// Menu
	do
	{
		exitoFuncion = utn_getNumberLimited(&opcionMenu,
				"\n|-------------------------MENU-----------------------------|"
				"\n| 1. Cargar los datos desde archivo.                       |"
				"\n| 2. Ordenar lista ascendentemente seg?n el autor.         |"
				"\n| 3. Imprimir los datos de los libros.                     |"
				"\n| 4. Calcular descuentos.                                  |"
				"\n| 5. Generar archivo (mapeado.csv).                        |"
				"\n| 6. Salir.                                                |"
				"\n|----------------------------------------------------------|"
				"\n| Seleccione una opci?n (ingrese su n?mero): ",
				"\n|         ---- ?LA OPCION INGRESADA ES INCORRECTA! ----    |\n",
				1, 6, 3);

		if(exitoFuncion == 0)
		{
			switch(opcionMenu)
			{
				case 1:
					controller_loadFromText(listaLibros);
					break;
				case 2:
					controller_sortAutores(listaLibros);
					break;
				case 3:
					controller_ListLibros(listaLibros);
					break;
				case 4:
					controller_calcularDescuentos(listaLibros);
					break;
				case 5:
					controller_generarArchivoMapeado(listaLibros);
					break;
			}
		}
	} while(opcionMenu != 6);

    printf("\n|    --- ?GRACIAS POR UTILIZAR EL PROGRAMA! ---     |\n");

	return 0;
}
