#include<iostream>
using namespace std;
typedef long long int lint;

lint gcd(lint a, lint b){
    return a==0 ? b : gcd(b%a , a);
}

lint lcm(lint a, lint b){
    return ( a * (b/gcd(a,b)));
}



int main(){
 cout<<gcd(10,15)<<endl;
}
