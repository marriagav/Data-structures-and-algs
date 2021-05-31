#ifndef BitacoraGraph_H
#define BitacoraGraph_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>

#include "ipNode.h"
#include "heap.h"
#include "hash.h"


using namespace std;

class BitacoraGraph {
  private:
    int numNodes;
    int numEdges;
    HashTable *htable;
    std::ifstream inputFile;
    vector<IpNode> adjList;
    Heap heap1;
    void loadBitacoraGraphList(const string& archivo);
    int splitIP(string);
    vector<int> iguales;
    void checarIguales(); //---debug

  public:
    BitacoraGraph();
    BitacoraGraph(const string& archivo);
    BitacoraGraph(BitacoraGraph&& other)
    : htable(nullptr)
    , numNodes(0)
    , numEdges(0)
    , inputFile(0)
    , adjList(0)
    , heap1(Heap())
    , iguales(0)
    {
      htable=other.htable;
      numNodes=other.numNodes;
      numEdges=other.numEdges;
      //inputFile=other.inputFile;
      adjList=other.adjList;
      heap1=other.heap1;
      iguales=other.iguales;
    }
    ~BitacoraGraph();
    string printAdjList();
    string DFS(int, int);
    string BFS(int, int);
    Heap createAndSortHeap();
    void printGraphToFile(const string& archivo);
    void printHeapToFile(const string& archivo);
    void printNodesFromHeap(int, int);
    void printMapToFile(const string& archivo);
};

BitacoraGraph::BitacoraGraph(){
  numNodes =0;
  numEdges =0;
}

BitacoraGraph::~BitacoraGraph(){
  delete htable;
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
        htable = new HashTable(numNodes);
        continue;
      }
      else if (cont<numNodes){
        IpNode curr;
        curr=IpNode(line,cont);
        std::string noPortStr=line;
        int ipNoPort=splitIP(line);
        //cout<<cont<<endl;
        htable->Insert(ipNoPort,cont);

        iguales.push_back(htable->getIndex(ipNoPort));
        
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

        int ip1Num=splitIP(ip1);
        int ip2Num=splitIP(ip2);

        //cout<<cont<<endl;

        int ip1indx=htable->getIndex(ip1Num);
        int ip2indx=htable->getIndex(ip2Num);
        //cout<<ip1indx<<endl;
        //cout<<ip2indx<<endl;

        //IpNode from =IpNode(ip1,ip1indx);
        adjList[ip1indx].addNeighbor(ip2indx);
        cont++;
        continue;
      }
    }
  }
  else {std::cout << "Unable to open file";};
  checarIguales(); //-debug
}

int BitacoraGraph::splitIP(string _ip){
  _ip.erase(remove(_ip.begin(), _ip.end(), '.'), _ip.end());
  vector<int> accumInts;
  int final=stoll(_ip);
  srand(final);
  final=rand();
  if (final<0){
    final=final*-1;
  }
  //cout<<final<<endl;
  return final;
  
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

void BitacoraGraph::printMapToFile(const string& archivo){
    htable->display(archivo);
}

void BitacoraGraph::printHeapToFile(const string& archivo){
    std::ofstream outfile(archivo);
    outfile<<heap1.print(0,heap1.getSize());
}

void BitacoraGraph::printNodesFromHeap(int start, int end){
    cout<<heap1.print(start,end);
}

void BitacoraGraph::checarIguales(){
  vector<int> duplicate;
    sort(iguales.begin(),iguales.end());
    for (int i = 1; i < iguales.size(); i++) {
        if (iguales[i - 1] == iguales[i]) {
 
            // STL function to push the duplicate
            // words in a new vector string
            if (duplicate.empty())
              duplicate.push_back(iguales[i]);
            else if (iguales[i] != duplicate.back())
                duplicate.push_back(iguales[i]);
        }
    }
    if (duplicate.size() == 0)
        cout << "No Duplicate keys" << endl;
    else
        for (int i = 0; i < duplicate.size(); i++)
            cout << duplicate[i] << endl;
        cout<<duplicate.size()<<endl;
}



#endif