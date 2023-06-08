
#include "Clientes.h"

using namespace std;

Clientes::Clientes(int _nro_cliente, std::string _nombre, std::string _apellido, std::string _tipo, int _anio,
                   std::string _estado) {

    nro_cliente=_nro_cliente;
    nombre=_nombre;
    apellido=_apellido;
    tipo=_tipo;
    anio=_anio;
    estado=_estado;

}

Clientes::Clientes() {

    nro_cliente=0;
    nombre= " ";
    apellido= " ";
    tipo= " ";
    anio= 0;
    estado= " ";

}

int Clientes::getNumeroCliente() const {
    return nro_cliente;
}

void Clientes::setNumeroCliente(int _numeroCliente) {

    nro_cliente=_numeroCliente;

}

string Clientes::getNombre() {

    return nombre;

}

void Clientes::setNombre(string _nombre) {

    nombre=_nombre;

}

string Clientes::getApellido() {

    return apellido;

}

void Clientes::setApellido(string _apellido) {

    apellido=_apellido;

}

string Clientes::getTipo() {
    return tipo;
}

void Clientes::setTipo(string _tipo) {

    tipo=_tipo;

}

int Clientes::getAnio() {
    return anio;
}

void Clientes::setAnio(int _anio) {

    anio=_anio;

}

string Clientes::getEstado() {
    return estado;
}

void Clientes::setEstado(string _estado) {

    estado=_estado;
}



