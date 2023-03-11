#include<iostream>
#include<string>
using namespace std;
  
int main(){
    string str;
    while(cin>>str){
        cout << stoi(str,0,2) << endl;
    }
}; 