#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "utn.h"
#include "clientes.h"
#include "ventas.h"

/**
*@brief Imprime en cantalla la cantidad de clientes con más ventas en estado "a cobrar".
*@param listaDeClientes Es la lista de clientes
*@param listaDeAfiches Es la lista de ventas
*@param cLength Cantidad de clientes
*@param aLength Cantidad de ventas
*/
void informes_printClienteConMasPendientes(Cliente* listaDeClientes, Afiches* listaDeAfiches, int cLength, int aLength)
{
    int i;
    int aCobrarAux = 0;
    char auxNombre[32];
    char auxApellido[32];

    for(i=0;i<aLength;i++)
    {
        if(listaDeAfiches[i].aCobrar == true && ventas_contadorDeACobrar(listaDeAfiches, MAX_AFICHES, listaDeAfiches[i].idCliente) > aCobrarAux)
        {
            aCobrarAux = ventas_contadorDeACobrar(listaDeAfiches, MAX_AFICHES, listaDeAfiches[i].idCliente);
            strncpy(auxNombre,listaDeClientes[listaDeAfiches[i].idCliente].nombre,32);
            strncpy(auxApellido,listaDeClientes[listaDeAfiches[i].idCliente].apellido,32);
        }
    }
    printf("\n- El cliente con más ventas a cobrar es %s %s\n", auxApellido, auxNombre);
}

/**
*@brief Imprime en cantalla la cantidad de clientes con más ventas en estado "cobrada".
*@param listaDeClientes Es la lista de clientes
*@param listaDeAfiches Es la lista de ventas
*@param cLength Cantidad de clientes
*@param aLength Cantidad de ventas
*/
void informes_printClienteConMasCobradas(Cliente* listaDeClientes, Afiches* listaDeAfiches, int cLength, int aLength)
{
    int i;
    int cobradasAux = 0;
    char auxNombre[32];
    char auxApellido[32];

    for(i=0;i<aLength;i++)
    {
        if(listaDeAfiches[i].cobrada == true && ventas_contadorDeCobradas(listaDeAfiches, MAX_AFICHES, listaDeAfiches[i].idCliente) > cobradasAux)
        {
            cobradasAux = ventas_contadorDeCobradas(listaDeAfiches, MAX_AFICHES, listaDeAfiches[i].idCliente);
            strncpy(auxNombre,listaDeClientes[listaDeAfiches[i].idCliente].nombre,32);
            strncpy(auxApellido,listaDeClientes[listaDeAfiches[i].idCliente].apellido,32);
        }
    }
    printf("- El cliente con más ventas cobradas es %s %s\n", auxApellido, auxNombre);
}

/**
*@brief Imprime en cantalla la cantidad de clientes con más ventas, cualquiera sea su estado.
*@param listaDeClientes Es la lista de clientes
*@param listaDeAfiches Es la lista de ventas
*@param cLength Cantidad de clientes
*@param aLength Cantidad de ventas
*/
void informes_printClienteConMasVentas(Cliente* listaDeClientes, Afiches* listaDeAfiches, int cLength, int aLength)
{
    int i;
    int ventasAux = 0;
    char auxNombre[32];
    char auxApellido[32];

    for(i=0;i<aLength;i++)
    {
        if((listaDeAfiches[i].cobrada == true ||
           listaDeAfiches[i].aCobrar == true) &&
        (ventas_contadorDeCobradas(listaDeAfiches, MAX_AFICHES, listaDeAfiches[i].idCliente) + ventas_contadorDeACobrar(listaDeAfiches, MAX_AFICHES, listaDeAfiches[i].idCliente)> ventasAux))
        {
            ventasAux = ventas_contadorDeCobradas(listaDeAfiches, MAX_AFICHES, listaDeAfiches[i].idCliente) + ventas_contadorDeACobrar(listaDeAfiches, MAX_AFICHES, listaDeAfiches[i].idCliente);
            strncpy(auxNombre,listaDeClientes[listaDeAfiches[i].idCliente].nombre,32);
            strncpy(auxApellido,listaDeClientes[listaDeAfiches[i].idCliente].apellido,32);
        }
    }
    printf("- El cliente con más ventas es %s %s\n", auxApellido, auxNombre);
}

