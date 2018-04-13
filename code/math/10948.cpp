#include<iostream>
using namespace std;
#define SIZE 1000001
bool a[SIZE];
/****
 *Similar problem: 543 - Goldbach's Conjecture
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
    int n;
    while(cin>>n && n!=0){
    int s,b,diff=-1;
    for(int i=2; i<=n; i++){
     if(a[i] && n-i >=0 && a[n-i]) {
            if(a[i] - a[n-i] > diff){
                diff = a[i] - a[n-i];
                s = i;
                b = n-i;
            } 
        }
    } 
    cout<<n<<":"<<endl;    
    if(diff ==-1) cout<<"NO WAY!"<<endl;
        else cout<<s<<"+"<<b<<endl;
    }
}
