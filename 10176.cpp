#include<iostream>
#include<string>

using namespace std;
typedef long long int lint;

int main(){
 char s;
 lint ans;
 int b=0,l=0;
 while(cin>>s){
    ans = s-'0';
    while(cin>>s && s!='#'){
        ans = ans*2 + (s-'0');
        ans %= 131071;
    
    }
    if(ans==0) cout<<"YES";
    else cout<<"NO";
    cout<<endl;
 }
}
