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

/// @brief Agrega un nuevo libro con parámetros
///
/// @param idStr
/// @param tituloStr
/// @param autorStr
/// @param precioStr
/// @param editorialIdStr
/// @return Un nuevo libro con todos los parámentros que este tenga
eLibro* libro_newParametros(char* idStr, char* tituloStr, char* autorStr, char* precioStr, char* editorialIdStr);

/// @brief Valida el ID
///
/// @param this eLibro* Puntero al array de empleados
/// @param id int id que se validará
/// @return Devuelve 1 si se seteo correctamente, 0 si no
int libro_setId(eLibro* this, int id);

/// @brief Escribe el parámetro del nombre en el argumento anterior
///
/// @param this Puntero al array de empleados
/// @param id int id que se validará
/// @return Devuelve 1 si se agarró el elemento correctamente, 0 si no
int libro_getId(eLibro* this, int* id);

/// @brief Setea el parámetro titulo
///
/// @param this Puntero al array de empleadosPuntero al array de empleados
/// @param titulo char* titulo que se validará
/// @return Devuelve 1 si se seteo correctamente, 0 si no
int libro_setTitulo(eLibro* this, char* titulo);

/// @brief Escribe el parámentro titulo
///
/// @param this Puntero al array de empleados
/// @param titulo char* titulo que se validará
/// @return Devuelve 1 si se agarró el elemento correctamente, 0 si no
int libro_getTitulo(eLibro* this, char* titulo);

/// @brief Setea el parámetro autor
///
/// @param this Puntero al array de empleados
/// @param autor
/// @return Devuelve 1 si se seteo correctamente, 0 si no
int libro_setAutor(eLibro* this, char* autor);

/// @brief Escribe el parámentro autor
///
/// @param this Puntero al array de libros
/// @param autor
/// @return Devuelve 1 si se agarró el elemento correctamente, 0 si no
int libro_getAutor(eLibro* this, char* autor);

/// @brief Setea el parámetro precio
///
/// @param this Puntero al array de libros
/// @param precio
/// @return Devuelve 1 si se seteo correctamente, 0 si no
int libro_setPrecio(eLibro* this, float precio);

/// @brief Escribe el parámentro precio
///
/// @param this Puntero al array de libros
/// @param precio
/// @return Devuelve 1 si se agarró el elemento correctamente, 0 si no
int libro_getPrecio(eLibro* this, float* precio);

/// @brief Setea el parámetro editorialId
///
/// @param this Puntero al array de libros
/// @param editorialId
/// @return Devuelve 1 si se seteo correctamente, 0 si no
int libro_setEditorialId(eLibro* this, char* editorialId);

/// @brief Escribe el parámentro editorialId
///
/// @param this Puntero al array de libros
/// @param editorialId
/// @return Devuelve 1 si se agarró el elemento correctamente, 0 si no
int libro_getEditorialId(eLibro* this, char* editorialId);

/// @brief Lista todos los libros
///
/// @param pArrayListaLibros La lista de libros
/// @return Devuelve 1 si se listó correctamente, 0 si no
int libro_listarLibros(LinkedList* pArrayListaLibros);

/// @brief Realiza descuento del 20% a libros de editorial Planeta cuyo precio sea igual o mayor a 300, o 10% a libros de editorial Siglo XXI Editores cuyo precio sea igual o menor que 200
///
/// @param pArrayListaLibros La lista de libros
/// @return Devuelve 1 si se realizó el descuento correctamente, 0 si no
int libro_descuentoPlanetaSigloXXI(LinkedList* pArrayListaLibros);

/// @brief Carga los datos de los libros desde el archivo data.csv (modo texto).
///
/// @param path La ruta del archivo
/// @param pArrayListaLibros
/// @return La cantidad de libros que se agregaron a la lista
int libro_loadFromText(char* path, LinkedList* pArrayListaLibros);

/// @brief Guarda los elementos de la lista en el archivo mapeados.csv
///
/// @param path
/// @param pArrayListaLibros
/// @return Devuelve 1 si se guardó correctamente, 0 si no
int libro_saveToText(char* path, LinkedList* pArrayListaLibros);

/// @brief Lista solo los libros que sean de la editorial Minotauro
///
/// @param pArrayListaLibros
/// @return Devuelve 1 si se listó correctamente, 0 si no
int libro_listaMinotauro(LinkedList* pArrayListaLibros);

/// @brief Guarda los libros de la editorial minotauro en el archivo minotauroLibros.csv
///
/// @param path
/// @param pArrayListaLibros
/// @return Devuelve 1 si se guardó correctamente, 0 si no
int libro_saveMinotauroToText(char* path, LinkedList* pArrayListaLibros);

/// @brief Ordena los libros por autor de manera ascendente
///
/// @param pArrayListaLibros
/// @return Devuelve 1 si se ordenó correctamente, 0 si no
int libro_ordenarPorAutor(LinkedList* pArrayListaLibros);

/// @brief Compara dos autores
///
/// @param libroA void*
/// @param libroB void*
/// @return Devuelve la comparacion de los dos parametros, o devuelve 0 si falla
int ordenarPorAutor(void* libroA, void* libroB);

#endif
