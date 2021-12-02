/*
 ============================================================================
 Name        : Recuperatorio.c
 Author      : Carolina Cappato
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Libros.h"

int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	int flagCargarArchivo = 0, flagOrdenarPorAutor = 0, flagDescuento = 0;
	LinkedList* listaLibros = ll_newLinkedList();

	do{
	    printf("-----------------Menu de opciones----------------\n");
	    printf("1. Cargar los datos de los libros desde el archivo \"data.csv\".\n");
	    printf("2. Ordenar los libros por autor (ascendente).\n");
	    printf("3. Mostrar los libros.\n");
	    printf("4. Realizar descuentos.\n");
	    printf("5. Generar archivo \"mapeado.csv\".\n");
	    printf("6. Filtrar solo libros que sean de Editorial Minotauro.\n");
	    printf("7. Generar archivo \"minotauroLibros.csv\".\n");
	    /*
	    printf(". \n");
	    printf(". \n");
	    printf(". \n");
	    printf(". \n");
	    */
	    printf("10. Salir.\n");
	    printf("Elija una opcion: ");
	    scanf("%d", &opcion);

	    switch(opcion)
		{
			case 1:
				if(flagCargarArchivo == 0)
				{
					libro_loadFromText("data/data.csv", listaLibros);
					flagCargarArchivo = 1;
				}
				else
				{
					printf("Ya se realizó la carga.\n");
				}
				break;
			case 2:
				if(flagOrdenarPorAutor == 0)
				{
					libro_ordenarPorAutor(listaLibros);
					flagOrdenarPorAutor = 1;
				}
				else
				{
					printf("Ya se realizó el ordenamiento. \n");
				}
				break;
			case 3:
				libro_listarLibros(listaLibros);
				break;
			case 4:
				if(flagDescuento == 0)
				{
					libro_descuentoPlanetaSigloXXI(listaLibros);
					flagDescuento = 1;
				}
				else
				{
					printf("Ya se realizaron los descuentos. \n");
				}
				break;
			case 5:
				libro_saveToText("data/mapeados.csv", listaLibros);
				break;
			case 6:
				libro_listaMinotauro(listaLibros);
				break;
			case 7:
				libro_saveMinotauroToText("data/minotauroLibros.csv", listaLibros);
				break;
		}
	}while(opcion != 10);

	return 0;
}
