/*
 * salon.h
 *
 *  Created on: 24 jun. 2022
 *      Author: Juan
 */

#ifndef SALON_H_
#define SALON_H_
#include "LinkedList.h"

typedef struct
{
	int idSalon;
	char nombre[51];
	char direccion[51];
	int tipo;
}Salon;





Salon* CargarUnSalon(int id , char * direccion , char * nombre , int tipo);
Salon * Salon_New();
void salon_delete(Salon * this );
int Salon_setId(Salon* this,int id);
int Salon_getId(Salon* this,int* id);
int Salon_setDireccion(Salon* this,char* direccion);
int Salon_getDireccion(Salon* this,char* direccion);
int Salon_setNombre(Salon* this,char* nombre);
int Salon_getNombre(Salon* this,char* nombre);
int Salon_setTipo(Salon* this,int tipo);
int Salon_getTipo(Salon* this,int* tipo);
int IngresarSalon(char name[],char direccion[],int* tipo ,int lenCadena);
Salon* Salon_newParametros(int id,char* nombreSalon,char* direccion,int tipo);
Salon* Salon_new();
int Alta_Salon(LinkedList* pArrayListSalon);
int Salon_ListarSalones(LinkedList* pArrayListSalon);
void convertirOpcionACadena(int opcion,  char* tipoChar,char* opcionAsignarA, char*opcionAsignarB);
int ScanSalonParaImprimir(LinkedList* pArrayListSalon, int posicion);
void MostrarUnSoloSalon(int id, char * nombre, char * direccion , int tipo);
int BajaSalon(LinkedList* pArrayListSalon , LinkedList * pArrayListaArcade);
int Salon_BuscarPorId(LinkedList* pArrayListSalon, int id,int* posicion);
int EliminarSalonPorId(LinkedList* pArrayListSalon , LinkedList * pArrayListaArcade);
void Salon_delete(Salon* this);
int Salon_ListarSalonesParaEliminar(LinkedList* pArrayListSalon);
int ScanSalonParaImprimirYEliminar(LinkedList* pArrayListSalon, int posicion);
int OdenarSalonPorNombre(LinkedList * pArrayListSalon , int orden);
int Sort_compareByNombreSalon(void* salonUno, void* salonDos);



#endif /* SALON_H_ */
