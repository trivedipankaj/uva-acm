#include<iostream>
using namespace std;
#define SIZE 1000001
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
int sum(lint n){
    int ans=0;
    while(n !=0){
        ans += n%10;
        n /= 10;
    }
    return ans;
}
void dig_prime(){
   lint num=0;
   for(lint i=0; i<SIZE; i++){
        if(a[i] && a[sum(i)]){
            num++;
        }
        b[i] = num;
   }
}

int main(){
    sieve();
    dig_prime();
    lint m,n,ans;
    int t;
    scanf("%d",&t);
    while(t-- && scanf("%lld %lld",&m,&n)){
        ans=0;
        if( (a[m] && a[sum(m)])) ans =1;
        printf("%lld\n",ans+ b[n] -b[m]);
    }
}
