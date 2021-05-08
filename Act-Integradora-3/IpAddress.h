#ifndef IPADDRESS_H
#define IPADDRESS_H

#include <string>

class IpAddress{
    private:
    int occurances;
    long address;

    public:
    IpAddress();
    IpAddress(int,long);
    int getOccurences();
    long getAddress();
    void setAddress(long);
    void setOccurences(int);
    std::string showIp();
};

IpAddress::IpAddress(){
    occurances=0;
    address=0;
}

IpAddress::IpAddress(int _occurences, long _address){
    occurances=_occurences;
    address=_address;
}

int IpAddress::getOccurences(){
    return occurances;
}

long IpAddress::getAddress(){
    return address;
}

std::string IpAddress::showIp(){
    std::string strIp=std::to_string(address);
    std::string res="";
    for (int i = 0; i < strIp.length(); i++)
    {
        if (i==2 ||i==4 ||i==7){
            res=res+".";
        }
        res=res+strIp[i];
    }
    res=res+" - " + std::to_string(occurances);
    return res;
}

void IpAddress::setOccurences(int _occurences){
    occurances=_occurences;
}

void IpAddress::setAddress(long _address){
    address=_address;
}

#endif