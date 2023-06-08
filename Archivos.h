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

    string palabras_trans[7];
    string palabras[6];

    int cantidadClientes_nuevos;
    int cantidadClientes;
    int cantidadTransacciones;

public:

    void agregar_nuevo_cliente();
    void baja_cliente();

    void cliente_actualizado();
    void cliente_actualizado_nuevo();
    void consulta_de_datos_por_numero_cliente();


    void agregar_nueva_transaccion();
    void consulta_transaccion_por_cliente();
    void consulta_transaccion_por_dia();
    void consulta_transaccion_por_dia_mes();
    void consulta_transaccion_por_dia_mes_anio();

    void transaccion_actualizado();
    void transaccion_actualizado_nuevo();

};

#endif //PROYECTO_FINAL_ARCHIVOS_H