#include<iostream>
using namespace std;

int main(){
int dp[100];

int a[] = {10,22,9,33,21,50,41,60,80};
int n=sizeof(a)/sizeof(a[0]);

for(int i=0; i<100;i++){
    dp[i] = 1;
}

for(int i=0; i<n;i++){
    for(int j=0; j<i; j++){
        if(a[i] > a[j] && dp[i] < dp[j]+1)
            dp[i]= dp[j]+1;
    }
}
int max=INT_MIN;
int pos=-1;
for(int i=0; i<n; i++){
    if(max < dp[i]) {
        max = dp[i];
        pos =i;
    }
}
cout<<max<<endl;
return 0;
}
