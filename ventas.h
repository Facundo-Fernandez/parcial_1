#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED
#define MAX_AFICHES 1000
#define CABA 1
#define ZONA_SUR 2
#define ZONA_OESTE 3

int ventas_nextEmptySlot(Afiches* listaDeAfiches);
int ventas_generateID (void);
void ventas_initAfiches(Afiches* listaDeAfiches, int length);
int ventas_sellPosters(Cliente* listaDeClientes, Afiches* listaDeAfiches, int aLength);
void ventas_printPosters (Afiches* listaDeAfiches, int aLength);
int ventas_editTransaction(Afiches* listaDeAfiches, int aLength);
int ventas_cobrarVenta(Afiches* listaDeAfiches, int aLength, Cliente* listaDeClientes, int cLength);
int ventas_contadorDeACobrar(Afiches* listaDeAfiches, int aLength, int idCliente);
int ventas_contadorDeCobradas(Afiches* listaDeAfiches, int aLength, int idCliente);
#endif // VENTAS_H_INCLUDED
