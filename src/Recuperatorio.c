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
	LinkedList* listaLibros = ll_newLinkedList();

	do{
	    printf("-----------------Menu de opciones----------------\n");
	    printf("1. Cargar los datos de los libros desde el archivo data.csv.\n");
	    printf("2. Ordenar los libros por autor\n");
	    printf("3. Mostrar los libros\n");
	    /*
	    printf(". \n");
	    printf(". \n");
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
				libro_loadFromText("data/data.csv", listaLibros);
				break;
			case 2:

				libro_ordenarPorAutor(listaLibros);
				break;
			case 3:
				libro_listarLibros(listaLibros);
				break;
		}
	}while(opcion != 10);

	return 0;
}
