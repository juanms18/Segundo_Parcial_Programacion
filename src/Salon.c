/*
 * salon.c
 *
 *  Created on: 24 jun. 2022
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
#define RETORNOPOSITIVO 0
#define RETORNONEGATIVO -1
#define REINTENTOS 3
#define MAXCHAR 51
#define MAXSALONES 1000


static int Salon_BuscaIdMaximo(LinkedList* pArrayListSalon);

static int Salon_NuevoIdPartiendoDelMaximo(LinkedList* pArrayListSalon,int* nuevoId);

static int Salon_NuevoIdPartiendoDelMaximo(LinkedList* pArrayListSalon,int* nuevoId)
{
	int retorno=RETORNONEGATIVO;
	static int id = 0 ;
	static int primeraEntrada = RETORNOPOSITIVO;

	if(pArrayListSalon!= NULL)
	{
		if(primeraEntrada == RETORNOPOSITIVO)
		{
			id = Salon_BuscaIdMaximo(pArrayListSalon);
			primeraEntrada = RETORNONEGATIVO;;
		}
		*nuevoId=id++;
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}


static int Salon_BuscaIdMaximo(LinkedList* pArrayListSalon)
{
	Salon* pSalon;
	int len;
	int maxId;
	int id=0;

	if(pArrayListSalon!= NULL)
	{
		len = ll_len(pArrayListSalon);

		for(int i=0;i<len;i++)
		{
			pSalon= ll_get(pArrayListSalon,i);
			Salon_getId(pSalon, &id);
			if (i == 0 || id > maxId)
			{
				maxId = id;
			}
		}
		id = maxId;
	}
	return id;
}





Salon * Salon_New()
{
	return (Salon*) malloc(sizeof(Salon));
}

Salon* CargarUnSalon(int id , char * nombre , char * direccion , int tipo)
{
	Salon * punteroSalon = NULL;
	punteroSalon = Salon_New();
	if(punteroSalon != NULL &&  id > 0 && nombre != NULL && direccion != NULL && tipo > 0 && tipo < 3 )
	{
		Salon_setId(punteroSalon, id);
		Salon_setDireccion(punteroSalon, direccion);
		Salon_setNombre(punteroSalon, nombre);
		Salon_setTipo(punteroSalon, tipo);
	}
	else
	{
		puts("Error Puntero salon");
	}
	return punteroSalon;
}

void salon_delete(Salon * this  )
{
   free(this);
}


int Salon_setId(Salon* this,int id)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && id>0)
	{
		this->idSalon=id;
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}


int Salon_getId(Salon* this,int* id)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && id>0)
	{
		*id=this->idSalon;
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}

int Salon_setDireccion(Salon* this,char* direccion)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && direccion!=NULL)
	{
		strncpy(this->direccion,direccion,MAXCHAR);
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}

int Salon_getDireccion(Salon* this,char* direccion)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && direccion!=NULL)
	{
		strncpy(direccion,this->direccion,MAXCHAR);
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}

int Salon_setNombre(Salon* this,char* nombre)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && nombre!=NULL)
	{
		strncpy(this->nombre,nombre,MAXCHAR);
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}


int Salon_getNombre(Salon* this,char* nombre)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && nombre!=NULL)
	{
		strncpy(nombre,this->nombre,MAXCHAR);
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}

int Salon_getTipo(Salon* this,int* tipo)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && tipo != NULL)
	{
		*tipo=this->tipo;
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}


int Salon_setTipo(Salon* this,int tipo)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && tipo > 0 && tipo < 3 )
	{
		this->tipo = tipo;
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}



int Alta_Salon(LinkedList* pArrayListSalon)
{
	int retorno=RETORNONEGATIVO;
	Salon *  pSalon;
	Salon auxSalon;

	if(pArrayListSalon!= NULL)
	{
		if(IngresarSalon(auxSalon.nombre, auxSalon.direccion,&auxSalon.tipo, MAXCHAR)==RETORNOPOSITIVO)
		{
			Salon_NuevoIdPartiendoDelMaximo(pArrayListSalon, &auxSalon.idSalon);
			auxSalon.idSalon++;
			pSalon=Salon_newParametros(auxSalon.idSalon,auxSalon.nombre, auxSalon.direccion , auxSalon.tipo);

			if(pSalon!= NULL)
			{

				retorno = ll_add(pArrayListSalon, pSalon);
				MostrarUnSoloSalon(auxSalon.idSalon, auxSalon.nombre, auxSalon.direccion, auxSalon.tipo);
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



int IngresarSalon(char name[],char direccion[],int* tipo ,int lenCadena)
{
	int retorno=RETORNONEGATIVO;
	Salon auxSalon;
	do{
		if(getStringValidado("Ingrese el nombre del Salon:\n", "No se aceptan numeros!!\n", "Nombre demaciado largo!!\n", auxSalon.nombre, lenCadena, 5)==1
				&& getStringAlfanumerico("Ingrese la direccion del salon:\n", auxSalon.direccion, "Datos mal ingresados, solo se aceptan letras y numeros!!\n", "Direccion demasiado larga!!\n", 3, lenCadena)==1
				&& getInt(&auxSalon.tipo, "Ingrese 1 para Shopping  y 2 para Local:\n","Dato ingresado incorrecto!!\n", 1, 2, 3)==1)
		{
			strncpy(name,auxSalon.nombre,lenCadena);
			strncpy(direccion,auxSalon.direccion,lenCadena);

			*tipo=auxSalon.tipo;
			retorno=RETORNOPOSITIVO;
		}
		else
		{
			puts("Ocurrio un error al cargar los datos, demasiados intentos erroneos!! Vuelva a intentar!!");
			system("pause");
			break;
		}
	}while(retorno==RETORNONEGATIVO);

	return retorno;

}

Salon* Salon_new()
{
	return (Salon*) malloc(sizeof(Salon));
}

Salon* Salon_newParametros(int id,char* nombreSalon,char* direccion,int tipo)
{
	Salon* punteroSalon= NULL;
	punteroSalon= Salon_new();
	if(punteroSalon!= NULL && nombreSalon!= NULL && direccion!= NULL )
	{
		Salon_setId(punteroSalon, id);
		Salon_setNombre(punteroSalon, nombreSalon);
		Salon_setDireccion(punteroSalon, direccion);
		Salon_setTipo(punteroSalon, tipo);
	}
	else
	{
		puts("PunteroPerson == null");
	}

	return punteroSalon;
}



int Salon_ListarSalones(LinkedList* pArrayListSalon)
{
	int retorno = RETORNONEGATIVO;
	int len;

	if(pArrayListSalon!= NULL)
	{
		len = ll_len(pArrayListSalon);

		puts("|ID SALON |      NOMBRE     |          DIRECCION          |   TIPO   | \n");
		 //OdenarSalonPorNombre(pArrayListSalon, 0);
		for(int i=0;i<len;i++)
		{
			retorno = ScanSalonParaImprimir(pArrayListSalon,i);
		}
	}
	return retorno;
}

int Salon_ListarSalonesParaEliminar(LinkedList* pArrayListSalon)
{
	int retorno = RETORNONEGATIVO;
	int len;

	if(pArrayListSalon!= NULL)
	{
		len = ll_len(pArrayListSalon);

		puts("|ID SALON |      NOMBRE     |          DIRECCION          |  \n");

		for(int i=0;i<len;i++)
		{
			retorno = ScanSalonParaImprimirYEliminar(pArrayListSalon,i);
		}
	}
	return retorno;
}

int ScanSalonParaImprimirYEliminar(LinkedList* pArrayListSalon, int posicion)
{
	int retorno=RETORNONEGATIVO;
	Salon* pSalon;
	Salon auxSalon;

	if(pArrayListSalon!= NULL && posicion > -1)
	{
		pSalon= (Salon*)ll_get(pArrayListSalon, posicion);
		if(pSalon!= NULL
				&& Salon_getId(pSalon, &auxSalon.idSalon)== RETORNOPOSITIVO
				&& Salon_getNombre(pSalon, auxSalon.nombre)== RETORNOPOSITIVO
				&& Salon_getDireccion(pSalon, auxSalon.direccion)== RETORNOPOSITIVO)
		{

			printf("\n|%5d    | %15s | %25s  |  \n "	,auxSalon.idSalon,auxSalon.nombre,auxSalon.direccion);
			retorno=RETORNOPOSITIVO;
		}
	}

	return retorno;
}

int ScanSalonParaImprimir(LinkedList* pArrayListSalon, int posicion)
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
			printf("|%5d    | %15s | %25s  | %10s |\n "	,auxSalon.idSalon,auxSalon.nombre,auxSalon.direccion,tipoChar);
			retorno=RETORNOPOSITIVO;
		}
	}

	return retorno;
}

void convertirOpcionACadena(int opcion,  char* tipoChar,char* opcionAsignarA, char*opcionAsignarB)
{
	if(opcion>0 && tipoChar != NULL && opcionAsignarA != NULL && opcionAsignarB != NULL)
	{
		switch (opcion)
		{
		case 1:
			strncpy(tipoChar,opcionAsignarA,MAXCHAR);
			break;
		case 2:
			strncpy(tipoChar,opcionAsignarB,MAXCHAR);
			break;
		}
	}
}

void MostrarUnSoloSalon(int id, char * nombre, char * direccion , int tipo)
{
	char tipoChar [MAXCHAR];
	convertirOpcionACadena(tipo, tipoChar, "Shopping", "Local");
	puts("|ID SALON |      NOMBRE     |          DIRECCION          |   TIPO   | ");
	printf("|%5d    | %15s | %25s   |    %s   | \n "	,id,nombre,direccion,tipoChar);
}


int BajaSalon(LinkedList* pArrayListSalon , LinkedList * pArrayListaArcade)
{
	int retorno=RETORNONEGATIVO;
	if(pArrayListSalon!= NULL)
	{
		if(ll_isEmpty(pArrayListSalon)==RETORNOPOSITIVO)
		{
			Salon_ListarSalones(pArrayListSalon);
			retorno = EliminarSalonPorId(pArrayListSalon , pArrayListaArcade);
		}

	}
	return retorno;
}

int EliminarSalonPorId(LinkedList* pArrayListSalon , LinkedList * pArrayListaArcade)
{
	int posicionSalonId;
	int retorno=RETORNONEGATIVO;
	int auxId;
	Salon* pSalon;
	int confirmar;
	int llamaGet;
	if(pArrayListSalon!= NULL )
	{

		Salon_ListarSalonesParaEliminar(pArrayListSalon);
		if(getInt(&auxId,"Ingrese el ID del salon que desea eliminar o 0 si desea cancelar.\n", "Valor ingresado incorrecto!!\n",0, MAXSALONES, 4)==1)
		{
			if(auxId != 0)
			{
				if(Salon_BuscarPorId(pArrayListSalon, auxId, &posicionSalonId)==RETORNOPOSITIVO)
				{
					pSalon = (Salon*)ll_get(pArrayListSalon, posicionSalonId);
					if(pSalon!=NULL)
					{
						puts("\nEl salon a eliminar es : ");
						ScanSalonParaImprimir(pArrayListSalon, posicionSalonId);
						llamaGet=getInt(&confirmar, "Esta seguro que desea eliminar??\n Presione 1 para confirmar y 2 para cancelar", "Valores ingresados incorrectamente!!\n", 1, 2, 4);
						if(llamaGet==1 && confirmar == 1)
						{
							Salon_delete(pSalon);
							retorno = ll_remove(pArrayListSalon, posicionSalonId);
							EliminarArcadePorIdSalon(auxId, pArrayListaArcade);

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

		}

	}


	return retorno;
}


int Salon_BuscarPorId(LinkedList* pArrayListSalon, int id,int* posicion)
{
	int retorno=RETORNONEGATIVO;
	int lenListSalon;
	int auxId;
	Salon * pSalon;
	if(pArrayListSalon!= NULL && id > -1)
	{
		lenListSalon= ll_len(pArrayListSalon);
		for(int i = 0 ; i<lenListSalon;i++)
		{
			pSalon= (Salon*)ll_get(pArrayListSalon, i);
			if(pSalon != NULL
					&& Salon_getId(pSalon, &auxId)==RETORNOPOSITIVO
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

void Salon_delete(Salon* this)
{
	free(this);
}

int OdenarSalonPorNombre(LinkedList * pArrayListSalon , int orden)
{
   int retorno = -1;

   retorno = ll_sort(pArrayListSalon, Sort_compareByNombreSalon, orden);

   return retorno;
}

int Sort_compareByNombreSalon(void* salonUno, void* salonDos)
{
	int retorno=-2;
	char auxNombreUno[MAXCHAR];
	char auxNombreDos[MAXCHAR];

	if(salonUno!= NULL && salonDos!= NULL)
	{
		Salon_getNombre(salonUno, auxNombreUno);
		Salon_getNombre(salonDos, auxNombreDos);
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

