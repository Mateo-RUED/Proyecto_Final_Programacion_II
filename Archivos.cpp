#include "Archivos.h"
#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

void Archivos::cliente_actualizado() {

    string linea;

    cantidadClientes=0;

    ifstream archivo("clientes.txt");  // Abrir el archivo de texto

    // Contar la cantidad de clientes en el archivo
    while (getline(archivo, linea)) {
        cantidadClientes++;
    }

    cantidadClientes=cantidadClientes-1;

    archivo.close();  // Cerrar el archivo

    cout<<cantidadClientes;

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
        f >> anio;
        f >> estado;

        c.setNumeroCliente(nro_cliente);
        c.setNombre(nombre);
        c.setApellido(apellido);
        c.setTipo(tipo);
        c.setAnio(anio);
        c.setEstado(estado);

        vector_clientes.push_back(c);


    }

}

void Archivos::agregar_nuevo_cliente() {

    string nombre, apellido, tipo, estado;
    int anio;

    Clientes _nuevocliente;

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

    cantidadClientes_nuevos+1;
}

void Archivos::baja_cliente() {

    int Nro_Cliente;

    cout<<"Ingrese el numero del cliente al que le quiere le cambiar el Estado a Baja :"<<endl;
    cin>>Nro_Cliente;


    for (int i=0; i<vector_clientes.size(); i++) {

        if (vector_clientes[i].getNumeroCliente() == Nro_Cliente) {
            vector_clientes[i].setEstado("baja");

            cout<<"***** SE LE HA CAMBIADO EL ESTADO AL CLIENTE DE NUMERO "<<Nro_Cliente<<" DE ACTIVO A BAJA"<<endl;
            cout<<endl;
            break;
        }
    }
}

