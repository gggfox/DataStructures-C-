#include <iostream>
#include "heap.h"

using namespace std;

int main(){
    heap arbol(false) ;
    arbol.push(6);
    arbol.push(3);
    arbol.push(2);
    arbol.push(4);
    arbol.push(5);
    arbol.push(1);
    arbol.push(7);
    arbol.push(8);
    arbol.push(9);
    arbol.push(10);
    arbol.push(41);
    arbol.push(51);
    arbol.push(11);
    arbol.push(71);
    arbol.push(81);
    arbol.push(91);
    //cout<<arbol.iSize()<<endl;
    arbol.print();
    cout<<endl<<endl;
    arbol.pop();
    arbol.print();
    cout<<endl<<endl;
    arbol.pop();
    arbol.print();
    return 0;
}
