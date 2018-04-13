#include<iostream>
using namespace std;
#define SIZE 20000001
typedef long long lint;

bool a[SIZE];
lint b[SIZE];

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

void settwin(){
    lint num=1;
    for(lint i=3; i<SIZE-2; i++){
        if(a[i] && a[i+2]){
            b[num++] =i;
        }
    }
}



int main(){
    sieve();
    settwin();
    lint n;
    while(cin>>n){
       cout<<"("<<b[n]<<", "<<b[n]+2<<")"<<endl;
    }
}
