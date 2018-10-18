#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED


void informes_printClienteConMasPendientes(Cliente* listaDeClientes, Afiches* listaDeAfiches, int cLength, int aLength);
void informes_printClienteConMasCobradas(Cliente* listaDeClientes, Afiches* listaDeAfiches, int cLength, int aLength);
void informes_printClienteConMasVentas(Cliente* listaDeClientes, Afiches* listaDeAfiches, int cLength, int aLength);
void informes_printClienteConMasAfichesPendientes(Cliente* listaDeClientes, Afiches* listaDeAfiches, int cLength, int aLength);
void informes_printClienteConMasAfichesCobrados(Cliente* listaDeClientes, Afiches* listaDeAfiches, int cLength, int aLength);
void informes_zonaConMenosAfichesVendidos(Afiches* listaDeAfiches, int aLength);
void informes_cantidadClientesMenos1000Afiches(Cliente* listaDeClientes, Afiches* listaDeAfiches, int cLength, int aLength);
void informes_cantidadDeAfichesVendidosPorZona (Afiches* listaDeAfiches, int aLength);
void informes_printListaDeVentasOrdenadaPorZona (Afiches* listaDeAfiches, int aLength);
void informes_printPromedioDeAfiches(Cliente* listaDeClientes, Afiches* listaDeAfiches, int cLength, int aLength);


#endif // INFORMES_H_INCLUDED
