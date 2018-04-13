#include<iostream>
using namespace std;
int primes[] ={2,3,5,7,11,13,17,19,23,29,31};
#define PRIMES 11
#define F(i,L,R) for(int i=L; i<R;i++)
int nums[50];
int used[50];

bool isSafe(int n){
    F(i,0,PRIMES) if(primes[i] == n) return true;
    return false;
}

void solve(int k,int m){
    if(k==m-1 && isSafe(nums[0]+nums[k])){
        F(i,0,m){
             { cout << nums[i]; if (i != m-1) cout << ' '; }
        }
        cout<<endl;
        return;
    }else if(k+1<m){
        F(i,2,m+1){
            if(!used[i] && isSafe(i+nums[k])){
                used[i]=true;
                nums[k+1] =i;
                solve(k+1,m);
                used[i] =false;
            }
        }
    
    }
}

int main()
{
 int m;
 int tc=1;
 while(cin>>m){
    if (tc != 1) cout << endl;
    F(i,0,m) used[i]=false;
    cout << "Case " << tc++ << ':' << endl;
    nums[0] =1;
    solve(0,m);
 }
}
