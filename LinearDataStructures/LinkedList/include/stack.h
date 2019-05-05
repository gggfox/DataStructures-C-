#include <iostream>
#include "Node.h"

#ifndef STACK_H
#define STACK_H

template <class T>
class stack
{
    public:
        stack();            //constructor
        virtual ~stack();   //destructor
        void push(T data);  //añande elemento al final
        void pop();         //borra el elemento del final
        T top();            //regresa el elemento del final
        bool empty();       //verifica si el stack esta vacio
        int size();         //regresa el tamaño

    private:
        Node<T> *tope;
        int iSize;
};

template <class T>
stack<T>::stack(){
    tope = NULL;
    iSize = 0;
}

template <class T>
stack<T>::~stack(){
    Node<T> *aux = tope;
    while ( aux != NULL){
        tope = tope->getNext();
        delete aux;
        aux = tope;
    }
}

template <class T>
void stack<T>::push(T data){
    tope = new Node<T>(data, tope);
    iSize++;
}

template <class T>
void stack<T>::pop(){
    Node<T> *aux = tope;
    tope = tope->getNext();
    delete aux;
    iSize--;
}

template <class T>
T stack<T>::top(){
    return tope->getData();
}

template <class T>
int stack<T>::size(){
    return iSize;
}

template <class T>
bool stack<T>::empty(){
    return(tope == NULL);
}
#endif // STACK_H
