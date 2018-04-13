#include<iostream>
using namespace std;

long long mat(long long a[], int n,int y){
    long long diff=1;
    for(int i=0; i<n-1; i++){
        diff =abs(a[i+1] - a[i]);

        if( diff==0 || ( y != diff && diff != 1) ){
            return -1;
        }
        if( y >1 && diff==1 && min(a[i],a[i+1]) % y ==0) return -1; 
    }
    if(y==0) y=1;
    return y;
}

int main(){

int n;
long long y=0;
long long a[300001];
long long x=1000000000;
while(cin>>n){
    for(int i=0; i<n; i++){
        cin>>a[i];
        if( i>0 &&  y < abs(a[i] - a[i-1])) y = abs(a[i]-a[i-1]);
    }
    long long ans = mat(a,n,y);
    if(ans ==-1){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
        cout<<x<<" "<<ans<<endl;
    }
    y=0;
}
return 0;
}
