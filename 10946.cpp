#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
#define SIZE 100
#define INIT(a,n) for(int i=0; i<n; i++) { a[i] =0; }
char mat[SIZE][SIZE];
int r,c;
int di[] ={-1,0,1,0};
int dj[] ={0,-1,0,1};
int total=0;

struct node{
    char c;
    int freq;
}p[2600];

bool cmp(node a, node b){
    if(a.freq > b.freq) return true;
    if(a.freq == b.freq && a.c < b.c) return true;
    return false;
}

void floodfill(int i, int j, char ch){
     if( i<0 || i>r-1) return;
     if( j<0 || j>c-1) return;
     if(  mat[i][j] != ch) return;
     mat[i][j] ='*';
     total++;
     for(int k=0; k<4; k++){
        floodfill(i+di[k], j+dj[k],ch);
     }
}

int main(){
 int t,tc=0;
 int cnt[26];
    while(cin>>r>>c && r!=0 && c!=0){
    tc++;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>mat[i][j];
        }
    }
    INIT(cnt,26);
    int len=0;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
                if(isalpha(mat[i][j])){
                    total=0;
                    char curr = mat[i][j];
                    floodfill(i,j,mat[i][j]);
                    p[len].c = curr;
                    p[len++].freq = total;
                }
        }
    }
    sort(p,p+len,cmp); 
    printf ("Problem %d:\n", tc);
    for ( int i = 0; i < len; i++ )
        printf ("%c %d\n", p [i].c, p [i].freq);
    }
}
