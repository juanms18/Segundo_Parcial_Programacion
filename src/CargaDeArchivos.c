/*
 * CargaDeArchivos.c
 *
 *  Created on: 28 jun. 2022
 *      Author: Juan
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Salon.h"
#include "LinkedList.h"
#include "Input.h"
#include "Arcade.h"
#include "CargaDeArchivos.h"
#include "Juego.h"
#define RETORNOPOSITIVO 0
#define RETORNONEGATIVO -1
#define MAXCHAR 51

int CargarDatosSalon(char* archivo , LinkedList* pArraySalon)
{
	int retorno=-1;
	FILE *pFile;

	if(archivo != NULL && pArraySalon != NULL)
	{
		pFile = fopen(archivo ,"r");
		if (pFile != NULL)
		{
			retorno = SalonFromText(pFile, pArraySalon);
			fclose(pFile);
		}
		else
		{
				printf("\nEl archivo %s no puede ser abierto" ,archivo);
				Salon_saveAsText(archivo, pArraySalon);
		}


	}
	return retorno;
}

int SalonFromText(FILE* pFile, LinkedList* pArraySalon)
{
	int retorno=RETORNONEGATIVO;

	Salon * pSalon;
	char titulo[200];
	char auxId[MAXCHAR];
	char auxNombre[MAXCHAR];
	char auxTipo[MAXCHAR];
	char auxDireccion[MAXCHAR];
    int retornoScan;

	if(pFile!=NULL && pArraySalon!=NULL)
	{
		fscanf(pFile, "%[^\n]\n" , titulo);
		do
		{
			retornoScan = fscanf(pFile , "%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre  , auxDireccion , auxTipo);
			if(retornoScan==4)
			{
				pSalon = CargarUnSalon(atoi(auxId),  auxNombre ,auxDireccion  ,atoi( auxTipo));

				if(pSalon!=NULL)
				{
					retorno = ll_add(pArraySalon, pSalon);
				}
			}


		}while(!feof(pFile));
	}

	return retorno;

}

int Salon_guardaSalonCsv(FILE* pFile , LinkedList* pArrayListSalon)
{
	int retorno=RETORNONEGATIVO;
	Salon* pSalon;
	Salon salon;
	int lenpArrayList;
	if(pFile != NULL && pArrayListSalon!= NULL)
	{
		lenpArrayList=ll_len(pArrayListSalon);
		fprintf(pFile,"ID SALON,NOMBRE,DIRECCION, TIPO\n ");
		for(int i=0;i<lenpArrayList+1;i++)
		{
			pSalon = (Salon*)ll_get(pArrayListSalon, i);
			if(Salon_getId(pSalon, &salon.idSalon)==RETORNOPOSITIVO
					&& Salon_getNombre(pSalon, salon.nombre)==RETORNOPOSITIVO
					&& Salon_getDireccion(pSalon, salon.direccion)==RETORNOPOSITIVO
					&& Salon_getTipo(pSalon, &salon.tipo)==RETORNOPOSITIVO)
			{
				fprintf(pFile,"%d,%s,%s,%d\n",salon.idSalon , salon.nombre , salon.direccion , salon.tipo);

				retorno=RETORNOPOSITIVO;
			}
		}
	}


	return retorno;
}

int Salon_saveAsText(char* path , LinkedList* pArrayListSalon)
{
	int retorno = RETORNONEGATIVO;
	FILE *pFile;

	if (path != NULL && pArrayListSalon!= NULL)
	{
		pFile = fopen(path, "w+");
		if (pFile != NULL)
		{
			retorno = Salon_guardaSalonCsv(pFile, pArrayListSalon);

			fclose(pFile);
		}
		else
		{
			puts("Error pFile==NULL");
		}
	}

    return retorno;
}

int CargarDatosArcade(char* archivo , LinkedList* pArrayArcade)
{
	int retorno=-1;
	FILE *pFile;

	if(archivo != NULL && pArrayArcade != NULL)
	{
		pFile = fopen(archivo ,"r");
		if (pFile != NULL)
		{
			retorno = ArcadeFromText(pFile, pArrayArcade);
			fclose(pFile);
		}
		else
		{

			printf("\nEl archivo %s no puede ser abierto" ,archivo);
		}

	}
	return retorno;
}

int ArcadeFromText(FILE* pFile, LinkedList* pArrayArcade)
{
	int retorno=RETORNONEGATIVO;

	Arcade* pArcade;
	char titulo[200];
	char auxIdArcade[MAXCHAR];
	char auxIdSalon[MAXCHAR];
	char auxIdJuego[MAXCHAR];
	char auxTipoDeSonido[MAXCHAR];
	char auxNacionalidad[MAXCHAR];
	char auxCantidadDeJugadores[MAXCHAR];
	char auxCapacidadMaximaDeFichas[MAXCHAR];

    int retornoScan;

	if(pFile!=NULL && pArrayArcade!=NULL)
	{
		fscanf(pFile, "%[^\n]\n" , titulo);
		do
		{
			retornoScan = fscanf(pFile , "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxIdArcade , auxIdSalon , auxIdJuego, auxTipoDeSonido, auxNacionalidad, auxCantidadDeJugadores,auxCapacidadMaximaDeFichas);
			if(retornoScan==7)
			{
				pArcade = CargarUnArcade(atoi (auxIdArcade), atoi (auxIdSalon) ,atoi (auxIdJuego), atoi(auxTipoDeSonido), atoi(auxNacionalidad), atoi(auxCantidadDeJugadores),atoi(auxCapacidadMaximaDeFichas));

				if(pArcade!=NULL)
				{
					retorno = ll_add(pArrayArcade, pArcade);
				}
			}


		}while(!feof(pFile));
	}

	return retorno;

}


int Arcade_saveAsText(char* path , LinkedList* pArrayListArcade)
{
	int retorno = RETORNONEGATIVO;
	FILE *pFile;

	if (path != NULL && pArrayListArcade!= NULL)
	{
		pFile = fopen(path, "w+");
		if (pFile != NULL)
		{
			retorno = Arcade_guardaArcadeCsv(pFile, pArrayListArcade);

			fclose(pFile);
		}
		else
		{
			puts("Error pFile==NULL");
		}
	}

    return retorno;
}


int Arcade_guardaArcadeCsv(FILE* pFile , LinkedList* pArrayListSalon)
{
	int retorno=RETORNONEGATIVO;
	Arcade* pArcade;
	Arcade arcade;
	int lenpArrayList;
	if(pFile != NULL && pArrayListSalon!= NULL)
	{
		lenpArrayList=ll_len(pArrayListSalon);
		fprintf(pFile,"ID ARCADE,ID SALON,ID JUEGO,TIPO DE SONIDO,NACIONALIDAD,CANTIDAD DE JUGADORES,MAXIMA CAPACIDAD DE FICHAS\n ");
		for(int i=0;i<lenpArrayList+1;i++)
		{
			pArcade = (Arcade*)ll_get(pArrayListSalon, i);
			if(Arcade_getIdArcade(pArcade, &arcade.idArcade)==RETORNOPOSITIVO
					&& Arcade_getIdSalon(pArcade, &arcade.idSalon)==RETORNOPOSITIVO
					&& Arcade_getIdJuego(pArcade, &arcade.idJuego)==RETORNOPOSITIVO
					&& Arcade_getTipoDeSonido(pArcade, &arcade.tipoDeSonido)==RETORNOPOSITIVO
					&& Arcade_getNacionalidad(pArcade, &arcade.nacionalidad)==RETORNOPOSITIVO
					&& Arcade_getCantidaDeJugadores(pArcade, &arcade.cantidadDeJugadores)==RETORNOPOSITIVO
					&& Arcade_getCapacidadMaximaDeFichas(pArcade, &arcade.capacidadMaximaDeFichas)==RETORNOPOSITIVO)
			{
				fprintf(pFile,"%d,%d,%d,%d,%d,%d,%d\n",arcade.idArcade,arcade.idSalon,arcade.idJuego,arcade.tipoDeSonido,arcade.nacionalidad,arcade.cantidadDeJugadores,arcade.capacidadMaximaDeFichas);

				retorno=RETORNOPOSITIVO;
			}
		}
	}


	return retorno;
}



int CargarDatosJuego(char* archivo , LinkedList* pArrayJuego)
{
	int retorno=-1;
	FILE *pFile;

	if(archivo != NULL && pArrayJuego!= NULL)
	{
		pFile = fopen(archivo ,"r");
		if (pFile != NULL)
		{
			retorno = JuegoFromText(pFile, pArrayJuego);
			fclose(pFile);
		}
		else
		{

			printf("\nEl archivo %s no puede ser abierto" ,archivo);
		}

	}
	return retorno;
}



int JuegoFromText(FILE* pFile, LinkedList* pArrayJuego)
{
	int retorno=RETORNONEGATIVO;

	Juego* pJuego;
	char titulo[200];
	char auxIdJuego[MAXCHAR];
	char auxGenero[MAXCHAR];
	char auxEmpresaJuego[MAXCHAR];
	char auxNombreJuego[MAXCHAR];
    int retornoScan;

	if(pFile!=NULL && pArrayJuego!=NULL)
	{
		fscanf(pFile, "%[^\n]\n" , titulo);
		do
		{
			retornoScan = fscanf(pFile , "%[^,],%[^,],%[^,],%[^\n]\n", auxIdJuego ,  auxGenero , auxEmpresaJuego , auxNombreJuego);
			if(retornoScan==4)
			{
				pJuego = CargarUnJuego(atoi (auxIdJuego), atoi(auxGenero), auxEmpresaJuego , auxNombreJuego);

				if(pJuego!=NULL)
				{
					retorno = ll_add(pArrayJuego, pJuego);
				}
			}


		}while(!feof(pFile));
	}

	return retorno;

}



int Juego_saveAsText(char* path , LinkedList* pArrayListJuego)
{
	int retorno = RETORNONEGATIVO;
	FILE *pFile;

	if (path != NULL && pArrayListJuego!= NULL)
	{
		pFile = fopen(path, "w+");
		if (pFile != NULL)
		{
			retorno = Juego_guardaArcadeCsv(pFile, pArrayListJuego);

			fclose(pFile);
		}
		else
		{
			puts("Error pFile==NULL");
		}
	}

    return retorno;
}


int Juego_guardaArcadeCsv(FILE* pFile , LinkedList* pArrayListJuego)
{
	int retorno=RETORNONEGATIVO;
	Juego* pJuego;
	Juego juego;
	int lenpArrayList;
	if(pFile != NULL && pArrayListJuego!= NULL)
	{
		lenpArrayList=ll_len(pArrayListJuego);
		fprintf(pFile,"ID JUEGO,GENERO,EMPRESA A LA QUE PERTENECE,NOMBRE DEL JUEGO\n");
		for(int i=0;i<lenpArrayList+1;i++)
		{
			pJuego= (Juego*)ll_get(pArrayListJuego, i);
			if(Juego_getIdJuego(pJuego, &juego.idJuego)==RETORNOPOSITIVO
					&& Juego_getGenero(pJuego, &juego.genero)==RETORNOPOSITIVO
					&& Juego_getEmpresa(pJuego, juego.empresaJuego)==RETORNOPOSITIVO
					&& Juego_getNombreJuego(pJuego, juego.nombreJuego)==RETORNOPOSITIVO)
			{
				fprintf(pFile,"%d,%d,%s,%s\n",juego.idJuego,juego.genero,juego.empresaJuego,juego.nombreJuego);

				retorno=RETORNOPOSITIVO;
			}
		}
	}


	return retorno;
}

