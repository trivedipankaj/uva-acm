#include<iostream>
#include<string>
using namespace std;

int dp[1005][1005] ={};

int lcs(string a, string b,  int m, int n){
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n;j++){
            if( a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[m][n];
}

int main(){
string a,b;
while(getline(cin,a)){
    getline(cin,b);
  for(int i=0; i<1005; i++){
    for(int j=0; j<1005; j++){
        dp[i][j]=0;
    }
  }
  cout<<lcs(a,b,a.length(), b.length())<<endl;
}
}
