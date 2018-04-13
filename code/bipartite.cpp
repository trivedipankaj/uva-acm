#include<iostream>
#include<queue>
using namespace std;
#define SIZE 4

bool isBipartite(int G[][SIZE], int src, int color[])
{
    for(int i=0; i<SIZE; i++) color[i] = -1;
    color[src] =1;
    queue<int> q;
    q.push(src);
    
    while(!q.empty()){
       int u = q.front();
       q.pop();
       if(G[u][u] ==1) return false;

       for(int i=0; i<SIZE;i++){
            if(G[u][i] ==1 && color[i] == -1){
                color[i] = 1-color[u];
                q.push(i);
            }else if(G[u][i]==1 && color[u] ==color[i]) return false;
       }
    }
    return true;
}

bool isBiGraph(int G[][SIZE])
{
    int color[SIZE];
    for (int i = 0; i < SIZE; ++i)
        color[i] = -1;
 
    // This code is to handle disconnected graoh
    for (int i = 0; i < SIZE; i++)
      if (color[i] == -1)
        if (isBipartite(G, i, color) == false)
           return false;
 
     return true;
}


int main(){
    int G[][SIZE] = {{0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };
   isBiGraph(G) ? cout << "Yes" : cout << "No";
}