void Archivos::consulta_de_datos_por_numero_cliente() {


    int numero_cliente;

    cout<<"Ingrese el numero del cliente que quiere consultar sus datos :"<<endl;
    cin>> numero_cliente;

    for (int i=0; i<vector_clientes.size(); i++) {

        if (vector_clientes[i].getNumeroCliente() == numero_cliente) {

            cout<<"******* DATOS DE SU CLIENTE ******"<<endl;
            cout<<endl;
            cout<<"Nombre: "<<vector_clientes[i].getNombre()<<endl;
            cout<<"Apellido: "<<vector_clientes[i].getApellido()<<endl;
            cout<<"Tipo: "<<vector_clientes[i].getTipo()<<endl;
            cout<<"Anio: "<<vector_clientes[i].getAnio()<<endl;
            cout<<"Estado: "<<vector_clientes[i].getEstado()<<endl;
            cout<<endl;

                if(vector_clientes[i].getTipo() == "oro"){

                    std::cout << "******************************************" << std::endl;
                    std::cout << "* TIENE ACCESO A UNA TARJETA DE $50.000  *" << std::endl;
                    std::cout << "******************************************" << std::endl;

                }

                if(vector_clientes[i].getTipo() == "black"){

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

    string linea;

    cantidadTransacciones=0;

    ifstream archivo("transacciones.txt");  // Abrir el archivo de texto

    // Contar la cantidad de clientes en el archivo
    while (getline(archivo, linea)) {
        cantidadTransacciones++;
    }

    cantidadTransacciones=cantidadTransacciones-1;

    archivo.close();  // Cerrar el archivo

    ifstream f("transacciones.txt");

    for (int i=0; i<7;i++){

        f>>palabras_trans[i];

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
        c.set_tipo(tipo);
        c.set_dia(dia);
        c.set_mes(mes);
        c.set_anio(anio);

        vector_transacciones.push_back(c);
    }

    f.close();
    //Segunda Parte
/*
    ofstream r("Transacciones.txt");

    for(int i=0; i<6; i++) {

        r << palabras[i] << "      ";
    }

    r<<endl;

    for (int i=0; i<vector_transacciones.size(); i++) {
        r << vector_transacciones[i].get_nro_cliente() << "                ";
        r << vector_transacciones[i].get_nro_transacciones(0) << "      ";
        r << vector_transacciones[i].get_cantidad() << "         ";
        r << vector_transacciones[i].get_tipo() << "      ";
        r << vector_transacciones[i].get_dia() << "      ";
        r << vector_transacciones[i].get_mes()<< "      ";
        r << vector_transacciones[i].get_anio()<<"      ";
        r << endl;
    }

    r.close();
*/
}

void Archivos::consulta_transaccion_por_cliente() {

    int numero_cliente;

    cout<<"Ingrese el numero del cliente al que quiere consultar sus transacciones :"<<endl;
    cin>>numero_cliente;

    for (int i=0; i<vector_transacciones.size(); i++){

        if(vector_transacciones[i].get_nro_cliente()==numero_cliente){

            cout << "*****INFORMACION DE TRANSACCION NUMERO " << vector_transacciones[i].get_nro_transacciones()
                 << "  :*****" << endl;
            cout <<"cantidad :"<< vector_transacciones[i].get_cantidad() <<endl;
            cout <<"tipo :" <<vector_transacciones[i].get_tipo() << endl;
            cout << "fecha:"<<vector_transacciones[i].get_dia()<<"/";
            cout << vector_transacciones[i].get_mes()<<"/";
            cout << vector_transacciones[i].get_anio()<<"/"<< endl;
            cout << endl;

        }
    }


}

void Archivos::consulta_transaccion_6_meses() {

    int anio;
    int periodo, periodo_1;


    cout<<"Ingrese el año del periodo :"<<endl;
    cin>>anio;
    cout<<"Ingrese el periodo del ao al que quiere consultar (1 = primero, 2 = segundo) :"<<endl;
    cin>>periodo;



    for (int i=0; i<vector_transacciones.size(); i++){

        if(vector_transacciones[i].get_mes()<=6){

            periodo_1=1;

        }

        if(vector_transacciones[i].get_mes()>6){

            periodo_1=2;

        }

        if(vector_transacciones[i].get_anio() == anio && periodo == periodo_1){

            cout << "*****INFORMACION DE TRANSACCION :*****" << endl;

            cout << "numero de cliente: "<< vector_transacciones[i].get_nro_cliente()<<endl;
            cout <<"cantidad: "<< vector_transacciones[i].get_cantidad() <<endl;
            cout <<"tipo: " <<vector_transacciones[i].get_tipo() << endl;
            cout << "fecha: "<<vector_transacciones[i].get_dia()<<"/";
            cout << vector_transacciones[i].get_mes()<<"/";
            cout << vector_transacciones[i].get_anio()<<"/"<< endl;
            cout << endl;

        }
    }

}

void Archivos::consulta_transaccion_anio() {

    int _anio;

    cout<<"Ingrese el anio al que quiere consultar las transacciones :"<<endl;
    cin>>_anio;


    for (int i=0; i<vector_transacciones.size(); i++){

        if(vector_transacciones[i].get_anio()==_anio){

            cout << "*****INFORMACION DE TRANSACCIONES EN EL ANIO " << vector_transacciones[i].get_anio()<<":*****"<< endl;
            cout << "numero de cliente: "<< vector_transacciones[i].get_nro_cliente()<<endl;
            cout <<"cantidad: "<< vector_transacciones[i].get_cantidad() <<endl;
            cout <<"tipo: " <<vector_transacciones[i].get_tipo() << endl;
            cout << "fecha: "<<vector_transacciones[i].get_dia()<<"/";
            cout << vector_transacciones[i].get_mes()<<"/";
            cout << vector_transacciones[i].get_anio()<<"/"<< endl;
            cout << endl;

        }
    }

}

void Archivos::consulta_transaccion_total() {


    for (int i=0; i<vector_transacciones.size(); i++){

            cout << "*****INFORMACION DE TRANSACCIONES TOTAL " << vector_transacciones[i].get_dia()<<"/"<< vector_transacciones[i].get_mes()<<"/"<< vector_transacciones[i].get_anio()
                 << "  :*****" << endl;

            cout << "numero de cliente: "<< vector_transacciones[i].get_nro_cliente()<<endl;
            cout <<"cantidad: "<< vector_transacciones[i].get_cantidad() <<endl;
            cout <<"tipo: " <<vector_transacciones[i].get_tipo() << endl;
            cout << "fecha: "<<vector_transacciones[i].get_dia()<<"/";
            cout << vector_transacciones[i].get_mes()<<"/";
            cout << vector_transacciones[i].get_anio()<<"/"<< endl;
            cout << endl;
            cout <<endl;

    }


}

void Archivos::agregar_nueva_transaccion() {

    int nro_cliente;
    int anio, mes, dia, cantidad;
    char tipo;

    Transacciones _nuevaTransaccion;

    cout<<"Ingrese su numero de cliente :"<<endl;
    cin>>nro_cliente;

    if(vector_clientes[nro_cliente].getEstado() == "baja"){

        cout<<"+++++++++  ALERTA  ++++++++++"<<endl;

        cout<<"USTED NO PUEDE HACER UNA TRANSACCION YA QUE SE ENCUENTRA EN ESTADO DE BAJA "<<endl;
        cout<<endl;


    }

    else{

        cout<<"Ingrese el tipo de transaccion :"<<endl;
        cin>>tipo;
        cout<<"Ingrese la cantidad :"<<endl;
        cin>>cantidad;
        cout<<"Ingrese el dia :"<<endl;
        cin>>dia;
        cout<<"Ingrese el mes:"<<endl;
        cin>> mes;
        cout<<"Ingrese el anio :"<<endl;
        cin>>anio;

        _nuevaTransaccion.set_nro_cliente(nro_cliente);
        _nuevaTransaccion.set_anio(anio);
        _nuevaTransaccion.set_dia(dia);
        _nuevaTransaccion.set_mes(mes);
        _nuevaTransaccion.set_cantidad(cantidad);
        _nuevaTransaccion.set_tipo(tipo);
        _nuevaTransaccion.set_nro_transaccion(cantidadTransacciones+1);

        vector_transacciones.push_back(_nuevaTransaccion);

    }


}

void Archivos::cliente_actualizado_nuevo() {

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

void Archivos::transaccion_actualizado_nuevo(){

ofstream r("Transacciones.txt");

for(int i=0; i<7; i++) {

r << palabras_trans[i] << "           ";
}

r<<endl;

for (int i=0; i<cantidadTransacciones+1; i++) {
r << vector_transacciones[i].get_nro_cliente() << "                     ";
r << vector_transacciones[i].get_nro_transacciones() << "                         ";
r << vector_transacciones[i].get_cantidad() << "                ";
r << vector_transacciones[i].get_tipo() << "              ";
r << vector_transacciones[i].get_dia() << "            ";
r << vector_transacciones[i].get_mes()<< "             ";
r << vector_transacciones[i].get_anio()<<"             ";
r << endl;
}

r.close();
}

void Archivos::consulta_cliente_total() {

    for (int i=0; i<vector_clientes.size(); i++){

        cout << "*****INFORMACION DE TODOS LOS CLIENTES ******"<<endl;

        cout<<"Nombre: "<<vector_clientes[i].getNombre()<<endl;
        cout<<"Apellido: "<<vector_clientes[i].getApellido()<<endl;
        cout<<"Tipo: "<<vector_clientes[i].getTipo()<<endl;
        cout<<"Anio: "<<vector_clientes[i].getAnio()<<endl;
        cout<<"Estado: "<<vector_clientes[i].getEstado()<<endl;
        cout<<endl;

    }

}
