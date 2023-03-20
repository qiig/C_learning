#include<bitset>
#include<iostream>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        bitset<32> b(n);
        cout<<b.count()<<endl;
    }
}