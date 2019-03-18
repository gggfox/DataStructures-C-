#include <iostream>
#include "LinkedList.h"
#include "stack.h"
#include "queue.h"
using namespace std;

int main(){
    queue<string> miPila;
    miPila.push("AAA");
    miPila.push("BBB");
    miPila.push("CCC");

    if( !miPila.empty() )
    cout<<"total de datos = "<<miPila.size()<<endl;

    cout<<endl;

    while( !miPila.empty() ){
        cout<<miPila.front()<<endl;
        miPila.pop();
    }

    cout<<endl;

    cout<<"total de datos = "<<miPila.size()<<endl;
    return 0;
}
