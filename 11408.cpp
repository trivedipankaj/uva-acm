#include<iostream>
using namespace std;
#define SIZE 5000001
typedef long long lint;

bool a[SIZE];
int f[SIZE];
int ans[SIZE];

void sieve(){
    for(lint i=0; i<SIZE; i++) {
        a[i] = true;
        f[i] =0;
        ans[i]=0;
    }
    a[1] =false;
    a[0] =false;
    for(lint i=2; i<SIZE; i++){
        if(a[i]){
            f[i] += i;
            for(lint j=2*i ; j<SIZE; j=j+i){
                a[j] = false;
                f[j] += i;
            }
        }
    }
    int sum=0;
    for(int i=2; i<SIZE;i++){
        if(a[f[i]]){
            sum += 1;
        }
        ans[i] =sum;
    }
}


int main(){
    sieve();
    int a,b;
    while(scanf("%d %d",&a,&b) && a!=0){
        printf("%d\n",ans[b] -ans[a-1]);
    
    }
}
