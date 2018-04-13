#include<iostream>
#include<string>
using namespace std;
#define SIZE 2000
bool a[SIZE];


void seive(){
    for(int i=0; i<SIZE; i++) a[i] = true;
    a[1] =true;
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
  string s;
  int len;
  while(cin>>s){
      len =0;
    for(int i=0; i<s.length(); i++){
        if(islower(s[i]))
            len += s[i] -'a' +1;
        else len += s[i] -'A' +27;
    }
    if(a[len]){
        cout<<"It is a prime word."<<endl;
    }else{
        cout<<"It is not a prime word."<<endl; 
    }
  }
}
