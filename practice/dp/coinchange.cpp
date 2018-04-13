#include<iostream>
using namespace std;

int main(){
    int S[] ={1,5,10,25,50};
    int n;
   int x,y; 
   while(cin>>n){
    int dp[n+1][6];
    for(int i=0; i<5;i++){
        dp[0][i]=1;
    }
    for(int i=1; i<=n; i++){
       for(int j=0; j<5; j++) {
        x = (i-S[j] >= 0)? dp[i - S[j]][j]: 0;
        y = (j >= 1)? dp[i][j-1]: 0;
        dp[i][j] = x+y;
       }
    }
    cout<<dp[n][4]<<endl;
   }
}
