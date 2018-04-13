#include<iostream>
using namespace std;
#define SIZE 8

void printSol();
int visited[SIZE][SIZE];
int movesx[] ={2,2,1,1,-1,-1,-2,-2};
int movesy[]={-1,1,-2,2,2,-2,1,-1};

bool isSafe(int i, int j){
    return ( i>=0 && i<SIZE && j>=0 && j<SIZE 
           && visited[i][j]==-1); 
}


bool solve(int i, int j, int move){
    int x, y;
    if(move == 64){
        printSol();
        return true;
    }
    for(int k=0; k<8; k++){
        x = i+movesx[k];
        y = j+movesy[k];
        if(isSafe(x,y)){
            visited[x][y] = move;
            if(solve(x, y, move+1)) return true;
            visited[x][y] =-1;
        }
    }
    return false;
}
void printSol(){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            cout<<visited[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            visited[i][j] =-1;
        }
    }
    visited[0][0]=0;
    solve(0,0,1);
    printSol();
}
