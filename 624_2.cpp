#include<iostream>
using namespace std;
#define SIZE 30
int a[SIZE];
bool used[SIZE];
int result[SIZE];
int n,k,diff,len;

void solve( int m, int pos){
    if(m <=n ){    
    if( n-m <= diff) {
            diff = n-m;
        len=0;
        for(int i=0; i<k; i++){
            if(used[i]){
                result[len++] = a[i];
            }
            }
        }
    }
    for(int i=pos; i<k; i++){
            if(!used[i]){
                used[i] =true;
                solve(m+a[i], i);
                used[i] = false;
            }
        }
}


int main(){
    while (scanf("%d %d", &n, &k) != EOF) {
        diff =INT8_MAX;
		for (int i = 0; i < k; i++) {
			scanf("%d", &a[i]);
		}
    for(int i=0; i<k; i++){
        used[i] = false;
    }
    solve(0,0);
    int sum=0;
    for(int i=0; i<len; i++){
        cout<<result[i]<<" ";
        sum += result[i];
    }
    cout<<"sum:"<<sum<<endl;
    }
}
