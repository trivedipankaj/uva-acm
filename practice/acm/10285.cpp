#include<iostream>
#include<string>
using namespace std;
#define SIZE 100
#define F(i,L,R) for(int i=L; i<R; i++)
int a[SIZE][SIZE];
int dp[SIZE][SIZE];
int mi,r,c;

int dfs(int i, int j){
    if(dp[i][j] != -1) return dp[i][j];
    int mi=0;
    if(i-1>=0 && a[i-1][j] < a[i][j]) mi = max(mi, dfs(i-1,j)+1);
    if(j-1>=0  && a[i][j-1] < a[i][j]) mi =max(mi,dfs(i,j-1)+1);
    if(i+1<r && a[i+1][j] <a[i][j]) mi =max(mi, dfs(i+1,j)+1);
    if(j+1<c && a[i][j+1] < a[i][j]) mi = max(mi,dfs(i,j+1)+1);
    
    dp[i][j] =mi;
    return mi;
}

int main(){
int k;
string s;
cin>>k;
while(k--){
cin>>s>>r>>c;
F(i,0,r){
    F(j,0,c){
        cin>>a[i][j];
        dp[i][j] = -1;
    }
}
int mi=0;
F(i,0,r){
    F(j,0,c){
        mi = max(mi, dfs(i,j));
    }
}
 cout << s << ": " << mi+1 << endl;
}
    return 0;
}
