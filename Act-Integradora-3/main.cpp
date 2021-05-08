#include<iostream>
#include <chrono>
#include "IpHeap.h"
using namespace std;

int main(){

    //Se crea una BitacoraHeap del archivo de texto "BitacoraHeap.txt"
    BitacoraHeap bit1= BitacoraHeap("bitacoraHeap.txt");

    std::cout << "\nHEAP SORT DE IPs: " <<std::endl;
    //se ordena la bitácora
    std::cout << "Ordenando la Bitacora..."<< std::endl;
    auto startTime1 = std::chrono::high_resolution_clock::now();
    bit1.heapSort();
    //se termina de medir el tiempo
    auto endTime1 = std::chrono::high_resolution_clock::now();
    auto totalTime1 = endTime1 - startTime1;
    //se imprime el tiempo que tardó
    std::cout << "Tiempo de ejecución en ms: " << totalTime1/std::chrono::milliseconds(1) << std::endl;
    //Se crea un archivo con os datos ordenados, llamado "bitacoraHeap_ordenada.txt"
    bit1.outputFile("bitacoraHeap_ordenada.txt");

    std::cout << "\nHEAP SORT POR ACCESOS: " <<std::endl;
    IpHeap heap1= IpHeap(&bit1);
    //se ordenan las ips
    std::cout << "Ordenando las IPs por número de accesos..."<< std::endl;
    //inicio tiempo
    auto startTime3 = std::chrono::high_resolution_clock::now();
    heap1.ordenarDescendente();
    //fin tiempo
    auto endTime3 = std::chrono::high_resolution_clock::now();
    auto totalTime3 = endTime3 - startTime3;
    std::cout << "Tiempo de ejecución en ms: " << totalTime3/std::chrono::milliseconds(1) << std::endl;
    //Se crea un archivo con os datos ordenados, llamado "IPs_ordenados_por_accesos.txt"
    heap1.outputFile("IPs_ordenados_por_accesos.txt");

    std::cout << "\n5 IPs CON MÁS ACCESOS (IP - NO. DE ACCESOS): " <<std::endl;
    heap1.print(0,4);

    return 0;
}