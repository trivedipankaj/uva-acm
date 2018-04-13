#include<iostream>
using namespace std;

int main(){
int t,n,m,k,y,ans=0;
cin>>t;
while(t--){
    ans=0;
    cin>>n>>m;
    while(m--){
        cin>>k;
        int z=1;
        for(int i=0; i<k; i++){
            cin>>y;
            z *=y; z %=n;
        }
        ans += z;
        ans %= n;
    }
    cout<<ans<<endl;
}

}
