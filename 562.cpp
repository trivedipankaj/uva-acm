#include<iostream>
#include<string>
using namespace std;
int cache[30];

bool isValid(string s){
    if(s.length() <4) return false;
    for(int i=0; i<s.length(); i++){
       cache[s[i]-'a'] += 1; 
    }
    int count=0;
    for(int i=0; i<30; i++){
        if(cache[i] != 0) count++;
    }
    for(int i=0; i<30;i++)
        if(count==2 && ( cache[i] !=0 && cache[i] < 2)) return false;
    if(count > 4 || count==1) return false;
    return true;
}


int main(){
   string s;
   while(cin>>s){
    for(int i=0; i<30; i++) cache[i] =0;
      if(isValid(s)){
        cout<<"Yes"<<endl;
      }else{
        cout<<"No"<<endl;
      }
   }
}
