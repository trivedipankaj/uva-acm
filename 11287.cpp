#include<iostream>
using namespace std;
typedef long long int lint;

bool isPrime(int n){
    for(int i=2; i*i<=n; i++){
        if(n%i ==0) return false;
    }
    return true;
}

lint bigmod(lint b, lint p, lint m){
    if(p==0) return 1;
    if(p%2==0){
        lint v = bigmod(b,p/2,m) %m;
        return (v*v)%m;
    }else{
        return ( (b%m) * bigmod(b,p-1,m)%m ) %m;
    }
}


int main(){
    lint a,p;
    while(cin>>p>>a && p!=0 && a!=0){
        if(isPrime(p) || bigmod(a,p,p) !=a) cout<<"no"<<endl;
        else cout<<"yes"<<endl;
    }
}

