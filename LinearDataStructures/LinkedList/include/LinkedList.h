#include <iostream>
using namespace std;
#include "Node.h"
#ifndef LINKEDLIST_H
#define LINKEDLIST_H


template <class T>
class LinkedList
{
    public:
        LinkedList();
        ~LinkedList();

        int getSize() const;
        bool isEmpty();

        void addFirst(T data);
        void addLast(T data);
        bool add(T data, int pos);

        void deleteFirst();
        void deleteLast();
        void del(int pos);
        void print();

        void reverse();//voltea la lista encadenada
        bool operator ==( const LinkedList<T> &LL);//verifica que 2 lista sean iguales
        void operator +=(T data);//añande un nodo al final de la lista
        void operator+=(const LinkedList<T> &LL);//añade una lista al final de la lista
        LinkedList(const LinkedList<T> &LL);//crea una lista nueva igual a la lista
        void operator=(const LinkedList<T> &LL);

        T get(int pos);
        T set(int pos, T data );
        bool change (int pos1, int pos2);
        int deleteAll();

    private:
        Node<T> *head;
        int iSize;
        void deleteHelper();

};

template <class T>
LinkedList<T>::LinkedList(){
    head = NULL;
    iSize = 0;
}

template <class T>
LinkedList<T>::~LinkedList(){
  deleteHelper();
}

template<class T>
void LinkedList<T>::addFirst(T data){
    head = new Node<T>(data,head);
    iSize++;
}

template<class T>
void LinkedList<T>::addLast(T data){
  if(this->isEmpty()){
    addFirst(data);
  }else {
    Node<T> *curr = head;
    while( curr->getNext()!= NULL){
        curr = curr->getNext();
    }
    curr->setNext(new Node<T>(data, curr->getNext()));
    iSize++;
  }
}

template <class T>
bool LinkedList<T>::add(T data, int pos){
  if (pos > iSize){
    return false;
  }
  if(pos == 0){
    addFirst(data);
  }else if (pos == iSize){
    addLast(data);
  }else{
    Node<T> *curr = head;
    for(int i=0;i<pos-1;i++){
      curr = curr->getNext();
    }
    curr->setNext(new Node<T>(data,curr->getNext()));
    iSize++;
  }
  return true;
}

template <class T>
bool LinkedList<T>::isEmpty(){
    return (head == NULL);
}

template <class T>
int LinkedList<T>::getSize() const{
    return iSize;
}

template <class T>
void LinkedList<T>::deleteFirst(){
    if( !this->isEmpty() ){
        Node<T> *curr = head;
        head = head->getNext();
        delete curr;
        iSize--;
    }
}

template <class T>
void LinkedList<T>::deleteLast(){
  if(iSize <= 1){
    deleteFirst();
  }else{
    Node<T> *curr = head;
    while(curr->getNext()->getNext() != NULL){
      curr = curr->getNext();
    }
    delete curr->getNext();
    curr->setNext(NULL);
    iSize--;
  }
}

template <class T>
void LinkedList<T>::del( int pos ){
  if( pos < iSize ){
    if( pos == 0 ){
      deleteFirst();
    }else if( pos == iSize-1 ){
      deleteLast();
    }else{
      Node<T> *curr = head;
      for(int i = 1; i < pos; i++){
        curr=curr->getNext();
      }
      Node<T> *temp = curr->getNext();
      curr->setNext( temp->getNext() );
      delete temp;
      iSize--;
    }
  }
}

template <class T>
T LinkedList<T>::get( int pos )
{
  Node<T> *curr = head;
  for( int i = 0; i < pos; i++ )
  {
    curr = curr->getNext();
  }
  return curr->getData();
}

template <class T>
T LinkedList<T>::set( int pos, T data )
{
  Node<T> *curr = head;
  for (int i = 0; i < pos; i++)
  {
    curr = curr->getNext();
  }
  T temp = curr->getData();
  curr->setData(data);
  return temp;
}

template <class T>
bool LinkedList<T>::change(int pos1, int pos2)
{
  if( pos1 == pos2 ){
    return true;
  }
  //elige la posicion menor
  int posMay = ( pos1 > pos2 ? pos1 : pos2 );
  //elige la posicion mayor
  int posMen = ( pos1 < pos2 ? pos1 : pos2 );

  Node<T> *curr = head;
  for ( int i = 0; i< posMen; i++ ){
    curr = curr->getNext();
  }
  Node<T> *curr2 = curr;
  for( int i = posMen; i < posMay; i++ ){
    curr2 = curr2->getNext();
  }
  T temp = curr->getData();
  curr->setData( curr2->getData() );
  curr2->setData( temp );
  return true;
}

template <class T>
int LinkedList<T>::deleteAll(){
  int cant = iSize;
  deleteHelper();
  iSize = 0;
  return cant;
}

template <class T>
void LinkedList<T>::deleteHelper(){
  Node<T> *curr = head;
  while( !this->isEmpty() ){  //head != NULL
    head = head->getNext();
    delete curr;
    curr = head;
  }
}

