/*
 * Input.h
 *
 *  Created on: 14 may. 2022
 *      Author: Juan
 */


#ifndef INPUT_H_
#define INPUT_H_



/// @fn int getInt(int*, char*, char*, char, char, int)
/// @brief recibe un numero entero y valida
/// @param pResultado devuelve el numero recibido
/// @param mensaje mensaje solicitando la carga del numero
/// @param mensajeError mensaje informando que el dato ingresado no es un numero o esta fuera de rrango
/// @param minimo rango minimo
/// @param maximo rango maximo
/// @param reintentos cantidad de reintentos
/// @return retorna 0 si no pudo cargar el dato y 1 si lo cargo correctamente.
int getInt(int *pResultado, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos);

/// @fn int validarNumeroEntero(char[], int*)
/// @brief valida que el char ingresado sea un numero y lo devuelve como int
/// @param numero char ingresado
/// @param numerovalido int devuelto al puntero indicado
/// @return retorna 0 si era un caracter y 1 si devolvio correctamente el entero
int validarNumeroEntero(char numero[] , int*numerovalido);



/// @brief Solicita un texto numérico al usuario y lo devuelve (acepta flotantes)
///
/// @param mensaje  Es el mensaje a ser mostrado
/// @param input AArray donde se cargará el texto ingresado
/// @return  1 si el texto contiene solo números y 0 si no lo guardo
int getStringNumerosFlotantes(char mensaje[],char mensajeError[],float *numeroFlotante ,int reintentos);

/// @brief Verifica si el valor recibido es numérico aceptando flotantes
///
/// @param str Array con la cadena a ser analizada
/// @return 1 si es númerico y 0 si no lo es
int esNumericoFlotante(char str[]);

/// @brief Solicita un string y valida
///
/// @param mensaje Es el mensaje a ser mostrado para solicitar el dato
/// @param errorNumericoMensaje Es el mensaje a ser mostrado en caso de error de tipo
/// @param errorMensajeLargo  Es el mensaje a ser mostrado en caso de error de longitud
/// @param input Array donde se cargará el texto ingresado
/// @param len  Longitud maxima del texto ingresado
/// @param reintentos indica la cantidad de reintentos ante un error
/// @return  1 si consiguio el String 0 si no
int getStringValidado(char mensaje[],char errorNumericoMensaje[], char errorMensajeLargo[],char input[], int len,int reintentos);


/// @brief Solicita un texto al usuario y lo devuelve
///
/// @param mensaje  mensaje Es el mensaje a ser mostrado
/// @param input  Array donde se cargará el texto ingresado
/// @return  1 si el texto contiene solo letras
int getStringLetras(char mensaje[],char input[]);

/// @brief Solicita un texto al usuario y lo devuelve
///
/// @param mensaje  Es el mensaje a ser mostrado
/// @param input Array donde se cargará el texto ingresado
void getString(char mensaje[],char input[]);

/// @brief   Verifica si el valor recibido contiene solo letras
///
/// @param str  Array con la cadena a ser analizada
/// @return  1 si contiene solo ' ' y letras y 0 si no lo es
int esSoloLetras(char str[]);

/// @brief valida caracteres alfanumericos caracteres alfanumericos
///
/// @param str Array donde se cargará el texto ingresado
/// @return retorna 0 si no es alfanumerica y 1 si es alfanumerica
int esAlfaNumerico(char str[]);


int getStringAlfanumerico(char mensaje[],char input[] , char mensajeError[] ,char mensajeErrorLen[], int reintentos ,int len);

int getEmail(char mensaje[],char errorCaracterDesconocido[], char errorMensajeLargo[],char input[], int len,int reintentos);

int esEmail(char str[]);

int getStringEmail(char mensaje[],char input[]);

int getValidCuit(char mensaje[],char mensajeEerror[], char errorLargo[],char input[], int len,int reintentos);

int getStringNumeros2(char mensaje[],char input[]);

void convertirEnMayuscula (char palabra[] , int len);

int comparar2Strings(char palabra1[], char palabra2[] , int len);

int esAlfaNumerico2(char str[]);

#endif /* INPUT_H_ */


