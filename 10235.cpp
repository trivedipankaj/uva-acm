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

lint reverse(lint n){
    lint ans=0;
    while( n !=0 ) {
        ans *=10;
        ans += n%10;
        n /= 10;
    }
    return ans;
}

int main(){
    sieve();
    lint n,r;
    while(cin>>n){
       lint r = reverse(n);
       if( r == n){
           r = 0;
       }
       if(!a[n]){
        cout<<n<<" is not prime.";
       }else if(!a[r]){
          cout<<n<<" is prime.";
       }else{
          cout<<n<<" is emirp.";
       }
       cout<<endl;
    }
}
