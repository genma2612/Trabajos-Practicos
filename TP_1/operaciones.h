/** \brief Imprime la 1ra opcion segun las siguientes condiciones:
 *         A-Sin numeros ingresados (x) B-Numero entero ingresado C-Numero decimal ingresado.
 *
 * \param int Bandera 1
 * \param float Numero 1
 * \return void
 *
 */
void primeraOpcion(int, float);

/** \brief Imprime la 2da opcion segun las siguientes condiciones:
 *         A-Sin numeros ingresados (y) B-Numero entero ingresado C-Numero decimal ingresado.
 *
 * \param int Bandera 2
 * \param float Numero 2
 * \return void
 *
 */
void segundaOpcion(int, float);

/** \brief Pide un numero float.
 *
 * \param char[] Mensaje con instrucciones al usuario.
 * \return float Numero ingresado por el usuario.
 *
 */
float pedirFloat(char[]);

/** \brief Suma dos numeros N1 y N2 e imprime en pantalla el resultado.
 *
 * \param float N1 ingresado previamente por el usuario.
 * \param float N2 ingresado previamente por el usuario.
 * \return void
 *
 */
void sumar(float, float);

/** \brief Resta dos numeros N1 y N2 e imprime en pantalla el resultado.
 *
 * \param float N1 ingresado previamente por el usuario.
 * \param float N2 ingresado previamente por el usuario.
 * \return void
 *
 */
void restar(float, float);

/** \brief Division entre dos numeros N1 y N2 e impresion en pantalla del resultado.
 *
 * \param float N1 ingresado previamente por el usuario.
 * \param float N2 ingresado previamente por el usuario.
 * \return void
 *
 */
void dividir(float, float);

/** \brief Multiplicacion entre dos numeros N1 y N2 e impresion en pantalla del resultado.
 *
 * \param float N1 ingresado previamente por el usuario.
 * \param float N2 ingresado previamente por el usuario.
 * \return void
 *
 */
void multiplicar(float, float);

/** \brief Calculo del factorial(!) de N1(A) e impresion en pantalla del resultado.
 *
 * \param float N1 ingresado previamente por el usuario.
 * \return void
 *
 */
void factorial(float);

/** \brief Llamado a todas las funciones de operaciones e impresion en pantalla de todos los resultados.
 *
 * \param float N1 ingresado previamente por el usuario.
 * \param float N2 ingresado previamente por el usuario.
 * \return void
 *
 */
void todasLasOperaciones(float, float);


