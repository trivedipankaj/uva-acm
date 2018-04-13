#include<iostream>
#include<queue>
using namespace std;
#define F(i,L,R) for(int i=L; i<R; i++)
#define SIZE 1000

void init(int a[][SIZE]){
 F(i,0,SIZE){
    F(j,0,SIZE){
        a[i][j]=0;
    }
 }
}

int bfs(int n, int a[][SIZE], int s, bool inicol){
    queue<int> q;
    bool visited[n];
    bool color[n];
    F(i,0,n) visited[i] =false;
    q.push(s);
    visited[s] = true;
    color[s] = inicol;
    while(!q.empty()){
        int p = q.front();
        q.pop();
        F(i,0,n){
            if(a[p][i]==1 && !visited[i]){
                q.push(i);
                visited[i] =true;
                if(color[p]) color[i] = false;
            }
        }
    }
    int black=0;
    F(i,0,n){
        if(!color[i]) black++;  
    }
    return black;
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
F(i,0,m){
    cin>>r>>c;
    a[r-1][c-1] =1;
    a[c-1][r-1] =1;
}
cout<<bfs(n,a,0,false);
}
}