/**
*@brief Imprime en pantalla el cliente que tiene más afiches pendientes de cobro.
*@param listaDeClientes Es la lista de clientes
*@param listaDeAfiches Es la lista de ventas
*@param cLength Cantidad de clientes
*@param aLength Cantidad de ventas
*/
void informes_printClienteConMasAfichesPendientes(Cliente* listaDeClientes, Afiches* listaDeAfiches, int cLength, int aLength)
{
    int i;
    int afichesAux = 0;
    char auxNombre[32];
    char auxApellido[32];

    for(i=0;i<aLength;i++)
    {
        if(listaDeAfiches[i].aCobrar == true && listaDeAfiches[i].cantidadAfiches != -1 && listaDeAfiches[i].cantidadAfiches > afichesAux)
        {
            afichesAux = listaDeAfiches[i].cantidadAfiches;
            strncpy(auxNombre,listaDeClientes[listaDeAfiches[i].idCliente].nombre,32);
            strncpy(auxApellido,listaDeClientes[listaDeAfiches[i].idCliente].apellido,32);
        }
    }
    printf("- El cliente con más afiches a cobrar es %s %s, con %d afiches pendientes de cobro.\n", auxApellido, auxNombre, afichesAux);
}

/**
*@brief Imprime en pantalla el cliente que tiene más afiches comprados.
*@param listaDeClientes Es la lista de clientes
*@param listaDeAfiches Es la lista de ventas
*@param cLength Cantidad de clientes
*@param aLength Cantidad de ventas
*/
void informes_printClienteConMasAfichesCobrados(Cliente* listaDeClientes, Afiches* listaDeAfiches, int cLength, int aLength)
{
    int i;
    int afichesAux = 0;
    char auxNombre[32];
    char auxApellido[32];

    for(i=0;i<aLength;i++)
    {
        if(listaDeAfiches[i].cobrada == true && listaDeAfiches[i].cantidadAfiches != -1 && listaDeAfiches[i].cantidadAfiches > afichesAux)
        {
            afichesAux = listaDeAfiches[i].cantidadAfiches;
            strncpy(auxNombre,listaDeClientes[listaDeAfiches[i].idCliente].nombre,32);
            strncpy(auxApellido,listaDeClientes[listaDeAfiches[i].idCliente].apellido,32);
        }
    }
    printf("- El cliente con más afiches a cobrar es %s %s, con %d afiches comprados.\n", auxApellido, auxNombre, afichesAux);
}

/**
*@brief Imprime en pantalla la zona en la que se vendieron menos afiches, siendo 1) CABA, 2) ZONA SUR y 3) ZONA OESTE
*@param listaDeAfiches Es la lista de ventas
*@param aLength Cantidad de ventas
*/
void informes_zonaConMenosAfichesVendidos(Afiches* listaDeAfiches, int aLength)
{
    int contadorCABA = 0;
    int contadorSUR = 0;
    int contadorOESTE = 0;
    int i;

    for(i=0;i < aLength;i++)
    {
        if(listaDeAfiches[i].zona == 1)
        {
            contadorCABA = contadorCABA + listaDeAfiches[i].cantidadAfiches;

        }
        if(listaDeAfiches[i].zona == 2)
        {
            contadorSUR = contadorSUR + listaDeAfiches[i].cantidadAfiches;

        }
        if(listaDeAfiches[i].zona == 3)
        {
            contadorOESTE = contadorOESTE + listaDeAfiches[i].cantidadAfiches;

        }
    }
    if(contadorCABA < contadorSUR)
    {
        if(contadorCABA < contadorOESTE )
        {
            printf("- La zona con menos afiches vendidos es CABA.\n");
        }
        else
        {
            if(contadorOESTE < contadorSUR)
            {
                printf("- La zona con menos afiches vendidos es zona Oeste.\n");
            }
            else
            {
                printf("- La zona con menos afiches vendidos es zona SUR.\n");
            }
        }
    }
    else
    {
        if(contadorSUR < contadorOESTE )
        {
            printf("- La zona con menos afiches vendidos es zona SUR.\n");
        }
        else
        {
            if(contadorCABA < contadorOESTE )
            {
            printf("- La zona con menos afiches vendidos es CABA.\n");
            }
            else
            {
            printf("- La zona con menos afiches vendidos es zona Oeste.\n");
            }
        }
    }
}

/**
*@brief Imprime en pantalla la cantidad de clientes que tienen menos de 1000 afiches
*@param listaDeClientes Es la lista de clientes
*@param listaDeAfiches Es la lista de ventas
*@param cLength Cantidad de clientes
*@param aLength Cantidad de ventas
*/
void informes_cantidadClientesMenos1000Afiches(Cliente* listaDeClientes, Afiches* listaDeAfiches, int cLength, int aLength)
{
    int i;
    int cantidadAfiches = 0;
    int cantidadClientes = 0;
    int j;

    for(i=0;i<cLength;i++)
    {
        if(listaDeClientes[i].isEmpty!=1)
        {
            for(j=0;j<aLength;j++)
            {
                if(listaDeAfiches[j].idCliente==listaDeClientes[i].id)
                {
                    cantidadAfiches++;
                }
            }
            if(cantidadAfiches<1000)
            {
                cantidadClientes++;
            }
        }
    }
    printf("- La cantidad de clientes con menos de 1000 afiches es %d\n",cantidadClientes);
}

