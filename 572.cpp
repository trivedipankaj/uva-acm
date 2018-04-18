#include<iostream>
using namespace std;
#define SIZE 101
//move in all 8 directions
int di[]={-1,0,1,0,-1,1,-1,1};
int dj[]={0,-1,0,1,-1,1,1,-1};
char mat[SIZE][SIZE];
int r,c;

void floodfill(int i, int j, char ch){
    if(i < 0 || i >= r ) return;
    if( j< 0 || j >=c ) return;
    if( mat[i][j] != ch) return;
    mat[i][j] = '*';
    for(int k=0; k<8; k++){
        floodfill(i+di[k], j+dj[k],ch);
    }
}


int main(){
  while(scanf("%d %d",&r, &c) && r!=0 ){
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                cin>>mat[i][j];
            }
        }
        int ans=0;
        for(int i=0; i<r;i++){
            for(int j=0; j<c; j++){
                if(mat[i][j] == '@'){
                    ans++;
                    floodfill(i,j,'@');
                }
            }
        }
        printf("%d\n",ans);
  }
}
