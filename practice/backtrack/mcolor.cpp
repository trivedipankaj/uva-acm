#include<iostream>
using namespace std;

#define N 4
bool isSafe( int G[N][N], int color[], int v, int c){
    for(int i=0; i<N; i++){
        if(G[v][i] && color[i] ==c) return false;
    }
    return true;
}

bool solve(int G[N][N], int color[], int m, int v){
    if(v ==N){
        return true;
    }
    for(int i=1; i<=m; i++){
        if(isSafe(G,color,v,i)){
            color[v] = i;
            if(solve(G,color,m,v+1)) return true;
            color[v] = 0;
        }
    }
    return false;
}

void printSol(int color[]){
    for(int i=0; i<N;i++){
        cout<<color[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int graph[N][N] = {{0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };
    int m = 3; // Number of colors
    int color[N];
    for(int i=0; i<N;i++) color[i] =0;
   if(!solve(graph,color, m, 0)){
    cout<<"No solution";
    }
    printSol(color);
    return 0;
}
