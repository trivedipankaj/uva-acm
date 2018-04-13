#include<iostream>
#include<string>

using namespace std;
#define SIZE 1001
typedef long long lint;

bool a[SIZE];
int cache[128];

void sieve(){
    for(lint i=0; i<SIZE; i++) a[i] = true;
    a[1] =false;
    a[0]=false;
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
    int n;
    int cases=0;
    string s;
    cin>>n;
    while(n--){
      cases++;
      
      for(int i=0; i<128;i++) cache[i]=0;
      cin>>s;  
      
      for(int i=0; i<s.length();i++){
        cache[int(s[i])]++;
      }
      cout<<"Case "<<cases<<": ";
      bool flag=false;
      for(int i=0; i<128; i++){
        if(a[cache[i]]){
            cout<<char(i);
            flag =true;
        }
      }
      if(!flag) cout<<"empty";
      cout<<endl;
    }
}
