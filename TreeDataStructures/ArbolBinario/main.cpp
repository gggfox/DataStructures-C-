#include "BST.h"
#include <iostream>

using namespace std;

int main()
{
    BST arbol;
    arbol.add(20);
    arbol.add(14);
    arbol.add(25);
    arbol.add(10);
    arbol.add(18);
    arbol.add(17);
    arbol.add(28);
    arbol.add(27);
    arbol.add(30);
    arbol.add(19);

    arbol.print(1);
    arbol.print(2);
    arbol.print(3);
    arbol.print(4);
    return 0;
}
