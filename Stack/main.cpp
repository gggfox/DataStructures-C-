#include <iostream>
#include <sstream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

bool isOperator(const string& input);
void performOpStack(const string& input, stack<int>& iStack);
void performOpQueue(const string& input, queue<int>& iQueue);
void performOpPriority(const string& input, priority_queue<int, vector<int>, std::greater<int> >& iPriority );
void printStack(stack<int> iStack);

/*SAMPLE INPUT
7 4 - 5 *
3 2 4 * +
3 4 2 - *
42 7 - 3 * 2 4 + *
5 3 5 - * 11 2 - 1 * -
#
*/

/*SAMPLE OUTPUT
15 -15 15
11 10 10
6 2 4
630 -412 630
-19 41 3
*/
int main(){
    queue<int>iQueue;//variable para mi queue
    stack<int>iStack;//variable para mi stack
    priority_queue<int, vector<int>, std::greater<int> > iPriority; //variable para mi priority queue

    string d, data,input;//variable para simbolos de ingreso
    int num = 0;//variable para suma

    getline(cin, data);    //usuario inserta valores
    while(data != "#"){    //loop para varios calculos
        stringstream ss;   //nos va a dejar leer el string como si fuera un archivo de texto
        ss << data;        //ingresar string a variable ss
        while (ss >> d){//mientras pueda meterle valores voy ameterle valores
            input = d;
            if(istringstream(input)>>num){
                iStack.push(num);
                iQueue.push(num);
                iPriority.push(num);
            }else
            if(isOperator(input)){
                performOpStack(input,iStack);
                performOpQueue(input,iQueue);
                performOpPriority(input, iPriority);
            }

        }
        cout<<iStack.top()<<" "<<iQueue.front()<<" "<<iPriority.top()<<endl;
   //     cout << "Termine linea" << endl;
        while(!iStack.empty()){
           iStack.pop();
        }
        while(!iQueue.empty()){
           iQueue.pop();
        }
        while(!iPriority.empty()){
            iPriority.pop();
        }

        getline(cin, data);
    }
    return 0;
}

void performOpStack(const string& input, stack<int>& iStack){
  int iVal, iVal2, iResult = 0;

  iVal2 = iStack.top();
  iStack.pop();

  iVal = iStack.top();
  iStack.pop();

  if(input == "-"){
    iResult = iVal - iVal2;
  }
  else if(input == "+"){
    iResult = iVal + iVal2;
  }
  else if(input == "*"){
    iResult = iVal * iVal2;
  }
  else{
    iResult = iVal / iVal2;
  }

  iStack.push(iResult);

  //printStack(iStack);
}

void performOpQueue(const string& input, queue<int>& iQueue){
  int iVal, iVal2, iResult = 0;

  iVal = iQueue.front();
  iQueue.pop();

  iVal2 = iQueue.front();
  iQueue.pop();

  if(input == "-"){
    iResult = iVal2 - iVal;
  }
  else if(input == "+"){
    iResult = iVal + iVal2;
  }
  else if(input == "*"){
    iResult = iVal * iVal2;
  }
  else{
    iResult = iVal / iVal2;
  }
  iQueue.push(iResult);
}

void performOpPriority(const string& input, priority_queue<int, vector<int>, std::greater<int> >& iPriority ){
  int iVal, iVal2, iResult = 0;

  iVal2 = iPriority.top();
  iPriority.pop();

  iVal = iPriority.top();
  iPriority.pop();

  if(input == "-"){
    iResult = iVal - iVal2;
  }
  else if(input == "+"){
    iResult = iVal + iVal2;
  }
  else if(input == "*"){
    iResult = iVal * iVal2;
  }
  else{
    iResult = iVal / iVal2;
  }
  iPriority.push(iResult);
}

bool isOperator(const string& input){
  string ops[] = {"-","+","*","/"};
  for(int i = 0; i < 4;i++){
    if(input == ops[i]){
      return true;
    }
  }
  return false;
}




