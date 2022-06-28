/*
 * Juego.c
 *
 *  Created on: 24 jun. 2022
 *      Author: Juan
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Juego.h"
#include "LinkedList.h"
#include "Input.h"
#include "Salon.h"
#include "Arcade.h"
#define RETORNOPOSITIVO 0
#define RETORNONEGATIVO -1
#define REINTENTOS 3
#define MAXCHAR 51



static int Juego_BuscaIdMaximo(LinkedList* pArrayListJuego);

static int Juego_NuevoIdPartiendoDelMaximo(LinkedList* pArrayListJuego,int* nuevoId);

static int Juego_NuevoIdPartiendoDelMaximo(LinkedList* pArrayListJuego,int* nuevoId)
{
	int retorno=RETORNONEGATIVO;
	static int id = 0 ;
	static int primeraEntrada = RETORNOPOSITIVO;

	if(pArrayListJuego!= NULL)
	{
		if(primeraEntrada == RETORNOPOSITIVO)
		{
			id = Juego_BuscaIdMaximo(pArrayListJuego);
			primeraEntrada = RETORNONEGATIVO;;
		}
		*nuevoId=id++;
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}


static int Juego_BuscaIdMaximo(LinkedList* pArrayListJuego)
{
	Juego* pJuego;
	int len;
	int maxId;
	int id=0;

	if(pArrayListJuego!= NULL)
	{
		len = ll_len(pArrayListJuego);

		for(int i=0;i<len;i++)
		{
			pJuego= ll_get(pArrayListJuego,i);
			Juego_getIdJuego(pJuego, &id);
			if (i == 0 || id > maxId)
			{
				maxId = id;
			}
		}
		id = maxId;
	}
	return id;
}



Juego * CargarUnJuego(int idJuego ,  int genero , char * empresaJuego , char* nombreJuego)
{
	Juego * punteroJuego= NULL;
	punteroJuego= Juego_New();
	if(punteroJuego!= NULL &&  idJuego > 0 )
	{
		Juego_setIdJuego(punteroJuego, idJuego);
		Juego_setGenero(punteroJuego, genero);
		Juego_setEmpresa(punteroJuego, empresaJuego);
		Juego_setNombreJuego(punteroJuego, nombreJuego);

	}
	else
	{
		puts("Error Puntero salon");
	}
	return punteroJuego;
}

Juego * Juego_New()
{
   return (Juego*) malloc(sizeof(Juego));
}


int Juego_setIdJuego(Juego* this,int idJuego)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && idJuego>0)
	{
		this->idJuego=idJuego;
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}


int Juego_getIdJuego(Juego* this,int* idJuego)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && idJuego>0)
	{
		*idJuego=this->idJuego;
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}


int Juego_setGenero(Juego* this,int genero)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL)
	{
		this->genero=genero;
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}


int Juego_getGenero(Juego* this,int* genero)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL )
	{
		*genero=this->genero;
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}


int Juego_setEmpresa(Juego* this,char* empresa)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && empresa!=NULL)
	{
		strncpy(this->empresaJuego,empresa,MAXCHAR);
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}

int Juego_getEmpresa(Juego* this,char* empresa)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && empresa!=NULL)
	{
		strncpy(empresa,this->empresaJuego,MAXCHAR);
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}

int Juego_setNombreJuego(Juego* this,char* nombre)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && nombre!=NULL)
	{
		strncpy(this->nombreJuego,nombre,MAXCHAR);
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}

int Juego_getNombreJuego(Juego* this,char* nombre)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && nombre!=NULL)
	{
		strncpy(nombre,this->nombreJuego,MAXCHAR);
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}

int Alta_Juego(LinkedList* pArrayListJuego)
{
	int retorno=RETORNONEGATIVO;
	Juego *  pJuego;
	Juego auxJuego;

	if(pArrayListJuego!= NULL)
	{
		if(IngresarJuego(  &auxJuego.genero, auxJuego.empresaJuego, auxJuego.nombreJuego)==RETORNOPOSITIVO)
		{
			Juego_NuevoIdPartiendoDelMaximo(pArrayListJuego, &auxJuego.idJuego);
			auxJuego.idJuego++;
			pJuego=Juego_newParametros(auxJuego.idJuego,  auxJuego.genero, auxJuego.empresaJuego,auxJuego.nombreJuego);

			if(pJuego!= NULL)
			{

				retorno = ll_add(pArrayListJuego, pJuego);
				MostrarUnSoloJuego(auxJuego.idJuego, auxJuego.genero, auxJuego.empresaJuego,auxJuego.nombreJuego);
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


int IngresarJuego(int* genero, char * EmpresaDelJuego, char * nombreDelJuego)
{
	int retorno=RETORNONEGATIVO;
	Juego auxJuego;
	do{
		if(getInt(&auxJuego.genero , "Ingrese el genero correspondiente al nuevo juego:\n1 PLATAFORMA\n2 LABERINTO\n3 AVENTURA\n4 OTRO\n", "Solo se admiten numeros!!\n", 1, 4, 4)==1
				&& getStringValidado("Ingrese el nombre de la empresa:\n", "Solo se admiten letras!!\n","Nombre demasiado largo!!\n", auxJuego.empresaJuego, MAXCHAR, 4)==1
				&& getStringAlfanumerico("Ingrese el nombre del juego:\n", auxJuego.nombreJuego, "Solo se admiten letras y numeros!!\n", "Nombre demasiado largo!!\n", 4, MAXCHAR)==1)
		{
			*genero=auxJuego.genero;
			strncpy(EmpresaDelJuego,auxJuego.empresaJuego,51);
			strncpy(nombreDelJuego,auxJuego.nombreJuego,51);
			retorno=RETORNOPOSITIVO;
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

Juego* Juego_newParametros(int idJuego, int genero, char * empresaDelJuego, char * nombreDelJuego)
{
	Juego* punteroJuego= NULL;
	punteroJuego= Juego_new();
	if(punteroJuego!= NULL)
	{
		Juego_setIdJuego(punteroJuego, idJuego);
		Juego_setGenero(punteroJuego, genero);
		Juego_setEmpresa(punteroJuego, empresaDelJuego);
		Juego_setNombreJuego(punteroJuego, nombreDelJuego);
	}
	else
	{
		puts("PunteroPerson == null");
	}

	return punteroJuego;
}

Juego* Juego_new()
{
	return (Juego*) malloc(sizeof(Juego));
}


void MostrarUnSoloJuego(int idJuego, int genero, char * empresaDelJuego, char * nombreDelJuego)
{
	char tipoGeneroChar[MAXCHAR];

	convertirOpcionACadena4(genero, tipoGeneroChar, "PLATAFORMA", "LABERINTO", "AVENTURA","OTRO");


	puts("|ID jUEGO |   GENERO   | EMPRESA A LA QUE PERTENECE |     NOMBRE DEL JUEGO     |");
	printf("|%5d    | %10s | %25s  | %24s |\n"	,idJuego,tipoGeneroChar,empresaDelJuego,nombreDelJuego);
}


int Juego_ListarJuego(LinkedList* pArrayListJuego)
{
	int retorno = RETORNONEGATIVO;
	int len;

	if(pArrayListJuego!= NULL)
	{
		len = ll_len(pArrayListJuego);

		puts("|ID JUEGO |   GENERO   | EMPRESA A LA QUE PERTENECE |     NOMBRE DEL JUEGO     |");
		//OdenarJuegoPorNombre(pArrayListJuego, 0);
		for(int i=0;i<len;i++)
		{
			retorno = ScanJuegosParaImprimir(pArrayListJuego,i);
		}
	}
	return retorno;
}


int ScanJuegosParaImprimir(LinkedList* pArrayListJuego, int posicion)
{
	int retorno=RETORNONEGATIVO;
	Juego* pJuego;
	Juego auxJuego;
	char tipoChar[MAXCHAR];
	if(pArrayListJuego!= NULL && posicion > -1)
	{
		pJuego= (Juego*)ll_get(pArrayListJuego, posicion);
		if(pJuego!= NULL
				&& Juego_getIdJuego(pJuego, &auxJuego.idJuego)== RETORNOPOSITIVO
				&& Juego_getGenero(pJuego, &auxJuego.genero)== RETORNOPOSITIVO
				&& Juego_getEmpresa(pJuego, auxJuego.empresaJuego)==RETORNOPOSITIVO
				&& Juego_getNombreJuego(pJuego, auxJuego.nombreJuego)== RETORNOPOSITIVO)
		{
			convertirOpcionACadena4(auxJuego.genero, tipoChar, "PLATAFORMA", "LABERINTO" , "AVENTURA" , "OTRO");
			printf("|%5d    | %10s | %25s  | %24s |\n ",auxJuego.idJuego,tipoChar,auxJuego.empresaJuego,auxJuego.nombreJuego);
			retorno=RETORNOPOSITIVO;
		}
	}

	return retorno;
}



int Juego_BuscarPorId(LinkedList* pArrayListJuego, int id,int* posicion)
{
	int retorno=RETORNONEGATIVO;
	int lenListJuego;
	int auxId;
	Juego * pJuego;
	if(pArrayListJuego!= NULL && id > -1)
	{
		lenListJuego= ll_len(pArrayListJuego);
		for(int i = 0 ; i<lenListJuego;i++)
		{
			pJuego= (Juego*)ll_get(pArrayListJuego, i);
			if(pJuego!= NULL
					&& Juego_getIdJuego(pJuego, &auxId)==RETORNOPOSITIVO
					&& auxId==id)
			{
				*posicion=i;
				retorno=RETORNOPOSITIVO;
				break;
			}
		}
	}

	return retorno;
}
