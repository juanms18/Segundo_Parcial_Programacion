/*
 * Arcade.h
 *
 *  Created on: 24 jun. 2022
 *      Author: Juan
 */

#ifndef ARCADE_H_
#define ARCADE_H_
#include "LinkedList.h"

typedef struct
{
	int idSalon;
	int idArcade;
	int idJuego;
	int nacionalidad;
	int tipoDeSonido;
	int cantidadDeJugadores;
	int capacidadMaximaDeFichas;

}Arcade;



Arcade * CargarUnArcade(int idArcade ,int idSalon , int idJuego , int tipoDeSonido , int nacionalidad , int cantidadDeJugadores , int capacidadMaximaDeFichas);
Arcade * Arcade_New();
int Arcade_setIdArcade(Arcade* this, int  idArcade);
int Arcade_getIdArcade(Arcade* this,int* idArcade);
int Arcade_setIdSalon(Arcade* this,int idSalon);
int Arcade_getIdSalon(Arcade* this,int* idSalon);
int Arcade_setIdJuego(Arcade* this,int idJuego);
int Arcade_getIdJuego(Arcade* this,int* idJuego);
int Arcade_setTipoDeSonido(Arcade* this,int tipoDeSonido);
int Arcade_getTipoDeSonido(Arcade* this,int* tipoDeSonido);
int Arcade_setNacionalidad(Arcade* this,int nacionalidad);
int Arcade_getNacionalidad(Arcade* this,int* nacionalidad);
int Arcade_setCantidadDeJugadores(Arcade* this,int cantidadDeJugadores);
int Arcade_getCantidaDeJugadores(Arcade* this,int* cantidadDeJugadores);
int Arcade_setCapacidadMaximaDeFichas(Arcade* this,int cantidadMaximaDeFichas);
int Arcade_getCapacidadMaximaDeFichas(Arcade* this,int* cantidadMaximaDeFichas);
int Alta_Arcade(LinkedList* pArrayListArcade , LinkedList * pArraySalon , LinkedList * pArrayJuego);
int IngresarArcade(int* idSalon , int* idJuego , int* tipoDeSonido , int* nacionalidad, int*cantidadDeJugadores , int* capacidadMaximaDeFichas , LinkedList * pArraySalon , LinkedList * pArrayJuego );
Arcade* Arcade_newParametros(int idArcade, int idSalon , int idJuego , int tipoDeSonido, int nacionalidad , int cantidadDeJuegadores , int capacidadMaximaDeFichas);
Arcade* Arcade_new();
void MostrarUnSoloArcade(int id,  int idSalon , int idJuego , int tipoDeSonido, int nacionalidad , int cantidadDeJuegadores , int capacidadMaximaDeFichas);
void convertirOpcionACadena4(int opcion,  char* tipoChar,char* opcionAsignarA, char*opcionAsignarB, char*opcionAsignarC, char* opcionAsignarD);
int Arcade_modificarArcade(LinkedList* pArrayListArcade , LinkedList* pArrayListJuego );
int Arcade_ListArcade(LinkedList* pArrayListArcade , LinkedList * pArrayJuego );
int ScanArcadeParaImprimir(LinkedList* pArrayListArcade,LinkedList* pArrayListJuego,  int posicion);
int Arcade_editArcade(LinkedList* pArrayListArcade , LinkedList* pArrayListJuego);
int Arcade_BuscarPorId(LinkedList* pArrayArcade, int idArcade,int* posicion);
int Arcade_cambioDeDatos(LinkedList* pArrayListArcade , LinkedList* pArrayJuego,int posicion);
int EliminarArcadePorIdSalon(int idSalon, LinkedList* pArrayListArcade);
void Arcade_delete(Arcade* this);
int Arcade_ListArcadeConJuegos(LinkedList* pArrayListArcade , LinkedList * pArrayListJuego );
int ScanArcadeParaImprimirConJuegos(LinkedList* pArrayListArcade,LinkedList* pArrayListJuego,  int posicionArcade );
int Arcade_ListArcadeConJuegosYSalones(LinkedList* pArrayListArcade , LinkedList * pArrayListJuego ,LinkedList* pArrayListSalones );
int ScanArcadeParaImprimirConJuegosYSalones(LinkedList* pArrayListArcade,LinkedList* pArrayListJuego, LinkedList* pArrayListSalones ,  int posicionArcade );
int EliminarArcadePorId(LinkedList* pArrayListArcade, LinkedList * pArrayListaSalon , LinkedList * pArrayListaJuego);


#endif /* ARCADE_H_ */
