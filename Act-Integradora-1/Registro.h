#ifndef REGISTRO_H
#define REGISTRO_H
#include "Fecha.h"

class Registro{
    private:
    Fecha date;
    string ipPort;
    string falla;
    public:
    //constructores:
    Registro();
    Registro(Fecha,string,string);

    //metodos:
    Fecha getFecha();
    string getDato();

};
//constructor default:
Registro::Registro(){
    date=Fecha();
    ipPort="00.000.00.00:0000";
    falla="Un error";
}

//con argumentos: Fecha date, string ipPort, string falla:
Registro::Registro(Fecha _fecha, string _ipPort, string _falla){
    date=_fecha;
    ipPort=_ipPort;
    falla=_falla;
}

Fecha Registro::getFecha(){
    return date;
}

string Registro::getDato(){
    return(date.getFecha()+" "+ipPort+" "+falla);
}

#endif