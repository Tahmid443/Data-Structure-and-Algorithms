#include <bits/stdc++.h>
using namespace std;
void fibo(int n,int a, int b){
    if(n==0) return;
    cout << a << " ";
    return fibo(n-1,b,a+b); 
}
int main(){
    int n;
    cin >> n;
    fibo(n,0,1);
    return 0;
}