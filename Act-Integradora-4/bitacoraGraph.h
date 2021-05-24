#ifndef BitacoraGraph_H
#define BitacoraGraph_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include "ipNode.h"
#include "heap.h"

using namespace std;

class BitacoraGraph {
  private:
    int numNodes;
    int numEdges;
    std::map<std::string,int> diccionario;
    std::ifstream inputFile;
    vector<IpNode> adjList;
    Heap heap1;
    void loadBitacoraGraphList(const string& archivo);

  public:
    BitacoraGraph();
    BitacoraGraph(const string& archivo);
    string printAdjList();
    string DFS(int, int);
    string BFS(int, int);
    Heap createAndSortHeap();
    void printGraphToFile(const string& archivo);
    void printHeapToFile(const string& archivo);
    void printNodesFromHeap(int, int);
};

BitacoraGraph::BitacoraGraph(){
  numNodes =0;
  numEdges =0;
}

BitacoraGraph::BitacoraGraph(const string& archivo){
    loadBitacoraGraphList(archivo);
}

void BitacoraGraph::loadBitacoraGraphList(const string& archivo) {
  inputFile.open(archivo);
  std::string line;
  int cont=-1;
  string trash;
  string ip1;
  string ip2;
  if (inputFile.is_open()){
    while (std::getline(inputFile, line)) {
      if (line.empty()){
        continue;
      }
      if (cont==-1){
        std::istringstream ss(line);
        ss>>numNodes>>numEdges;
        cont++;
        continue;
      }
      else if (cont<numNodes){
        IpNode curr;
        curr=IpNode(line,cont);
        diccionario[line]=cont;
        adjList.push_back(curr);
        cont++;
        continue;
      }
      else{
        std::istringstream ss(line);
        ss>>trash>>trash>>trash>>ip1>>ip2>>trash;

        std::string::size_type pos = ip1.find(':');
            if (pos != std::string::npos)
            {
                ip1=ip1.substr(0, pos);
            }
    
        std::string::size_type pos1 = ip2.find(':');
            if (pos1 != std::string::npos)
            {
                ip2=ip2.substr(0, pos1);
            }

        int ip1indx=diccionario[ip1];
        int ip2indx=diccionario[ip2];
        IpNode from =IpNode(ip1,ip1indx);
        adjList[ip1indx].addNeighbor(ip2indx);
        cont++;
        continue;
      }
    }
  }
  else {std::cout << "Unable to open file";};
}

string BitacoraGraph::printAdjList(){
  stringstream aux;
  for (int i = 0; i < numNodes; i++){
    aux << "IP "
        << adjList[i].getIP() << " :";
    for (int j = 0; j < adjList[i].getNumNeighbors(); j ++){
        aux << " " << adjList[adjList[i].neighbors[j]].getIP();
    }
    aux << "\n";
  }
  return aux.str();
}

void BitacoraGraph::printGraphToFile(const string& archivo){
    std::ofstream outfile(archivo);
    outfile<<printAdjList();
}

Heap BitacoraGraph::createAndSortHeap(){
    //Heap heap1;
    for (int i = 0; i < numNodes; i++){
        heap1.insertNode(adjList[i]);
    }
    heap1.heapSort();
    return heap1;
}

void BitacoraGraph::printHeapToFile(const string& archivo){
    std::ofstream outfile(archivo);
    outfile<<heap1.print(0,heap1.getSize());
}

void BitacoraGraph::printNodesFromHeap(int start, int end){
    cout<<heap1.print(start,end);
}



#endif