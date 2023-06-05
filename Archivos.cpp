#include "Archivos.h"
#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

void Archivos::cliente_actualizado() {

    string palabras[6];

    string linea;

    ifstream archivo("clientes.txt");  // Abrir el archivo de texto

    // Contar la cantidad de clientes en el archivo
    while (getline(archivo, linea)) {
        cantidadClientes++;
    }

    cantidadClientes=cantidadClientes-1;

    archivo.close();  // Cerrar el archivo


    ifstream f("clientes.txt");

    for (int i=0; i<6;i++){

        f>>palabras[i];

    }

    for (int i = 0; i < cantidadClientes; i++) {
        Clientes c;
        string nombre, apellido, tipo, estado;
        int anio, nro_cliente;

        f >> nro_cliente;
        f >> nombre;
        f >> apellido;
        f >> tipo;
        f >>anio;
        f >>estado;


        c.setNombre(nombre);
        c.setApellido(apellido);
        c.setTipo(tipo);
        c.setAnio(anio);
        c.setEstado(estado);
        c.setNumeroCliente(nro_cliente);

        vector_clientes.push_back(c);
    }

    f.close();
    //Segunda Parte

    ofstream r("clientes.txt");

    for(int i=0; i<6; i++) {

        r << palabras[i] << "      ";
    }

    r<<endl;

    for (int i=0; i<vector_clientes.size(); i++) {
        r << vector_clientes[i].getNumeroCliente() << "                ";
        r << vector_clientes[i].getNombre() << "      ";
        r << vector_clientes[i].getApellido() << "         ";
        r << vector_clientes[i].getTipo() << "      ";
        r << vector_clientes[i].getAnio() << "      ";
        r << vector_clientes[i].getEstado()<< "      ";
        r << endl;
    }

    r.close();

}

void Archivos::agregar_nuevo_cliente(Clientes _nuevocliente) {

    string nombre, apellido, tipo, estado;
    int anio;


    cout<<"Ingrese su nombre :"<<endl;
    cin>>nombre;
    cout<<"Ingrese su apellido :"<<endl;
    cin>>apellido;
    cout<<"Ingrese su anio :"<<endl;
    cin>>anio;
    cout<<"Ingrese su estado :"<<endl;
    cin>>estado;

    if(anio>=2021){

        tipo="plata";

    }

    if(anio<2021 ^ anio>=2019){

        tipo="oro";

    }

    if(anio<2019){

        tipo="black";

    }

    _nuevocliente.setNombre(nombre);
    _nuevocliente.setApellido(apellido);
    _nuevocliente.setTipo(tipo);
    _nuevocliente.setAnio(anio);
    _nuevocliente.setEstado(estado);
    _nuevocliente.setNumeroCliente(cantidadClientes+1);

    vector_clientes.push_back(_nuevocliente);

}

void Archivos::baja_cliente(int Nro_Cliente) {

    for (int i=0; i<vector_clientes.size(); i++) {

        if (vector_clientes[i].getNumeroCliente() == Nro_Cliente) {
            vector_clientes[i].setEstado("baja");

            cout<<"***** SE LE HA CAMBIADO EL ESTADO AL CLIENTE DE NUMERO "<<Nro_Cliente<<" DE ACTIVO A BAJA"<<endl;
            cout<<endl;
            break;
        }
    }
}

void Archivos::consulta_de_datos_por_numero_cliente(int numero_cliente) {

    for (int i=0; i<vector_clientes.size(); i++) {

        if (vector_clientes[i].getNumeroCliente() == numero_cliente) {

            cout<<"******* DATOS DE SU CLIENTE ******"<<endl;
            cout<<endl;
            cout<<"Nombre: "<<vector_clientes[i].getNombre();
            cout<<"Apellido: "<<vector_clientes[i].getApellido();
            cout<<"Tipo: "<<vector_clientes[i].getTipo();
            cout<<"Anio: "<<vector_clientes[i].getAnio();
            cout<<"Estado: "<<vector_clientes[i].getEstado();
            cout<<endl;

                if(vector_clientes[i].getEstado()=="oro"){

                    std::cout << "******************************************" << std::endl;
                    std::cout << "* TIENE ACCESO A UNA TARJETA DE $50.000  *" << std::endl;
                    std::cout << "******************************************" << std::endl;

                }

                if(vector_clientes[i].getEstado()=="black"){

                    std::cout << "******************************************" << std::endl;
                    std::cout << "* TIENE ACCESO A UNA TARJETA DE $250.000 *" << std::endl;
                    std::cout << "******************************************" << std::endl;

                }

            cout<<endl;
            cout<<endl;
            break;
        }
    }


}

