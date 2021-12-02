#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

int parser_LibrosFromText(FILE* pFile, LinkedList* pArrayListaLibros)
{
	eLibro* auxLibro = libro_new();
	int r;
	int i = 0;
	char idAux[10], tituloAux[TITULO_LEN], autorAux[AUTOR_LEN], precioAux[10], editorialIdAux[EDITORIAL_LEN];

	if(pFile == NULL)
	{
		return -1;
	}

	r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idAux, tituloAux, autorAux, precioAux, editorialIdAux);

	while(!feof(pFile))
	{
		r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idAux, tituloAux, autorAux, precioAux, editorialIdAux);
		if(r == 5)
		{
			auxLibro = libro_newParametros(idAux, tituloAux, autorAux, precioAux, editorialIdAux);

			ll_add(pArrayListaLibros, auxLibro);
			i++;
		}
		else
			break;
	}

	printf("Se cargaron %d libros a la lista con exito\n", i);

	return i;
}
