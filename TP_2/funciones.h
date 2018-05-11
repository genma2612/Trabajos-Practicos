#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/** \brief Recorre el array y asigna 0 al campo "estado".
 *
 * \param el array se pasa como parametro.
 * \return void
 *
 */
void inicializarPersonasEstado(EPersona[]);

/** \brief Recorre el array y hardcodea datos iniciales.
 *
 * \param el array se pasa como parametro.
 * \return void
 *
 */
void inicializarPersonasHardCode(EPersona[]);

/** \brief Se agrega una persona a la lista.
 *
 * \param el array se pasa como parametro.
 * \return int retorna un cod. para devolver un mensaje.
 *
 */
int agregarPersona(EPersona[]);

/** \brief Obtiene el primer indice libre del array.
 *
 * @param el array se pasa como parametro.
 * @return el primer indice disponible.
 */
int obtenerEspacioLibre(EPersona[]);

/** \brief Obtiene el indice que coincide con el dni pasado por parametro.
 *
 * @param el array se pasa como parametro.
 * @param el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni.
 */
int buscarPorDni(EPersona[], int);

/** \brief Se realiza la baja lógica del item de la lista seleccionado.
 *
 * \param el array se pasa como parametro.
 * \return int retorna un cod. para devolver un mensaje.
 *
 */
int bajaDePersona(EPersona[]);

/** \brief Ordena el array por nombre.
 *
 * \param el array se pasa como parametro.
 * \return void
 *
 */
void ordernarPorNombre(EPersona[]);

/** \brief Recorre el array y lo muestra en pantalla.
 *
 * \param el array se pasa como parametro.
 * \return void
 *
 */
void mostrarListado(EPersona[]);

/** \brief Muestra en pantalla un grafico de barras verticales a partir del rango de las edades.
 *
 * \param el array se pasa como parametro.
 * \return void
 *
 */
void graficarEdades(EPersona[]);

#endif // FUNCIONES_H_INCLUDED
