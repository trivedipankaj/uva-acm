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
    int n,sum,ans;
    while(cin>>n && n!=0){
        sum =0;
        ans=0;
        for(int i=0; i<=n;i++){
            for(int j=i ; a[i] && j<=n; j++){
               if(a[j]){
                   sum += j; 
                   if(sum >= n){
                    if(sum ==n )
                        ans++;
                    sum=0;
                    break;
                   }
               } 
            }
        }  
    cout<<ans<<endl;
    }

}
