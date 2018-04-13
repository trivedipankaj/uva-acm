#include<iostream>
using namespace std;

#define N 8
int maxSum=0;
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

int sumBoard(int board[][N], int mat[][N]){
    int sum=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(board[i][j]){
                sum += mat[i][j];
            }
        }
    }
    return sum;
}

int nQueen(int mat[][N] ,int row){
    if(row == N){
        int sum= sumBoard(board, mat); 
        if(sum > maxSum) maxSum = sum;
    }else{
        for(int i=0; i<N; i++){
            if(isSafe(board, row, i)){
                board[row][i]=1;
                nQueen(mat, row+1);
                board[row][i]=0;
            }
        }
    }
    return maxSum;
}

int main(){
    int mat[N][N];
    int k;
    int total;
    cin>>k;
    while(k--){
    maxSum=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N;j++){
            cin>>mat[i][j];
        }
    }
    for(int i=0; i<N;i++){
        for(int j=0; j<N;j++){
            board[i][j]=0;
        }
    }
    
    total =nQueen(mat,0);
    printf("%5d\n", total);
    }
    return 0;
}
