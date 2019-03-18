#ifndef NODE_H
#define NODE_H


template<class T>
class Node
{
  public:
    Node(T data);
    Node(T data, Node<T> *next);
    T getData();
    Node<T>* getNext();
    void setData(T data);
    void setNext(Node<T> *next);
  private:
    T data;
    Node<T> *next;
};

template <class T>
Node<T>::Node(T data)
{
    this->data = data;
    this->next = nullptr;
}
/*
Este constructor se va a utilizar en el caso que
tengamos que agregar un nodo entre 2 nodos existentes
*/
template <class T>
Node<T>::Node(T data, Node<T> *next)
{
    this->data = data;
    this->next = next;
}

template <class T>
T Node<T>::getData(){
    return data;
}

template <class T>
Node<T>* Node<T>::getNext(){
    return next;
}

template <class T>
void Node<T>::setData(T data){
    this->data = data;
}

template <class T>
void Node<T>::setNext(Node<T> *next){
    this->next = next;
}

#endif // NODE_H
