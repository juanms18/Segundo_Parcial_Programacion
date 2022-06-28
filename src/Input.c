/*
 * Input.c
 *
 *  Created on: 14 may. 2022
 *      Author: Juan
 */




#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Input.h"
#include <ctype.h>

int validarNumeroEntero(char numero[] , int*numerovalido)
{
	int i;


	for(i=0; i<strlen(numero); i++)
	{
		if(!(isdigit(numero[i])))
		{

			return 0;
		}
		if(isdigit(numero[i]))
		{
			*numerovalido=atoi(numero);
			return 1;
		}
	}

}



int getInt(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = 0;
	char bufferChar[5];
	int validar;
	int numeroValidado;

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
	do
	{
		printf("%s" ,mensaje);
		fflush(stdin);
		scanf("%s" ,&bufferChar);
		validar=validarNumeroEntero(bufferChar ,&numeroValidado);

		if(numeroValidado >= minimo && numeroValidado <= maximo && validar==1)
		{
		 *pResultado = numeroValidado;
          retorno = 1;
          break;
		}
		else
		{
			printf("%s\n", mensajeError);
			reintentos--;
		}
	}while(reintentos >= 0);
}
return retorno;
}


int getStringNumerosFlotantes(char mensaje[],char mensajeError[],float *numeroFlotante ,int reintentos)
{
	char aux[256];
	int i;
	for(i=0; i<reintentos; i++)
	{
		getString(mensaje,aux);
		if(esNumericoFlotante(aux)!=0)
		{
			*numeroFlotante=atof(aux);
			return 1;
			break;
		}
		if(esNumericoFlotante(aux)==0)
		{
			printf("%s",mensajeError);
		}
		reintentos--;
	}
	return 0;
}

int esNumericoFlotante(char str[])
{
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (i == 0 && str[i] == '-')
       {
           i++;
           continue;

       }
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}



int getStringValidado(char mensaje[],char errorNumericoMensaje[], char errorMensajeLargo[],char input[], int len,int reintentos)
{
    int i;
    int retorno=0;
    char buffer[1024];

    for(i=0;i<reintentos;i++)
    {
        if (getStringLetras(mensaje,buffer)==0)
        {
            printf ("%s",errorNumericoMensaje);
            reintentos--;
            continue;
        }
        if(strlen(buffer) >= len)
        {
            printf ("%s", errorMensajeLargo);
            reintentos--;
            continue;

        }
        retorno=1;
        strcpy(input,buffer);
        break;
    }
    return retorno;
}


int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;

    }
    return 0;
}

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    fflush(stdin);
    gets(input);
}


int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}


int esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}


int getStringAlfanumerico(char mensaje[],char input[] , char mensajeError[] ,char mensajeErrorLen[], int reintentos ,int len)
{
	char aux[256];
	int i;
	int retorno=0;


	for (i=0 ; i<reintentos ; i++)
	{
		getString(mensaje,aux);
		if (esAlfaNumerico(aux)==0)
		{
			printf("%s",mensajeError);
			reintentos--;
		}
		if (strlen(aux)>= len)
		{
			printf("%s",mensajeErrorLen);
			reintentos--;
		}
		if(esAlfaNumerico(aux)==1)
		{
			strcpy(input,aux);
			retorno=1;
			break;
		}
	}

	return retorno;
}


int getValidCuit(char mensaje[],char mensajeEerror[], char errorLargo[],char input[], int len,int reintentos)
{
    int i;
    int retorno=-1;
    char buffer[1024];

    for(i=0;i<reintentos;i++)
    {
        if (!getStringNumeros2(mensaje,buffer))
        {
            printf ("%s",mensajeEerror);
            reintentos--;
            continue;
        }
        if(strlen(buffer) < len-1 || strlen(buffer) > len-1)
        {
            printf ("%s",errorLargo);
            reintentos--;
            continue;

        }
        retorno=0;
        strcpy(input,buffer);
        break;
    }
    return retorno;
}


int getStringNumeros2(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esAlfaNumerico2(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


int esAlfaNumerico2(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] > '-' && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}


int esEmail(char str[])
{
	int retorno=0;
	int i=0;
	int flag=0;
	int flag2=0;
	while(str[i] != '\0' )
	{
		if((str[i] != '@') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] != '-')&& (str[i] != '_') && (str[i] != '.') && (str[i] < '0' || str[i] > '9') && (str[i] != ' '))
		{
			return retorno;
		}

		if((str[i]=='@'))
		{
			flag= 1;
		}
		if(str[i]=='.')
		{
			flag2=1;
		}
		i++;
	}
	if(flag==1 && flag2==1)
	{
		retorno = 1;
	}

	   return retorno;;

}

int getEmail(char mensaje[],char errorCaracterDesconocido[], char errorMensajeLargo[],char input[], int len,int reintentos)

{
	int i;
	int retorno=0;
	char buffer[1024];
	int llamar;

	for(i=0;i<reintentos;i++)
	{
		llamar=getStringEmail(mensaje,buffer);
		if (llamar==0)
		{
			printf ("%s",errorCaracterDesconocido);
			continue;
		}
		if(strlen(buffer) >= len)
		{
			printf ("%s", errorMensajeLargo);
			continue;

		}
		if(llamar==1)
		{
			retorno=1;
			convertirEnMayuscula(buffer, 1024);
			strcpy(input,buffer);
			break;
		}
	}
	return retorno;
}

int getStringEmail(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esEmail(aux)==1)
    {
        strcpy(input,aux);
        return 1;

    }

    return 0;
}

void convertirEnMayuscula (char palabra[] , int len)
{
  int i;

   for(i=0 ; palabra[i] != '\0'; i++)
   {
	   palabra[i]= toupper(palabra[i]);

   }

}


int comparar2Strings(char palabra1[], char palabra2[] , int len)
{
	int retorno=-1;

	convertirEnMayuscula(palabra1, len);
	convertirEnMayuscula(palabra2, len);
	if(strcmp(palabra1 , palabra2)==0)
	{
		retorno=0;
	}
	return retorno;

}
