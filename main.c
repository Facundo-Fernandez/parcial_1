#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "utn.h"
#include "parcial_programacion.h"

int main()
{
    Afiches listaDeAfiches[MAX_AFICHES];
    Cliente listaDeClientes[MAX_CLIENTES];
    int selectedOption;

    printf("ventaDeAfiches v0.1");
    initAfiches(listaDeAfiches, MAX_AFICHES);
    initClient(listaDeClientes, MAX_CLIENTES);
menu:
    printf("\n-------------------------------- Menu principal --------------------------------\n\n");
    printf("Seleccione la opción que desea llevar a cabo:\n\n1) Alta de cliente\n2) Modificar datos de cliente\n3) Baja de cliente\n4) Vender afiches\n5) Editar venta\n6) Cobrar venta\n7) Imprimir clientes\n\nOpción elegida: ");
    scanf("%d", &selectedOption);
    switch(selectedOption)
    {
    case 1:
        addClient(listaDeClientes, MAX_CLIENTES);
        break;
    case 2:
        modifyClient(listaDeClientes, MAX_CLIENTES);
        break;
    case 3:
        removeClient(listaDeClientes, MAX_CLIENTES);
        break;
    case 4:
        sellPosters(listaDeAfiches, MAX_AFICHES);
        break;
    case 5:
        printPosters(listaDeAfiches, MAX_AFICHES);
        editTransaction(listaDeAfiches, MAX_AFICHES);
        break;
    case 6:
        cobrarVenta(listaDeAfiches,MAX_AFICHES,listaDeClientes,MAX_CLIENTES);
        break;
    case 7:
        printClients(listaDeAfiches, MAX_AFICHES, listaDeClientes, MAX_CLIENTES);
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
