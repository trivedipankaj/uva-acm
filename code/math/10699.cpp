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
    int n,ans,t;
    while(cin>>n && n!=0){
        ans=0;
        t =n;
        for(int i=2; i<=n;i++){
            if(a[i] && t!=1){
                if(t%i ==0){
                    t = t/i;
                    ans++;
                    if(t==1) break;
                }
            }
        }
        cout<<n<<" : "<<ans<<endl;
    }
}
