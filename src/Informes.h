/*
 * Informes.h
 *
 *  Created on: 27 jun. 2022
 *      Author: Juan
 */

#ifndef INFORMES_H_
#define INFORMES_H_

void Menu_informes(LinkedList * pArrayListSalon , LinkedList * pArraylistArcade , LinkedList * pArrayListJuegos);
int ArcadeMasDe2Jugadores_ListArcadeConJuegosYSalones(LinkedList* pArrayListArcade , LinkedList * pArrayListJuego ,LinkedList* pArrayListSalones );
int ScanArcadeParaImprimirConJuegosYSalonesMasDe2Jugadores(LinkedList* pArrayListArcade,LinkedList* pArrayListJuego, LinkedList* pArrayListSalones ,  int posicionArcade );
int BuscarSalonPorNombreLieteral(LinkedList* pArrayListSalon);
int ScanSalonParaImprimirNombreYTipo(LinkedList* pArrayListSalon, int posicion);
int ListaDeArcadesIngresandoIdSalon( LinkedList * pArrayListSalon , LinkedList* pArrayListArcade , LinkedList* pArrayListJuego );
void ScanArcadeParaImprimirConJuegos2(LinkedList* pArrayListArcade,LinkedList* pArrayListJuego,   int posicionArcade );
void ListarArcadesConNombreDeJuegosPorIdSalon(int idSalon, LinkedList* pArrayListArcade , LinkedList * pArraListJuego);
void ListarArcadesConSonidoMonoYGeneroDelJuegoPlataforma(LinkedList * pArrayListArcade , LinkedList * pArrayListJuego);
int Juego_BuscarJuegosDePlataforma(LinkedList * pArrayListJuego , int idJuego);
void ScanArcadeParaImprimirConJuegoGeneroyCantidadDeJuegadores(LinkedList* pArrayListArcade,LinkedList* pArrayListJuego,   int posicionArcade );
int SortJuego_compareByNombre(void* nombreUno, void* nombreDos);
int ListaSalonConMasDeCuatroArcade(LinkedList* pArrayListSalon , LinkedList* pArrayListArcade);
int VerificarJuegoCompleto(LinkedList * pArrayListJuego, int idJuego);
int ListaSalonCompletos(LinkedList* pArrayListSalon , LinkedList* pArrayListArcade , LinkedList * pArrayListJuego);
int ListaSalonCompletos(LinkedList* pArrayListSalon , LinkedList* pArrayListArcade , LinkedList * pArrayListJuego);
int VerificarSalonCompletos(LinkedList* pArrayListSalon , LinkedList* pArrayListArcade , LinkedList * pArrayListJuego , int idSalon);
int OdenarJuegoPorNombre(LinkedList * pArrayListJuego, int orden);
int CantidadDeArcadesPorSalonDesdeArcade(LinkedList * pArrayListArcade , int idSalon , int * cantidadDeArcade  );
int ScanSalonParaImprimirConCantidadDeArcades(LinkedList* pArrayListSalon, int posicion , int cantidadDeArcades);
int CantidadDeArcadesPorSalon(LinkedList * pArrayListSalon , LinkedList * pArrayListArcade);
int Filtrar_ArcadePorNacionalidadEstadounidence( void* arcade);
int Arcade_ListArcadeConJuegosEEUU(LinkedList* pArrayListArcade , LinkedList * pArrayListJuego );
int FiltroEEUU(LinkedList * pArrayListArcade );






#endif /* INFORMES_H_ */
