#include<iostream>
using namespace std;
//11085
//Number of minimum moves for NQueen problem
#define N 8
int minMoves=1000;
int board[N][N];

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
    for(int i=0; i<N; i++){
        for(int j=0; j<N;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

int numMoves(int board[][N], int mat[][N]){
    int moves=0;
    int x,y;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(board[j][i]==1){
                x =j;
            }
            if(mat[j][i]==1){
                y=j;
            }
        }
        moves += (x-y) == 0 ? 0 :1;
    }
    return moves;
}

int nQueen(int mat[][N] ,int row){
    if(row == N){
        int m= numMoves(board, mat);
        if(m <minMoves) minMoves = m;
    }else{
        for(int i=0; i<N; i++){
            if(isSafe(board, row, i)){
                board[row][i]=1;
                nQueen(mat, row+1);
                board[row][i]=0;
            }
        }
    }
    return minMoves;
}

int main(){
    int mat[N][N];
    int k=0;
    int total;
    int row[8];
    while (scanf("%d", &row[0]) != EOF) {
     for (int i = 1; i < 8; ++i)
            scanf("%d", &row[i]);
        minMoves=100;
    k++;
    for(int i=0; i<N; i++){
        for(int j=0; j<N;j++){
            mat[i][j]=0;
        }
    }
    for(int i=0; i<N; i++){
            mat[row[i]-1][i]=1;
    }

    for(int i=0; i<N;i++){
        for(int j=0; j<N;j++){
            board[i][j]=0;
        }
    }
    
    total =nQueen(mat,0);
    printf("Case %d: %d\n", k, total);
    }
    return 0;
}
