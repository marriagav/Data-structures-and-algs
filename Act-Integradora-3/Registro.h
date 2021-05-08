#ifndef REGISTRO_H
#define REGISTRO_H
#include <algorithm>
#include "Fecha.h"

class Registro{
    private:
    Fecha date;
    string ipPort;
    string falla;
    long ipNoPort;

    public:
    //constructores:
    Registro();
    Registro(Fecha,string,string);

    //metodos:
    string getIp();
    string getFalla();
    Fecha getFecha();
    long getIpNoPort();
    void calculateIp();
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
    calculateIp();
}

//con argumentos: Fecha date, string ipPort, string falla:
Registro::Registro(Fecha _fecha, string _ipPort, string _falla){
    date=_fecha;
    ipPort=_ipPort;
    falla=_falla;
    calculateIp();
}

void Registro::calculateIp(){
    std::string noPortStr=ipPort.substr(0,ipPort.length()-5);
    noPortStr.erase(remove(noPortStr.begin(), noPortStr.end(), '.'), noPortStr.end());
    ipNoPort=std::stol(noPortStr);
}

Fecha Registro::getFecha(){
    return date;
}

long Registro::getIpNoPort(){
    return ipNoPort;
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