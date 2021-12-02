#ifndef LIBROS_H
#define LIBROS_H
#define TITULO_LEN 100
#define AUTOR_LEN 50
#define EDITORIAL_LEN 50

typedef struct{
	int id;
	char titulo[TITULO_LEN];
	char autor[AUTOR_LEN];
	float precio;
	char editorialId[EDITORIAL_LEN];
}eLibro;

/// @brief Almacena un espacio en memoria dinámica para un libro
///
/// @return El libro
eLibro* libro_new();

/// @brief
///
/// @param idStr
/// @param tituloStr
/// @param autorStr
/// @param precioStr
/// @param editorialIdStr
/// @return
eLibro* libro_newParametros(char* idStr, char* tituloStr, char* autorStr, char* precioStr, char* editorialIdStr);

/// @brief
///
/// @param this
/// @param id
/// @return
int libro_setId(eLibro* this, int id);

/// @brief
///
/// @param this
/// @param id
/// @return
int libro_getId(eLibro* this, int* id);

/// @brief
///
/// @param this
/// @param titulo
/// @return
int libro_setTitulo(eLibro* this, char* titulo);

/// @brief
///
/// @param this
/// @param titulo
/// @return
int libro_getTitulo(eLibro* this, char* titulo);

/// @brief
///
/// @param this
/// @param autor
/// @return
int libro_setAutor(eLibro* this, char* autor);

/// @brief
///
/// @param this
/// @param autor
/// @return
int libro_getAutor(eLibro* this, char* autor);

/// @brief
///
/// @param this
/// @param precio
/// @return
int libro_setPrecio(eLibro* this, float precio);

/// @brief
///
/// @param this
/// @param precio
/// @return
int libro_getPrecio(eLibro* this, float* precio);

/// @brief
///
/// @param this
/// @param editorialId
/// @return
int libro_setEditorialId(eLibro* this, char* editorialId);

/// @brief
///
/// @param this
/// @param editorialId
/// @return
int libro_getEditorialId(eLibro* this, char* editorialId);

/// @brief
///
/// @param pArrayListaLibros
/// @return
int libro_listarLibros(LinkedList* pArrayListaLibros);

/// @brief
///
/// @param pArrayListaLibros
/// @return
int libro_descuentoPlanetaSigloXXI(LinkedList* pArrayListaLibros);

/// @brief
///
/// @param path
/// @param pArrayListaLibros
/// @return
int libro_loadFromText(char* path, LinkedList* pArrayListaLibros);

/// @brief
///
/// @param path
/// @param pArrayListaLibros
/// @return
int libro_saveToText(char* path, LinkedList* pArrayListaLibros);

/// @brief
///
/// @param pArrayListaLibros
/// @return
int libro_listaMinotauro(LinkedList* pArrayListaLibros);

/// @brief
///
/// @param path
/// @param pArrayListaLibros
/// @return
int libro_saveMinotauroToText(char* path, LinkedList* pArrayListaLibros);

/// @brief
///
/// @param pArrayListaLibros
/// @return
int libro_ordenarPorAutor(LinkedList* pArrayListaLibros);

/// @brief Compara dos autores
///
/// @param libroA void*
/// @param libroB void*
/// @return Devuelve la comparacion de los dos parametros, o devuelve 0 si falla
int ordenarPorAutor(void* libroA, void* libroB);

#endif
