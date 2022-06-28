/*
 * Informes.c
 *
 *  Created on: 27 jun. 2022
 *      Author: Juan
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Arcade.h"
#include "LinkedList.h"
#include "Input.h"
#include "Salon.h"
#include "Juego.h"
#include "Informes.h"
#define RETORNOPOSITIVO 0
#define RETORNONEGATIVO -1
#define REINTENTOS 3
#define MAXCHAR 51
#define MAXSALONES 1000
#define MAXJUEGOS 500
#define MAXARCADE 2000
#define MAXFICHAS 1000
#define MONO 1
#define ESTEREO 2
#define PLATAFORMA 1
#define LABERINTO 2
#define AVENTURA 3
#define OTRO 4

void Menu_informes(LinkedList * pArrayListSalon , LinkedList * pArraylistArcade , LinkedList * pArrayListJuegos)
{
	int opcion;

do{

	if(getInt(&opcion, "\n*****************************************************************************SUBMENU***********************************************************************************\n"
			"1) Listar los salones con más de 4 arcade. Indicando ID de salón, nombre, dirección y tipo de salón.\n"
			"2)Listar los arcade para más de 2 jugadores, indicando ID de arcade, cantidad de jugadores, nombre del juego, su género y nombre del salón al que pertenece. \n"
			"3)Listar toda la información de un salón en específico ingresado por el usuario. Imprimir ID de salón, nombre, tipo y dirección.\n"
			"4) Un salón se encuentra completo si posee al menos 4 juegos del género plataforma, 3 del género laberinto y 5 del género Aventura. Listar los salones que cumplan con este mínimo de requisito.\n"
			"5) Listar todos los arcades de un salón determinado ingresando su ID. Informar nombre y tipo de salón, listar todos los arcade con sus datos junto con el nombre del juego que lo compone.\n"
			"6) Imprimir el salón con más cantidad de arcade, indicando todos los datos del salón y la cantidad de arcade que posee. Ordenado de manera ascendente.\n"
			"7) Listar los arcades que cumplan con sonido MONO y el género de su juego sea PLATAFORMA, informando nombre de juego, género y cantidad de jugadores que soporta el arcade. El listado deberá estar ordenado por nombre de juego.\n"
			"8) Filtro (Filtra la lista sin los arcades de EEUU)\n"
			"9) Volver al menu.\n" ,"Opcion incorrecta!!\n", 1 ,9 , 3)==1)
			{

					switch(opcion)
					{
					case 1:
						if(ListaSalonConMasDeCuatroArcade(pArrayListSalon, pArraylistArcade)==RETORNONEGATIVO)
						{
							puts("No hay salones con mas de 4 Arcade!");
						}


						break;

					case 2:
						if(ArcadeMasDe2Jugadores_ListArcadeConJuegosYSalones(pArraylistArcade,  pArrayListSalon, pArrayListJuegos)==RETORNONEGATIVO)
						{
							puts("No se encontraron arcades para mas de 2 jugadores!!");
							system("pause");
						}
						break;
					case 3:
						if(BuscarSalonPorNombreLieteral(pArrayListSalon)==RETORNONEGATIVO)
						{
							puts("No se encontro el salon ingresado!!");
						}
						break;
					case 4:
						if(ListaSalonCompletos(pArrayListSalon, pArraylistArcade, pArrayListJuegos)==RETORNONEGATIVO)
						{
							puts("No Hay Listado!!");
						}
					break;

					case 5:
						ListaDeArcadesIngresandoIdSalon(pArrayListSalon, pArraylistArcade, pArrayListJuegos);
						break;

					case 6 :
						 CantidadDeArcadesPorSalon(pArrayListSalon, pArraylistArcade);
						break;

					case 7 :
						ListarArcadesConSonidoMonoYGeneroDelJuegoPlataforma(pArraylistArcade, pArrayListJuegos);

						break;
					case 8:
						Arcade_ListArcadeConJuegosEEUU(pArraylistArcade, pArrayListJuegos);
						break;

					}
			}

}while (opcion!=9);

}


int ArcadeMasDe2Jugadores_ListArcadeConJuegosYSalones(LinkedList* pArrayListArcade , LinkedList * pArrayListJuego ,LinkedList* pArrayListSalones )
{
    int retorno = RETORNONEGATIVO;
    int len;

    if(pArrayListArcade!= NULL)
    {
    	len = ll_len(pArrayListArcade);
     	puts("|ID Arcade|CANT DE JUGADORES|NOMBRE DEL JUEGO|     GENERO    |NOMBRE DEL SALON|");

    	for(int i=0;i<len;i++)
    	{

    		retorno = ScanArcadeParaImprimirConJuegosYSalonesMasDe2Jugadores(pArrayListArcade, pArrayListJuego, pArrayListSalones,i);

    	}
    }
    return retorno;
}


int ScanArcadeParaImprimirConJuegosYSalonesMasDe2Jugadores(LinkedList* pArrayListArcade,LinkedList* pArrayListJuego, LinkedList* pArrayListSalones ,  int posicionArcade )
{
	int retorno;
	Arcade* pArcade;
	Arcade auxArcade;
	Juego * pJuego;
	Juego AuxJuego;
	Salon * pSalon;
	Salon Auxsalon;
	char generoChar[MAXCHAR];
	int posicionJuego;
	int posicionSalon;


	if(pArrayListArcade!= NULL && posicionArcade > -1)
	{
		pArcade= (Arcade*)ll_get(pArrayListArcade, posicionArcade);

		if(pArcade!= NULL
				&& Arcade_getIdArcade(pArcade, &auxArcade.idArcade)== RETORNOPOSITIVO
				&&Arcade_getCantidaDeJugadores(pArcade, &auxArcade.cantidadDeJugadores)== RETORNOPOSITIVO
				&& Arcade_getIdJuego(pArcade, &auxArcade.idJuego)==RETORNOPOSITIVO
				&& Arcade_getIdSalon(pArcade, &auxArcade.idSalon)==RETORNOPOSITIVO
				&& auxArcade.cantidadDeJugadores > 2)

		{
			if(Juego_BuscarPorId(pArrayListJuego, auxArcade.idJuego, &posicionJuego)==RETORNOPOSITIVO && Salon_BuscarPorId(pArrayListSalones, auxArcade.idSalon, &posicionSalon)==RETORNOPOSITIVO)
			{
				pSalon = (Salon * ) ll_get(pArrayListSalones , posicionSalon);
				pJuego = (Juego * ) ll_get(pArrayListJuego, posicionJuego);

				if(pJuego != NULL && pSalon != NULL
						&& Juego_getNombreJuego(pJuego, AuxJuego.nombreJuego)==RETORNOPOSITIVO
						&& Juego_getGenero(pJuego, &AuxJuego.genero)==RETORNOPOSITIVO
						&& Salon_getNombre(pSalon, Auxsalon.nombre)==RETORNOPOSITIVO)
				{

					convertirOpcionACadena4(AuxJuego.genero, generoChar, "PLATAFORMA", "LABERINTO", "AVENTURA", "OTRO");
					printf("|  %-6d |        %-8d | %-15s|  %-13s|%-16s|\n "	,auxArcade.idArcade, auxArcade.cantidadDeJugadores,AuxJuego.nombreJuego ,  generoChar , Auxsalon.nombre);
					retorno=RETORNOPOSITIVO;
				}
				else
				{
					retorno=RETORNONEGATIVO;
				}

			}
		}
	}

	return retorno;
}

int BuscarSalonPorNombreLieteral(LinkedList* pArrayListSalon)
{
	int retorno=RETORNONEGATIVO;
	int lenListSalon;
	char auxNombre [MAXCHAR];
	char auxNombreSalon[MAXCHAR];
	Salon * pSalon;



	if(pArrayListSalon!=NULL && getStringValidado("Ingrese el nombre del salon que desea ver:\n", "Solo se admiten letras!\n", "Nombre demasiado largo!\n", auxNombre, MAXCHAR, 3)==1 )
	{
		lenListSalon = ll_len(pArrayListSalon);
		puts("|ID SALON |   NOBRE SALON   |          DIRECCION         |TIPO DE SALON| ");
		for(int i=0; i<lenListSalon ; i++)
		{
			pSalon = (Salon *) ll_get(pArrayListSalon, i);
			if(pSalon!= NULL && Salon_getNombre(pSalon, auxNombreSalon)==RETORNOPOSITIVO && comparar2Strings(auxNombre, auxNombreSalon, MAXCHAR)==RETORNOPOSITIVO)
			{
                ScanSalonParaImprimir(pArrayListSalon, i);
				retorno = RETORNOPOSITIVO;
				//break;  informo si hay mas 2 uno con el mismo nombre
			}
		}
	}
  return retorno;
}



int ListaDeArcadesIngresandoIdSalon( LinkedList * pArrayListSalon , LinkedList* pArrayListArcade , LinkedList* pArrayListJuego )
{
	int posicionArcadeIdSalon;
	int retorno=RETORNONEGATIVO;
	Arcade auxArcade;
	if(pArrayListArcade!= NULL )
	{

		if(getInt(&auxArcade.idSalon, "Ingrese el ID del salon:\n", "Valor ingresado fuera de rango!!\n", 1, MAXSALONES, 4)==1)
		{
			    if(Salon_BuscarPorId(pArrayListSalon,auxArcade.idSalon,&posicionArcadeIdSalon)==RETORNOPOSITIVO)
				{
			    	puts("|ID SALON |   NOBRE SALON   |TIPO DE SALON| ");
			    	ScanSalonParaImprimirNombreYTipo(pArrayListSalon, posicionArcadeIdSalon);
			    	puts("*************************Lista de Arcades que contiene***********************************************");
			    	ListarArcadesConNombreDeJuegosPorIdSalon(auxArcade.idSalon, pArrayListArcade, pArrayListJuego);

					 retorno=RETORNOPOSITIVO;
				}
				else
				{
					puts("no se encontro el ID");
				}
			}


	}
    return retorno;
}



int ScanSalonParaImprimirNombreYTipo(LinkedList* pArrayListSalon, int posicion)
{
	int retorno=RETORNONEGATIVO;
	Salon* pSalon;
	Salon auxSalon;
	char tipoChar[MAXCHAR];
	if(pArrayListSalon!= NULL && posicion > -1)
	{
		pSalon= (Salon*)ll_get(pArrayListSalon, posicion);
		if(pSalon!= NULL
				&& Salon_getId(pSalon, &auxSalon.idSalon)== RETORNOPOSITIVO
				&& Salon_getNombre(pSalon, auxSalon.nombre)== RETORNOPOSITIVO
				&& Salon_getTipo(pSalon, &auxSalon.tipo)== RETORNOPOSITIVO)
		{
			convertirOpcionACadena(auxSalon.tipo, tipoChar, "Shopping", "Local");
			printf("|%5d    | %15s | %10s  |\n "	,auxSalon.idSalon,auxSalon.nombre,tipoChar);
			retorno=RETORNOPOSITIVO;
		}
	}

	return retorno;
}


void ListarArcadesConNombreDeJuegosPorIdSalon(int idSalon, LinkedList* pArrayListArcade , LinkedList * pArraListJuego)
{

	int lenListArcade;
	int auxIdSalon;

	Arcade* pArcade;
	if(pArrayListArcade != NULL && idSalon > -1)
	{
		lenListArcade= ll_len(pArrayListArcade);
		puts("|ID ARCADE|    SONIDO    | NACIONALIDAD |CANTIDAD DE JUGADORES|CANTIDAD DE FICHAS|JUEGO QUE CONTIENE|");
		for(int i =0 ; i<lenListArcade; i++)
		{
			pArcade = (Arcade*)ll_get(pArrayListArcade, i);
			if(pArcade!= NULL && Arcade_getIdSalon(pArcade, &auxIdSalon)==RETORNOPOSITIVO	&& auxIdSalon==idSalon)
			{
				ScanArcadeParaImprimirConJuegos2(pArrayListArcade, pArraListJuego, i);
			}
		}
	}
}

void ScanArcadeParaImprimirConJuegos2(LinkedList* pArrayListArcade,LinkedList* pArrayListJuego,   int posicionArcade )
{

	Arcade* pArcade;
	Arcade auxArcade;
	Juego * pJuego;
	Juego AuxJuego;
	char tipoDeSonidoChar[MAXCHAR];
	char nacionalidadChar[MAXCHAR];
	int posicionJuego;



	if(pArrayListArcade!= NULL && posicionArcade > -1)
	{
		pArcade= (Arcade*)ll_get(pArrayListArcade, posicionArcade);

		if(pArcade!= NULL
				&& Arcade_getIdArcade(pArcade, &auxArcade.idArcade)== RETORNOPOSITIVO
				&& Arcade_getIdSalon(pArcade, &auxArcade.idSalon)==RETORNOPOSITIVO
				&& Arcade_getIdJuego(pArcade, &auxArcade.idJuego)== RETORNOPOSITIVO
				&&Arcade_getTipoDeSonido(pArcade, &auxArcade.tipoDeSonido)== RETORNOPOSITIVO
				&&Arcade_getNacionalidad(pArcade, &auxArcade.nacionalidad)== RETORNOPOSITIVO
				&&Arcade_getCantidaDeJugadores(pArcade, &auxArcade.cantidadDeJugadores)== RETORNOPOSITIVO
				&&Arcade_getCapacidadMaximaDeFichas(pArcade, &auxArcade.capacidadMaximaDeFichas)== RETORNOPOSITIVO)

		{
			if(Juego_BuscarPorId(pArrayListJuego, auxArcade.idJuego, &posicionJuego)==RETORNOPOSITIVO )
			{

				pJuego = (Juego * ) ll_get(pArrayListJuego, posicionJuego);

				if(pJuego != NULL && Juego_getNombreJuego(pJuego, AuxJuego.nombreJuego)==RETORNOPOSITIVO)

				{
					convertirOpcionACadena(auxArcade.tipoDeSonido, tipoDeSonidoChar, "MONO", "ESTEREO");
					convertirOpcionACadena4(auxArcade.nacionalidad, nacionalidadChar, "ESTADOUNIDENSE", "JAPONES", "CHINO","COREANO");


					printf("|%6d   |   %-11s|%14s|        %-10d   |       %-10d | %-16s |\n "	,auxArcade.idArcade, tipoDeSonidoChar,
							nacionalidadChar, auxArcade.cantidadDeJugadores,auxArcade.capacidadMaximaDeFichas ,AuxJuego.nombreJuego );
				}
			}
		}
	}

}

void ListarArcadesConSonidoMonoYGeneroDelJuegoPlataforma(LinkedList * pArrayListArcade , LinkedList * pArrayListJuego)
{
	int lenListArcade;
	int auxIdJuego;
	Arcade* pArcade;
	int auxTipoSonido;
	int lenJuego;
	Juego * pJuego;
	int auxGenero;
	int auxIdJuego2;

	if(pArrayListArcade != NULL && pArrayListJuego !=NULL )
	{
		lenListArcade= ll_len(pArrayListArcade);
		lenJuego = ll_len(pArrayListJuego);
		puts("|ID ARCADE| NOMBRE DEL JUEGO |GENERO DEL JUEGO |CANTIDAD DE JUGADORES|");

		OdenarJuegoPorNombre(pArrayListJuego, 1);

		for(int i =0 ; i<lenJuego; i++)
		{
			pJuego = (Juego*)ll_get(pArrayListJuego, i);
			if(pJuego!= NULL && Juego_getIdJuego(pJuego, &auxIdJuego2)== RETORNOPOSITIVO && Juego_getGenero(pJuego, &auxGenero)==RETORNOPOSITIVO && auxGenero==PLATAFORMA)

			{

				for(int j =0 ; j<lenListArcade; j++)
				{

					pArcade = (Arcade*)ll_get(pArrayListArcade, j);

					if(pArcade!=NULL
							&& Arcade_getIdJuego(pArcade, &auxIdJuego)==RETORNOPOSITIVO
							&& Arcade_getTipoDeSonido(pArcade, &auxTipoSonido)==RETORNOPOSITIVO
							&& auxTipoSonido == MONO
							&& auxIdJuego == auxIdJuego2)
					{
						//
						ScanArcadeParaImprimirConJuegoGeneroyCantidadDeJuegadores(pArrayListArcade, pArrayListJuego, j);
					}
				}

			}
		}
	}
}


int Juego_BuscarJuegosDePlataforma(LinkedList * pArrayListJuego , int idJuego)
{
	int len;
	Juego * pJuego;
	int auxGenero;
	int auxIdJuego;
	int retorno=RETORNONEGATIVO;

	if(pArrayListJuego!=NULL && idJuego>0)
	{
		len = ll_len(pArrayListJuego);

		for(int i =0 ; i<len ; i++)
		{
			pJuego = (Juego*)ll_get(pArrayListJuego , i);
			if(pJuego!=NULL && Juego_getIdJuego(pJuego, &auxIdJuego)== RETORNOPOSITIVO && Juego_getGenero(pJuego, &auxGenero)==RETORNOPOSITIVO && auxIdJuego == idJuego && auxGenero==PLATAFORMA )
			{
					retorno = RETORNOPOSITIVO;
			}
		}
	}
	return retorno;
}

void ScanArcadeParaImprimirConJuegoGeneroyCantidadDeJuegadores(LinkedList* pArrayListArcade,LinkedList* pArrayListJuego,   int posicionArcade )
{

	Arcade* pArcade;
	Arcade auxArcade;
	Juego * pJuego;
	Juego AuxJuego;
	char generoChar[MAXCHAR];
	int posicionJuego;



	if(pArrayListArcade!= NULL && posicionArcade > -1)
	{
		pArcade= (Arcade*)ll_get(pArrayListArcade, posicionArcade);

		if(pArcade!= NULL
				&& Arcade_getIdArcade(pArcade, &auxArcade.idArcade)== RETORNOPOSITIVO
				&& Arcade_getIdJuego(pArcade, &auxArcade.idJuego)== RETORNOPOSITIVO
				&&Arcade_getCantidaDeJugadores(pArcade, &auxArcade.cantidadDeJugadores)== RETORNOPOSITIVO)

		{
			if(Juego_BuscarPorId(pArrayListJuego, auxArcade.idJuego, &posicionJuego)==RETORNOPOSITIVO )
			{
				pJuego = (Juego * ) ll_get(pArrayListJuego, posicionJuego);
				if(pJuego != NULL && Juego_getNombreJuego(pJuego, AuxJuego.nombreJuego)==RETORNOPOSITIVO && Juego_getGenero(pJuego, &AuxJuego.genero)==RETORNOPOSITIVO)
				{

					convertirOpcionACadena4(AuxJuego.genero, generoChar, "PLATAFORMA", "LABERINTO", "AVENTURA","OTRO");
					printf("|    %-5d|%-16s  | %-15s |          %-6d     |\n ",auxArcade.idArcade ,AuxJuego.nombreJuego ,generoChar	, auxArcade.cantidadDeJugadores);
				}
			}
		}
	}

}

int OdenarJuegoPorNombre(LinkedList * pArrayListJuego, int orden)
{
   int retorno = -1;

   retorno = ll_sort(pArrayListJuego, SortJuego_compareByNombre, orden);

   return retorno;
}


int SortJuego_compareByNombre(void* nombreUno, void* nombreDos)
{
	int retorno=-2;
	char auxNombreUno[MAXCHAR];
	char auxNombreDos[MAXCHAR];

	if(nombreUno != NULL && nombreDos!= NULL)
	{
		Juego_getNombreJuego(nombreUno, auxNombreUno);
		Juego_getNombreJuego(nombreDos, auxNombreDos);
		retorno = strncmp(auxNombreUno, auxNombreDos, MAXCHAR);
		if(retorno>0)
		{
			retorno=1;
		}else if(retorno<0)
		{
			retorno=-1;
		}
	}
	return retorno;
}


int ListaSalonConMasDeCuatroArcade(LinkedList* pArrayListSalon , LinkedList* pArrayListArcade)
{
	int len;
	Salon * pSalon;
	int retorno=RETORNONEGATIVO;
	int auxIdSalon;
	int cantidadDeArcadePorSalon;

	if(pArrayListSalon!=NULL )
	{
		len = ll_len(pArrayListSalon);
		puts("|ID SALON |      NOMBRE     |          DIRECCION          |   TIPO   | ");
		for(int i =0 ; i<len ; i++)
		{
			pSalon = (Salon*)ll_get(pArrayListSalon, i);

			if(Salon_getId(pSalon, &auxIdSalon)==RETORNOPOSITIVO
					&& CantidadDeArcadesPorSalonDesdeArcade(pArrayListArcade, auxIdSalon, &cantidadDeArcadePorSalon)==RETORNOPOSITIVO
					&& cantidadDeArcadePorSalon>4)
			{
				ScanSalonParaImprimir(pArrayListSalon,i);
				retorno = RETORNOPOSITIVO;
			}
		}
	}
	return retorno;
}



int ListaSalonCompletos(LinkedList* pArrayListSalon , LinkedList* pArrayListArcade , LinkedList * pArrayListJuego)
{
	int len;
	Salon * pSalon;
	int retorno=RETORNONEGATIVO;
	int auxId;
	int flag = 0;

	if(pArrayListSalon!=NULL )
	{
		len = ll_len(pArrayListSalon);
		puts("|ID SALON |      NOMBRE     |          DIRECCION          |   TIPO   | ");
		for(int i =0 ; i<len ; i++)
		{
			pSalon = (Salon*)ll_get(pArrayListSalon, i);

			if( Salon_getId(pSalon, &auxId)==RETORNOPOSITIVO && VerificarSalonCompletos(pArrayListSalon, pArrayListArcade, pArrayListJuego, auxId)==RETORNOPOSITIVO)
			{
				ScanSalonParaImprimir(pArrayListSalon,i);
				retorno = RETORNOPOSITIVO;
				flag=1;

			}

		}
		if(flag==0)
		{
			puts("No hay salones completos!! ");
		}
	}
	return retorno;
}


int VerificarSalonCompletos(LinkedList* pArrayListSalon , LinkedList* pArrayListArcade , LinkedList * pArrayListJuego , int idSalon)
{
	int len;
	Arcade * pArcade;
	Arcade auxArcade;
	int retorno=RETORNONEGATIVO;
	int verificaPlataforma=0;
	int verificaLaberinto=0;
	int verificaAventura=0;

	if(pArrayListArcade!=NULL )
	{
		len = ll_len(pArrayListArcade);
		for(int i =0 ; i<len ; i++)
		{
			pArcade = (Arcade*)ll_get(pArrayListArcade, i);
			if(pArcade!=NULL && Arcade_getIdSalon(pArcade, &auxArcade.idSalon) == RETORNOPOSITIVO && auxArcade.idSalon == idSalon)
			{
				if(Arcade_getIdJuego(pArcade, &auxArcade.idJuego)==RETORNOPOSITIVO)
				{
					if(VerificarJuegoCompleto(pArrayListJuego, auxArcade.idJuego)== PLATAFORMA)
					{
						verificaPlataforma= verificaPlataforma+ 1;
					}
					if(VerificarJuegoCompleto(pArrayListJuego, auxArcade.idJuego)==LABERINTO)
					{
						verificaLaberinto = verificaLaberinto + 1;
					}
					if(VerificarJuegoCompleto(pArrayListJuego, auxArcade.idJuego)==AVENTURA)
					{
						verificaAventura = verificaAventura + 1;
					}
				}
			}
		}
		if(verificaPlataforma >=4 && verificaLaberinto >=3 && verificaAventura >=5)
		{
			retorno = RETORNOPOSITIVO;
		}
		else
		{
			retorno = -2;
		}

	}
	return retorno;
}

int VerificarJuegoCompleto(LinkedList * pArrayListJuego, int idJuego)
{
	int len;
	Juego * pJuego;
	int auxIdJuego;
	int auxGenero;
	int retorno=RETORNONEGATIVO;
	;

	if(pArrayListJuego!=NULL)
	{
		len=ll_len(pArrayListJuego);
		for(int i=0 ; i<len ; i++)
		{
			pJuego = (Juego *)ll_get(pArrayListJuego, i);
			if(pArrayListJuego != NULL && Juego_getIdJuego(pJuego, &auxIdJuego)==RETORNOPOSITIVO && auxIdJuego==idJuego && Juego_getGenero(pJuego, &auxGenero)==RETORNOPOSITIVO)
			{
				retorno = auxGenero;

			}
		}

	}
	return retorno;
}

int CantidadDeArcadesPorSalon(LinkedList * pArrayListSalon , LinkedList * pArrayListArcade)
{
	int len;
	Salon * pSalon;
	//Salon auxSalon;
	int retorno=RETORNONEGATIVO;
	int auxIdSalon;
	int auxCantidadDeArcades;


	if(pArrayListSalon!=NULL )
	{
		len = ll_len(pArrayListSalon);
		puts("|ID SALON |      NOMBRE     |          DIRECCION            |    TIPO   |CANTIDAD DE ARCADES| ");

			for(int i =0 ; i<len ; i++)
			{
				pSalon = (Salon*)ll_get(pArrayListSalon, i);

				if(Salon_getId(pSalon, &auxIdSalon)==RETORNOPOSITIVO
						&& CantidadDeArcadesPorSalonDesdeArcade(pArrayListArcade, auxIdSalon, &auxCantidadDeArcades)==RETORNOPOSITIVO)
				{
					if(auxCantidadDeArcades)
					{
					ScanSalonParaImprimirConCantidadDeArcades(pArrayListSalon,i,auxCantidadDeArcades);
					retorno = RETORNOPOSITIVO;
					}
				}

			}


	}
	return retorno;
}

//////////////////////////////////////////////

int ScanSalonParaImprimirConCantidadDeArcades(LinkedList* pArrayListSalon, int posicion , int cantidadDeArcades)
{
	int retorno=RETORNONEGATIVO;
	Salon* pSalon;
	Salon auxSalon;
	char tipoChar[MAXCHAR];
	if(pArrayListSalon!= NULL && posicion > -1)
	{
		pSalon= (Salon*)ll_get(pArrayListSalon, posicion);
		if(pSalon!= NULL
				&& Salon_getId(pSalon, &auxSalon.idSalon)== RETORNOPOSITIVO
				&& Salon_getNombre(pSalon, auxSalon.nombre)== RETORNOPOSITIVO
				&& Salon_getDireccion(pSalon, auxSalon.direccion)== RETORNOPOSITIVO
				&& Salon_getTipo(pSalon, &auxSalon.tipo)== RETORNOPOSITIVO)
		{
			convertirOpcionACadena(auxSalon.tipo, tipoChar, "Shopping", "Local");
			printf("|%5d    | %15s | %28s  | %8s  |         %-8d  |\n "	,auxSalon.idSalon,auxSalon.nombre,auxSalon.direccion,tipoChar,cantidadDeArcades);
			retorno=RETORNOPOSITIVO;
		}
	}

	return retorno;
}


int CantidadDeArcadesPorSalonDesdeArcade(LinkedList * pArrayListArcade , int idSalon , int * cantidadDeArcade  )
{
	int lenArcade;
	Arcade * pArcade;
	Arcade auxArcade;
	int retorno=RETORNONEGATIVO;
	int contador=0;

	if(pArrayListArcade!=NULL )
	{
		lenArcade = ll_len(pArrayListArcade);
		for(int i =0 ; i<lenArcade ; i++)
		{
			pArcade = (Arcade*)ll_get(pArrayListArcade, i);
			if(pArcade!=NULL && Arcade_getIdSalon(pArcade, &auxArcade.idSalon) == RETORNOPOSITIVO && auxArcade.idSalon == idSalon)
			{
				contador=contador+1;

			}
		}
		if(contador>0)
		{
			retorno = RETORNOPOSITIVO;
			*cantidadDeArcade = contador;
		}
	}
	return retorno;
}

/*
int OprdemarPorCantidadDeArcadesPorSalonDesdeArcade(LinkedList * pArrayListSalon,  int cantidadDeArcade , int idSalon , int posicionSalon)
{

	return retorno;
}
int CantidadDeArcadesPorSalon(LinkedList * pArrayListSalon , LinkedList * pArrayListArcade)
{
	int len;
	Salon * pSalon;
	Salon * pSalon2
	Salon auxSalon;
	Salon auxSalon2;
	int retorno=RETORNONEGATIVO;
	int auxCantidadDeArcades;
	int auxCantidadDeArcades2;


	if(pArrayListSalon!=NULL )
	{
		len = ll_len(pArrayListSalon);
		puts("|ID SALON |      NOMBRE     |          DIRECCION            |    TIPO   |CANTIDAD DE ARCADES| ");

			for(int i =0 ; i<len ; i++)
			{
				pSalon = (Salon*)ll_get(pArrayListSalon, i);
				pSalon2= (Salon *)ll_get(pArrayListSalon , i+1);

				if(Salon_getId(pSalon, &auxSalon.idSalon)==RETORNOPOSITIVO
						&& CantidadDeArcadesPorSalonDesdeArcade(pArrayListArcade, auxSalon.idSalon, &auxCantidadDeArcades)==RETORNOPOSITIVO
						&&Salon_getId(pSalon2, auxSalon2.idSalon)==RETORNOPOSITIVO
						&& CantidadDeArcadesPorSalonDesdeArcade(pArrayListArcade, auxSalon2.idSalon, &auxCantidadDeArcades2)==RETORNOPOSITIVO)
				{
					sort(pArrayListSalon  , auxSalon.idSalon , auxSalon2.idSalon , auxCantidadDeArcades , auxCantidadDeArcades2);
				}

			}


	}
	return retorno;
}

int sort(LinkedList * pArrayListSalon  , int id1 , int id2, int CantidadDeArcades , int CantidadDeArcades2)
{
	int len;
	Salon * pSalon;
	Salon auxSalon;
	int retorno=RETORNONEGATIVO;

	if(pArrayListSalon!=NULL )
		{
			len = ll_len(pArrayListSalon);

		}
*/

int Filtrar_ArcadePorNacionalidadEstadounidence( void* arcade)
{
	int retorno=-2;
    int auxNacionalidad;

	if(arcade != NULL )
	{
		Arcade_getNacionalidad(arcade, &auxNacionalidad);
		if(auxNacionalidad != 1)
		{
			retorno=1;
		}
	}
	return retorno;
}


int Arcade_ListArcadeConJuegosEEUU(LinkedList* pArrayListArcade , LinkedList * pArrayListJuego )
{
	int retorno = RETORNONEGATIVO;
	int len;

	if(pArrayListArcade!= NULL)
	{
		len = ll_len(pArrayListArcade);
		LinkedList * listasinEEUU = ll_Filt(pArrayListArcade, Filtrar_ArcadePorNacionalidadEstadounidence);

		puts("|ID Arcade | ID SALON | ID JUEGO | TIPO DE SONIDO | NACIONALIDAD |N° JUGADORES|CAP MAX DE FICHAS|  NOMBRE DEL JUEGO  |EMP CREADORA|   GENERO   | ");
		for(int i=0;i<len;i++)
		{
		    	retorno = ScanArcadeParaImprimirConJuegos(listasinEEUU, pArrayListJuego,i);
		}
	}
	return retorno;
}

