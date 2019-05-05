//Gerado Galan Garzafox
//A00821196

#include <iostream>
#include <vector>

#ifndef HEAP_H
#define HEAP_H

using namespace std;

class heap
{
    public:
        heap();                             //default constructor
        heap(bool);                         //cutom constructor
        int iSize();                        //number of "nodes" in our heap
        int top();                          //root of our heap
        bool bEmpty();                      //to see if the heap is empty
        void print();                       //print the heap for testing
        void push(int dato);                //add a new "node"
        bool checa(int dir);                //to organize depending on the priority

        void pop();                         //to delete the root
        bool check(int dir,int iNext);      //balance the pop depending on the priority
        int myNextNode(int dir);            //gives back the next "node" in pop function

    private:
        vector<int>contenedor;
        bool prioridad;
        int tam;
        void reacomodoAbajo(int data);//formula pop
};

heap::heap(){
    contenedor.assign(101,0);
    prioridad = true;
    tam = 0;
}

heap::heap(bool b){
    contenedor.assign(101,0);
    prioridad = b;
    tam = 0;
}

int heap::iSize(){
    return tam;
}

int heap::top(){
    return contenedor[1];
}

bool heap::bEmpty(){
    if(tam == 0){
        return true;
    }else{
        return false;
    }
}

void heap::print(){
    int cont = 1;
    int level = 2;
    while(cont<=tam){
        cout<<contenedor[cont]<<"\t";
        cont++;
        if(level==cont){
            cout<<endl;
            level = level*2;
        }
    }
}

void heap::push(int dato){
    contenedor[++tam]=dato;
    int dir = tam;
    while(dir!=1 && checa(dir)){
        int aux = contenedor[dir/2];
        contenedor[dir/2]=contenedor[dir];
        contenedor[dir]=aux;
        dir/=2;
    }
}

bool heap::checa(int dir){
    if(prioridad){
        return(contenedor[dir/2]<contenedor[dir]);
    }else return (contenedor[dir/2]>contenedor[dir]);
}


void heap::pop(){
    contenedor[1]=contenedor[tam--];
    int dir = 1;
    int iNext = myNextNode(dir);
    while(check(dir,iNext)&&iNext<=tam){
        int aux = contenedor[dir];
        contenedor[dir]=contenedor[iNext];
        contenedor[iNext]=aux;
        dir = iNext;
        iNext = myNextNode(dir);
    }


}
bool heap::check(int dir,int iNext){
    if(prioridad){
        return contenedor[dir]<contenedor[iNext];
    }else{
        return contenedor[dir]>contenedor[iNext];
    }
}

int heap::myNextNode(int dir){
    if(prioridad){
        int iNext=(contenedor[dir*2]>contenedor[dir*2+1])?dir*2:dir*2+1;
        return iNext;
    }else{
        int iNext=(contenedor[dir*2]<contenedor[dir*2+1])?dir*2:dir*2+1;
        return iNext;
    }
}


#endif // HEAP_H
