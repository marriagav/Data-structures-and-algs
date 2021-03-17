#include<iostream>
#include <chrono>
#include "Bitacora.h"
using namespace std;
int main(){

    //Se crea una bitacora del archivo de texto "bitacora.txt"
    Bitacora bit1= Bitacora("bitacora.txt");
    //se empieza a medir el tiempo
    std::cout << "\nQUICK SORT: " <<std::endl;
    auto startTime1 = std::chrono::high_resolution_clock::now();
    //se llama al metodo quickSort
    bit1.quickSort(0,bit1.getSize()-1);
    //se termina de medir el tiempo
    auto endTime1 = std::chrono::high_resolution_clock::now();
    auto totalTime1 = endTime1 - startTime1;
    //se imprime el tiempo que tardó
    std::cout << "Tiempo de ejecución en ms: " << totalTime1/std::chrono::milliseconds(1) << std::endl;
    //Se crea un archivo con os datos ordenados, llamado "quickSort.txt"
    bit1.outputFile("quickSort.txt");

    //Prueba con mergeSort para comparar tiempos
    Bitacora bit2= Bitacora("bitacora.txt");
    std::cout << "\nMERGE SORT: " <<std::endl;
    auto startTime2 = std::chrono::high_resolution_clock::now();
    bit2.mergeSort(0,bit2.getSize()-1);
    auto endTime2 = std::chrono::high_resolution_clock::now();
    auto totalTime2 = endTime2 - startTime2;
    std::cout << "Tiempo de ejecución en ms: " << totalTime2/std::chrono::milliseconds(1) << std::endl;
    //Se crea un archivo con os datos ordenados, llamado "mergeSort.txt"
    bit1.outputFile("mergeSort.txt");

    std::cout << "\nBINARY SEARCH: " <<std::endl;
    //Método de busqueda binaria para encontrar el índice de una fecha
    Fecha fecha2 = Fecha("Jul",9,16,19,58);
    //inicio tiempo
    auto startTime3 = std::chrono::high_resolution_clock::now();
    cout<<bit1.binSearch(fecha2)<<endl;
    //fin tiempo
    auto endTime3 = std::chrono::high_resolution_clock::now();
    auto totalTime3 = endTime3 - startTime3;
    std::cout << "Tiempo de ejecución en ms: " << totalTime3/std::chrono::milliseconds(1) << std::endl;

    //Método para pedirle dos fechas al usuario e imprimir los regitros en ese rango:
    std::cout << "\nPIDE USUARIO (DOS BÚSQUEDAS BINARIAS): " <<std::endl;
    bit1.pideUsuario();
    
    return 0;
}