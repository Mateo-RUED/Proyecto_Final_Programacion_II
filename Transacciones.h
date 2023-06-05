#ifndef PROYECTO_FINAL_TRANSACCIONES_H
#define PROYECTO_FINAL_TRANSACCIONES_H


class Transacciones {

    int nro_cliente;
    int nro_transaccion;
    int cantidad;
    char tipo;
    int dia;
    int mes;
    int anio;

public:

    void set_nro_cliente(int _nro_cliente);
    void set_nro_transaccion(int _nro_transacciones);
    void set_cantidad(int _cantidad);
    void set_tipo(char _tipo);
    void set_dia(int _dia);
    void set_mes(int _mes);
    void set_anio(int _anio);

    int get_nro_cliente();
    int get_nro_transacciones();
    int get_cantidad();
    char get_tipo();
    int get_dia();
    int get_mes();
    int get_anio();

};


#endif //PROYECTO_FINAL_TRANSACCIONES_H
