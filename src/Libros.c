#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "parser.h"
#include "utn.h"

eLibro* libro_new()
{
	return (eLibro*)calloc(1, sizeof(eLibro));
}

eLibro* libro_newParametros(char* idStr, char* tituloStr, char* autorStr, char* precioStr, char* editorialIdStr)
{
	eLibro* auxLibro = libro_new();

	if(auxLibro != NULL)
	{
		int id = atoi(idStr);
		float precio = atof(precioStr);

		libro_setId(auxLibro, id);
		libro_setTitulo(auxLibro, tituloStr);
		libro_setAutor(auxLibro, autorStr);
		libro_setPrecio(auxLibro, precio);
		libro_setEditorialId(auxLibro, editorialIdStr);
	}

	return auxLibro;
}

int libro_setId(eLibro* this, int id)
{
    int retorno = 0;

    if(this != NULL)
    {
        if(id > 0)
        {
            this->id = id;
            retorno = 1;
        }
    }
    return retorno;
}

int libro_getId(eLibro* this, int* id)
{
    int retorno = 0;

    if(this != NULL)
    {
        *id = this->id;
        retorno = 1;
    }
    return retorno;
}

int libro_setTitulo(eLibro* this, char* titulo)
{
	int retorno = 0;

    if(this != NULL && strlen(titulo) != 0)
    {
        strcpy(this->titulo, titulo);
        retorno = 1;
    }

    return retorno;
}

int libro_getTitulo(eLibro* this, char* titulo)
{
	int retorno = 0;

    if(this != NULL)
    {
        strcpy(titulo, this->titulo);
        retorno = 1;
    }

    return retorno;
}

int libro_setAutor(eLibro* this, char* autor)
{
	int retorno = 0;

    if(this != NULL && strlen(autor) != 0)
    {
        strcpy(this->autor, autor);
        retorno = 1;
    }

    return retorno;
}

int libro_getAutor(eLibro* this, char* autor)
{
	int retorno = 0;

    if(this != NULL)
    {
        strcpy(autor, this->autor);
        retorno = 1;
    }

    return retorno;
}

int libro_setPrecio(eLibro* this, float precio)
{
    int retorno = 0;

    if(this != NULL)
    {
        if(precio > 0)
        {
            this->precio = precio;
            retorno = 1;
        }
    }
    return retorno;
}

int libro_getPrecio(eLibro* this, float* precio)
{
    int retorno = 0;

    if(this != NULL)
    {
        *precio = this->precio;
        retorno = 1;
    }
    return retorno;
}

int libro_setEditorialId(eLibro* this, char* editorialId)
{
	int retorno = 0;

    if(this != NULL && strlen(editorialId) != 0)
    {
        strcpy(this->editorialId, editorialId);
        retorno = 1;
    }

    return retorno;
}

int libro_getEditorialId(eLibro* this, char* editorialId)
{
	int retorno = 0;

    if(this != NULL)
    {
        strcpy(editorialId, this->editorialId);
        retorno = 1;
    }

    return retorno;
}

static void libro_listarUnLibro(void* pArrayListaLibros)
{
	eLibro* libroAux = (eLibro*)pArrayListaLibros;
	int auxId;
	char auxTitulo[TITULO_LEN];
	char auxAutor[AUTOR_LEN];
	float auxPrecio;
	char auxIdEditorial[EDITORIAL_LEN];

	if(pArrayListaLibros != NULL)
	{
		libro_getId(libroAux, &auxId);
		libro_getTitulo(libroAux, auxTitulo);
		libro_getAutor(libroAux, auxAutor);
		libro_getPrecio(libroAux, &auxPrecio);
		libro_getEditorialId(libroAux, auxIdEditorial);
		printf("%d   %s \t\t %s \t %.2f \t %s\n", auxId, auxTitulo, auxAutor, auxPrecio, auxIdEditorial);
	}
}

int libro_listarLibros(LinkedList* pArrayListaLibros)
{
	int retorno = 0;

	if(pArrayListaLibros != NULL)
	{
		printf("ID   TITULO \t\t\t\t AUTOR \t PRECIO \t EDITORIAL \n");
		retorno = ll_map(pArrayListaLibros, libro_listarUnLibro);
	}
	else
	{
		printf("No hay libros para mostrar.\n");
	}

	return retorno;
}

static void libro_descuentos(void* pArrayListaLibros)
{
	eLibro* libroAux = (eLibro*)pArrayListaLibros;
	float nuevoPrecio;
	float auxPrecio;
	char auxIdEditorial[EDITORIAL_LEN];
	char edPlaneta[EDITORIAL_LEN] = "PLANETA";
	char edSigloXXI[EDITORIAL_LEN] = "SIGLO XXI EDITORES";

	if(pArrayListaLibros != NULL)
	{
		libro_getPrecio(libroAux, &auxPrecio);
		libro_getEditorialId(libroAux, auxIdEditorial);

		if(auxPrecio >= 300 && stricmp(auxIdEditorial, edPlaneta) == 0)
		{
			nuevoPrecio = auxPrecio * 0.80;
			libro_setPrecio(libroAux, nuevoPrecio);
		}

		if (auxPrecio <= 200 && stricmp(auxIdEditorial, edSigloXXI) == 0)
		{
			nuevoPrecio = auxPrecio * 0.90;
			libro_setPrecio(libroAux, nuevoPrecio);
		}
	}
}

