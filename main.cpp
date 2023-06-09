#include <iostream>
#include "Clientes.h"
#include "Archivos.h"
#include <fstream>

using namespace std;

void Menu(){
    cout<<"**Banco UCC**"<<endl;
    cout<<"1.Dar de alta a un cliente nuevo"<<endl; //*
    cout<<"2.Consulta de cliente por numero de cliente"<<endl;
    cout<<"3.Consulta de transacciones"<<endl;//*
    cout<<"4.Consulta de todos los clientes"<<endl;//*
    cout<<"5.Dar de baja a un cliente"<<endl;
    cout<<"6.Hacer una transaccion"<<endl;
    cout<<"7.Salir"<<endl;

}

int main() {

    Archivos a;

    int respuesta;

    a.cliente_actualizado();
    a.transaccion_actualizado();

    do {
        respuesta = 0;
        Menu();
        cout << "Ingrese la opcion que desea ejecutar" << endl;
        cin >> respuesta;
        switch (respuesta) {
            case 1:

                a.agregar_nuevo_cliente();
                a.cliente_actualizado_nuevo();

                break;
            case 2:
                a.consulta_de_datos_por_numero_cliente();
                break;
            case 3:
                int opcion;
                cout << "Que tipo de consulta desea realizar: " << endl;
                cout << "1.Por periodo de 6 meses" << endl;
                cout << "2.Por un anio entero" << endl;
                cout << "3.El total de transacciones" << endl;
                cout << "4.Por Cliente" << endl;
                cout << "Elija 1, 2, 3 o 4 segun corresponda" << endl;
                cin >> opcion;

                if (opcion == 1) {
                    cout << "1" << endl;
                    a.consulta_transaccion_6_meses();
                }
                if (opcion == 2) {
                    cout << "2" << endl;
                    a.consulta_transaccion_anio();
                }
                if (opcion == 3) {
                    cout << "3" << endl;
                    a.consulta_transaccion_total();
                }
                if(opcion == 4){
                    a.consulta_transaccion_por_cliente();
                }
                break;
            case 4:
                a.consulta_cliente_total();
                break;
            case 5:
                a.baja_cliente();
                a.cliente_actualizado_nuevo();
                break;
            case 6:

                a.agregar_nueva_transaccion();
                a.transaccion_actualizado_nuevo();
                break;
            case 7:
                exit(0);
                break;
            default:
                respuesta = 8;
                cout << "La opcion ingresada en incorrecta, ingrese nuevamente" << endl;
        }

    } while (respuesta == 8 || (respuesta >= 1 && respuesta <= 7));

    return 0;

}
