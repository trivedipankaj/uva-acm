#include<iostream>
using namespace std;
#define SIZE 1000002
bool a[SIZE];
typedef long long  lint;
lint aprime[SIZE];

void sieve(){
    for(int i=0; i<SIZE; i++) a[i] = true;
    a[1] =false;
    a[0] = false;
    for(int i=2; i<SIZE; i++){
        if(a[i]){
            for(int j=2*i ; j<SIZE; j=j+i){
                a[j] = false;
            }
        }
    }
}


int main(){
    sieve();
    int n=0;
    for(lint i=2; i<SIZE; i++){
        if(a[i]){
            for(lint j= i*i; j<=1000000000000LL; j=j*i) aprime[n++] = j;
        }
    }
    int t;
    lint low, high;
    cin>>t;
    while(t--){
        cin>>low>>high;
        int ans=0;
        for(int i=0; i<n;i++){
            if(aprime[i]>= low && aprime[i] <= high) {
                ans++;
            } 
        }
        cout<<ans<<endl;
    }
}
