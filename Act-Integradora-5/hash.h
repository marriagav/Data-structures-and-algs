#ifndef Hash_H
#define Hash_H

#include <iostream>
#include <string>
#include <cmath>

#define MIN_TABLE_SIZE 10
using namespace std;
/*
 * Node Type Declaration
 */
enum EntryType {Legitimate, Empty, Deleted};  //--bandera
/*
 * Node Declaration
 */
class HashNode
{
    public:
    int element;
    enum EntryType info;
    int index;
};

/*
 * Table Declaration
 */
class HashTable
{
    private:
        int size;
        HashNode *table;
    public:
    HashTable(int);
    ~HashTable();
    bool isPrime(int);
    int nextPrime(int);
    int HashFunc(int);
    int Find(int key);
    void Insert(int key, int index);
    int getIndex(int key);
    void display(string);
};

HashTable::HashTable(int size1)
{
    if (size1 < MIN_TABLE_SIZE)
    {
        cout<<"Table Size Too Small"<<endl;
        return;
    }
    size = nextPrime(size1);
    table = new HashNode [size];
    if (table == NULL)
    {
        cout<<"Table Size Too Small"<<endl;
        return;
    }
    for (int i = 0; i < size; i++)
    {
        table[i].info = Empty;
        table[i].element=0;
        table[i].index=-1;
    }
}

HashTable::~HashTable(){
    delete[] table;
}

int HashTable::HashFunc(int key)
{
    if( key < 0 ) key = -key;
    return (key % size);

    //return floor (size * (key * 13 % 1));
}

bool HashTable::isPrime (int n)
{
    if (n == 2 || n == 3)
        return true;
    if (n == 1 || n % 2 == 0)
        return false;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;
    return true;
}
/*
 * Finding next prime size of the table
 */
int HashTable::nextPrime(int n)
{
    if (n <= 0)
        n = 3;
    if (n % 2 == 0)
        n++;
    for (; !isPrime( n ); n += 2);
    return n;
}

int HashTable::Find(int key)
{
    int pos = HashFunc(key);
    int collisions = 0;
    while (table[pos].info != Empty &&
           table[pos].element != key)
    {

        pos = pos + 2 * ++collisions -1;
        if (pos >= size)
            pos = pos - size;
    }
    //std::cout<<key<<endl;
    // std::cout<<table[pos].element<<endl;
    return pos;
}

void HashTable::Insert(int key, int indice)
{
    int pos = Find(key);
    if (table[pos].info != Legitimate)
    {
        table[pos].info = Legitimate;
        table[pos].element = key;
        table[pos].index= indice;
    }
}

int HashTable::getIndex(int key){
    int pos=Find(key);
    return (table[pos].index);
}

void HashTable::display(string file) {
    std::ofstream outfile(file);
   for (int i = 0; i < size; i++) {
      int value = table[i].element;
      if (value==-1)
         outfile<<"Position: "<<i + 1<<" Element: Null"<<endl;
      else
         outfile<<"Position: "<<i + 1<<" Element: "<<value<<endl;
   }
}

#endif