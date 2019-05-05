#include "NodeT.h"
#include <cstddef>
#include <iostream>
#ifndef BST_H
#define BST_H


class BST
{
    public:
        BST();
        ~BST();
        void add(int data);
        bool search(int data);
        void remove(int data);
        void print(int c);
        int count();

    protected:

    private:
        NodeT *root;
        int howManyChildren(NodeT *r);
        int pred(NodeT *r);
        int succ(NodeT *r);
        void preOrder(NodeT *r);
        void inOrder(NodeT *r);
        void postOrder(NodeT *r);
        void liberar(NodeT *r);
        void printLeaves(NodeT *r);
        int cuenta(NodeT *r);
};

BST::BST(){
    root = NULL;
}

void BST::add(int data){
    NodeT *father = NULL;
    NodeT *curr = root;
    while(curr != NULL){
        father = curr;
        curr = (curr->getData() > data ? curr->getLeft() : curr->getRight());
        /*
        if (curr-> getData() > data)
            curr = curr->getLeft();
        else
            curr = curr->getRight();
        */
    }
    if(father == NULL){
        root = new NodeT(data);
    }else{
        if (father->getData() > data){
            father->setLeft(new NodeT(data));
        }else{
            father->setRight(new NodeT(data));
        }
        /*
        ((father->getData() > data)?
        father->setLeft(new NodeT(data)) :
        father->setRight(new NodeT(data)) );
        */
    }
}

bool BST::search(int data){
    NodeT *curr = root;
    while (curr!=NULL){
        if(curr->getData() == data){
            return true;
        }
        curr = (curr->getData() > data ? curr->getLeft() : curr->getRight());
    }
    return false;
}

void BST::remove(int data){
    NodeT *curr = root;
    NodeT *father = NULL;
    while(curr != NULL && curr->getData() != data){
        father = curr;
        curr = (curr->getData() > data ? curr->getLeft() : curr->getRight());
    }
    if(curr == NULL){
        return;
    }
    int c = howManyChildren(curr);
    switch(c){
        case 0 :
            if (father == NULL){
                root = NULL;
                delete curr;
            }else{
                if (father->getData()>data){
                    father->setLeft(NULL);
                }else{
                    father->setRight(NULL);
                }
            }
            delete curr;
            break;
        case 1 :
            if(father == NULL ){
                if(curr->getLeft() != NULL){
                    root = curr->getLeft();
                }else{
                    root = curr->getRight();
                }
            }
            else{
                if(father->getData() > data){
                        if(curr->getLeft() != NULL){
                            father->setLeft(curr->getLeft());
                        }else{
                            father->setLeft(curr->getRight());
                        }
                }else{
                    if(curr->getLeft() != NULL){
                        father->setRight(curr->getLeft());
                    }else{
                        father->setRight(curr->getRight());
                    }
                }
            }
            delete curr;
            break;
        case 2:
            int x =succ(curr);
            remove(x);
            curr->setData(x);
            break;
    }
}

int BST::howManyChildren(NodeT *r){
    int cont = 0;
    if(r->getLeft() != NULL){
        cont++;
    }
    if(r->getRight() != NULL){
        cont++;
    }
    return cont;
}

int BST::pred(NodeT *r){
    NodeT *curr = r->getLeft();
    while(curr->getLeft() != NULL){
        curr = curr->getRight();
    }
    return curr->getData();
}

int BST::succ(NodeT *r){
    NodeT *curr = r->getRight();
    while(curr->getLeft()!= NULL){
        curr = curr->getLeft();
    }
    return curr->getData();
}
void BST::postOrder(NodeT *r){
    if(r != NULL){
        postOrder(r->getLeft());
        postOrder(r->getRight());
        std::cout<<r->getData()<<"\t";
    }
}
void BST::preOrder(NodeT *r){
    if(r != NULL){
        std::cout<<r->getData()<<"\t";
        preOrder(r->getLeft());
        preOrder(r->getRight());
    }
}

void BST::inOrder(NodeT *r){
    if(r != NULL){
        inOrder(r->getLeft());
        std::cout<<r->getData()<<"\t";
        inOrder(r->getRight());
    }

}
BST::~BST(){
    liberar(root);
}

void BST::liberar(NodeT *r){
    if( r!=NULL){
        liberar(r->getLeft());
        liberar(r->getRight());
        delete r;
    }
}
void BST::printLeaves( NodeT *r ){
    if( r != NULL ){
        if( r->getLeft() == NULL && r->getRight() == NULL ){
            std::cout<<r->getData()<<" ";
        }
        printLeaves( r->getLeft() );
        printLeaves( r->getRight() );
    }
}

int BST::count(){
    return cuenta(root);
}

int BST::cuenta(NodeT *r){
    if( r != NULL ){
        return 1 + cuenta(r->getLeft())+cuenta(r->getRight());
    }else{
        return 0;
    }
}

void BST::print(int c){
    switch(c){
        case 1: preOrder(root);
            break;
        case 2: inOrder(root);
            break;
        case 3: postOrder(root);
            break;
        case 4: printLeaves(root);
            break;
    }
    std::cout<<std::endl;
}
#endif // BST_H
