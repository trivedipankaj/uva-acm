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
 int t, a, b,l,g;
 scanf("%d",&t);
 while(t--){
    scanf("%d %d",&a,&b);
      g = gcd(a,b);
      l = lcm(a,b);
      if( a!=g && b!=l) printf("-1\n");
      else printf("%d %d\n",a,b);
 }
}
