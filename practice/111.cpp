#include<iostream>
using namespace std;

int dp[25][25] ={};

int lcs(int a[], int b[],  int m, int n){
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n;j++){
            if( a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[m][n];
}

int main(){
int n;
cin>>n;
int correct[n];
int temp;
for(int i=0; i<n;i++) { cin>>temp;
    correct[--temp] = i;
}
while(1){
int answer[n];
int flag =0;
for(int i=0; i<n;i++) {
    if(scanf("%d", &temp) != 1)
                {flag = 1;break;}
    answer[--temp]=i;
}
if(flag==1) break;
    for(int i=0; i<25; i++) {
        for(int j=0; j<25; j++){
            dp[i][j]=0;
        }
    }
    cout<<lcs(correct,answer,n,n)<<endl;
}
return 0;
}
