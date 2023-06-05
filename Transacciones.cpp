#include "Transacciones.h"

void Transacciones::set_nro_cliente(int _nro_cliente) {

    nro_cliente=_nro_cliente;

}

void Transacciones::set_nro_transaccion(int _nro_transacciones) {

    nro_transaccion=_nro_transacciones;

}

void Transacciones::set_cantidad(int _cantidad) {

    cantidad=_cantidad;

}

void Transacciones::set_tipo(char _tipo) {

    tipo=_tipo;

}

void Transacciones::set_dia(int _dia) {

    dia=_dia;

}

void Transacciones::set_mes(int _mes) {

    mes=_mes;

}

void Transacciones::set_anio(int _anio) {

    anio=_anio;

}

int Transacciones::get_nro_cliente() {
    return nro_cliente;
}

int Transacciones::get_nro_transacciones() {
    return nro_transaccion;
}

int Transacciones::get_cantidad() {
    return cantidad;
}

char Transacciones::get_tipo() {
    return tipo;
}

int Transacciones::get_dia() {
    return dia;
}

int Transacciones::get_mes() {
    return mes;
}

int Transacciones::get_anio() {
    return anio;
}
