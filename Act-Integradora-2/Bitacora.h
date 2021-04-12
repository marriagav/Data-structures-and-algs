#ifndef BITACORA_H
#define BITACORA_H
#include <vector>
#include <fstream>
#include <sstream>
//#include "Stack.h"
#include "Registro.h"

class Bitacora{
    private:
    Registro *head,*tail;
    int size;
    std::ifstream inputFile;

    void _quickSort(int, int);
    int partition(int, int);

    public:
    //constructores
    Bitacora();
    Bitacora(const string&); //entrada: archivo de texto
    //~Bitacora();  
    
    //sorters
    void intercambiar(int a, int b);
    void quickSort();
    
    //busqueda
    int binSearch(Fecha);
    void rangoFechas(Fecha,Fecha);
    void pideUsuario();
    Registro * getAt(int);
    int getPos(Registro*);
    
    //metodos extra
    Registro * getHead();
    Registro * getTail();
    void addLast(Registro* reg);
    void outputFile(string);
    void printBitacora();
    int getSize();
    void clean();

};

Bitacora::Bitacora(){
    head=NULL;
    tail=NULL;
    size=0;
}
//toma como argumento el nombre del archivo de texto, en formato de string
Bitacora::Bitacora(const string& archivo){
    size=0;
    inputFile.open(archivo);
    string linea;
    string mes,tiempo,ip,error;
    int dia,hora,minuto,segundo;
    Fecha dat;
    Registro* reg;
    if (inputFile.is_open()){   
        //std::cout << "Unable to open file";
        while (std::getline(inputFile,linea)) {
            std::istringstream ss(linea);
            ss>>mes>>dia>>tiempo>>ip;
            //se borra un espacio extra del error
            std::getline(ss,error);
            error=error.substr(1);
            //se separan las horas, minutos y segundos
            hora=std::stoi(tiempo.substr(0,2));
            minuto=std::stoi(tiempo.substr(3,2));
            segundo=std::stoi(tiempo.substr(6,2));
            //se construye la fecha y regustro
            dat= Fecha(mes,dia,hora,minuto,segundo);
            reg = new Registro(dat,ip,error);

            //se le agrega la lista
            addLast(reg);
            //std::cout<<reg->getDato()<<std::endl;
            //std::cout<<size<<std::endl;
        };
    inputFile.close();
    }
    else {std::cout << "Unable to open file";};
}

/*Bitacora::~Bitacora(){
    clean();
    head = 0;
    tail=0; 
}*/

void Bitacora::clean(){
    Registro* current = head;
    while( current != 0 ) {
        Registro* next = current->next;
        delete current;
        current = next;
    }
    head = NULL;
    tail = NULL;
    size=0;

}

Registro * Bitacora::getHead(){
    return head;
}

Registro * Bitacora::getTail(){
    return tail;
}

void Bitacora::addLast(Registro* reg){
    //newnode->next=NULL;
    if (head==NULL){
        head=reg;
        tail=reg;
    }
    else{
        tail->next=reg;
        reg->prev=tail;
        tail=reg;
    }
    size+=1;
}

int Bitacora::getSize(){
    return size;
}

void Bitacora::_quickSort(int l, int h){
    int stack[h-l+1];
    int top = -1;

    stack[++top] = l;
    stack[++top]= h;

    while (top>=0){
        //std::cout<<top<<std::endl;
        h=stack[top--];
        l=stack[top--];

        int pos =partition(l,h);
        //std::cout<<pos<<std::endl;

        if (pos-1>l){
            stack[++top]=l;
            stack[++top]=pos-1;
        }
        if (pos+1<h){
            stack[++top]=pos+1;
            stack[++top]=h;
        }
    }

    /*if (h != NULL && l != h && l != h->next)
    {
        Registro *p = partition(l, h);
        _quickSort(l, p->prev);
        _quickSort(p->next, h);
    }
    */

}

void Bitacora::quickSort(){
    _quickSort(0,size-1);
}

int Bitacora::partition(int l, int h){
    Registro* pivot = getAt(h);
    int i = l-1;
    int j;
    for (j=l; j<=h-1; j++){
        if (getAt(j)->getFecha()<=pivot->getFecha()){
            i++;
            intercambiar(i,j);
        }
    }
    intercambiar(i+1,h);
    return i+1;
    
   /*
    // set pivot as h element
    Fecha x = h->getFecha();
 
    // similar to i = l-1 for array implementation
    Registro *i = l->prev;
 
    // Similar to "for (int j = l; j <= h- 1; j++)"
    for (Registro *j = l; j != h; j = j->next)
    {
        if (j->getFecha() <= x)
        {
            // Similar to i++ for array
            i = (i == NULL)? l : i->next;
 
            intercambiar(i, j);
        }
    }
    i = (i == NULL)? l : i->next; // Similar to i++
    intercambiar(i, h);
    return i;
    */
}

int Bitacora::getPos(Registro* buscar){
    Registro* curr = head;
    for (int i = 0; i < size; i++)
    {
        if(curr==buscar){
            return i;
        }
        curr=curr->next;
    }
    return -1;
}


