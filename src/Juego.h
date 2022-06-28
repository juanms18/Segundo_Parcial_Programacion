/*
 * Juego.h
 *
 *  Created on: 24 jun. 2022
 *      Author: Juan
 */

#ifndef JUEGO_H_
#define JUEGO_H_
#include "LinkedList.h"


typedef struct
{
	int idJuego;
	char nombreJuego[51];
	char empresaJuego[51];
	int genero;

}Juego;



Juego * CargarUnJuego(int idJueo ,  int genero , char * empresaJuego , char* nombreJuego);
Juego * Juego_New();
int Juego_setIdJuego(Juego* this,int idJuego);
int Juego_getIdJuego(Juego* this,int* idJuego);
//int Juego_setIdArcade(Juego* this,int idArcade);
//int Juego_getIdArcade(Juego* this,int* idArcade);
int Juego_setGenero(Juego* this,int genero);
int Juego_getGenero(Juego* this,int* genero);
int Juego_setEmpresa(Juego* this,char* empresa);
int Juego_getEmpresa(Juego* this,char* empresa);
int Juego_setNombreJuego(Juego* this,char* nombre);
int Juego_getNombreJuego(Juego* this,char* nombre);
int Alta_Juego(LinkedList* pArrayListJuego);
int IngresarJuego( int* genero, char * EmpresaDelJuego, char * nombreDelJuego);
Juego* Juego_new();
Juego* Juego_newParametros(int idJuego, int genero, char * empresaDelJuego, char * nombreDelJuego);
void MostrarUnSoloJuego(int idJuego, int genero, char * empresaDelJuego, char * nombreDelJuego);
int Juego_ListarJuego(LinkedList* pArrayListJuego);
int ScanJuegosParaImprimir(LinkedList* pArrayListJuegos, int posicion);
int Juego_BuscarPorId(LinkedList* pArrayListJuego, int id,int* posicion);

#endif /* JUEGO_H_ */
