#include<iostream>
using namespace std;
int fib(int n){
    if(n==0||n==1){ 
    return n;
    }
    return fib(n-1)+fib(n-2);
}
int main()
{
    int n;
    cin>>n;
    int d= fib(n);
    cout<<d;
    return 0;
}


// 8
// 21