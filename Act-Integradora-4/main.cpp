#include "bitacoraGraph.h"

int main(){
    BitacoraGraph bit1=BitacoraGraph("bitacoraGrafos.txt");
    bit1.printGraphToFile("Grafo Bitácora.txt");
    cout<<"La lista de adyacencia se puede encontrar en el archivo: Grafo Bitácora.txt"<<endl;
    bit1.createAndSortHeap();
    bit1.printHeapToFile("Bitácora por conexiones.txt");
    cout<<"Primeras 5 ips que más conexiones tienen:"<<endl;
    bit1.printNodesFromHeap(0,5); //Toma el primer y último nodo que se quieren imprimir
    cout<<"El resto de las ips ordenadas por conexiones se pueden encontrar en el archivo: Bitácora por conexiones.txt"<<endl;
    return 0;
}