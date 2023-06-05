#ifndef PROYECTO_FINAL_ARCHIVOS_H
#define PROYECTO_FINAL_ARCHIVOS_H

#include <iostream>
#include "Clientes.h"
#include "Transacciones.h"
#include <vector>

using namespace std;

class Archivos{

    vector<Transacciones> vector_transacciones;
    vector<Clientes> vector_clientes;

    int cantidadClientes;
    int cantidadTransacciones;
public:

    void agregar_nuevo_cliente(Clientes _nuevocliente);
    void baja_cliente(int Nro_Cliente);

    void cliente_actualizado();

    void consulta_de_datos_por_numero_cliente(int numero_cliente);


    void agregar_nueva_transaccion(Transacciones _nuevaTransaccion);
    void transaccion_por_cliente(int numero_cliente);
    void transaccion_por_dia(int _dia);
    void transaccion_por_dia_mes(int _dia, int _mes);
    void transaccion_por_dia_mes_anio(int _dia, int _mes, int _anio);

    void transaccion_actualizado();




};

#endif //PROYECTO_FINAL_ARCHIVOS_H