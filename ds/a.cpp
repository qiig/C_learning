#include<iostream>
using namespace std;
int f(int a, int b = 20, int c = 30){
    return a+b+c;
}
int main(){
    cout << f(10,10) << endl;
    return 0;
}