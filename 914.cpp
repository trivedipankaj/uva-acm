#include<iostream>
using namespace std;
#define SIZE 1000001
typedef long long lint;

bool a[SIZE];
int b[SIZE];

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
    int t,l,u;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&l, &u);
        int prev=-1,diff=0;
        for(int i=0; i<SIZE; i++) b[i] =0;
        for(int i=l; i<=u;i++){
            if(a[i]){
                if(prev ==-1){
                    prev = i;
                }else{
                   diff = i - prev;
                   prev = i;
                   b[diff]++;
                }
            } 
        }
        int max=0;
        int ans=-1;
        for(int i=0 ; i< SIZE; i++){
            if(b[i] !=0 && b[i] >= max) {
                if(b[i] == max) {
                    ans = -1;
                }else{
                    max = b[i];
                    ans = i;
                }
            }
        }
        if(ans ==-1) {
            printf("No jumping champion\n");
        }else{
            printf("The jumping champion is %d\n", ans);
        }

    }
}
