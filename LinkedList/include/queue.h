#include "Node.h"
#include <iostream>
#ifndef QUEUE_H
#define QUEUE_H

template <class T>
class queue
{
    public:
        queue();            //constructor
        virtual ~queue();   //destructor

        void push(T data);  //
        void pop();         //
        T front();
        bool empty();
        int size();
    private:
        Node<T> *elFin;
        int iSize;
};

template<class T>
queue<T>::queue(){
    elFin = NULL;
    iSize = 0;
}
template<class T>
queue<T>::~queue(){
    if ( elFin != NULL){
        Node<T> *aux = elFin->getNext();
        elFin->setNext(NULL);
        elFin = aux;
        while( elFin != NULL ){
            elFin = elFin->getNext();

            delete aux;
            aux = elFin;
        }
    }
}

template <class T>
void queue<T>::push( T data ){
    if(elFin == NULL){
        elFin = new Node<T>(data);
        elFin->setNext(elFin);
    }else{
        elFin->setNext( new Node<T>( data, elFin->getNext() ) );
        elFin = elFin->getNext();
    }
    iSize++;
}

template<class T>
void queue<T>::pop(){
    Node<T> *aux = elFin->getNext();
    if( aux == elFin ){
        elFin = NULL;
    }else{
        elFin->setNext( aux->getNext() );
    }
    delete aux;
    iSize--;
}

template <class T>
T queue<T>::front(){
    return elFin->getNext()->getData();
}

template <class T>
int queue<T>::size(){
    return iSize;
}

template <class T>
bool queue<T>::empty(){
    return (elFin == NULL);
}
#endif // QUEUE_H
