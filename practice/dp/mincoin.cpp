#include<iostream>
using namespace std;

int c[]={1,3,7};
int N= sizeof(c)/sizeof(c[0]);
int M=7;
int main(){
    int dp[M+1];
    dp[0] = 0;
    for(int i=1; i<=M; i++){
        dp[i]=INT_MAX;
       for(int j=0; j<N; j++){
           if(i-c[j]>=0)
            dp[i] = min(dp[i], dp[i-c[j]]) +1;
       } 
    }
    cout<<dp[M];
return 0;
}
