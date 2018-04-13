#include<iostream>
using namespace std;
#define SIZE 30
int a[SIZE];
bool used[SIZE];
bool result[SIZE];
int n,k,total,len;

void solve(int l){
    if(l==k ){
        int csum=0;
        for(int i=0; i<k; i++){
            if(used[i]){
                csum += a[i];
            }
        }
        if(csum >total && csum<=n){
            total = csum;
            for(int i=0; i<k; i++) result[i] = used[i];
        }
       return;
    }
        used[l] =true;
        solve( l+1);
        used[l] = false;
        solve(l+1);
}


int main(){
    while (scanf("%d %d", &n, &k) != EOF) {
        total =0;
		for (int i = 0; i < k; i++) {
			scanf("%d", &a[i]);
		}
    for(int i=0; i<k; i++){
        used[i] = false;
    }
    solve(0);
    for (int i = 0; i < k; i++) if (result[i]) cout << a[i] << ' ';
    cout << "sum:" << total << endl;
    }
    return 0;
}
