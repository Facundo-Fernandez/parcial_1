#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#define MAX_CLIENTES 100


typedef struct
{
    char nombre[32];
    char apellido[32];
    char cuit[11];
    int id;
    int isEmpty;
}Cliente;

typedef struct
{
    int idCliente;
    int idVenta;
    int cantidadAfiches;
    char nombreArchivo[25];
    int zona;
    int isEmpty;
    int aCobrar;
    int cobrada;
}Afiches;

void client_initClient(Cliente* listaDeClientes, int length);
int client_nextEmptySlot(Cliente* listaDeClientes);
int client_generateID (void);
int client_addClient (Cliente* listaDeClientes, int cLength);
void client_modifyClient(Cliente* listaDeEmpleados, int cLength);
int client_removeClient (Cliente* listaDeClientes, int cLength);
void client_printClients (Afiches* listaDeAfiches, int aLength, Cliente* listaDeClientes, int cLength);
int client_getCuit (char* pString, int tries, char* msg, char* errorMsg, int lenght);
void cargaForzada(Cliente* listaDeClientes);


#endif // CLIENTES_H_INCLUDED
