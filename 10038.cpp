#include<iostream>
using namespace std;
#define SIZE 3000
int a[SIZE];
int b[SIZE];

int main(){
    int n,diff;
    while(cin>>n){
    for(int i=0; i<n; i++) b[i] =0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        if(i>0){
            diff = abs(a[i] - a[i-1]);
            if(diff > 0 && diff < n){
                b[diff-1] = 1;
            }
        }
    }
    bool flag = true;
    for(int i=0; i<n-1; i++){
        if(b[i] == 0) { 
            flag =false;
        }
    }
        if(!flag) cout<<"Not jolly"<<endl;
        else cout<<"Jolly"<<endl;
   }
}
