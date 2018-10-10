#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "utn.h"
#include "parcial_programacion.h"

///Validaciones de ID y separar en bibliotecas separadas

//1
/**
*@brief Inicializa el array de clientes, cambiando el estado del flag <isEmpty> a <true>.
*@param listaDeClientes Es el array de estructuras de empleados
*@param length La maxima cantidad de empleados
*/
void initClient(Cliente* listaDeClientes, int length)
{
    int i;

    for (i=0;i<length;i++)
    {
        strncpy(listaDeClientes[i].nombre, "no data", 32);
        strncpy(listaDeClientes[i].apellido, "no data", 32);
        strncpy(listaDeClientes[i].cuit, "no data", 12);
        listaDeClientes[i].id = -1;
        listaDeClientes[i].isEmpty = true;
    }
}

/**
*@brief Denota la posicion del proximo slot libre en el array
*@param listaDeClientes Es el array de estructuras de clientes
*@return Retorna la id del proximo slot vacio del array, en caso de que no lo haya retorna -1
*/

int nextEmptySlot(Cliente* listaDeClientes)
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
*@brief Denota la posicion del proximo slot libre en el array
*@param listaDeClientes Es el array de estructuras de afiches
*@return Retorna la id del proximo slot vacio del array, en caso de que no lo haya retorna -1
*/

