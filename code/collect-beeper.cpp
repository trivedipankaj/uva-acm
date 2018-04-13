#include<iostream>
#include<cmath>
using namespace std;
#define F(i,L,R) for(int i=L; i<R; i++)
#define SIZE 50
int sx[SIZE];
int sy[SIZE];
bool visited[SIZE];
int startx, starty;
int m=INT8_MAX;

void init(int a[][SIZE]){
    F(i,0,SIZE)
        F(j,0,SIZE) a[i][j]=0;
}

void dfs(int x, int y, int n, int p, int dist){
    if(p==n){
        int d = abs(x-startx) + abs(y-starty);
        m = min(dist+d, m);
        return;
    }
    F(i,0,n){
        if(!visited[i]){
            visited[i]=true;
            int d = abs(x-sx[i]) + abs(y-sy[i]);
            dfs(sx[i],sy[i],n,p+1, dist+d);
            visited[i]=false;
        }
    }
}


int main(){
int k,l,n,x,y,p,r,c;
int a[SIZE][SIZE];
cin>>k;
while(k--){
cin>>l>>n>>startx>>starty>>p;
m=INT8_MAX;
init(a);
F(i,0,p){
    cin>>r>>c;
    sx[i] = r;
    sy[i] = c;
    visited[i]=false;
}
dfs(startx, starty, p,0,0);
cout << "The shortest path has length " << m << endl;
}
}
