#ifndef IPHEAP_H
#define IPHEAP_H
#include "BitacoraHeap.h"
#include "IpAddress.h"

class IpHeap{
    private:
    std::vector<IpAddress> vect;
    int size;
    BitacoraHeap* bit;
    void swap(int,int);
    void heapify(int);
    void heapifydel(int,int);
    std::ifstream inputFile;

    public:
    //constructores
    IpHeap();
    IpHeap(BitacoraHeap* _bit); //entrada: bitácora

    //sorter
    void heapSort();
    void ordenarDescendente();
    
    //metodos extra
    void countAndFill();
    void outputFile(string);
    void insertNode(IpAddress);
    void deleteRoot();
    IpAddress top();
    bool empty();
    int getSize();
    void print(int,int);

};

IpHeap::IpHeap(){
    vect={};
    size=0;
    bit= new BitacoraHeap();
}

IpHeap::IpHeap(BitacoraHeap* _bit){
    vect={};
    size=0;
    bit=_bit;
    countAndFill();
}

void IpHeap::countAndFill(){
    bit->heapSort();
    std::vector<Registro> reg=bit->getVect();
    IpAddress _adr;
    Registro left=reg[0];
    Registro right;
    for (int i = 0; i < bit->getSize(); i++)
    {
        //left=reg[i];
        right=left;
        int count=0;
        while(left.getIpNoPort()==right.getIpNoPort()){
            count+=1;
            right=reg[i+count];
        }
        _adr=IpAddress(count+1,left.getIpNoPort());
        left=right;
        i+=count;
        insertNode(_adr);
    }
}

void IpHeap::swap(int i,int j)
{
    IpAddress temporal;
    temporal = vect[i];
    vect[i] = vect[j];
    vect[j] = temporal;
}

void IpHeap::heapify(int i)
{
    // Encontar padre
    int parent = (i - 1) / 2;
  
    if (vect[parent].getOccurences() > 0) {
        if (vect[i].getOccurences() > vect[parent].getOccurences()) {
            swap(i, parent);
            heapify(parent);
        }
    }
}

void IpHeap::insertNode(IpAddress key)
{
    size ++;
    vect.push_back(key);
    heapify(size - 1);
}

void IpHeap::heapifydel(int n, int i)
{
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
    if (l < n && vect[l].getOccurences() > vect[largest].getOccurences())
        largest = l;
    if (r < n && vect[r].getOccurences() > vect[largest].getOccurences())
        largest = r;
    if (largest != i) {
        swap(i,largest);
        heapifydel(n,largest);
    }
}

void IpHeap::deleteRoot()
{
    IpAddress lastElement = vect[size - 1];
    vect[0] = lastElement;
    vect.pop_back();
    size = size - 1;
    heapifydel(size,0);
}

IpAddress IpHeap::top(){
    return vect[0];
}

bool IpHeap::empty(){
    return size == 0;
}

int IpHeap::getSize(){
    return size;
}

void IpHeap::print(int start, int end){
    if (end>size){
        std::cout << "Error: Indices fuera de rango" << std::endl;
    }
    else{
        //std::string message;
        for (int i = start; i <= end; ++i) {
            //message = std::to_string(vect[i].getAddress()) + " - " + std::to_string(vect[i].getOccurences());
            //std::cout << message << std::endl;
            std::cout << vect[i].showIp() << std::endl;
        }
    }
}

void IpHeap::heapSort()
{
    /*for (int i = size / 2 - 1; i >= 0; i--){
        heapifydel(i);
    }*/

    // One by one extract an element from heap
    for (int i = size - 1; i >= 0; i--) {
        // Move current root to end
        swap(0, i);
        // call max heapify on the reduced heap
        heapifydel(i,0);
    }
}

void IpHeap::ordenarDescendente(){
    heapSort();
    reverse(vect.begin(), vect.end());
}

//imprime el vector en un archivo, argumento es el nombre deseado del archivo y debe de ser .txt
void IpHeap::outputFile(string nameOfFile){
    std::ofstream outfile(nameOfFile);
    if (size == 0) {
        outfile<< "List is empty!" << std::endl;
    }
    else {
        for (int i = 0; i < size; ++i) {
            //outfile << std::to_string(vect[i].getAddress()) + " - " + std::to_string(vect[i].getOccurences()) << std::endl;
            outfile << vect[i].showIp() << std::endl;
        }
    }
    outfile.close();
}

#endif