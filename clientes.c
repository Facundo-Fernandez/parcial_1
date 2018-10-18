#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "utn.h"
#include "clientes.h"
#include "ventas.h"

void cargaForzada(Cliente* listaDeClientes)
{
        strncpy(listaDeClientes[0].nombre, "Facundo", 32);
        strncpy(listaDeClientes[0].apellido, "Fernandez", 32);
        strncpy(listaDeClientes[0].cuit, "20402231181", 11);
        listaDeClientes[0].id = 1;
        listaDeClientes[0].isEmpty = false;
        strncpy(listaDeClientes[1].nombre, "Gonzalo", 32);
        strncpy(listaDeClientes[1].apellido, "Fernandez", 32);
        strncpy(listaDeClientes[1].cuit, "20402222265", 11);
        listaDeClientes[1].id = 2;
        listaDeClientes[1].isEmpty = false;
        strncpy(listaDeClientes[2].nombre, "Gustavo", 32);
        strncpy(listaDeClientes[2].apellido, "Perez Ayala", 32);
        strncpy(listaDeClientes[2].cuit, "20322231187", 11);
        listaDeClientes[2].id = 3;
        listaDeClientes[2].isEmpty = false;
        strncpy(listaDeClientes[3].nombre, "Sebasti", 32);
        strncpy(listaDeClientes[3].apellido, "Rodriguez", 32);
        strncpy(listaDeClientes[3].cuit, "20402231123", 11);
        listaDeClientes[3].id = 4;
        listaDeClientes[3].isEmpty = false;
        strncpy(listaDeClientes[4].nombre, "Guiller", 32);
        strncpy(listaDeClientes[4].apellido, "Sambusetti", 32);
        strncpy(listaDeClientes[4].cuit, "20402235109", 11);
        listaDeClientes[4].id = 5;
        listaDeClientes[4].isEmpty = false;
}
//1
/**
*@brief Inicializa el array de clientes, cambiando el estado del flag <isEmpty> a <true>.
*@param listaDeClientes Es el array de estructuras de empleados
*@param length La maxima cantidad de empleados
*/
void client_initClient(Cliente* listaDeClientes, int length)
{
    int i;

    for (i=0;i<length;i++)
    {
        strncpy(listaDeClientes[i].nombre, "no data", 32);
        strncpy(listaDeClientes[i].apellido, "no data", 32);
        strncpy(listaDeClientes[i].cuit, "no data", 11);
        listaDeClientes[i].id = -1;
        listaDeClientes[i].isEmpty = true;
    }
}

/**
*@brief Denota la posicion del proximo slot libre en el array
*@param listaDeClientes Es el array de estructuras de clientes
*@return Retorna la id del proximo slot vacio del array, en caso de que no lo haya retorna -1
*/

int client_nextEmptySlot(Cliente* listaDeClientes)
{
    int i;
    int ret = -1;

    for(i=0;i<MAX_CLIENTES;i++)
    {
        if(listaDeClientes[i].isEmpty == true)
        {
            ret = i;
            break;
        }

    }
    return (ret);
}

/**
*@brief Genera numeros ID
*@return Retorna una ID unica
*/

int client_generateID (void)
{
    static int iD = 0;
    iD++;
    return (iD);
}

/**
*@brief Da de alta un cliente, pidiendole al usuario que ingrese los datos del mismo y otorgandole una ID unica.
*@param listaDeClientes Es el array de estructuras de clientes
*@param cLength La maxima cantidad de clientes
*@return Retorna 0 si pudo agregar los datos sin problemas, caso contrario denota -1
*/
int client_addClient (Cliente* listaDeClientes, int cLength)
{
    int nextEmpty = client_nextEmptySlot(listaDeClientes);
    int i;
    int ret = -1;
    char nombre[32];
    char apellido[32];
    char cuit[12];

    utn_getString(nombre, 2, "\nIngrese el nombre del cliente: ", "El nombre no es valido.\n", 32);
    utn_getString(apellido, 2, "Ingrese el apellido del cliente: ", "El nombre no es valido.\n", 32);
    client_getCuit(cuit, 2, "Ingrese el cuit del cliente: ", "El cuit no es valido.\n", 12);

    if(listaDeClientes != NULL && client_nextEmptySlot(listaDeClientes) != -1)
    {
        for(i=0; i<cLength; i++)
        {
            if(i == nextEmpty)
            {
                strncpy(listaDeClientes[i].nombre, nombre, 51);
                strncpy(listaDeClientes[i].apellido, apellido, 51);
                strncpy(listaDeClientes[i].cuit, cuit, 11);
                listaDeClientes[i].id = client_generateID();
                listaDeClientes[i].isEmpty = false;
                ret = 0;
                printf("Se ha registrado correctamente al cliente %s bajo la ID %d.", listaDeClientes[i].apellido, listaDeClientes[i].id);
            }
        }
    }
    return (ret);
}

