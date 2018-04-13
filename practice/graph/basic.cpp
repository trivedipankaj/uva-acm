#include<iostream>
using namespace std;
bool visited[100];
int SIZE = 6;

int G[][6] = { {0,1,1,0,0,0}, 
      {0,0,0,1,1,0 },
      {0,0,0,1,0,1},
      {0,0,0,0,0,1},
      {0,0,0,0,0,0}
    };

void initNodes(){
    for(int i=0; i<100; i++) visited[i] = false;
}

void DFS(int node){
   cout<<node+1<<" ";
   visited[node] = true;
   for(int i=0; i<SIZE; i++){
    if(G[node][i] ==1 && !visited[i] ){
        DFS(i);
    }
   }
} 


int main(){
  DFS(0);
}
