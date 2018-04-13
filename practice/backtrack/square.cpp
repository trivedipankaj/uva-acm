#include<iostream>
using namespace std;

#define N 5
#define M 5
int path[100];
int pathlen=0;

void printPath(int len){
    for(int i=0;i<len;i++){
       cout<<path[i]<<" "; 
    } 
    cout<<endl;
}
void traverse(int a[][N], int i, int j, int len){
    path[len++] = a[i][j];
    if(i==M-1 && j==N-1){
        printPath(len);
    }else{
        if(i+1<M )   traverse(a,i+1,j, len);
        if(j+1<N)    traverse(a,i,j+1,len);
        if(i+1<M && j+1<N) traverse(a, i+1,j+1,len);
    } 
}

int main(){
    int a[][N] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
    traverse(a,0,0,0);
    return 0;
}
