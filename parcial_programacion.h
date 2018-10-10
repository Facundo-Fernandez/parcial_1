#ifndef PARCIAL_PROGRAMACION_H_INCLUDED
#define PARCIAL_PROGRAMACION_H_INCLUDED
#define MAX_CLIENTES 100
#define MAX_AFICHES 1000
#define CABA 1
#define ZONA_SUR 2
#define ZONA_OESTE 3

typedef struct
{
    char nombre[32];
    char apellido[32];
    char cuit[12];
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

void initClient(Cliente* listaDeClientes, int length);
void printClients (Afiches* listaDeAfiches, int aLength, Cliente* listaDeClientes, int cLength);
int nextEmptySlot(Cliente* listaDeClientes);
int nextEmptySlot_v(Afiches* listaDeAfiches);
int generateID (void);
int generateID_v (void);
int addClient (Cliente* listaDeClientes, int cLength);
void modifyClient(Cliente* listaDeEmpleados, int cLength);
int removeClient (Cliente* listaDeClientes, int cLength);
void initAfiches(Afiches* listaDeAfiches, int length);
int sellPosters(Afiches* listaDeAfiches, int aLength);
void printPosters (Afiches* listaDeAfiches, int aLength);
int editTransaction(Afiches* listaDeAfiches, int aLength);
int contadorDeACobrar(Afiches* listaDeAfiches, int aLength, int idCliente);
int cobrarVenta(Afiches* listaDeAfiches, int aLength, Cliente* listaDeClientes, int cLength);
int getCuit (char* pString, int tries, char* msg, char* errorMsg, int lenght);

#endif // PARCIAL_PROGRAMACION_H_INCLUDED
