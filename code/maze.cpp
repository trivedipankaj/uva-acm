#include<iostream>
using namespace std;

#define N 4
#define F(i,L,R) for (int i = L; i < R; i++) 

bool isSafe(int maze[N][N], int i, int j){
    if(i>=0 && i<N && j>=0 && j<N && maze[i][j]==1) return true;
    return false;
} 

bool solve(int maze[N][N], int i, int j, int solution[N][N]){
    if(i==N-1 && j==N-1) {
        solution[i][j]=1;
        return true;
    }
    if(isSafe(maze,i,j)){
        solution[i][j]=1;
    if(solve(maze,i+1,j,solution)) return true;
    if(solve(maze,i,j+1,solution)) return true;
        solution[i][j]=0;
    }
    return false;
}

void printSol(int sol[N][N]){
    F(i,0,N){
        F(j,0,N){
            cout<<sol[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int maze[N][N]  =  { {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };
    int sol[N][N];
    F(i,0,N) 
        F(j,0,N) 
        sol[i][j] =0;

    if(!solve(maze,0,0,sol)){
        cout<<"Solution does not exist!";
    }
    printSol(sol);
    return 0;
}
