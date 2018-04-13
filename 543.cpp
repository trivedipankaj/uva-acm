#include<iostream>
using namespace std;
#define SIZE 1000001
bool a[SIZE];
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
    int n;
    while(cin>>n && n!=0){
    int s,b,diff=-1;
    a[2]=false;
    for(int i=3; i<=n/2; i=i+2){
     if(a[i] && n-i >=0 && a[n-i]) {
            if(a[i] - a[n-i] > diff){
                diff = a[i] - a[n-i];
                s = i;
                b = n-i;
                break;
            } 
        }
    } 
    if(diff ==-1) cout<<"Goldbach's conjecture is wrong."<<endl;
        else cout<<n<<" = "<<s<<" + "<<b<<endl;
    }
}
