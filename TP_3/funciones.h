#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[50];
    char genero[20];
    int duracion;
    char descripcion[512];
    int puntaje;
    char linkImagen[256];
    int idPelicula;
    int estado;
}EMovie;

/**
 *  Agrega una pelicula.
 *  @param movie la estructura a ser agregada.
 *  @return retorna -1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie* pLista, int cantidad);

/** \brief modifica una pelicula.
 *
 * \param pLista EMovie* el puntero al array de peliculas.
 * \param cantidad int array size.
 * \return int retorna valor segun haya o no podido modificar la pelicula.
 *
 */
int modificarPelicula(EMovie* pLista, int cantidad);

/** \brief Borra una pelicula.
 *
 * \param pLista EMovie* el puntero al array de peliculas.
 * \param cantidad int array size.
 * \return int retorna un valor -1 o 0 segun se si el borrado fue exitoso o no.
 *
 */
int borrarPelicula(EMovie* pLista, int cantidad);

/**
 *  \brief Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 */
void generarPagina(EMovie lista[]);

/** \brief Inicializa un array de peliculas.
 *
 * \param pLista EMovie* el puntero al array de peliculas.
 * \param cantidad int array size.
 * \return int retorna un valor -1 o 0 segun el exito de la operacion.
 *
 */
int inicializacionPeliculas(EMovie* pLista, int cantidad);

/** \brief Ingresa una nueva pelicula.
 *
 * \param pLista EMovie* el puntero al array de peliculas.
 * \param cantidad int array size.
 * \param titulo[] char titulo de la pelicula a ingresar.
 * \param genero[] char genero de la pelicula a ingresar.
 * \param duracion int duracion de la pelicula a ingresar.
 * \param descripcion[] char descripcion de la pelicula a ingresar.
 * \param puntaje int puntaje de la pelicula a ingresar.
 * \param linkImagen[] char link de la portada de la pelicula a ingresar.
 * \param indice int indice de la pelicula a ingresar.
 * \return int
 *
 */
int ingresoEstructura(EMovie* pLista, int cantidad, char titulo[], char genero[], int duracion, char descripcion[], int puntaje, char linkImagen[], int indice);

/** \brief Busca una ID en el listado de peliculas.
 *
 * \param pLista EMovie* el puntero al array de peliculas.
 * \param cantidad int array size.
 * \param idABuscar int id a buscar.
 * \return int
 *
 */
int buscarIndiceDeId(EMovie* pLista, int cantidad, int idABuscar);

/** \brief realiza hardcodeo de peliculas iniciales.
 *
 * \param pLista EMovie* el puntero al array de peliculas.
 * \param cantidad int array size.
 * \return void
 *
 */
void primerHC(EMovie* pLista, int cantidad);

/** \brief Busca lugar disponible para agregar una pelicula.
 *
 * \param pLista EMovie* el puntero al array de peliculas.
 * \param cantidad int array size.
 * \return int
 *
 */
int buscarEspacio(EMovie* pLista, int cantidad);

/** \brief genera una ID nueva para el ingreso de una pelicula.
 *
 * \param pLista EMovie* el puntero al array de peliculas.
 * \param cantidad int array size.
 * \return int
 *
 */
int generarIdDisponible(EMovie* pLista, int cantidad);

/** \brief muestra datos del archivo binario. Sirve a modo de comprobacion.
 *
 * \param pLista EMovie* el puntero al array de peliculas.
 * \param cantidad int array size.
 * \return void
 *
 */
void mostrarCargados(EMovie* pLista, int cantidad);

/** \brief Comprueba si existe un archivo binario. Si existe, lo lee. Si no existe, lo crea y le carga datos iniciales.
 *
 * \param pLista EMovie* el puntero al array de peliculas.
 * \return void
 *
 */
void comprobacionEinicializacion(EMovie* pLista);

/** \brief Actualiza el archivo binario luego de una operacion para evitar perdida de datos.
 *
 * \param pLista EMovie* el puntero al array de peliculas.
 * \return void
 *
 */
void actualizarArchivo(EMovie* pLista);

#endif // FUNCIONES_H_INCLUDED
