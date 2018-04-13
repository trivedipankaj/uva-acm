#include<iostream>
using namespace std;
typedef long long int lint;

lint bigmod(lint b, lint p, lint m){
    if(p==0) return 1;
    if(p%2 == 0){
        lint v =bigmod(b,p/2,m)%m;
        return (v * v)%m;
    }else{
        return ((b%m) * bigmod(b,p-1,m) %m) %m;
    }
}


int main(){
    lint b,p,m;
    while(cin>>b>>p>>m){
        cout<<bigmod(b,p,m)<<endl;
    }
}