/**
*@brief Imprime un informe del total de afiches vendidos en cada zona.
*@param listaDeAfiches Es la lista de ventas
*@param aLength Cantidad de ventas
*/
void informes_cantidadDeAfichesVendidosPorZona (Afiches* listaDeAfiches, int aLength)
{
    int contadorCABA = 0;
    int contadorSUR = 0;
    int contadorOESTE = 0;
    int i;

    for(i=0;i < aLength;i++)
    {
        if(listaDeAfiches[i].zona == 1)
        {
            contadorCABA = contadorCABA + listaDeAfiches[i].cantidadAfiches;

        }
        if(listaDeAfiches[i].zona == 2)
        {
            contadorSUR = contadorSUR + listaDeAfiches[i].cantidadAfiches;

        }
        if(listaDeAfiches[i].zona == 3)
        {
            contadorOESTE = contadorOESTE + listaDeAfiches[i].cantidadAfiches;

        }
    }
    printf("- La cantidad de afiches vendidos es:\n   + CABA\t%d\n   + ZONA SUR\t%d\n   + ZONA OESTE\t%d\n", contadorCABA, contadorSUR, contadorOESTE);
}

/**
*@brief Ordena e imprime la lista de ventas por zona, desde ZONA OESTE hasta CABA.
*@param listaDeAfiches Es la lista de ventas
*@param aLength Cantidad de ventas
*/
void informes_printListaDeVentasOrdenadaPorZona (Afiches* listaDeAfiches, int aLength)
{
    char auxNombre[32];
    int auxZona;
    int auxAfiches;
    int auxIdCliente;
    int auxIdVenta;
    int i;
    int j;

    for(i=0; i<MAX_AFICHES; i++)
    {
        for(j=i+1; j<MAX_AFICHES; j++)
        {
            if(listaDeAfiches[i].zona < listaDeAfiches[j].zona)
            {
                strcpy(auxNombre,listaDeAfiches[i].nombreArchivo);
                strcpy(listaDeAfiches[i].nombreArchivo, listaDeAfiches[j].nombreArchivo);
                strcpy(listaDeAfiches[j].nombreArchivo, auxNombre);

                auxZona = listaDeAfiches[i].zona;
                listaDeAfiches[i].zona = listaDeAfiches[j].zona;
                listaDeAfiches[j].zona = auxZona;

                auxAfiches = listaDeAfiches[i].cantidadAfiches;
                listaDeAfiches[i].cantidadAfiches = listaDeAfiches[j].cantidadAfiches;
                listaDeAfiches[j].cantidadAfiches = auxAfiches;

                auxIdCliente = listaDeAfiches[i].idCliente;
                listaDeAfiches[i].idCliente = listaDeAfiches[j].idCliente;
                listaDeAfiches[j].idCliente = auxIdCliente;

                auxIdVenta = listaDeAfiches[i].idVenta;
                listaDeAfiches[i].idVenta = listaDeAfiches[j].idVenta;
                listaDeAfiches[j].idVenta = auxIdVenta;
            }
        }
        printf("\nNombre del Archivo\t\tZona\tN° Afiches\tID Cliente\tID Venta\n");
        for(i=0; i < aLength; i++)
        {
            if(listaDeAfiches[i].isEmpty == false)
            {
                printf("\n%s\t%d\t%d\t%d\t%d", listaDeAfiches[i].nombreArchivo, listaDeAfiches[i].zona, listaDeAfiches[i].cantidadAfiches, listaDeAfiches[i].idCliente, listaDeAfiches[i].idVenta);
            }
        }
    }
}
/*
/**
*@brief Imprime en pantalla el primedio de afiches vendidos por cliente.
*@param listaDeClientes Es la lista de clientes
*@param listaDeAfiches Es la lista de ventas
*@param cLength Cantidad de clientes
*@param aLength Cantidad de ventas
*

void informes_printPromedioDeAfiches(Cliente* listaDeClientes, Afiches* listaDeAfiches, int cLength, int aLength)
{
    int cantClientes;
    int cantAfiches;
    float promedio;
    int i;
}
*/
