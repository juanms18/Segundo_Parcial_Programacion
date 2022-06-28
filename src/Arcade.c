/*
 * Arcade.c
 *
 *  Created on: 24 jun. 2022
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
#define RETORNOPOSITIVO 0
#define RETORNONEGATIVO -1
#define REINTENTOS 3
#define MAXCHAR 51
#define MAXSALONES 1000
#define MAXJUEGOS 500
#define MAXARCADE 2000
#define MAXFICHAS 1000


static int Arcade_BuscaIdMaximo(LinkedList* pArrayListArcade);

static int Arcade_NuevoIdPartiendoDelMaximo(LinkedList* pArrayListArcade,int* nuevoId);

static int Arcade_NuevoIdPartiendoDelMaximo(LinkedList* pArrayListArcade,int* nuevoId)
{
	int retorno=RETORNONEGATIVO;
	static int id = 0 ;
	static int primeraEntrada = RETORNOPOSITIVO;

	if(pArrayListArcade!= NULL)
	{
		if(primeraEntrada == RETORNOPOSITIVO)
		{
			id = Arcade_BuscaIdMaximo(pArrayListArcade);
			primeraEntrada = RETORNONEGATIVO;;
		}
		*nuevoId=id++;
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}


static int Arcade_BuscaIdMaximo(LinkedList* pArrayListArcade)
{
	Arcade* pArcade;
	int len;
	int maxId;
	int id=0;

	if(pArrayListArcade!= NULL)
	{
		len = ll_len(pArrayListArcade);

		for(int i=0;i<len;i++)
		{
			pArcade= ll_get(pArrayListArcade,i);
			Arcade_getIdArcade(pArcade, &id);
			if (i == 0 || id > maxId)
			{
				maxId = id;
			}
		}
		id = maxId;
	}
	return id;
}





Arcade * CargarUnArcade(int idArcade ,int idSalon , int idJuego , int tipoDeSonido , int nacionalidad , int cantidadDeJugadores , int capacidadMaximaDeFichas)
{
	Arcade * punteroArcade = NULL;
	punteroArcade = Arcade_New();
	if(punteroArcade != NULL &&  idArcade > 0 )
	{
		Arcade_setIdArcade(punteroArcade, idArcade);
		Arcade_setIdSalon(punteroArcade, idSalon);
		Arcade_setIdJuego(punteroArcade, idJuego);
		Arcade_setTipoDeSonido(punteroArcade, tipoDeSonido);
		Arcade_setNacionalidad(punteroArcade, nacionalidad);
		Arcade_setCantidadDeJugadores(punteroArcade, cantidadDeJugadores);
		Arcade_setCapacidadMaximaDeFichas(punteroArcade, capacidadMaximaDeFichas);

	}
	else
	{
		puts("Error Puntero salon");
	}
	return punteroArcade;
}


Arcade * Arcade_New()
{
   return (Arcade*) malloc(sizeof(Arcade));
}



int Arcade_setIdArcade(Arcade* this,int idArcade)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && idArcade>0)
	{
		this->idArcade=idArcade;
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}


int Arcade_getIdArcade(Arcade* this,int* idArcade)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && idArcade>0)
	{
		*idArcade=this->idArcade;
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}

int Arcade_setIdSalon(Arcade* this,int idSalon)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && idSalon>0)
	{
		this->idSalon=idSalon;
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}

int Arcade_getIdSalon(Arcade* this,int* idSalon)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && idSalon>0)
	{
		*idSalon=this->idSalon;
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}

int Arcade_setIdJuego(Arcade* this,int idJuego)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && idJuego>0)
	{
		this->idJuego=idJuego;
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}


int Arcade_getIdJuego(Arcade* this,int* idJuego)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && idJuego>0)
	{
		*idJuego=this->idJuego;
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}

int Arcade_setTipoDeSonido(Arcade* this,int tipoDeSonido)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL)
	{
		this->tipoDeSonido=tipoDeSonido;
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}


int Arcade_getTipoDeSonido(Arcade* this,int* tipoDeSonido)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL )
	{
		*tipoDeSonido=this->tipoDeSonido;
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}



int Arcade_setNacionalidad(Arcade* this,int nacionalidad)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL )
	{
		this->nacionalidad=nacionalidad;
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}


int Arcade_getNacionalidad(Arcade* this,int* nacionalidad)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL )
	{
		*nacionalidad=this->nacionalidad;
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}


int Arcade_setCantidadDeJugadores(Arcade* this,int cantidadDeJugadores)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL)
	{
		this->cantidadDeJugadores=cantidadDeJugadores;
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}


int Arcade_getCantidaDeJugadores(Arcade* this,int* cantidadDeJugadores)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL )
	{
		*cantidadDeJugadores=this->cantidadDeJugadores;
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}


int Arcade_setCapacidadMaximaDeFichas(Arcade* this,int capacidadMaximaDeFichas)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL )
	{
		this->capacidadMaximaDeFichas=capacidadMaximaDeFichas;
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}


int Arcade_getCapacidadMaximaDeFichas(Arcade* this,int* capacidadMaximaDeFichas)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL )
	{
		*capacidadMaximaDeFichas=this->capacidadMaximaDeFichas;
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}



int Alta_Arcade(LinkedList* pArrayListArcade , LinkedList * pArraySalon , LinkedList * pArrayJuego)
{
	int retorno=RETORNONEGATIVO;
	Arcade *  pArcade;
	Arcade auxArcade;

	if(pArrayListArcade!= NULL)
	{
		if(IngresarArcade( &auxArcade.idSalon, &auxArcade.idJuego , &auxArcade.tipoDeSonido , &auxArcade.nacionalidad , &auxArcade.cantidadDeJugadores , &auxArcade.capacidadMaximaDeFichas , pArraySalon , pArrayJuego )==RETORNOPOSITIVO)
		{
			Arcade_NuevoIdPartiendoDelMaximo(pArrayListArcade, &auxArcade.idArcade);
			auxArcade.idArcade++;
			pArcade=Arcade_newParametros(auxArcade.idArcade, auxArcade.idSalon , auxArcade.idJuego , auxArcade.tipoDeSonido ,auxArcade.nacionalidad , auxArcade.cantidadDeJugadores , auxArcade.capacidadMaximaDeFichas);

			if(pArcade!= NULL)
			{

				retorno = ll_add(pArrayListArcade, pArcade);
				MostrarUnSoloArcade(auxArcade.idArcade, auxArcade.idSalon , auxArcade.idJuego , auxArcade.tipoDeSonido ,auxArcade.nacionalidad , auxArcade.cantidadDeJugadores , auxArcade.capacidadMaximaDeFichas);
				retorno=RETORNOPOSITIVO;


			}
		}
	}
	else
	{
		puts("\n\npArrayListSalon==NULL\n");
		retorno=-2;
	}

	return retorno;
}


int IngresarArcade(int* idSalon , int* idJuego , int* tipoDeSonido , int* nacionalidad, int*cantidadDeJugadores , int* capacidadMaximaDeFichas , LinkedList * pArrayListSalon , LinkedList * pArrayListJuego )
{
	int retorno=RETORNONEGATIVO;
	Arcade auxArcade;
	int posicionIdSalon;
	int posicionIdJuego;
	do{
		if(getInt(&auxArcade.idSalon, "Ingrese el ID del salon al que pertenece:\n","Dato ingresado incorrecto!!\n", 1, MAXSALONES, 4)==1
				&& getInt(&auxArcade.idJuego, "Ingrese el ID del juego que contiente:\n", "Dato ingresado incorrecto!!\n", 1, MAXJUEGOS, 4)==1
				&& getInt(&auxArcade.tipoDeSonido, "Ingrese el tipo de sonido correspondiente:\n1 MONO\n2 ESTEREO\n" ,"Dato ingresado incorrecto!!\n", 1, 2, 4)==1
				&& getInt(&auxArcade.nacionalidad, "Ingrese la nacionalidad correspondiente:\n1 ESTADOUNIDENSE\n2 JAPONES\n3 CHINO\n4 COREANO \n", "Dato ingresado incorrecto", 1, 4, 4)==1
				&& getInt(&auxArcade.cantidadDeJugadores, "Ingrese la cantidad de jugadores posibles(minimo 1 maximo 4):\n","Dato ingresado incorrecto!!\n", 1, 4, 4)==1
				&& getInt(&auxArcade.capacidadMaximaDeFichas, "Ingrese la cantidad maxima de fichas para el ARCADE:\n", "Valor ingresado incorrecto!!(minimo 1 maximo 1000)", 1, MAXFICHAS, 4)==1)
		{
			if(Salon_BuscarPorId(pArrayListSalon, auxArcade.idSalon, &posicionIdSalon)!=RETORNONEGATIVO
					&& Juego_BuscarPorId(pArrayListJuego, auxArcade.idJuego, &posicionIdJuego)!=RETORNONEGATIVO)

			{

				*idSalon=auxArcade.idSalon;
				*idJuego=auxArcade.idJuego;
				*tipoDeSonido=auxArcade.tipoDeSonido;
				*nacionalidad=auxArcade.nacionalidad;
				*cantidadDeJugadores=auxArcade.cantidadDeJugadores;
				*capacidadMaximaDeFichas=auxArcade.capacidadMaximaDeFichas;
				retorno=RETORNOPOSITIVO;
			}
			else
			{
				puts("ERROR!! ID de Juegos o ID Salon no existen");
				break;
			}
		}
		else
		{
			puts("Ocurrio un error al cargar los datos, demasiados intentos erroneos!! Vuelva a intentar desde el principio!!");
			system("pause");
			break;
		}
	}while(retorno==RETORNONEGATIVO);

	return retorno;

}


Arcade* Arcade_newParametros(int idArcade, int idSalon , int idJuego , int tipoDeSonido, int nacionalidad , int cantidadDeJuegadores , int capacidadMaximaDeFichas)
{
	Arcade* punteroArcade= NULL;
	punteroArcade= Arcade_new();
	if(punteroArcade!= NULL)
	{
		Arcade_setIdArcade(punteroArcade, idArcade);
		Arcade_setIdSalon(punteroArcade, idSalon);
		Arcade_setIdJuego(punteroArcade, idJuego);
		Arcade_setTipoDeSonido(punteroArcade, tipoDeSonido);
		Arcade_setNacionalidad(punteroArcade, nacionalidad);
		Arcade_setCantidadDeJugadores(punteroArcade, cantidadDeJuegadores);
		Arcade_setCapacidadMaximaDeFichas(punteroArcade, capacidadMaximaDeFichas);
	}
	else
	{
		puts("PunteroPerson == null");
	}

	return punteroArcade;
}



Arcade* Arcade_new()
{
	return (Arcade*) malloc(sizeof(Arcade));
}


void MostrarUnSoloArcade(int id,  int idSalon , int idJuego , int tipoDeSonido, int nacionalidad , int cantidadDeJuegadores , int capacidadMaximaDeFichas)
{
	char tipoDeSonidoChar[MAXCHAR];
	char nacionalidadChar[MAXCHAR];
	convertirOpcionACadena(tipoDeSonido, tipoDeSonidoChar, "MONO", "ESTEREO");
	convertirOpcionACadena4(nacionalidad , nacionalidadChar, "ESTADOUNIDENSE", "JAPONES", "CHINO","COREANO");

	puts("|ID Arcade | ID SALON | ID JUEGO | TIPO DE SONIDO | NACIONALIDAD | CANTIDAD DE JUGADORES| CAPACIDAD MACIMA DE FICHAS| ");
	printf("|%6d    | %8d | %7d  | %14s |%14s| %21d|%26d |\n "	,id,idSalon,idJuego,tipoDeSonidoChar,nacionalidadChar,cantidadDeJuegadores,capacidadMaximaDeFichas);
}

void convertirOpcionACadena4(int opcion,  char* tipoChar,char* opcionAsignarA, char*opcionAsignarB, char*opcionAsignarC, char* opcionAsignarD)
{
	if(opcion>0 && tipoChar != NULL && opcionAsignarA != NULL && opcionAsignarB != NULL && opcionAsignarC != NULL && opcionAsignarD != NULL  )
	{
		switch (opcion)
		{
		case 1:
			strncpy(tipoChar,opcionAsignarA,MAXCHAR);
			break;
		case 2:
			strncpy(tipoChar,opcionAsignarB,MAXCHAR);
			break;
		case 3:
			strncpy(tipoChar,opcionAsignarC,MAXCHAR);
			break;
		case 4:
			strncpy(tipoChar,opcionAsignarD,MAXCHAR);
			break;
		}
	}
}



int Arcade_modificarArcade(LinkedList* pArrayListArcade , LinkedList* pArrayListJuego )
{
	int retorno=RETORNONEGATIVO;
	if(pArrayListArcade!= NULL)
	{
		if(ll_isEmpty(pArrayListArcade)==RETORNOPOSITIVO)
		{

			Arcade_ListArcade(pArrayListArcade , pArrayListJuego);
			retorno=Arcade_editArcade(pArrayListArcade , pArrayListJuego);

		}
		else
		{
			puts("Primero se debe cargar los datos");
			retorno = -2;
		}

	}

	return retorno;
}


int Arcade_ListArcade(LinkedList* pArrayListArcade , LinkedList * pArrayListJuego )
{
    int retorno = RETORNONEGATIVO;
    int len;

    if(pArrayListArcade!= NULL)
    {
    	len = ll_len(pArrayListArcade);

    	puts("|ID Arcade | ID SALON | ID JUEGO | TIPO DE SONIDO | NACIONALIDAD | CANTIDAD DE JUGADORES| CAPACIDAD MAXIMA DE FICHAS| ");

    	for(int i=0;i<len;i++)
    	{
    		retorno = ScanArcadeParaImprimir(pArrayListArcade, pArrayListJuego,i);

    	}
    }
    return retorno;
}


int ScanArcadeParaImprimir(LinkedList* pArrayListArcade,LinkedList* pArrayListJuego,  int posicion)
{
	int retorno=RETORNONEGATIVO;
	Arcade* pArcade;
	Arcade auxArcade;

	char tipoDeSonidoChar[MAXCHAR];
	char nacionalidadChar[MAXCHAR];

	if(pArrayListArcade!= NULL && posicion > -1)
	{
		pArcade= (Arcade*)ll_get(pArrayListArcade, posicion);
		if(pArcade!= NULL
				&& Arcade_getIdArcade(pArcade, &auxArcade.idArcade)== RETORNOPOSITIVO
				&& Arcade_getIdSalon(pArcade, &auxArcade.idSalon)==RETORNOPOSITIVO
				&& Arcade_getIdJuego(pArcade, &auxArcade.idJuego)== RETORNOPOSITIVO
				&&Arcade_getTipoDeSonido(pArcade, &auxArcade.tipoDeSonido)== RETORNOPOSITIVO
				&&Arcade_getNacionalidad(pArcade, &auxArcade.nacionalidad)== RETORNOPOSITIVO
				&&Arcade_getCantidaDeJugadores(pArcade, &auxArcade.cantidadDeJugadores)== RETORNOPOSITIVO
				&&Arcade_getCapacidadMaximaDeFichas(pArcade, &auxArcade.capacidadMaximaDeFichas)== RETORNOPOSITIVO)
		{
			convertirOpcionACadena(auxArcade.tipoDeSonido, tipoDeSonidoChar, "MONO", "ESTEREO");
			convertirOpcionACadena4(auxArcade.nacionalidad, nacionalidadChar, "ESTADOUNIDENSE", "JAPONES", "CHINO","COREANO");
			printf("|%6d    | %8d | %7d  | %14s |%14s| %21d|%26d |\n "	,auxArcade.idArcade, auxArcade.idSalon, auxArcade.idJuego, tipoDeSonidoChar, nacionalidadChar, auxArcade.cantidadDeJugadores,auxArcade.capacidadMaximaDeFichas);
			retorno=RETORNOPOSITIVO;
		}
	}

	return retorno;
}


int Arcade_editArcade(LinkedList* pArrayListArcade , LinkedList* pArrayListJuego)
{
	int posicionArcadeId;
	int retorno=RETORNONEGATIVO;
	Arcade auxArcade;
	if(pArrayListArcade!= NULL )
	{

		if(getInt(&auxArcade.idArcade, "Ingrese el ID del arcade a modificar:\n", "Valor ingresado fuera de rango!!\n", 1, MAXARCADE , 4)==1)
		{

				if(Arcade_BuscarPorId(pArrayListArcade,auxArcade.idArcade,&posicionArcadeId)==RETORNOPOSITIVO)
				{
					 retorno=Arcade_cambioDeDatos(pArrayListArcade,pArrayListJuego,posicionArcadeId);
				}
				else
				{
					puts("no se encontro el ID");
				}

		}
	}
    return retorno;
}


int Arcade_BuscarPorId(LinkedList* pArrayArcade, int idArcade,int* posicion)
{
	int retorno=RETORNONEGATIVO;
	int lenListArcade;
	int auxId;
	Arcade * pArcade;
	if(pArrayArcade!= NULL && idArcade > -1)
	{
		lenListArcade= ll_len(pArrayArcade);
		for(int i = 0 ; i<lenListArcade;i++)
		{
			pArcade = (Arcade*)ll_get(pArrayArcade, i);
			if(pArcade!= NULL
					&& Arcade_getIdArcade(pArcade, &auxId)==RETORNOPOSITIVO
					&& auxId==idArcade)
			{
				*posicion=i;
				retorno=RETORNOPOSITIVO;
				break;
			}
		}
	}

	return retorno;
}


int Arcade_cambioDeDatos(LinkedList* pArrayListArcade , LinkedList* pArrayJuego,int posicion)
{
	int retorno=RETORNOPOSITIVO;
	int opcion;


	Arcade auxArcade;
	Arcade * pArcade;
	pArcade= (Arcade*)ll_get(pArrayListArcade, posicion);
	if(pArcade!= NULL)
	{
		do{
			puts("El Arcade a modificar  es : ");
			puts("|ID Arcade | ID SALON | ID JUEGO | TIPO DE SONIDO | NACIONALIDAD | CANTIDAD DE JUGADORES| CAPACIDAD MACIMA DE FICHAS| ");
			ScanArcadeParaImprimir(pArrayListArcade , pArrayJuego, posicion);
			puts("-------------------------------------------------------------------------------------------------\n");

			if(getInt(&opcion, "Ingrese la Opcion que desea modificar:\n1 Cantidad de Jugadores\n2 Juego que Contiene\n0 Salir\n ", "Dato ingresado es erroneo!\n", 0, 2, 4)==1)
			{
				switch(opcion)
				{
				case 0:
					puts("Saliendo del menu de modificacion\n");
					system("pause");
					retorno=RETORNONEGATIVO;
					break;
				case 1:
					if(getInt(&auxArcade.cantidadDeJugadores, "Ingrese la cantidad de jugadores:\n", "Dato ingresado incorrecto!!\n(minimo 1 maximo 4 )", 1, 4, 4)==1)
					{

						Arcade_setCantidadDeJugadores(pArcade, auxArcade.cantidadDeJugadores);
						retorno=RETORNOPOSITIVO;
						break;
					}
					else
					{
						retorno=RETORNONEGATIVO;
						break;
					}

				case 2:
					Juego_ListarJuego(pArrayJuego);
					if(getInt(&auxArcade.idJuego,"Ingrese el ID del nuevo juego que va a conterner el Arcade:\n","Error! el id no existe" , 1, 1000, 3)==1)
					{
						Arcade_setIdJuego(pArcade, auxArcade.idJuego);
						retorno=RETORNOPOSITIVO;
						break;
					}
					else
					{
						retorno=RETORNONEGATIVO;
						break;
					}

				default :
					retorno=RETORNONEGATIVO;
					puts("Error de opcion\n");

				}

			}


		}while(opcion!=RETORNOPOSITIVO);
	}

	return retorno;
}

int EliminarArcadePorIdSalon(int idSalon, LinkedList* pArrayListArcade)
{
	int retorno=RETORNONEGATIVO;
	int lenListArcade;
	int auxIdSalon;

	Arcade* pArcade;
	if(pArrayListArcade != NULL && idSalon > -1)
	{
		lenListArcade= ll_len(pArrayListArcade);
		for(int i =0 ; i<lenListArcade; i++)
		{
			pArcade = (Arcade*)ll_get(pArrayListArcade, i);
			if(pArcade!= NULL && Arcade_getIdSalon(pArcade, &auxIdSalon)==RETORNOPOSITIVO	&& auxIdSalon==idSalon)
			{
				ll_remove(pArrayListArcade, i);
				Arcade_delete(pArcade);
				retorno=RETORNOPOSITIVO;
			}
		}

	}
	return retorno;
}



void Arcade_delete(Arcade* this)
{
	free(this);
}


int ScanArcadeParaImprimirConJuegos(LinkedList* pArrayListArcade,LinkedList* pArrayListJuego,  int posicionArcade )
{
	int retorno=RETORNONEGATIVO;
	Arcade* pArcade;
	Arcade auxArcade;
	Juego * pJuego;
	Juego AuxJuego;
	char tipoDeSonidoChar[MAXCHAR];
	char nacionalidadChar[MAXCHAR];
	char generoChar[MAXCHAR];
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
			if(Juego_BuscarPorId(pArrayListJuego, auxArcade.idJuego, &posicionJuego)==RETORNOPOSITIVO)
			{
				pJuego = (Juego * ) ll_get(pArrayListJuego, posicionJuego);
				if(pJuego != NULL
						&&Juego_getEmpresa(pJuego, AuxJuego.empresaJuego)==RETORNOPOSITIVO
						&& Juego_getNombreJuego(pJuego, AuxJuego.nombreJuego)==RETORNOPOSITIVO
						&& Juego_getGenero(pJuego, &AuxJuego.genero)==RETORNOPOSITIVO)
				{


					convertirOpcionACadena(auxArcade.tipoDeSonido, tipoDeSonidoChar, "MONO", "ESTEREO");
					convertirOpcionACadena4(auxArcade.nacionalidad, nacionalidadChar, "ESTADOUNIDENSE", "JAPONES", "CHINO","COREANO");
					convertirOpcionACadena4(AuxJuego.genero, generoChar, "PLATAFORMA", "LABERINTO", "AVENTURA", "OTRO");
					printf("|%6d    | %8d | %7d  | %14s |%14s|    %-7d|     %-12d | %-18s| %-13s|%-11s|\n "	,auxArcade.idArcade, auxArcade.idSalon, auxArcade.idJuego, tipoDeSonidoChar, nacionalidadChar, auxArcade.cantidadDeJugadores,auxArcade.capacidadMaximaDeFichas , AuxJuego.nombreJuego , AuxJuego.empresaJuego , generoChar);
					retorno=RETORNOPOSITIVO;
				}
			}
		}
	}

	return retorno;
}

int Arcade_ListArcadeConJuegos(LinkedList* pArrayListArcade , LinkedList * pArrayListJuego )
{
    int retorno = RETORNONEGATIVO;
    int len;

    if(pArrayListArcade!= NULL)
    {
    	len = ll_len(pArrayListArcade);

    	puts("|ID Arcade | ID SALON | ID JUEGO | TIPO DE SONIDO | NACIONALIDAD |N° JUGADORES|CAP MAX DE FICHAS|  NOMBRE DEL JUEGO  |EMP CREADORA|   GENERO   | ");

    	for(int i=0;i<len;i++)
    	{
    		retorno = ScanArcadeParaImprimirConJuegos(pArrayListArcade, pArrayListJuego,i);

    	}
    }
    return retorno;
}

int Arcade_ListArcadeConJuegosYSalones(LinkedList* pArrayListArcade , LinkedList * pArrayListJuego ,LinkedList* pArrayListSalones )
{
    int retorno = RETORNONEGATIVO;
    int len;

    if(pArrayListArcade!= NULL)
    {
    	len = ll_len(pArrayListArcade);

    	puts("|ID Arcade|ID SALON|ID JUEGO|TIPO DE SONIDO| NACIONALIDAD |CANT DE JUGADORES|CAP MAX DE FICHAS| NOMBRE DEL JUEGO|EMPRESA CREADORA |  GENERO  |NOMBRE DEL SALON|     DIRECCION DEL SALON    |TIPO DE SALON|");

    	for(int i=0;i<len;i++)
    	{
    		retorno = ScanArcadeParaImprimirConJuegosYSalones(pArrayListArcade, pArrayListJuego, pArrayListSalones,i);

    	}
    }
    return retorno;
}


int ScanArcadeParaImprimirConJuegosYSalones(LinkedList* pArrayListArcade,LinkedList* pArrayListJuego, LinkedList* pArrayListSalones ,  int posicionArcade )
{
	int retorno=RETORNONEGATIVO;
	Arcade* pArcade;
	Arcade auxArcade;
	Juego * pJuego;
	Juego AuxJuego;
	Salon * pSalon;
	Salon Auxsalon;
	char tipoDeSonidoChar[MAXCHAR];
	char nacionalidadChar[MAXCHAR];
	char generoChar[MAXCHAR];
	char tipoSalonChar[MAXCHAR];
	int posicionJuego;
	int posicionSalon;


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
			if(Juego_BuscarPorId(pArrayListJuego, auxArcade.idJuego, &posicionJuego)==RETORNOPOSITIVO && Salon_BuscarPorId(pArrayListSalones, auxArcade.idSalon, &posicionSalon)==RETORNOPOSITIVO)
			{
				pSalon = (Salon * ) ll_get(pArrayListSalones , posicionSalon);
				pJuego = (Juego * ) ll_get(pArrayListJuego, posicionJuego);

				if(pJuego != NULL && pSalon != NULL
						&&Juego_getEmpresa(pJuego, AuxJuego.empresaJuego)==RETORNOPOSITIVO
						&& Juego_getNombreJuego(pJuego, AuxJuego.nombreJuego)==RETORNOPOSITIVO
						&& Juego_getGenero(pJuego, &AuxJuego.genero)==RETORNOPOSITIVO
						&& Salon_getNombre(pSalon, Auxsalon.nombre)==RETORNOPOSITIVO
						&& Salon_getDireccion(pSalon, Auxsalon.direccion)==RETORNOPOSITIVO
						&& Salon_getTipo(pSalon, &Auxsalon.tipo)==RETORNOPOSITIVO)
				{

                    convertirOpcionACadena(Auxsalon.tipo,tipoSalonChar , "SHOPPING", "LOCAL");
					convertirOpcionACadena(auxArcade.tipoDeSonido, tipoDeSonidoChar, "MONO", "ESTEREO");
					convertirOpcionACadena4(auxArcade.nacionalidad, nacionalidadChar, "ESTADOUNIDENSE", "JAPONES", "CHINO","COREANO");
					convertirOpcionACadena4(AuxJuego.genero, generoChar, "PLATAFORMA", "LABERINTO", "AVENTURA", "OTRO");
					printf("|%6d   |%-8d| %7d|   %-11s|%14s|       %-10d|      %-10d | %-16s|  %-15s|%-10s|  %-14s|%-28s|%-13s|\n "	,auxArcade.idArcade, auxArcade.idSalon,
							auxArcade.idJuego, tipoDeSonidoChar, nacionalidadChar, auxArcade.cantidadDeJugadores,auxArcade.capacidadMaximaDeFichas ,
							AuxJuego.nombreJuego , AuxJuego.empresaJuego , generoChar , Auxsalon.nombre , Auxsalon.direccion , tipoSalonChar);
					retorno=RETORNOPOSITIVO;
				}
			}
		}
	}

	return retorno;
}


int EliminarArcadePorId(LinkedList* pArrayListArcade, LinkedList * pArrayListaSalon , LinkedList * pArrayListaJuego)
{
	int posicionArcadeId;
	int retorno=RETORNONEGATIVO;
	int auxIdArcade;
	Arcade* pArcade;
	int confirmar;
	int llamaGet;
	if(pArrayListArcade!= NULL )
	{

		Arcade_ListArcadeConJuegosYSalones(pArrayListArcade, pArrayListaJuego, pArrayListaSalon);
		if(getInt(&auxIdArcade,"Ingrese el ID del Arcade que desea eliminar o 0 si desea cancelar.\n", "Valor ingresado incorrecto!!\n",0, MAXARCADE, 4)==1)
		{
			if(auxIdArcade != 0)
			{
				if(Arcade_BuscarPorId(pArrayListArcade, auxIdArcade, &posicionArcadeId)==RETORNOPOSITIVO)
				{
					pArcade = (Arcade*)ll_get(pArrayListArcade, posicionArcadeId);
					if(pArcade!=NULL)
					{
						puts("\nEl arcade a eliminar es : ");
						puts("|ID Arcade|ID SALON|ID JUEGO|TIPO DE SONIDO| NACIONALIDAD |CANT DE JUGADORES|CAP MAX DE FICHAS| NOMBRE DEL JUEGO|EMPRESA CREADORA |  GENERO  |NOMBRE DEL SALON|     DIRECCION DEL SALON    |TIPO DE SALON|");
						ScanArcadeParaImprimirConJuegosYSalones(pArrayListArcade, pArrayListaJuego, pArrayListaSalon, posicionArcadeId);
						llamaGet=getInt(&confirmar, "Esta seguro que desea eliminar??\n Presione 1 para confirmar y 2 para cancelar", "Valores ingresados incorrectamente!!\n", 1, 2, 4);
						if(llamaGet==1 && confirmar == 1)
						{
							Arcade_delete(pArcade);
							retorno = ll_remove(pArrayListArcade, posicionArcadeId);
													}
						else
						{
							puts("Se cancela la operacion eliminar");
							retorno = -2;
						}

					}

				}
				else
				{
					puts("no se encontro el ID");

				}
			}
			else
			{
				puts("Se cancela la eliminacion...");
			}

		}

	}


	return retorno;
}
