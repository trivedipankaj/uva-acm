#include<iostream>
using namespace std;
#define F(i,L,R) for (int i = L; i < R; i++)

#define N 8

bool isSafe( int board[][N], int row, int col){
    for(int i=0; i<row; i++){
        if(board[i][col]) return false;
    }
    for(int i=row, j=col; i>=0 &&  j<N;i--, j++){
        if(board[i][j]) return false;
    }
    for(int i=row, j=col; i>=0 && j>=0; i--,j--){
        if(board[i][j]) return false;
    }
    return true;
}

void printBoard(int board[][N]){
    F(i,0,N){
        F(j,0,N){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool nQueen(int board[][N], int row){
    if(row == N){
       printBoard(board);
    }else{
        for(int i=0; i<N; i++){
            if(isSafe(board, row, i)){
                board[row][i]=1;
                if(nQueen(board,row+1)) return true;
                board[row][i]=0;
            }
        }
    }
    return false;
}

int main(){
    int board[N][N];
    memset(board,0, sizeof(board));
    nQueen(board,0);
    return 0;
}
