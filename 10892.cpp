#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
typedef long long int lint;

lint gcd(lint a, lint b){
    return a==0 ? b : gcd(b%a , a);
}

lint lcm(lint a, lint b){
    return ( a * (b/gcd(a,b)));
}



int main(){
    lint n,ans;
    while(scanf("%lld",&n) && n!=0){
        vector<lint> v;
        int limit = (int) sqrt(n);
        ans=0;
        for(lint i=1; i<=limit; i++){
            if(n%i==0){
                v.push_back(i);
                if(i != n/i) v.push_back(n/i);
            }
        }
        for(int i=0; i< v.size(); i++){
            for(int j=i; j< v.size(); j++){
                 if( lcm(v[i], v[j]) == n){
                    ans++;
                 }
            }
        }
        printf("%lld %lld\n", n, ans);
    }
}
