#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "utn.h"
#include "clientes.h"
#include "ventas.h"

/**
*@brief Denota la posicion del proximo slot libre en el array
*@param listaDeAfiches Es el array de estructuras de afiches
*@return Retorna la id del proximo slot vacio del array, en caso de que no lo haya retorna -1
*/
int ventas_nextEmptySlot(Afiches* listaDeAfiches)
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

int ventas_generateID (void)
{
    static int iD = 0;
    iD++;
    return (iD);
}


/**
*@brief Inicializa el array de afiches, cambiando el estado del flag <isEmpty> a <true> y el flag <aCobrar> a <false>.
*@param listaDeAfiches Es el array de estructuras de empleados
*@param length La maxima cantidad de empleados
*/

void ventas_initAfiches(Afiches* listaDeAfiches, int length)
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
int ventas_sellPosters(Cliente* listaDeClientes, Afiches* listaDeAfiches, int aLength)
{
    int idCliente;
    int cantidadDeAfiches;
    char nombreDeArchivo[25];
    int zona;
    int nextEmpty = ventas_nextEmptySlot(listaDeAfiches);
    int i;
    int ret = -1;

    utn_getInt(&idCliente,2,"Ingrese el numero de ID del cliente al cual se le venderan los afiches: ", "El ID ingresado no es valido.\n", 0, MAX_CLIENTES+1);
    if(listaDeClientes[idCliente-1].isEmpty == false)
    {
        utn_getInt(&cantidadDeAfiches,2,"Ingrese el numero de afiches que se venderan al cliente: ", "El numero ingresado no es valido.\n", 0, MAX_AFICHES+1);
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
        if(listaDeAfiches != NULL && ventas_nextEmptySlot(listaDeAfiches) != -1)
        {
            for(i=0; i<aLength; i++)
            {
                if(i == nextEmpty)
                {
                    strncpy(listaDeAfiches[i].nombreArchivo, nombreDeArchivo, 25);
                    listaDeAfiches[i].idCliente = idCliente;
                    listaDeAfiches[i].idVenta= ventas_generateID();
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
    }
    else
    {
        printf("ERROR. El id ingresado no corresponde a ningun cliente registrado.");
    }
    return (ret);
}
//5
/**
*@brief Muestra en pantalla los afiches y sus respectivos datos
*@param listaDeAfiches Es el array de estructuras de afiches
*@param aLength La maxima cantidad de afiches
*/
void ventas_printPosters (Afiches* listaDeAfiches, int aLength)
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
int ventas_editTransaction(Afiches* listaDeAfiches, int aLength)
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
        if(listaDeAfiches[i].isEmpty == false)
        {
            if(listaDeAfiches[i].isEmpty == false && listaDeAfiches[i].aCobrar == true && listaDeAfiches[i].idCliente == idCliente)
            {
                utn_getInt(&idCliente,2,"Ingrese el nuevo numero de ID del cliente al cual se le asocian los afiches: ", "El ID ingresado no es valido.\n", 0, MAX_CLIENTES+1);
                utn_getInt(&cantidadDeAfiches,2,"Ingrese el nuevo numero de afiches que se asocian al cliente: ", "El numero ingresado no es valido.\n", 0, MAX_AFICHES+1);
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
                break;
            }
        }
        else
        {
            printf("El id ingresado no corresponde a ninguna venta registrada.");
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
int ventas_cobrarVenta(Afiches* listaDeAfiches, int aLength, Cliente* listaDeClientes, int cLength)
{
    int idVenta;
    int i, j;
    int ret = -1;
    int eleccion;

    ventas_printPosters(listaDeAfiches, MAX_AFICHES);
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

/**
*@brief Denota la cantidad de ventas en estado a cobrar del cliente de la id ingresada
*@param listaDeAfiches Es el array de estructuras de afiches
*@param aLength La maxima cantidad de afiches
*@param idCliente es la id del cliente del cual se quieren obtener los datos
*@return Retorna el contador de ventas a cobrar
*/

int ventas_contadorDeACobrar(Afiches* listaDeAfiches, int aLength, int idCliente)
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

/**
*@brief Denota la cantidad de ventas en estado cobrada del cliente de la id ingresada
*@param listaDeAfiches Es el array de estructuras de afiches
*@param aLength La maxima cantidad de afiches
*@param idCliente es la id del cliente del cual se quieren obtener los datos
*@return Retorna el contador de ventas cobradas
*/

int ventas_contadorDeCobradas(Afiches* listaDeAfiches, int aLength, int idCliente)
{
    int i;
    int contador = 0;

    for(i=0; i<aLength; i++)
    {
        if(listaDeAfiches[i].idCliente == idCliente && listaDeAfiches[i].cobrada == true)
        {
            contador++;
        }
    }
    return(contador);
}