template<class T>
void LinkedList<T>::print(){
  Node<T> *curr = head;
  while( curr != NULL ){
    cout<<curr->getData()<<endl;
    curr = curr->getNext();
  }
}
/*
Vamos a voltear la lista para esto vamos a necesitar
3 apuntadores uno para el actual elemento otro para
el siguiente elemento de la lista y otro para el previo
*/
template <class T>
void LinkedList<T>::reverse(){
  Node<T> *curr = head;//igualamos nuesto apuntador actual a head
  Node<T> *prev = NULL;//Nuestros apuntadores prev y next no apuntan a nada por ahora
  Node<T> *next = NULL;
  while( curr != NULL ){
    next = curr->getNext();//next apunta al siguiente nodo de curr
    curr->setNext(prev);//ahora el elemento previo ahora es el siguiente
    prev = curr;//prev avanza a curr
    curr = next;//curr avanza a head
  }
  head = prev;//una vez que salimos del ciclo ponemos nuestra cabeza al final de la lista
}
/*
Vamos a sobre cargar el operador == vamos a regresar true si
todos los elementos en las 2 listas son identicos primero checamos el tamaño
para no molestarnos en revisar lo demas si esto no es igual
*/
template <class T>
bool LinkedList<T>::operator==( const LinkedList<T> &LL){
    if( iSize != LL.getSize() ){//si el tamaño no es el mismo regresamos falso
        return false;
    }
    Node<T> *curr = head;
    Node<T> *curr2 = LL.head;
    while( curr != NULL && curr2 != NULL){
        if( curr->getData() != curr2->getData() ){
            return false;//si un dato es diferente regresa falso
        }
        curr = curr->getNext();
        curr2 = curr2->getNext();
    }
    return (curr == NULL && curr2 == NULL );//regresa verdadero si
}
/*
Vamos a sobre cargar el operador += para añada el dato
que se nos proporciono al final de una lista, o al principio
si es el primer dato que se le da a la lista
*/
template <class T>
void LinkedList<T>::operator+=( T data){
   if( this->isEmpty() ){
    addFirst(data);
  }else {
    Node<T> *curr = head;
    while( curr->getNext()!= NULL){
        curr = curr->getNext();
    }

    curr->setNext( new Node<T>( data ) );
    iSize++;

  }
}
/*
Vamos a sobre cargar el operador += para que vaya igualando una lista existente
a otra lista tambien existente,pero no vamos a apendizar una lista a la otra
solo vamos a copiar todo lo de la segunda lista al final de la primera
*/
template <class T>
void LinkedList<T>::operator+=( const LinkedList<T> &LL ){
    Node<T> *curr = head;
    Node<T> *curr2 = LL.head;
    if( LL.head != NULL){
        if(head != NULL){
        //si curr no es nulo lo avanza hasta el final
            while( curr->getNext()!= NULL ){
                curr = curr->getNext();
            }
        }else if(head == NULL){
            this->addFirst( curr2->getData() );//agregamos nuestro head
            curr = head;//actualizamos nuestro curr al nuevo head
            curr2 = curr2->getNext();//avanzamos nuestro curr 2
        }
        while( curr2 != NULL  ){
            curr->setNext( new Node<T>( curr2->getData() ) );
            iSize++;
            curr = curr->getNext();
            curr2 = curr2->getNext();
        }
    }
}
/*
Vamos a hacer un constructor copia para que iguale una lista sindatos
a otra lista existente. Hay que recordar poner actualizar el head despues
de llamar a nuestro metodo addFirst
*/
template<class T>
LinkedList<T>::LinkedList(const LinkedList<T> &LL){
    Node<T> *curr = head;
    Node<T> *curr2 = LL.head;
    if(LL.head != NULL){
        this->addFirst( curr2->getData() );
        curr2 = curr2->getNext();
        curr = head;
        iSize++;
        while( curr2 != NULL){
            curr->setNext( new Node<T>( curr2->getData() ) );
            iSize++;
            curr = curr->getNext();
            curr2 = curr2->getNext();
        }
    }
}
/*
Vamos a sobre cargar el operador = para que iguale una lista existente
a otra lista tambien existente, primero vamos a borrar todo lo de la lista
que va primero luego se iguala todo a la segunda lista
*/
template<class T>
void LinkedList<T>::operator=( const LinkedList<T> &LL){
    this->deleteAll();
    Node<T> *curr = head;
    Node<T> *curr2 = LL.head;
    if( this->isEmpty() ){
        this->addFirst( curr2->getData() );
        curr2 = curr2->getNext();
        curr = head;
        iSize++;
        while( curr2 != NULL){
            curr->setNext( new Node<T>( curr2->getData() ) );
            iSize++;
            curr = curr->getNext();
            curr2 = curr2->getNext();
        }
    }
}
#endif // LINKEDLIST_H