//2
/**
*@brief Pide al usuario un ID y modifica los datos del cliente correspondiente
*@param employeeList Es el array de estructuras de empleados
*@param cLength La maxima cantidad de clientes
*/
void client_modifyClient(Cliente* listaDeClientes, int cLength)
{
    int i;
    int idCliente;

    utn_getInt(&idCliente, 2, "\nIngrese el ID del cliente cuyos datos desea modificar: ", "ID Fuera de rango.", 0, cLength+1);
    for(i=0;i<cLength;i++)
    {
            if(listaDeClientes[i].isEmpty == false && listaDeClientes[i].id == idCliente)
           {
                utn_getString(listaDeClientes[i].nombre, 2, "Ingrese el nuevo nombre del cliente: ", "El nombre ingresado es invalido\n.", 32);
                utn_getString(listaDeClientes[i].apellido, 2, "Ingrese el nuevo apellido del cliente: ", "El apellido ingresado es invalido\n.", 32);
                client_getCuit(listaDeClientes[i].cuit, 2, "Ingrese el nuevo cuit del cliente: ", "El cuit ingresado es invalido\n.", 11);
                break;
           }
           else
           {
               printf("La ID Ingresada no corresponde con ningun cliente registrado");
               break;
           }
    }
}

//3
/**
*@brief Cambia el estado del flag <isEmpty> de la estructura de los clientes a <false>
*@param listaDeClientes Es el array de estructuras de clientes
*@param cLength La maxima cantidad de clientes
*@return En caso de que se haya eliminado al cliente retorna 0, caso contrario retorna -1.
*/
int client_removeClient (Cliente* listaDeClientes, int cLength)
{
    int i;
    int ret = -1;
    int id;
    int eleccion;

    utn_getInt(&id,2,"Ingrese el numero de ID del cliente a dar de baja: ", "El ID ingresado no es valido", 0, MAX_CLIENTES+1);
    if(listaDeClientes[id-1].isEmpty == false)
    {
        printf("¿Está seguro que desea eliminar al cliente?\n1) Si\n2) No\n");
        scanf("%d", &eleccion);
        switch(eleccion)
        {
        case 1:
            if(listaDeClientes != NULL && cLength <= MAX_CLIENTES)
            {
                for(i=0;i<cLength;i++)
                {
                    if(listaDeClientes[i].id == id)
                    {
                        strncpy(listaDeClientes[i].nombre, "no data", 32);
                        strncpy(listaDeClientes[i].apellido, "no data", 32);
                        strncpy(listaDeClientes[i].cuit, "no data", 12);
                        listaDeClientes[i].id = -1;
                        listaDeClientes[i].isEmpty = true;
                        ret = 0;
                        break;
                    }
                }
            }
            break;
        case 2:
            printf("El cliente no se eliminará");
            break;

            }
    }
    else
    {
        printf("\nERROR. La ID ingresada no corresponde a un cliente registrado\n");
    }
    return(ret);
}

 //7
/**
*@brief Muestra en pantalla los clientes y sus respectivos datos
*@param listaDeClientes Es el array de estructuras de clientes
*@param cLength La maxima cantidad de clientes
*@param listaDeAfiches Es el array de estructuras de afiches
*@param aLength La maxima cantidad de afiches
*/
void client_printClients (Afiches* listaDeAfiches, int aLength, Cliente* listaDeClientes, int cLength)
{
    int i;
    int idCliente;

    printf("\nApellido\tNombre\t\tCUIT\t\tID\tVentas a cobrar\n");
        for(i=0; i < cLength; i++)
        {
            if(listaDeClientes[i].isEmpty == false)
            {
                idCliente = listaDeClientes[i].id;
                printf("\n%s\t%s\t\t%s\t%d\t%d", listaDeClientes[i].apellido, listaDeClientes[i].nombre, listaDeClientes[i].cuit, listaDeClientes[i].id, ventas_contadorDeACobrar(listaDeAfiches, aLength, idCliente));
            }
        }
}

/**
*@brief Muestra en pantalla los clientes y sus respectivos datos
*@param pString Es la cadena de caracteres en la que guardara los datos
*@param tries La cantidad de intentos
*@param msg El mensaje de petición de datos
*@param errorMsg El mensaje de error
*@param lenght El tamaño maximo de la cadena
*@return  retorna 0 si la operación se completó correctamente, caso contrario denota -1
*/
int client_getCuit (char* pString, int tries, char* msg, char* errorMsg, int lenght)
{
    int i;
    int ret = -1;
    char aux[lenght];

    if(pString != NULL && lenght>0)
    {
        for(i=0; i<tries; i++)
        {
            printf("%s", msg);
            if (getString(aux, lenght) == 0 && (isText(aux) == 0 || isNumber(aux) == 0))
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
