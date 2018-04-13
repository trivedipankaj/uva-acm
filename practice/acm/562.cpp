#include<iostream>
using namespace std;
int dp[200][25000];

int knapsack(int W, int w[], int n){
    for(int i=0; i<=n;i++){
        for(int j=0; j<=W; j++){
            if(i==0 || j==0) dp[i][j] =0;
            else if(j-w[i-1] >=0){
                dp[i][j] = max(dp[i-1][j], w[i-1]+dp[i-1][j-w[i-1]]); 
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
return dp[n][W];
}

int main(){
int n;
cin>>n;

while(n--){
 int m;
 cin>>m;
 int a[m];
 int sum=0;
 for(int i=0; i<m;i++){
    cin>>a[i];
    sum += a[i];
 }
 cout<<(sum - 2*knapsack(sum/2,a,m))<<endl;
}
}
