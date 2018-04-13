#include<iostream>
using namespace std;
#define SIZE 1000001
typedef long long lint;

bool a[SIZE];


void sieve(){
    for(lint i=0; i<SIZE; i++) a[i] = true;
    a[1] =true;
    a[0] =false;
    for(lint i=2; i<SIZE; i++){
        if(a[i]){
            for(lint j=2*i ; j<SIZE; j=j+i){
                a[j] = false;
            }
        }
    }
}

int main(){
    sieve();
    int n,c;
    while(cin>>n>>c){
        int start,end,total=0,t;
        cout<<n<<" "<<c<<":";
        for(lint i=0; i<=n;i++) { if(a[i]) total++;}
        if(total % 2 ==0) {
            c *=2;
        }else{
            c = c*2 -1 ; 
        }
        if(c>=total){
           start =0; 
           end = total;
        }else{
           start = (total-c)/2;
           end  = (total-c)/2+c;
        }
        int j=1,cnt=0;
        for(int i=0; i<=n && start < end; i++){
            if(a[i]){
                if(cnt == start){
                    cout<<" "<<i;
                    start++;
                }
                cnt++;
            }
        }
        cout<<endl<<endl;
    }
}
