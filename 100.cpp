#include<iostream>
using namespace std;

int main(){
int a,b;
while(cin>>a>>b){
        int t;
	bool f=true;
	if( a > b){
		t =b;
		b =a;
		a =t;
		f= false;	
	}	
	int m=-1,v;
	for(int i=a; i<=b; i++){
		unsigned int n = i;
		int cnt =1;
		while(n!=1){
			cnt +=1;
			if(n%2==1)
				n = 3*n+1;
			else
				n =n/2;			
		}
		if ( cnt > m){
	     	m = cnt;
	     }
	}
	if(f)	
		cout<<a<<" "<<b<<" "<<m<<endl;
	else
		cout<<b<<" "<<a<<" "<<m<<endl;
}
return 0;
}

