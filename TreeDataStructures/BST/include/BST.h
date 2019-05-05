#include "NodeT.h"
#include <cstddef>
#include <iostream>
#include <stack>
#include <queue>
#ifndef BST_H
#define BST_H


class BST
{
    public:
        BST();
        BST(const BST &otro);
        ~BST();
        void add(int data);
        bool search(int data);
        void remove(int data);
        void print(int c);
        int count();
        void whatLevelamI(int data);
        void ancestors(int data);
        void height();

        void nearestRelative(int nodo1, int nodo2);
        void maxWidth();
        void mirror();
        bool operator ==(const BST &otro);
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
        int cuenta(NodeT *r);//counts the number of nodes in our Binary Seach Tree
        int getHeight(NodeT *r);//prints the height for the BST

        int getLevel(NodeT *r, int data, int level);
        void getAncestors(NodeT *r, int data,std::stack<int> iStack);
        void NivelxNivel(NodeT *r);
        NodeT* findNR(NodeT *r, int n1, int n2);//finds nearest relative
        int getWidth(NodeT *r);
        void flip(NodeT *r);
        NodeT* copyPreorder(NodeT *r);
        bool checkPreorder(NodeT *r1, NodeT *r2);
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

int BST::getHeight( NodeT *r ){
  if(r == NULL )return 0;
  else{
    int lAlt = getHeight( r->getLeft() );
    int rAlt = getHeight( r->getRight() );

    if( lAlt > rAlt )return( lAlt + 1 );
    else return( rAlt + 1 );
  }

}

void BST::height(){
  std::cout<<getHeight(root)<<std::endl;
}

int BST::getLevel(NodeT *r, int data, int level){
  if(!search(data))return -1;
  if( r == NULL )return 0;
  if( r->getData() == data )return level;
  int ilevelBelow = getLevel( r->getLeft(),data,level+1);
  if( ilevelBelow != 0)return ilevelBelow;
  ilevelBelow = getLevel( r->getRight(),data,level+1);
  return ilevelBelow;
}

void BST::whatLevelamI(int data){
  std::cout<<getLevel(root, data, 0)<<std::endl;
}

void BST::ancestors(int data){
  std::stack<int> iStack;
  getAncestors(root,data, iStack);
}
//este metodo imprime los anacestros del valor pedido, no imprime si valor no existe en el arbol o
//si se pide el ancestro de root, usa stacks para imprimir
void BST::getAncestors(NodeT *r, int data,std::stack<int> iStack){
    if( !search(data) )std::cout<<"No existe este valor en el arbol"<<std::endl;
    if( r->getData() == data )std::cout<<"No tiene ancestros"<<std::endl;
    NodeT *curr = r;
    while (curr != NULL){
        if(curr->getData() == data){
            while(!iStack.empty()){
              std::cout<<iStack.top()<<std::endl;
              iStack.pop();
            }
        }
        iStack.push(curr->getData());
        curr = (curr->getData() > data ? curr->getLeft() : curr->getRight());
    }

}

void BST::NivelxNivel(NodeT *r){
  if( r == NULL )return;
  std::queue<NodeT *> iQueue;
  iQueue.push(r);
  while(!iQueue.empty()){

    int numNodes = iQueue.size();

    while( numNodes > 0 ){
      NodeT *nodo = iQueue.front();
      std::cout<<nodo->getData()<<" ";
      iQueue.pop();
      if (nodo->getLeft() != NULL)
        iQueue.push( nodo->getLeft() );
      if (nodo->getRight() != NULL)
        iQueue.push( nodo->getRight() );
      numNodes--;
    }
    std::cout<<std::endl;
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
        case 5: NivelxNivel(root);
         break;

    }
    std::cout<<std::endl;
}
NodeT* BST::findNR(NodeT *r, int n1, int n2){
  //if there are not any values in the
  if( r == NULL ) return NULL;
  //if a value is the same as root, then it is the nearest relaitve
  if( r->getData() == n1 || r->getData() == n2 ) return r;

  NodeT *left = findNR(r->getLeft(),n1,n2);
  NodeT *right = findNR(r->getRight(),n1,n2);

  if(left!=NULL && right!=NULL) return r;
  return(left != NULL)?left:right;

}

void BST::nearestRelative(int nodo1, int nodo2 ){
  std::cout<<"Nearest Relative of "<< nodo1 <<" and "<< nodo2<<": "<<findNR(root, nodo1, nodo2)->getData()<<std::endl;
}

int BST::getWidth(NodeT *r){
int maxVal = 0;
  if( r == NULL )return maxVal;
  std::queue<NodeT *> iQueue;
    iQueue.push(r);

    while(!iQueue.empty()){
    int numNodes = iQueue.size();
    if(numNodes>maxVal)maxVal=numNodes;

    while( numNodes > 0 ){
      NodeT *nodo = iQueue.front();
      iQueue.pop();
      if (nodo->getLeft() != NULL)
        iQueue.push( nodo->getLeft() );
      if (nodo->getRight() != NULL)
        iQueue.push( nodo->getRight() );
      numNodes--;
    }
  }
  return maxVal;
}

void BST::maxWidth(){
  std::cout<<"the largest level has "<<getWidth(root)<<" nodes"<<std::endl;

}


void BST::mirror(){
  flip(root);
}




void BST::flip(NodeT *r){
        if(r == NULL)return;
        else{
            NodeT *temp;

            flip(r->getLeft());
            flip(r->getRight());

            temp = r->getLeft();
            r->setLeft(r->getRight());
            r->setRight(temp);
        }
      }

NodeT* BST::copyPreorder(NodeT *r){
  if(r==NULL)
    return NULL;
  NodeT* curr = new NodeT(r->getData());
  curr->setLeft(copyPreorder(r->getLeft()));
  curr->setRight(copyPreorder(r->getRight()));
  return curr;
}

BST::BST(const BST &otro){
  root = copyPreorder(otro.root);
}

bool BST::operator ==(const BST &otro){
  return checkPreorder(this->root,otro.root);
}

bool BST::checkPreorder(NodeT *r1, NodeT *r2){
  if(r1==NULL&&r2==NULL)return true;
  if(r1==NULL&&r2!=NULL||r1!=NULL&&r2==NULL)return false;
  if(r1->getData()!=r2->getData())return false;
  return checkPreorder(r1->getLeft(),r2->getLeft())&&
  checkPreorder(r1->getRight(),r2->getRight());
}


#endif // BST_H
