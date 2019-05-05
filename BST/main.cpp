#include "BST.h"
#include <iostream>

using namespace std;

int main()
{
    BST arbol,tree;
    arbol.add(20);
    arbol.add(14);
    arbol.add(10);
    arbol.add(18);
    arbol.add(17);
    arbol.add(19);
    arbol.add(25);
    arbol.add(28);
    arbol.add(27);
    arbol.add(30);

    //arbol.add(24);

    arbol.print(1);
    arbol.print(2);
    arbol.print(3);


    arbol.print(4);
    std::cout<<std::endl;
    std::cout<<"altura: ";
    arbol.height();
    cout<<endl<<"What level am i (30)"<<endl;
    arbol.whatLevelamI(30);
    cout<<endl<<"ancestors of 30"<<endl;
    arbol.ancestors(30);
    cout<<endl<<"nivel por nivel"<<endl;
    arbol.print(5);
    cout<<endl;
    arbol.maxWidth();
   // arbol.nearestRelative(20,30);
    arbol.nearestRelative(14,25);
    arbol.nearestRelative(27,30);
    arbol.nearestRelative(20,30);
    arbol.nearestRelative(10,19);
    cout<<endl;

    tree.add(50);
    tree.add(55);
    tree.add(49);
    tree.add(48);
    tree.add(45);
    tree.add(40);
    tree.add(46);
    tree.mirror();
    tree.print(5);
    arbol.mirror();
    arbol.print(5);
    BST otro(arbol);
    otro.print(5);
    if(otro==arbol){
    std::cout<<"Funciona h";
    }
    return 0;
}
