#include<iostream>
#include<queue>

using namespace std;
#define SIZE 205
int a[SIZE][SIZE];
int t,e,v,p,q;
int color[SIZE];

int bfs(int s){
    color[s] =1;
    int zero=0;
    int one=1;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0; i<v; i++){
            if(a[u][i] ==1 && color[i] ==-1){
                color[i] = 1-color[u];
                if(color[i] == 1) one++;
                else if(color[i] ==0) zero++;
                q.push(i);
            }else if(a[u][i]==1 && color[u] == color[i]){
                return -1;
            }
        }
    }
    if(zero ==0) return one;
    return min(zero, one);
}

int main(){
cin>>t;
while(t--){
    cin>>v>>e;
    for(int i=0; i<v;i++){
        for(int j=0; j<v;j++){
            a[i][j]=0;
        }
    }
    for(int i=0; i<e;i++){
        cin>>p>>q;
        a[p][q] =1;
        a[q][p] =1;
    }
    for(int i=0; i<v;i++) color[i] =-1;
    int ans=0;
    for(int i=0; i<v;i++){
        if(color[i] == -1){
        int temp = bfs(i);
        if(temp ==-1){
                ans=-1;
                break;
        }else{
            ans += temp;
        }
    }
    }
    cout<<ans<<endl;
}
 return 0;
}