Registro * Bitacora::getAt(int num){
    Registro * curr= head;
    int half = size-1/2;
    if (num<half){
        for (int i=0; i<num;i++){
            curr=curr->next;
        }
        return curr;
    }
    else{
        curr=tail;
        int reg = size-num;
        for(int i=0; i<reg; i++){
            curr=curr->prev;
        }
        return curr;
    }
}


void Bitacora::intercambiar(int a, int b){
    //std::cout<<1<<std::endl;
    /*Registro temp=*a;
    a->setFalla(b->getFalla());
    a->setFecha(b->getFecha());
    a->setIp(b->getIp());
    b->setFalla(temp.getFalla());
    b->setFecha(temp.getFecha());
    b->setIp(temp.getIp());
    */
    Registro temporaldata;
    Registro* primerNodo;
    Registro* segundoNodo;
    primerNodo = getAt(a);
    segundoNodo= getAt(b);

    temporaldata = *primerNodo;
    primerNodo->setFecha(segundoNodo->getFecha());
    primerNodo->setFalla(segundoNodo->getFalla());
    primerNodo->setIp(segundoNodo->getIp());

    segundoNodo->setFecha(temporaldata.getFecha());
    segundoNodo->setFalla(temporaldata.getFalla());
    segundoNodo->setIp(temporaldata.getIp());
}

int Bitacora::binSearch(Fecha clave){
    //solo sirve para arreglos ordenados 
    int left=0;
    int right=size-1;
    //int comparaciones=0;
    while(left<=right){
        int mid=int((left+right)/2);
        //comparaciones++;
        if (getAt(mid)->getFecha()>clave){
            right=mid-1;
        }
        else if(getAt(mid)->getFecha()<clave){
            left=mid+1;
        }
        else{
            return (mid);
        }
    }
    return -1;
}

void Bitacora::rangoFechas(Fecha inicio, Fecha fin){
    int start=binSearch(inicio);
    int finish=binSearch(fin);
    if (start ==-1 ||finish==-1){
        std::cout<<"No se encontraron esas fechas"<<std::endl;
    }
    else{
        std::cout<<"Resultado de la búsqueda en archivo resultado_busqueda.txt"<<std::endl;
        std::ofstream outfile("resultado_busqueda.txt");
        Registro* temp = getAt(start);
        for (start; start <= finish; start++)
        {
            outfile<<temp->getDato()<<std::endl;
            temp=temp->next;
        }
        outfile.close();
    }
    
}

void Bitacora::pideUsuario(){
    Fecha start;
    Fecha end;
    int dia;
    int hora;
    int minuto;
    int segundo;
    string tiempo;
    string codigoMes;

    int dia2;
    int hora2;
    int minuto2;
    int segundo2;
    string tiempo2;
    string codigoMes2;

    std::cout<<"Introduce la fecha de inicio "<<std::endl;
    std::cout<<"Mes en código de tres letras (Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec): "<<std::endl;
    std::cin>>codigoMes;
    std::cout<<"Número de día: "<<std::endl;
    std::cin>>dia;
    std::cout<<"Hora en formato 00:00:00"<<std::endl;
    std::cin>>tiempo;
    hora=std::stoi(tiempo.substr(0,2));
    minuto=std::stoi(tiempo.substr(3,2));
    segundo=std::stoi(tiempo.substr(6,2));
    start=Fecha(codigoMes,dia,hora,minuto,segundo);

    std::cout<<"Introduce la fecha de fin "<<std::endl;
    std::cout<<"Mes en código de tres letras (Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec): "<<std::endl;
    std::cin>>codigoMes2;
    std::cout<<"Número de día: "<<std::endl;
    std::cin>>dia2;
    std::cout<<"Hora en formato 00:00:00"<<std::endl;
    std::cin>>tiempo2;
    hora2=std::stoi(tiempo2.substr(0,2));
    minuto2=std::stoi(tiempo2.substr(3,2));
    segundo2=std::stoi(tiempo2.substr(6,2));
    end=Fecha(codigoMes2,dia2,hora2,minuto2,segundo2);

    rangoFechas(start,end);
}

//imprime la lista en la consola
void Bitacora::printBitacora(){

    if (head == NULL) {
        std::cout << "List is empty!" << std::endl;
    }
    else {
        Registro* temp = head;
        while (temp != NULL) {
            std::cout << temp->getDato() << std::endl;
            temp = temp->next;
        }
        std::cout << std::endl;
    }
    
}

//imprime el vector en un archivo, argumento es el nombre deseado del archivo y debe de ser .txt
void Bitacora::outputFile(string nameOfFile){
    std::ofstream outfile(nameOfFile);
    if (head == NULL) {
        outfile<< "List is empty!" << std::endl;
    }
    else {
        Registro* temp = head;
        while (temp != NULL) {
            outfile << temp->getDato() << std::endl;
            temp = temp->next;
        }
        std::cout << std::endl;
    }
    outfile.close();
}



#endif