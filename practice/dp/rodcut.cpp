#include<iostream>
using namespace std;

int rodcut(int a[], int n){
    int dp[100];
    dp[0]=0;
    for(int i=1; i<=n; i++){
        int m=INT_MIN;
        for(int j=1; j<=i; j++){
            cout<<m<<endl;
            m = max(m, a[j-1]+ dp[i-j]);
        }
        dp[i] =m;
    }
    return dp[n];
}

int main(){
    int a[]={1,5,8,9};
    cout<<rodcut(a,4);
return 0;
}
