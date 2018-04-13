#include<iostream>
using namespace std;
#define SIZE 1000001
bool a[SIZE];
bool mark[SIZE];
/****
 *  Goldbach's Conjecture
 * */

void seive(){
    for(int i=0; i<SIZE; i++) a[i] = true;
    a[1] =false;
    a[0] =false;
    for(int i=2; i<SIZE; i++){
        if(a[i]){
            for(int j=2*i ; j<SIZE; j=j+i){
                a[j] = false;
            }
        }
    }
}

int main(){
    seive();
    int n,ans;
    while(cin>>n && n!=0){
    int s,b,diff=-1;
    ans=0;
    for(int i=0; i<=n; i++){
        mark[i] =false;
    }
    for(int i=2; i<=n; i++){
     if(a[i] && n-i >=0 && a[n-i]) {
            if(i> n-i) break;
            ans++;
            } 
     }
    
    cout<<ans<<endl;    
    } 
}
