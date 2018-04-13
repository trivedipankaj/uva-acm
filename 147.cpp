#include<iostream>
using namespace std;

long long dp[30001][15];
int coins[] ={10000,5000,2000,1000,500,200,100,50,20,10,5};
int m= sizeof(coins)/sizeof(coins[0]);

long long countWays( int A){
    long long x,y;
    for(int i=0; i<m;i++) dp[0][i] = 1;

    for(int i=1; i<=A; i++){
        for(int j=0; j<m;j++){
            x = (i-coins[j]) >=0 ? dp[i-coins[j]][j] : 0;
            y = (j>=1) ? dp[i][j-1] : 0;
            dp[i][j] = x+y;
        }
    }
    return dp[A][m-1];
}


int main(){
    double d;
    while(cin>>d){
     if(d==0) break;
     long long n =  d * 20;
     n = n*5;
         printf("%6.2lf%17lld\n",d,countWays(n));
    }
    return 0;
}
