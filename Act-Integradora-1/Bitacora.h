#ifndef BITACORA_H
#define BITACORA_H
#include <vector>
#include <fstream>
#include <sstream>
#include "Registro.h"

class Bitacora{
    private:
    std::vector<Registro> registros;
    std::ifstream inputFile;

    public:
    //constructores
    Bitacora();
    Bitacora(const string&); //entrada: archivo de texto  
    //sorters
    void intercambiar(int,int);
    void quickSort(int, int);
    int partition(int, int);
    void mergeSort(int, int);
    void merge(int,int,int);
    //busqueda
    int binSearch(Fecha);
    void rangoFechas(Fecha,Fecha);
    void pideUsuario();
    //metodos extra
    void outputFile(string);
    void printBitacora();
    int getSize();
};

Bitacora::Bitacora(){
    registros.push_back(Registro());
}
//toma como argumento el nombre del archivo de texto, en formato de string
Bitacora::Bitacora(const string& archivo){
    inputFile.open(archivo);
    string linea;
    string mes,tiempo,ip,error;
    int dia,hora,minuto,segundo;
    Fecha dat;
    Registro reg;
    if (inputFile.is_open()){   
        //std::cout << "Unable to open file";
        while (std::getline(inputFile,linea)) {
            std::istringstream ss(linea);
            ss>>mes>>dia>>tiempo>>ip;
            //se borra un espacio extra del error
            std::getline(ss,error);
            error=error.substr(1);
            //se separan las horas, minutos y segundos
            hora=std::stoi(tiempo.substr(0,2));
            minuto=std::stoi(tiempo.substr(3,2));
            segundo=std::stoi(tiempo.substr(6,2));
            //se construye la fecha y regustro
            dat= Fecha(mes,dia,hora,minuto,segundo);
            reg = Registro(dat,ip,error);
            //se le agrega al vector
            registros.push_back(reg);
            //debug: std::cout<<reg.getDato()<<std::endl;
        };
    inputFile.close();
    }
    else {std::cout << "Unable to open file";};
}

int Bitacora::getSize(){
    return registros.size();
}

void Bitacora::quickSort(int low, int high){
    if (low<high){
        int pi=partition(low,high);
        quickSort(low,pi-1);
        quickSort(pi+1,high);
    }
}

int Bitacora::partition(int low, int high){
    Registro pivot=registros[high];
    int i=low-1;
    for (int j = low; j <= high-1; j++)
    {
        //quickComparaciones++;
        if (registros[j].getFecha()<pivot.getFecha()){
            i++;
            intercambiar(i,j);
        }
    }
    intercambiar(i+1,high);
    return (i+1);
}


void Bitacora::mergeSort(int inicio, int fin){
    if (inicio<fin){
        int centro =int((inicio+fin)/2);
        mergeSort(inicio,centro);
        mergeSort(centro+1,fin);
        merge(inicio,centro,fin);
    }
}

void Bitacora::merge(int l, int m, int r){
    int n1 =m-l+1;
    int n2 =r-m;
    Registro L[n1],R[n2];
        // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = registros[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = registros[m + 1 + j];
 
    // Merge the temp arrays back into arr[l..r]
 
    // Initial index of first subarray
    int i = 0;
 
    // Initial index of second subarray
    int j = 0;
 
    // Initial index of merged subarray
    int k = l;
 
    while (i < n1 && j < n2) {
        //mergeComparaciones++;
        if (L[i].getFecha() <= R[j].getFecha()) {
            registros[k] = L[i];
            i++;
        }
        else {
            registros[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        registros[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2) {
        registros[k] = R[j];
        j++;
        k++;
    }

}

void Bitacora::intercambiar(int i, int j){
    Registro temp;
    temp=registros[i];
    registros[i]=registros[j];
    registros[j]=temp;
}

int Bitacora::binSearch(Fecha clave){
    //solo sirve para arreglos ordenados 
    int n=registros.size();
    int left=0;
    int right=n-1;
    //int comparaciones=0;
    while(left<=right){
        int mid=int((left+right)/2);
        //comparaciones++;
        if (registros[mid].getFecha()>clave){
            right=mid-1;
        }
        else if(registros[mid].getFecha()<clave){
            left=mid+1;
        }
        else{
            return (mid);
        }
    }
    return -1;
}

void Bitacora::rangoFechas(Fecha inicio, Fecha fin){
    int start=binSearch(inicio);
    int finish=binSearch(fin);
    if (start ==-1 ||finish==-1){
        std::cout<<"No se encontraron esas fechas"<<std::endl;
    }
    else{
        std::cout<<"Las fechas en ese rango son:"<<std::endl;
        for (start; start <= finish; start++)
        {
            std::cout<<registros[start].getDato()<<std::endl;
        }
    }
}

void Bitacora::pideUsuario(){
    Fecha start;
    Fecha end;
    int dia;
    int hora;
    int minuto;
    int segundo;
    string tiempo;
    string codigoMes;

    int dia2;
    int hora2;
    int minuto2;
    int segundo2;
    string tiempo2;
    string codigoMes2;

    std::cout<<"Introduce la fecha de inicio "<<std::endl;
    std::cout<<"Mes en código de tres letras (Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec): "<<std::endl;
    std::cin>>codigoMes;
    std::cout<<"Número de día: "<<std::endl;
    std::cin>>dia;
    std::cout<<"Hora en formato 00:00:00"<<std::endl;
    std::cin>>tiempo;
    hora=std::stoi(tiempo.substr(0,2));
    minuto=std::stoi(tiempo.substr(3,2));
    segundo=std::stoi(tiempo.substr(6,2));
    start=Fecha(codigoMes,dia,hora,minuto,segundo);

    std::cout<<"Introduce la fecha de fin "<<std::endl;
    std::cout<<"Mes en código de tres letras (Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec): "<<std::endl;
    std::cin>>codigoMes2;
    std::cout<<"Número de día: "<<std::endl;
    std::cin>>dia2;
    std::cout<<"Hora en formato 00:00:00"<<std::endl;
    std::cin>>tiempo2;
    hora2=std::stoi(tiempo2.substr(0,2));
    minuto2=std::stoi(tiempo2.substr(3,2));
    segundo2=std::stoi(tiempo2.substr(6,2));
    end=Fecha(codigoMes2,dia2,hora2,minuto2,segundo2);

    rangoFechas(start,end);
}


//imprime el vactor en la consola
void Bitacora::printBitacora(){
    for (int i = 0; i < registros.size(); i++)
    {
        std::cout<<registros[i].getDato()<<std::endl;
    }
    
}

//imprime el vector en un archivo, argumento es el nombre deseado del archivo y debe de ser .txt
void Bitacora::outputFile(string nameOfFile){
    std::ofstream outfile(nameOfFile);
    for (int i = 0; i < registros.size(); i++)
    {
        outfile<<registros[i].getDato()<<std::endl;
    }
    outfile.close();
}



#endif