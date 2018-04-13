#include<iostream>
using namespace std;
#define SIZE 1000001
typedef long long lint;

bool a[SIZE];


void sieve(){
    for(lint i=0; i<SIZE; i++) a[i] = true;
    a[1] =false;
    a[0] =false;
    for(lint i=2; i<SIZE; i++){
        if(a[i]){
            for(lint j=2*i ; j<SIZE; j=j+i){
                a[j] = false;
            }
        }
    }
}


int main(){
    sieve();
   for(int i=2; i<=100; i++){
     if(a[i]) {
        cout<<i<<" ";
     }
   } 
}
