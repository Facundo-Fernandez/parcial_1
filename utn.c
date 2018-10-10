#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "utn.h"

/// Funciones get...

/**
*@brief
*@param pResult
*@return
*/
int getInt(int* pResult)
{
    int ret = -1;
    char string[64];

    scanf("%s", string);
    if(isNumber(string) == 0)
    {
        *pResult = atoi(string);
        ret = 0;
    }
    return (ret);
}

/**
*@brief
*@param pResult
*@return
*/
int getFloat(float* pResult)
{
    int ret = -1;
    char string[64];

    scanf("%s", string);
    if(isFloat(string) == 0)
    {
        *pResult = atof(string);
        ret = 0;
    }
    return (ret);
}

/**
*@brief
*@param pBuffer
*@param limit
*@return
*/
int getString(char* pBuffer,int limit)
{
    char bufferString[4096];
    int ret =-1;

    if (pBuffer != NULL && limit >0)
    {
        __fpurge(stdin);
        fgets (bufferString,sizeof(bufferString),stdin);
        if (bufferString[strlen(bufferString)-1] == '\n')
        {
            bufferString[strlen(bufferString)-1] = '\0';
        }
        if(strlen(bufferString)<= limit)
        {
            strncpy(pBuffer,bufferString,limit);
            ret=0;
        }
    }
    return ret;
}

/// Funciones is...
/**
*@brief
*@param
*@return
*/
int isNumber(char* pString) //Sacar de Apunte_Inputs_V1.1
{
    int i;
    int ret = -1;
    int contadorDePuntos = 0;

    for(i = 0; i < strlen(pString); i++)
    {
        char c = pString [i];
        if(c == ',' || c == '.')
        {
            c = '.';
            contadorDePuntos++;
            if (contadorDePuntos == 1)
            {
                break;
            }
        }
        else if (c < 48  || c > 57)   //Rango ASCII del 1 al 9. Siempre se ponen los rangos en su codigo ASCII
        {
            break;
        }
        else
        {
            ret = 0;
        }
    }
    return(ret);
}

/**
*@brief
*@param pString
*@return
*/
int isFloat(char* pString) //Sacar de Apunte_Inputs_V1.1
{
    int i;
    int ret = -1;
    int contadorDePuntos = 0;

    for(i = 0; i < strlen(pString); i++)
    {
        char c = pString [i];
        if(c == ',' || c == '.')
        {
            c = '.';
            contadorDePuntos++;
            if (contadorDePuntos == 2)
            {
                break;
            }
        }
        else if(c < 48  || c > 57) //Rango ASCII del 1 al 9. Siempre se ponen los rangos en su codigo ASCII
        {
            break;
        }
        else
        {
            ret = 0;
        }
    }
    return(ret);
}

/**
*@brief
*@param
*@return
*/
int isText (char* pString)
{
    int i;
    int ret = -1;

    for(i = 0; i<strlen(pString); i++)
    {
        char c = pString [i];
        if ((c < 64  || c > 91) && (c < 60 || c > 123))//Rango ASCII
        {
            break;
        }
        else
        {
            ret = 0;
        }
    }
    return(ret);
}

///Funciones utn_get...
/**
*@brief
*@param pNumber
*@param tries
*@param msg
*@param errorMsg
*@param lowLimit
*@param hiLimit
*@return
*/
int utn_getInt(int* pNumber,int tries, char* msg, char* errorMsg, int lowLimit, int hiLimit)
{
    int ret =-1;
    int aux;
    int i;

    for(i=0;i<tries;i++)
    {
        printf("%s", msg);
        if(getInt(&aux) == 0)
        {
            if(aux >= lowLimit && aux < hiLimit)
            {
                *pNumber = aux;
                ret = 0;
                break;
            }
            else
            {
                printf("%s", errorMsg);
            }
        }
        else
        {
            printf("%s", errorMsg);
            __fpurge(stdin);
        }
    }
    return (ret);
}

/**
*@brief
*@param pNumber
*@param tries
*@param msg
*@param errorMsg
*@param lowLimit
*@param hiLimit
*@return
*/
int utn_getFloat(float* pNumber,int tries, char* msg, char* errorMsg, float lowLimit, float hiLimit)
{
    int ret =-1;
    float aux;
    int i;

    for(i=0;i<tries;i++)
    {
        printf("%s", msg);
        if(getFloat(&aux) == 0)
        {
            if(aux >= lowLimit && aux < hiLimit)
            {
                *pNumber = aux;
                ret = 0;
                break;
            }
            else
            {
                printf("%s", errorMsg);
            }
        }
        else
        {
            printf("%s", errorMsg);
            __fpurge(stdin);
        }
    }
    return (ret);
}

/**
*@brief
*@param pString
*@param lenght
*@param tries
*@param msg
*@param errorMsg
*@return
*/
int utn_getString (char* pString, int tries, char* msg, char* errorMsg, int lenght)
{
    int i;
    int ret = -1;
    char aux[lenght];

    if(pString != NULL && lenght>0)
    {
        for(i=0; i<tries; i++)
        {
            printf("%s", msg);
            if (getString(aux, lenght) == 0 && isText(aux) == 0)
            {
                strncpy(pString, aux, lenght);
                ret = 0;
                break;
            }
            else
            {
                printf("%s", errorMsg);
            }
        }
    }
    return (ret);
}

/// Funciones para Arrays

/**
*@brief
*@param
*@param
*@param
*@return
*/
int initArray (int* pArray, int limit, int value)
{
    int ret = -1;
    int i;
    if(pArray != NULL && limit > 0)
    {
        for(i=0; i<limit; i++)
        {
            pArray[i] = value;
        }
        ret = 0;
    }
    return(ret);
}

/**
*@brief
*@param pArray
*@param limit
*@return
*/
int printArray(int* pArray, int limit)
{
    int i;

    for (i=0;i<limit;i++)
    {
        printf("\n%d",pArray[i]);
    }
    return (0);
}

/**
*@brief
*@param
*@param
*@param
*@return
*/
void calculateMaxMinArray(int* pArray, int limit)
{
    int i;
    int maxValue = pArray[0];
    int minValue = pArray [0];

    if(pArray != NULL && limit > 0)
    {
        for (i=0; i<limit; i++)
        {
            if (pArray[i] > maxValue)
            {
                maxValue = pArray[i];
            }
            else if (pArray[i] < minValue)
            {
                minValue = pArray[i];
            }
        }
    }
printf("\nEl maximo valor cargado en el array es %d\nEl minimo valor cargado en el array es %d\n", maxValue, minValue);
}

/**
*@brief
*@param pArray
*@param length
*@return
*/
void insertionSort(int* pArray, int length)
{
    int i;
    int j;
    int temp;

    for (i=1; i < length; i++)
    {
        temp = pArray[i];
        j = i - 1;
        while (j > 0 && temp < pArray[j]) // temp < pArray[j] o temp > pArray[j]
        {
            pArray[j + 1] = pArray[j];
            j--;
        }
        pArray[j+1] = temp; //Inserción
    }
}

