#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "utn.h"
#include "clientes.h"
#include "ventas.h"
#include "informes.h"

int main()
{
    Afiches listaDeAfiches[MAX_AFICHES];
    Cliente listaDeClientes[MAX_CLIENTES];
    int selectedOption;

    printf("ventaDeAfiches v0.1");
    ventas_initAfiches(listaDeAfiches, MAX_AFICHES);
    client_initClient(listaDeClientes, MAX_CLIENTES);
    cargaForzada(listaDeClientes);
menu:
    printf("\n-------------------------------- Menu principal --------------------------------\n\n");
    printf("Seleccione la opción que desea llevar a cabo:\n\n1) Alta de cliente\n2) Modificar datos de cliente\n3) Baja de cliente\n4) Vender afiches\n5) Editar venta\n6) Cobrar venta\n7) Imprimir clientes\n8) Informes\n\nOpción elegida: ");
    scanf("%d", &selectedOption);
    switch(selectedOption)
    {
    case 1:
        client_addClient(listaDeClientes, MAX_CLIENTES);
        break;
    case 2:
        client_modifyClient(listaDeClientes, MAX_CLIENTES);
        break;
    case 3:
        client_removeClient(listaDeClientes, MAX_CLIENTES);
        break;
    case 4:
        ventas_sellPosters(listaDeClientes, listaDeAfiches, MAX_AFICHES);
        break;
    case 5:
        ventas_printPosters(listaDeAfiches, MAX_AFICHES);
        ventas_editTransaction(listaDeAfiches, MAX_AFICHES);
        break;
    case 6:
        ventas_cobrarVenta(listaDeAfiches,MAX_AFICHES,listaDeClientes,MAX_CLIENTES);
        break;
    case 7:
        client_printClients(listaDeAfiches, MAX_AFICHES, listaDeClientes, MAX_CLIENTES);
        break;
    case 8:
        informes_printClienteConMasPendientes(listaDeClientes, listaDeAfiches, MAX_CLIENTES, MAX_AFICHES);
        informes_printClienteConMasCobradas(listaDeClientes, listaDeAfiches, MAX_CLIENTES, MAX_AFICHES);
        informes_printClienteConMasVentas(listaDeClientes, listaDeAfiches, MAX_CLIENTES, MAX_AFICHES);
        informes_printClienteConMasAfichesPendientes(listaDeClientes, listaDeAfiches, MAX_CLIENTES, MAX_AFICHES);
        informes_zonaConMenosAfichesVendidos(listaDeAfiches, MAX_AFICHES);
        informes_cantidadClientesMenos1000Afiches(listaDeClientes, listaDeAfiches, MAX_CLIENTES, MAX_AFICHES);
        informes_cantidadDeAfichesVendidosPorZona(listaDeAfiches, MAX_AFICHES);
        informes_printListaDeVentasOrdenadaPorZona(listaDeAfiches, MAX_AFICHES);
        break;
    default:
        printf("\n%d no es una opción valida.\n", selectedOption);
    }
finDeOperacion:
    printf("\n\n¿Desea realizar otra accion?\n1)Si\n2)No\n\nElección: ");
    scanf("%d", &selectedOption);
    switch (selectedOption)
    {
        case 1:
            goto menu;;
            break;
        case 2:
            return(0);
            break;
        default:
            printf("\nERROR. La opcion ingresada no corresponde a una operación valida.\n");
            goto finDeOperacion;
    }
}

