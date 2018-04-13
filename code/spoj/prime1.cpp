#include<iostream>
using namespace std;
typedef long long int lint;

bool isPrime(lint n){
    if(n==1) return false;
    for(int i=2; i*i <= n; i++){
        if(n%i ==0) return false;
    }
    return true;
}

int main(){
    lint m,n;
    int t;
    cin>>t;
    while(t--){
        cin>>m>>n;
        for(lint i=m; i<=n; i++){
            if(isPrime(i)){
                cout<<i<<endl;
            }
        }
        cout<<endl;
    }
}
