#include<iostream>
using namespace std;
typedef long long int lint;
#define SIZE 65002
bool a[SIZE];
bool c[SIZE];

void sieve(){
    for(lint i=0; i<SIZE; i++) a[i] = true;
    a[1] =false;
    for(lint i=2; i<SIZE; i++){
        if(a[i]){
            for(lint j=2*i ; j<SIZE; j=j+i){
                a[j] = false;
            }
        }
    }
}


lint bigmod(lint b, lint p, lint m){
    if(p==0) return 1;
    if(p%2==0){
        lint v = bigmod(b,p/2,m) %m;
        return (v*v)%m;
    }else{
        return ( (b%m) * bigmod(b,p-1,m)%m ) %m;
    }
}

bool isCarmi(lint n){
    if(a[n]) return false;
    for(int i = 2; i < n; i++) {
		if(bigmod(i, n, n) != i) return false;
	}
	return true;
}

int main(){
    lint n;
    sieve();
    for(lint i=2 ; i< SIZE; i++){
        c[i] = isCarmi(i);    
    }
    bool flag;
    while(cin>>n && n!=0){
        if(!c[n])    
            cout<<n<<" is normal."<<endl;
        else cout<<"The number "<<n<<" is a Carmichael number."<<endl;
    }
}

