#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED
#define true 1
#define false 0

/// Funciones is...
int isNumber(char* pString);
int isFloat(char* pString);
int isText (char* pString);

///Funciones get...
int getInt(int* pResult);
int getFloat(float* pResult);
int getString(char* pBuffer,int limit);

///Funciones utn_get...
int utn_getInt(int* pNumber,int tries, char* msg, char* errorMsg, int lowLimit, int hiLimit);
int utn_getFloat(float* pNumber,int tries, char* msg, char* errorMsg, float lowLimit, float hiLimit);
int utn_getString (char* pString, int tries, char* msg, char* errorMsg, int lenght);

/// Funciones para Arrays
int initArray (int* pArray, int limit, int value);
int printArray(int* pArray, int limit);
void calculateMaxMinArray(int* pArray, int limit);
void insertionSort(int* pArray, int length);

#endif // UTN_H_INCLUDED

