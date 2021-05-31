#ifndef IpNode_H
#define IpNode_H

#include <vector>
#include <string>

class IpNode {
  private:
    int numNeighbors;
    std::string ipString;
    int index;

  public:
    IpNode();
    IpNode(std::string,int);
    void addNeighbor(int);
    int getNumNeighbors();
    std::string getIP();
    std::vector<int> neighbors;
};

IpNode::IpNode(){
    numNeighbors=0;
    ipString="";
    neighbors={0};
    index=0;
}

IpNode::IpNode(std::string _ipString,int _index){
    numNeighbors=0;;
    ipString=_ipString;
    index=_index;
}

void IpNode::addNeighbor(int _inx){
    neighbors.push_back(_inx);
    numNeighbors+=1;
}

int IpNode::getNumNeighbors(){
    return numNeighbors;
}

std::string IpNode::getIP(){
    return ipString;
}


#endif