void Archivos::transaccion_actualizado() {

    string palabras[7];

    string linea;

    ifstream archivo("transacciones.txt");  // Abrir el archivo de texto

    // Contar la cantidad de clientes en el archivo
    while (getline(archivo, linea)) {
        cantidadTransacciones++;
    }

    cantidadTransacciones=cantidadTransacciones-1;

    archivo.close();  // Cerrar el archivo


    ifstream f("transacciones.txt");

    for (int i=0; i<6;i++){

        f>>palabras[i];

    }

    for (int i = 0; i < cantidadTransacciones; i++) {
        Transacciones c;
        int nro_cliente, nro_transaccion, cantidad, dia, mes, anio;
        char tipo;

        f >> nro_cliente;
        f >> nro_transaccion;
        f >> cantidad;
        f >> tipo;
        f >>dia;
        f >>mes;
        f >>anio;


        c.set_nro_cliente(nro_cliente);
        c.set_nro_transaccion(nro_transaccion);
        c.set_cantidad(cantidad);
        c.set_dia(dia);
        c.set_mes(mes);
        c.set_anio(anio);

        vector_transacciones.push_back(c);
    }

    f.close();
    //Segunda Parte

    ofstream r("Transacciones.txt");

    for(int i=0; i<6; i++) {

        r << palabras[i] << "      ";
    }

    r<<endl;

    for (int i=0; i<vector_transacciones.size(); i++) {
        r << vector_transacciones[i].get_nro_cliente() << "                ";
        r << vector_transacciones[i].get_nro_transacciones()<< "      ";
        r << vector_transacciones[i].get_cantidad() << "         ";
        r << vector_transacciones[i].get_tipo() << "      ";
        r << vector_transacciones[i].get_dia() << "      ";
        r << vector_transacciones[i].get_mes()<< "      ";
        r << vector_transacciones[i].get_anio()<<"      ";
        r << endl;
    }

    r.close();

}

void Archivos::transaccion_por_cliente(int numero_cliente) {

    for (int i=0; i<vector_transacciones.size(); i++){

        if(vector_transacciones[i].get_nro_cliente()==numero_cliente){

            cout <<"*****INFORMACION DE TRANSACCION NUMERO "<< vector_transacciones[i].get_nro_transacciones()<<"  :*****"<<endl;
            cout <<"cantidad :"<< vector_transacciones[i].get_cantidad() <<endl;
            cout <<"tipo :" <<vector_transacciones[i].get_tipo() << endl;
            cout << "fecha:"<<vector_transacciones[i].get_dia()<<"/";
            cout << vector_transacciones[i].get_mes()<<"/";
            cout << vector_transacciones[i].get_anio()<<"/"<< endl;
            cout << endl;

        }
    }


}

void Archivos::transaccion_por_dia(int _dia) {

    for (int i=0; i<vector_transacciones.size(); i++){

        if(vector_transacciones[i].get_dia()==_dia){

            cout <<"*****INFORMACION DE TRANSACCION NUMERO "<< vector_transacciones[i].get_nro_transacciones()<<"  :*****"<<endl;
            cout <<"cantidad :"<< vector_transacciones[i].get_cantidad() <<endl;
            cout <<"tipo :" <<vector_transacciones[i].get_tipo() << endl;
            cout << "fecha:"<<vector_transacciones[i].get_dia()<<"/";
            cout << vector_transacciones[i].get_mes()<<"/";
            cout << vector_transacciones[i].get_anio()<<"/"<< endl;
            cout << endl;

        }
    }

}

void Archivos::transaccion_por_dia_mes(int _dia, int _mes) {

    for (int i=0; i<vector_transacciones.size(); i++){

        if(vector_transacciones[i].get_dia()==_dia ^ vector_transacciones[i].get_mes()==_mes){

            cout <<"*****INFORMACION DE TRANSACCION NUMERO "<< vector_transacciones[i].get_nro_transacciones()<<"  :*****"<<endl;
            cout <<"cantidad :"<< vector_transacciones[i].get_cantidad() <<endl;
            cout <<"tipo :" <<vector_transacciones[i].get_tipo() << endl;
            cout << "fecha:"<<vector_transacciones[i].get_dia()<<"/";
            cout << vector_transacciones[i].get_mes()<<"/";
            cout << vector_transacciones[i].get_anio()<<"/"<< endl;
            cout << endl;

        }
    }

}

void Archivos::transaccion_por_dia_mes_anio(int _dia, int _mes, int _anio) {

    for (int i=0; i<vector_transacciones.size(); i++){

        if(vector_transacciones[i].get_dia()==_dia ^ vector_transacciones[i].get_mes()==_mes ^ vector_transacciones[i].get_anio()==_anio ){

            cout <<"*****INFORMACION DE TRANSACCION NUMERO "<< vector_transacciones[i].get_nro_transacciones()<<"  :*****"<<endl;
            cout <<"cantidad :"<< vector_transacciones[i].get_cantidad() <<endl;
            cout <<"tipo :" <<vector_transacciones[i].get_tipo() << endl;
            cout << "fecha:"<<vector_transacciones[i].get_dia()<<"/";
            cout << vector_transacciones[i].get_mes()<<"/";
            cout << vector_transacciones[i].get_anio()<<"/"<< endl;
            cout << endl;

        }
    }


}

void Archivos::agregar_nueva_transaccion(Transacciones _nuevaTransaccion) {

    vector_transacciones.push_back(_nuevaTransaccion);

}
