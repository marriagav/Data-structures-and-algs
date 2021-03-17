#ifndef FECHA_H
#define FECHA_H

#include <string>
#include <iostream>
#include <map>

using std::cout;
using std::string;

//clase fecha, sirve para poder comparar fechas entre ellas y conocer cuál es mayor
class Fecha{
    private:
    int mes;
    int dia;
    int hora;
    int minuto;
    int segundo;
    string codigoMes;

    public:
    //constructores:
    Fecha();
    Fecha(string, int, int, int, int);

    //sobrecarga de operadores booleanos:
    bool operator ==(const Fecha& fecha2);
    bool operator >(const Fecha& fecha2);
    bool operator <(const Fecha& fecha2);
    bool operator >=(const Fecha& fecha2);
    bool operator <=(const Fecha& fecha2);

    //metodos:
    string getFecha();
    int numMes();
};

//constructores:
Fecha::Fecha(){
    codigoMes="Jan";
    mes=numMes();
    dia,hora,minuto,segundo=1;
}

//Constructor, toma mes, dia, hora, minuto y segundo como enteros
Fecha::Fecha(string _codigoMes,int _dia,int _hora,int _minuto,int _segundo){
    codigoMes=_codigoMes;
    mes=numMes();
    dia=_dia;
    hora=_hora;
    minuto=_minuto;
    segundo=_segundo;
}

//sobrecarga de operadores para poder comparar fechas entre ellas
bool Fecha::operator ==(const Fecha& fecha2){
    return (mes==fecha2.mes & dia==fecha2.dia & hora==fecha2.hora & minuto==fecha2.minuto & segundo==fecha2.segundo);
}
bool Fecha::operator >(const Fecha& fecha2){
    if (mes>fecha2.mes){
        return true;
    }
    else if (mes<fecha2.mes){
        return false;
    }
    else{
        if (dia>fecha2.dia){
            return true;
        }
        else if (dia<fecha2.dia){
            return false;
        }
        else{
            if (hora>fecha2.hora){
                return true;
            }
            else if (hora<fecha2.hora){
                return false;
            }
            else{
                if (minuto>fecha2.minuto){
                    return true;
                }
                else if (minuto<fecha2.minuto){
                    return false;
                }
                else{
                    if (segundo>fecha2.segundo){
                        return true;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
    }
}
bool Fecha::operator <(const Fecha& fecha2){
    if (mes<fecha2.mes){
        return true;
    }
    else if (mes>fecha2.mes){
        return false;
    }
    else{
        if (dia<fecha2.dia){
            return true;
        }
        else if (dia>fecha2.dia){
            return false;
        }
        else{
            if (hora<fecha2.hora){
                return true;
            }
            else if (hora>fecha2.hora){
                return false;
            }
            else{
                if (minuto<fecha2.minuto){
                    return true;
                }
                else if (minuto>fecha2.minuto){
                    return false;
                }
                else{
                    if (segundo<fecha2.segundo){
                        return true;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
    }
}
bool Fecha::operator >=(const Fecha& fecha2){
    return (*this==fecha2 || *this>fecha2);
}
bool Fecha::operator <=(const Fecha& fecha2){
    return (*this==fecha2 || *this<fecha2);
}

//metodos:

//Convierte siglas de mes a número:
int Fecha::numMes(){
    std::map<string,int> codes={
        {"Jan",1},
        {"Feb",2},
        {"Mar",3},
        {"Apr",4},
        {"May",5},
        {"Jun",6},
        {"Jul",7},
        {"Aug",8},
        {"Sep",9},
        {"Oct",10},
        {"Nov",11},
        {"Dec",12}
    };
    return codes[codigoMes];
    //string codes [12]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"}
    
}

//regresa la fecha en el formato deseado
string Fecha::getFecha(){
    string day,hour,minute,second;
    if (dia<10){
        day="0"+std::to_string(dia);
    }
    else{
        day=std::to_string(dia);
    }
    if (hora<10){
        hour="0"+std::to_string(hora);
    }
    else{
        hour=std::to_string(hora);
    }
    if (minuto<10){
        minute="0"+std::to_string(minuto);
    }
    else{
        minute=std::to_string(minuto);
    }
    if (segundo<10){
        second="0"+std::to_string(segundo);
    }
    else{
        second=std::to_string(segundo);
    }
    return(codigoMes+" "+day+" "+hour+":"+minute+":"+second);
}


#endif