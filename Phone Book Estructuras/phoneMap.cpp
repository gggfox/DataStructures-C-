#include <iostream>
#include <queue>
#include <map>

using namespace std;

void add(int phone, string name,map<int,string> &nameMap){
    nameMap[phone]=name;
}

void find(int phone, map<int,string> &nameMap){
    (nameMap[phone].empty()?cout<<"not found \n":cout<<nameMap[phone]<<"\n");
}

void del(int phone,map<int,string> &nameMap){
    nameMap.erase(phone);
}

int main(){
    int n,phone;
    string name,action;
    map<int,string> nameMap;
    cin>>n;
    for(int i=0;i<=n;i++){
        cin>>action;
        cin>>phone;
        if(action=="add"){
            cin>>name;
            add(phone,name,nameMap);
        }if(action=="find"){
            find(phone,nameMap);
        }if(action=="del"){
            del(phone,nameMap);
        }
    }
    cout<<endl;
    return 0;
}