int nextEmptySlot_v(Afiches* listaDeAfiches)
{
    int i;
    int ret = -1;

    for(i=0;i<MAX_CLIENTES;i++)
    {
        if(listaDeAfiches[i].isEmpty == true)
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

int generateID (void)
{
    static int iD = 0;
    iD++;
    return (iD);
}

/**
*@brief Genera numeros ID
*@return Retorna una ID unica
*/

int generateID_v (void)
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
int addClient (Cliente* listaDeClientes, int cLength)
{
    int nextEmpty = nextEmptySlot(listaDeClientes);
    int i;
    int ret = -1;
    char nombre[32];
    char apellido[32];
    char cuit[12];

    utn_getString(nombre, 2, "\nIngrese el nombre del cliente: ", "El nombre no es valido.\n", 32);
    utn_getString(apellido, 2, "Ingrese el apellido del cliente: ", "El nombre no es valido.\n", 32);
    getCuit(cuit, 2, "Ingrese el cuit del cliente: ", "El cuit no es valido.\n", 12);

    if(listaDeClientes != NULL && nextEmptySlot(listaDeClientes) != -1)
    {
        for(i=0; i<cLength; i++)
        {
            if(i == nextEmpty)
            {
                strncpy(listaDeClientes[i].nombre, nombre, 51);
                strncpy(listaDeClientes[i].apellido, apellido, 51);
                strncpy(listaDeClientes[i].cuit, cuit, 12);
                listaDeClientes[i].id = generateID();
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
void modifyClient(Cliente* listaDeEmpleados, int cLength)
{
    int i;
    int idCliente;

    utn_getInt(&idCliente, 2, "\nIngrese el ID del cliente cuyos datos desea modificar: ", "ID Fuera de rango.", 0, cLength+1);
    for(i=0;i<cLength;i++)
    {
        if(listaDeEmpleados[i].isEmpty == false && listaDeEmpleados[i].id == idCliente)
           {
                    utn_getString(listaDeEmpleados[i].nombre, 2, "Ingrese el nuevo nombre del cliente: ", "El nombre ingresado es invalido\n.", 32);
                    utn_getString(listaDeEmpleados[i].apellido, 2, "Ingrese el nuevo apellido del cliente: ", "El apellido ingresado es invalido\n.", 32);
                    utn_getString(listaDeEmpleados[i].cuit, 2, "Ingrese el nuevo cuit del cliente: ", "El cuit ingresado es invalido\n.", 12);
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
int removeClient (Cliente* listaDeClientes, int cLength)
{
    int i;
    int ret = -1;
    int id;
    int eleccion;

    utn_getInt(&id,2,"Ingrese el numero de ID del cliente a dar de baja", "El ID ingresado no es valido", 0, MAX_CLIENTES+1);
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
    return(ret);
}

//4
/**
*@brief Inicializa el array de afiches, cambiando el estado del flag <isEmpty> a <true> y el flag <aCobrar> a <false>.
*@param listaDeAfiches Es el array de estructuras de empleados
*@param length La maxima cantidad de empleados
*/

void initAfiches(Afiches* listaDeAfiches, int length)
{
    int i;

    for (i=0;i<length;i++)
    {
        strncpy(listaDeAfiches[i].nombreArchivo, "no data", 25);
        listaDeAfiches[i].idCliente = -1;
        listaDeAfiches[i].idVenta= -1;
        listaDeAfiches[i].cantidadAfiches = -1;
        listaDeAfiches[i].zona = -1;
        listaDeAfiches[i].isEmpty = true;
        listaDeAfiches[i].aCobrar = false;
        listaDeAfiches[i].cobrada = false;
    }
}

/**
*@brief Cambia el estado del flag <isEmpty> de la estructura de los clientes a <false>
*@param employeeList Es el array de estructuras de clientes
*@param cLength La maxima cantidad de clientes
*@return En caso de que la operacion haya sido exitosa retorna 0, caso contrario retorna -1.
*/
int sellPosters(Afiches* listaDeAfiches, int aLength)
{
    int idCliente;
    int cantidadDeAfiches;
    char nombreDeArchivo[25];
    int zona;
    int nextEmpty = nextEmptySlot_v(listaDeAfiches);
    int i;
    int ret = -1;

    utn_getInt(&idCliente,2,"Ingrese el numero de ID del cliente al cual se le venderan los afiches: ", "El ID ingresado no es valido.\n", 0, MAX_CLIENTES+1);
    utn_getInt(&cantidadDeAfiches,2,"Ingrese el numero de afiches que se venderan al cliente: ", "El numero ingresado no es valido.\n", 0, MAX_CLIENTES+1);
    utn_getString(nombreDeArchivo, 2, "Ingrese el nombre del archivo de imagen del cliente: ", "El nombre ingresado es invalido\n.", 25);
    printf("Ingrese la zona en la que será pegado el afiche:\n1) CABA\n2) ZONA SUR\n3) ZONA OESTE");
    scanf("%d", &zona);
    switch(zona)
    {
    case 1:
        zona = CABA;
        break;
    case 2:
        zona = ZONA_SUR;
        break;
    case 3:
        zona = ZONA_OESTE;
        break;
    default:
        printf("La opción ingresada no corresponde a una zona valida.");
    }
    if(listaDeAfiches != NULL && nextEmptySlot_v(listaDeAfiches) != -1)
    {
        for(i=0; i<aLength; i++)
        {
            if(i == nextEmpty)
            {
                strncpy(listaDeAfiches[i].nombreArchivo, nombreDeArchivo, 25);
                listaDeAfiches[i].idCliente = idCliente;
                listaDeAfiches[i].idVenta= generateID_v();
                listaDeAfiches[i].cantidadAfiches = cantidadDeAfiches;
                listaDeAfiches[i].zona = zona;
                listaDeAfiches[i].isEmpty = false;
                listaDeAfiches[i].aCobrar = true;
                listaDeAfiches[i].cobrada = false;
                ret = 0;
                printf("Se ha registrado correctamente la venta bajo la ID %d.", listaDeAfiches[i].idVenta);
                break;
            }
        }
    }
    return (ret);
}
//5
/**
*@brief Muestra en pantalla los afiches y sus respectivos datos
*@param listaDeAfiches Es el array de estructuras de afiches
*@param aLength La maxima cantidad de afiches
*/
void printPosters (Afiches* listaDeAfiches, int aLength)
{
    int i;

    printf("\nNombre del Archivo\t\tZona\tN° Afiches\tID Cliente\tID Venta\n");
        for(i=0; i < aLength; i++)
        {
            if(listaDeAfiches[i].isEmpty == false)
            {
                printf("\n%s\t%d\t%d\t%d\t%d", listaDeAfiches[i].nombreArchivo, listaDeAfiches[i].zona, listaDeAfiches[i].cantidadAfiches, listaDeAfiches[i].idCliente, listaDeAfiches[i].idVenta);
            }
        }
}

/**
*@brief Pide al usuario un ID y modifica los datos del afiche correspondiente
*@param listaDeAfiches Es el array de estructuras de afiches
*@param aLength La maxima cantidad de afiches
*@return En caso de que la operacion haya sido exitosa retorna 0, caso contrario retorna -1.
*/
int editTransaction(Afiches* listaDeAfiches, int aLength)
{
    int i;
    int idCliente;
    int cantidadDeAfiches;
    char nombreDeArchivo[25];
    int zona;
    int ret = -1;

    utn_getInt(&idCliente, 2, "\nIngrese el ID de la venta cuyos datos desea modificar: ", "ID Fuera de rango.", 0, aLength+1);
    for(i=0;i<aLength;i++)
    {
        if(listaDeAfiches[i].isEmpty == false && listaDeAfiches[i].aCobrar == true && listaDeAfiches[i].idCliente == idCliente)
        {
            utn_getInt(&idCliente,2,"Ingrese el nuevo numero de ID del cliente al cual se le asocian los afiches: ", "El ID ingresado no es valido.\n", 0, MAX_CLIENTES+1);
            utn_getInt(&cantidadDeAfiches,2,"Ingrese el nuevo numero de afiches que se asocian al cliente: ", "El numero ingresado no es valido.\n", 0, MAX_CLIENTES+1);
            utn_getString(nombreDeArchivo, 2, "Ingrese el nuevo nombre del archivo de imagen del cliente: ", "El nombre ingresado es invalido\n.", 25);
            printf("Ingrese la nueva zona en la que será pegado el afiche:\n1) CABA\n2) ZONA SUR\n3) ZONA OESTE");
            scanf("%d", &zona);
            switch(zona)
            {
            case 1:
                zona = CABA;
                break;
            case 2:
                zona = ZONA_SUR;
                break;
            case 3:
                zona = ZONA_OESTE;
                break;
            default:
                printf("La opción ingresada no corresponde a una zona valida.");
            }
            ret = 0;
        }
    }
    return (ret);
}

//6
/**
*@brief Pide al usuario un ID de venta y cambia el flag <cobrada> a <true>
*@param listaDeAfiches Es el array de estructuras de afiches
*@param aLength La maxima cantidad de afiches
*@return En caso de que la operacion haya sido exitosa retorna 0, caso contrario retorna -1.
*/
int cobrarVenta(Afiches* listaDeAfiches, int aLength, Cliente* listaDeClientes, int cLength)
{
    int idVenta;
    int i, j;
    int ret = -1;
    int eleccion;

    printPosters(listaDeAfiches, MAX_AFICHES);
    utn_getInt(&idVenta,2,"\nIngrese el numero de ID de la venta: ", "El ID ingresado no es valido.\n", 0, MAX_CLIENTES+1);
    for(i=0;i<MAX_AFICHES;i++)
    {
        if(idVenta == listaDeAfiches[i].idVenta)
        {
            if(listaDeAfiches[i].cobrada == false)
            {
                for(j=0;j<MAX_CLIENTES;j++)
                {
                    if(listaDeAfiches[i].idCliente == listaDeClientes[j].id)
                    {
                        printf("\nApellido\tNombre\tCUIT\t\tID\n");
                        printf("\n%s\t%s\t\t%s\t\t%d", listaDeClientes[j].apellido, listaDeClientes[j].nombre, listaDeClientes[j].cuit, listaDeClientes[j].id);
                        printf("\n\n¿Desea cambiar el estado de esta venta a CERRADA?\n1) Si\n2) No\n\nEleccion: ");
                        scanf("%d", &eleccion);
                        switch(eleccion)
                        {
                            case 1:
                                listaDeAfiches[i].cobrada = true;
                                listaDeAfiches[i].aCobrar = false;
                                goto end;
                                break;
                            case 2:
                                printf("La venta no se cobrará");
                                break;
                            default:
                                printf("%d no es una opción valida", eleccion);
                        }
                        ret = 0;
                        break;
                    }
                    else
                    {
                        printf("El ID de venta ingresado no corresponde con ningun cliente.\n");
                    }
                }
            }
            else
            {
                printf("No hay ninguna venta sin cobrar bajo la ID ingresada.");
            }
        }
        else
        {
            printf("El ID de venta ingresado no esta registrado.\n");
        }
    }
end:
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
void printClients (Afiches* listaDeAfiches, int aLength, Cliente* listaDeClientes, int cLength)
{
    int i;
    int idCliente;

    printf("\nApellido\tNombre\tCUIT\t\tID\tVentas a cobrar\n");
        for(i=0; i < cLength; i++)
        {
            if(listaDeClientes[i].isEmpty == false)
            {
                idCliente = listaDeClientes[i].id;
                printf("\n%s\t%s\t%s\t%d\t%d", listaDeClientes[i].apellido, listaDeClientes[i].nombre, listaDeClientes[i].cuit, listaDeClientes[i].id, contadorDeACobrar(listaDeAfiches, aLength, idCliente));
            }
        }
}

/**
*@brief Pide al usuario un ID de venta y cambia el flag <cobrada> a <true>
*@param listaDeAfiches Es el array de estructuras de afiches
*@param aLength La maxima cantidad de afiches
*@param idCliente es la id del cliente del cual se quieren obtener los datos
*@return En caso de que la operacion haya sido exitosa retorna 0, caso contrario retorna -1.
*/
int contadorDeACobrar(Afiches* listaDeAfiches, int aLength, int idCliente)
{
    int i;
    int contador = 0;

    for(i=0; i<aLength; i++)
    {
        if(listaDeAfiches[i].idCliente == idCliente && listaDeAfiches[i].aCobrar == true)
        {
            contador++;
        }
    }
    return(contador);
}

int getCuit (char* pString, int tries, char* msg, char* errorMsg, int lenght)
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

