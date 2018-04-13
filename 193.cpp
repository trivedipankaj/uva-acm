#include<iostream>
#include<queue>
using namespace std;
#define F(i,L,R) for(int i=L; i<R; i++)
#define SIZE 1000
int max1=0;
bool color[SIZE];
int ans[SIZE];
int temp[SIZE];

void init(int a[][SIZE]){
 F(i,0,SIZE){
    F(j,0,SIZE){
        a[i][j]=0;
    }
 }
}

bool isSafe(int a[][SIZE],bool color[],int n, int v){
   F(i,0,n){
     if(a[v][i]==1 && !color[i]) return false;
   } 
   return true;
}

void dfs(int a[][SIZE], int n,bool visited[], int s){
        if(s == n){
            int black=0;
            F(i,0,n) if(!color[i]) {
                temp[black] = i+1;
                black++;
            }
            if(max1 < black) {
                max1 =black;
                F(i,0,max1) ans[i]=temp[i];
            }
            return;
        }
        if(isSafe(a,color,n,s)){
                    color[s] = false;
                    dfs(a,n,visited,s+1);
                    color[s] =true;
                }
                dfs(a,n,visited,s+1);
            
}

int main(){
int k;
int n,m;
int a[SIZE][SIZE];
cin>>k;
while(k--){
cin>>n>>m;
int r,c;
init(a);
max1=0;
F(i,0,m){
    cin>>r>>c;
    a[r-1][c-1] =1;
    a[c-1][r-1] =1;
}
bool visited[n];
F(i,0,n) visited[i] = false;
F(i,0,n) color[i] = true;
dfs(a,n,visited,0);
cout<<max1<<endl;
F(i,0,max1-1) cout<<ans[i]<<" ";
cout<<ans[max1-1]<<endl;
}
}

