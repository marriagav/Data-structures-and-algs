#include <vector>
#include <iostream>
#include "ipNode.h"

class Heap
{
private:
    std::vector<IpNode> vect;
    int size;
    void swap(int,int);
    void heapify(int);
    void heapifydel(int,int);
public:
    Heap();
    void insertNode(IpNode);
    void deleteRoot();
    IpNode top();
    bool empty();
    int getSize();
    std::string print(int, int);
    void heapSort();
};

Heap::Heap()
{
    vect = {};
    size = 0;
}


void Heap::swap(int i,int j)
{
    IpNode temporal;
    temporal = vect[i];
    vect[i] = vect[j];
    vect[j] = temporal;
}


void Heap:: heapify(int i)
{
    // Encontar padre
    int parent = (i - 1) / 2;
  
    if (vect[parent].getNumNeighbors() > 0) {
        if (vect[i].getNumNeighbors() < vect[parent].getNumNeighbors()) {
            swap(i, parent);
            heapify(parent);
        }
    }
}

void Heap::insertNode(IpNode key)
{
    size ++;
    vect.push_back(key);
    heapify(size - 1);
}

void Heap::heapifydel(int n, int i)
{
    int smallest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
    if (l < n && vect[l].getNumNeighbors() < vect[smallest].getNumNeighbors())
        smallest = l;
    if (r < n && vect[r].getNumNeighbors() < vect[smallest].getNumNeighbors())
        smallest = r;
    if (smallest != i) {
        swap(i,smallest);
        heapifydel(n,smallest);
    }
}

void Heap::deleteRoot()
{
    IpNode lastElement = vect[size - 1];
    vect[0] = lastElement;
    vect.pop_back();
    size = size - 1;
    heapifydel(size,0);
}

IpNode Heap::top(){
    return vect[0];
}

bool Heap::empty(){
    return size == 0;
}

int Heap::getSize(){
    return size;
}

std::string Heap::print(int start, int end){
    std::stringstream aux;
    for (int i = start; i < end; i++) {
        aux << vect[i].getIP() <<" -> "<<vect[i].getNumNeighbors() << std::endl;
    }
    return aux.str();
}

void Heap::heapSort()
{
    // One by one extract an element from heap
    for (int i = size - 1; i >= 0; i--) {
        // Move current root to end
        swap(0, i);
        // call max heapify on the reduced heap
        heapifydel(i,0);
    }
}