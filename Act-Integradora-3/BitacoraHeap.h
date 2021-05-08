#ifndef BitacoraHeap_H
#define BitacoraHeap_H
#include <vector>
#include <fstream>
#include <sstream>
//#include "Stack.h"
#include "Registro.h"

class BitacoraHeap{
    private:
    std::vector<Registro> vect;
    int size;
    void swap(int,int);
    void heapify(int);
    void heapifydel(int,int);
    std::ifstream inputFile;

    public:
    //constructores
    BitacoraHeap();
    BitacoraHeap(const string&); //entrada: archivo de texto
    //~BitacoraHeap();  

    //sorter
    void heapSort();
    
    //metodos extra
    std::vector<Registro> getVect();
    void outputFile(string);
    void insertNode(Registro);
    void deleteRoot();
    Registro top();
    bool empty();
    int getSize();
    void print();

};

BitacoraHeap::BitacoraHeap(){
    vect={};
    size=0;
}

//toma como argumento el nombre del archivo de texto, en formato de string
BitacoraHeap::BitacoraHeap(const string& archivo){
    size=0;
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

            //se le agrega al heap
            insertNode(reg);
        };
    inputFile.close();
    }
    else {std::cout << "Unable to open file";};
}

void BitacoraHeap::swap(int i,int j)
{
    Registro temporal;
    temporal = vect[i];
    vect[i] = vect[j];
    vect[j] = temporal;
}

void BitacoraHeap:: heapify(int i)
{
    // Encontar padre
    int parent = (i - 1) / 2;
  
    if (vect[parent].getIpNoPort() > 0) {
        if (vect[i].getIpNoPort() > vect[parent].getIpNoPort()) {
            swap(i, parent);
            heapify(parent);
        }
    }
}

void BitacoraHeap::insertNode(Registro key)
{
    size ++;
    vect.push_back(key);
    heapify(size - 1);
}

void BitacoraHeap::heapifydel(int n, int i)
{
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
    if (l < n && vect[l].getIpNoPort() > vect[largest].getIpNoPort())
        largest = l;
    if (r < n && vect[r].getIpNoPort() > vect[largest].getIpNoPort())
        largest = r;
    if (largest != i) {
        swap(i,largest);
        heapifydel(n,largest);
    }
}

void BitacoraHeap::deleteRoot()
{
    Registro lastElement = vect[size - 1];
    vect[0] = lastElement;
    vect.pop_back();
    size = size - 1;
    heapifydel(size,0);
}

Registro BitacoraHeap::top(){
    return vect[0];
}

bool BitacoraHeap::empty(){
    return size == 0;
}

int BitacoraHeap::getSize(){
    return size;
}

std::vector<Registro> BitacoraHeap::getVect(){
    return vect;
}

void BitacoraHeap::print(){
    for (int i = 0; i < size; ++i) {
        std::cout << vect[i].getDato() << std::endl;
    }
}

void BitacoraHeap::heapSort()
{
    // One by one extract an element from heap
    for (int i = size - 1; i >= 0; i--) {
        // Move current root to end
        swap(0, i);
        // call max heapify on the reduced heap
        heapifydel(i,0);
    }
}

//imprime el vector en un archivo, argumento es el nombre deseado del archivo y debe de ser .txt
void BitacoraHeap::outputFile(string nameOfFile){
    std::ofstream outfile(nameOfFile);
    if (size == 0) {
        outfile<< "List is empty!" << std::endl;
    }
    else {
        for (int i = 0; i < size; ++i) {
            outfile << vect[i].getDato() << std::endl;
        }
    }
    outfile.close();
}

#endif