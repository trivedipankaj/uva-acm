#include<iostream>
using namespace std;
#define SIZE 100000001
typedef long long int lint;
bool a[SIZE];
/****
 *  Goldbach's Conjecture
 * */

void seive(){
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
    seive();
    lint n;
    while(cin>>n){
    int s,b,diff=-1;
    if(n%2 == 1){
       s =2;
       if(a[n-s]){
         diff =1;
         b = n-s;
       }else{
        diff =-1;
       }
    }else{
    for(int i=n/2; i>=3; --i){
     if(a[i] && n-i >=0 && a[n-i] && i != n-i) {
                diff = 1;
                s = i;
                b = n-i;
                break;
        }
        } 
    }
    if(diff ==-1) cout<<n<<" is not the sum of two primes!"<<endl;
        else cout<<n<<" is the sum of "<<s<<" and "<<b<<"."<<endl;
    }
}
