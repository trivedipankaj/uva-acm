#include<iostream>
#include<string>
using namespace std;
#define SIZE 1000
#define INIT(a,n) for(int i=0; i<n; i++) { a[i] =0; }
char mat[SIZE][SIZE];
int r,c;
int di[] ={-1,0,1,0};
int dj[] ={0,-1,0,1};

void floodfill(int i, int j, char ch){
     if( i<0 || i>r-1) return;
     if( j<0 || j>c-1) return;
     if(  mat[i][j] != ch) return;
     mat[i][j] ='*';
     for(int k=0; k<4; k++){
        floodfill(i+di[k], j+dj[k],ch);
     }
}

int main(){
 int t,tc;
 int cnt[26];
cin>>t;
 for(tc=1; tc<=t; tc++){
    cin>>r>>c;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>mat[i][j];
        }
    }
    INIT(cnt,26);
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
                if(mat[i][j] !='*'){
                    cnt[mat[i][j]-'a']++;
                    floodfill(i,j,mat[i][j]);
                }
        }
    }
    cout << "World #" << tc << endl;
    for(int i=0; i<26; i++){
			int ind = 0;
			for(int j=0; j<26; j++){
				if( cnt[ind] < cnt[j] ){
					ind = j;
				}
			}
			if( cnt[ind] > 0 ){
				cout << (char)('a' + ind) << ": " << cnt[ind] << endl;
				cnt[ind] = 0;
			}
		}
 }

}
