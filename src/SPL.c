/*
 ============================================================================
 Name        : SPL.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Input.h"
#include "Salon.h"
#include "Arcade.h"
#include"Juego.h"
#include "Informes.h"
#include "CargaDeArchivos.h"
#define RETORNOPOSITIVO 0
#define RETORNONEGATIVO -1
#define REINTENTOS 3
#define MAXSALONES 1000

int main(void) {

	setbuf(stdout, NULL);
	int opcion;
	int cargaDatosSalon;
	int cargaDatosArcade;
	int cargaDatosJuegos;
	int llamaFuncion;


	LinkedList* listaSalon = ll_newLinkedList();
	LinkedList* listaArcade = ll_newLinkedList();
	LinkedList* listaJuego = ll_newLinkedList();



	cargaDatosSalon=CargarDatosSalon("datasalon.csv", listaSalon );
	cargaDatosArcade = CargarDatosArcade("dataarcade.csv", listaArcade);
	cargaDatosJuegos=CargarDatosJuego("datajuego.csv", listaJuego);

	if(cargaDatosArcade == 0 && cargaDatosSalon == 0 && cargaDatosJuegos == 0)
	{

		do{
			if(getInt(&opcion, "\n1) ALTA DE SALÓN\n"
					"2) ELIMINAR SALÓN \n"
					"3) LISTAR SALONES\n"
					"4) INCORPORAR ARCADE\n"
					"5) MODIFICAR ARCADE\n"
					"6) ELIMINAR ARCADE\n"
					"7) IMPRIMIR ARCADE\n"
					"8) AGREGAR JUEGO\n"
					"9) IMPRIMIR JUEGO\n"
					"10) INFORMES\n"
					"11) SALIR Y GUARDAR DATOS CARGADOS\n", "Error!! Opcion seleccionada no valida", 1, 11, REINTENTOS)==1)
			{
				switch(opcion)
				{
				case 1:

					if(Alta_Salon(listaSalon)==0)
					{
						puts("El Salon se cargo correctamente!!");
						system("pause");
					}
					else
					{
						puts("Error al cargar el salon!!");
						system("pause");
					}

					break;

				case 2:
					llamaFuncion=EliminarSalonPorId(listaSalon, listaArcade);
					if(llamaFuncion==RETORNOPOSITIVO)
					{
						puts("Se ha eliminado el salon y todos los arcades que continia  con exito");
						system("pause");
					}
					else if(llamaFuncion==-2)
					{
						puts("Volviendo al Menu!!");
					}
					else
					{
						puts("No se elimino ningun Salon...");
					}
					break;

				case 3:
					if(Salon_ListarSalones(listaSalon)==RETORNONEGATIVO)
					{
						puts("Aun no se cargaron datos para mostrar!!\n");
						system("pause");
					}
					break;

				case 4:

					if(Alta_Arcade(listaArcade , listaSalon , listaJuego)==0)
					{
						puts("El Arcade se cargo correctamente!!");
						system("pause");
					}
					else
					{
						puts("Error al cargar el Arcade!!");
						system("pause");
					}

					break;

				case 5:
					if(Arcade_modificarArcade(listaArcade , listaJuego)==RETORNOPOSITIVO)
					{
						puts("Arcade modificado con exito");
					}
					else
					{
						puts("Los Datos de Arcade no fueron modificados");
					}

					break;


				case 6:
					llamaFuncion=EliminarArcadePorId(listaArcade, listaSalon, listaJuego);
					if(llamaFuncion==RETORNOPOSITIVO)
					{
						puts("Se ha eliminado el Arcade  correctamente.\n");
						system("pause");
					}
					else if(llamaFuncion==-2)
					{
						puts("Volviendo al Menu!!");
					}
					else
					{
						puts("No se elimino ningun Arcade...");
					}
										break;
					break;


				case 7:
					if(Arcade_ListArcadeConJuegos(listaArcade, listaJuego)==RETORNONEGATIVO)
					{
						puts("Aun no se cargaron datos para mostrar!!\n");
						system("pause");
					}
					break;


				case 8:

					if(Alta_Juego(listaJuego)==0)
					{
						puts("El Juego se cargo correctamente!!");
						system("pause");
					}
					else
					{
						puts("Error al cargar el Juego!!");
						system("pause");
					}
					break;

				case 9:
					if(Juego_ListarJuego(listaJuego)==RETORNONEGATIVO)
					{
						puts("Aun no se cargaron datos para mostrar!!\n");
						system("pause");
					}

					break;
				case 10:
					Menu_informes(listaSalon, listaArcade, listaJuego);
					break;
				case 11:
						Salon_saveAsText("datasalon.csv", listaSalon);
						Arcade_saveAsText("dataarcade.csv", listaArcade);
						Juego_saveAsText("datajuego.csv", listaJuego);
						opcion=12;
					break;
				}
			}
		}while(opcion!=12);
	}
	else
	{
		puts("ERROR!!! no pudieron cargarse los archivos csv!!!\n");
	}

	return EXIT_SUCCESS;
}