int libro_descuentoPlanetaSigloXXI(LinkedList* pArrayListaLibros)
{
	int retorno = 0;

	if(pArrayListaLibros != NULL)
	{
		retorno = ll_map(pArrayListaLibros, libro_descuentos);
		printf("Descuentos realizados correctamente\n");
	}

	return retorno;
}

int libro_loadFromText(char* path, LinkedList* pArrayListaLibros)
{
    FILE* pFile = fopen(path, "r");
    int retorno = parser_LibrosFromText(pFile, pArrayListaLibros);

    if(pFile != NULL)
    {
        printf("El archivo se carg? correctamente.\n");
        fclose(pFile);
    }
    else
    {
        printf("El archivo no se pudo cargar.\n");
    }

    return retorno;
}

int libro_saveToText(char* path, LinkedList* pArrayListaLibros)
{
	int retorno = 0;
	int largo = ll_len(pArrayListaLibros);
	eLibro* libroAux;
	FILE* pFile = fopen(path, "w");

	if(pFile == NULL)
	{
		printf("Hubo un error y no se pudo guardar el archivo\n");
	}

	fprintf(pFile, "id,titulo,autor,precio,editorialId\n"); //Ser? la cabecera del archivo

	if(pArrayListaLibros != NULL)
	{
		for(int i = 0; i < largo; i++)
		{
			libroAux = (eLibro*)ll_get(pArrayListaLibros, i);
			fprintf(pFile, "%d,%s,%s,%.2f,%s\n", libroAux->id, libroAux->titulo, libroAux->autor, libroAux->precio, libroAux->editorialId);
		}
		printf("Se guard? el archivo con ?xito\n");
		retorno = 1;
	}

	fclose(pFile);
	return retorno;
}

static int libro_soloMinotauro(void* pArrayListaLibros)
{
	eLibro* libroAux = (eLibro*)pArrayListaLibros;
	int retorno = 0;
	int auxId;
	char auxTitulo[TITULO_LEN];
	char auxAutor[AUTOR_LEN];
	float auxPrecio;
	char auxIdEditorial[EDITORIAL_LEN];
	char edMinotauro[EDITORIAL_LEN] = "MINOTAURO";

	if(pArrayListaLibros != NULL)
	{
		libro_getId(libroAux, &auxId);
		libro_getTitulo(libroAux, auxTitulo);
		libro_getAutor(libroAux, auxAutor);
		libro_getPrecio(libroAux, &auxPrecio);
		libro_getEditorialId(libroAux, auxIdEditorial);

		if(stricmp(auxIdEditorial, edMinotauro) == 0)
		{
			printf("%d   %s \t\t %s \t %.2f \t %s\n", auxId, auxTitulo, auxAutor, auxPrecio, auxIdEditorial);
			retorno = 1;
		}
	}
	return retorno;
}

int libro_listaMinotauro(LinkedList* pArrayListaLibros)
{
	int retorno = 0;
	LinkedList* minotauro;

	if(pArrayListaLibros != NULL)
	{
		minotauro = ll_filter(pArrayListaLibros, libro_soloMinotauro);

		if (minotauro != NULL && libro_saveMinotauroToText("data/minotauroLibros.csv", minotauro) == 1)
		{
			retorno = 1;
		}

	}
	else
	{
		printf("No hay libros para mostrar.\n");
	}

	return retorno;
}

int libro_saveMinotauroToText(char* path, LinkedList* pArrayListaLibros)
{
	int retorno = 0;
	int largo = ll_len(pArrayListaLibros);
	char auxIdEditorial[EDITORIAL_LEN];
	char edMinotauro[EDITORIAL_LEN] = "MINOTAURO";
	eLibro* libroAux;
	FILE* pFile = fopen(path, "w");

	if(pFile == NULL)
	{
		printf("Hubo un error y no se pudo guardar el archivo\n");
	}

	fprintf(pFile, "id,titulo,autor,precio,editorialId\n"); //Ser? la cabecera del archivo

	if(pArrayListaLibros != NULL)
	{
		for(int i = 0; i < largo; i++)
		{
			libroAux = (eLibro*)ll_get(pArrayListaLibros, i);
			libro_getEditorialId(libroAux, auxIdEditorial);

			if (stricmp(auxIdEditorial, edMinotauro) == 0)
			{
				fprintf(pFile, "%d,%s,%s,%.2f,%s\n", libroAux->id, libroAux->titulo, libroAux->autor, libroAux->precio, libroAux->editorialId);
			}
		}
		printf("Se guard? el archivo con ?xito.\n");
		retorno = 1;
	}

	fclose(pFile);
	return retorno;


	return retorno;
}

int libro_ordenarPorAutor(LinkedList* pArrayListaLibros)
{
	int retorno = 0;

	if(pArrayListaLibros != NULL)
	{
		ll_sort(pArrayListaLibros, ordenarPorAutor, 1);
		printf("Se ordenaron correctamente los libros \n");
		retorno = 1;
	}
	else
	{
		printf("No hay una lista de libros \n");
	}

	return retorno;
}

int ordenarPorAutor(void* bookA, void* bookB)
{
	int retorno = 0;
	eLibro* libroA;
	eLibro* libroB;

	if((bookA != NULL) && (bookB != NULL))
	{
		libroA = (eLibro*) bookA;
		libroB = (eLibro*) bookB;
		retorno = stricmp(libroA->autor, libroB->autor);
	}

	return retorno;
}
