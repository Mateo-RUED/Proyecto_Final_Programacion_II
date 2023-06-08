#include <iostream>
#include "Clientes.h"
#include "Archivos.h"
#include <fstream>

using namespace std;

int main() {

    Archivos a;
    a.cliente_actualizado();

    a.transaccion_actualizado();
    a.agregar_nueva_transaccion();
    a.transaccion_actualizado_nuevo();
    a.consulta_transaccion_por_cliente();

}
