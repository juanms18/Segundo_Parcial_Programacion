/*
 * CargaDeArchivos.h
 *
 *  Created on: 28 jun. 2022
 *      Author: Juan
 */

#ifndef CARGADEARCHIVOS_H_
#define CARGADEARCHIVOS_H_


int CargarDatosSalon(char* archivo , LinkedList* pArraySalon);
int SalonFromText(FILE* pFile, LinkedList* pArraySalon);
int Salon_guardaSalonCsv(FILE* pFile , LinkedList* pArrayListSalon);
int Salon_saveAsText(char* path , LinkedList* pArrayListSalon);
int CargarDatosArcade(char* archivo , LinkedList* pArrayArcade);
int ArcadeFromText(FILE* pFile, LinkedList* pArrayArcade);
int Arcade_saveAsText(char* path , LinkedList* pArrayListArcade);
int Arcade_guardaArcadeCsv(FILE* pFile , LinkedList* pArrayListSalon);
int CargarDatosJuego(char* archivo , LinkedList* pArrayJuego);
int JuegoFromText(FILE* pFile, LinkedList* pArrayJuego);
int Juego_saveAsText(char* path , LinkedList* pArrayListJuego);
int Juego_guardaArcadeCsv(FILE* pFile , LinkedList* pArrayListJuego);


#endif /* CARGADEARCHIVOS_H_ */
