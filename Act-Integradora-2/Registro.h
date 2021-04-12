#ifndef REGISTRO_H
#define REGISTRO_H
#include "Fecha.h"

class Registro{
    private:
    Fecha date;
    string ipPort;
    string falla;

    public:
    Registro* next;
    Registro* prev;

    //constructores:
    Registro();
    Registro(Fecha,string,string);

    //metodos:
    string getIp();
    string getFalla();
    Fecha getFecha();
    void setIp(string);
    void setFalla(string);
    void setFecha(Fecha);

    string getDato();

};
//constructor default:
Registro::Registro(){
    date=Fecha();
    ipPort="00.000.00.00:0000";
    falla="Un error";
    next=NULL;
    prev=NULL;
}

//con argumentos: Fecha date, string ipPort, string falla:
Registro::Registro(Fecha _fecha, string _ipPort, string _falla){
    date=_fecha;
    ipPort=_ipPort;
    falla=_falla;
    next=NULL;
    prev=NULL;
}

Fecha Registro::getFecha(){
    return date;
}

string Registro::getIp(){
    return ipPort;
}

string Registro::getFalla(){
    return falla;
}

void Registro::setIp(string _ip){
    ipPort=_ip;
}

void Registro::setFalla(string _falla){
    falla=_falla;
}

void Registro::setFecha(Fecha _date){
    date=_date;
}

string Registro::getDato(){
    return(date.getFecha()+" "+ipPort+" "+falla);
}

#endif