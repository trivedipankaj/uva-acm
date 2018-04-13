#include<iostream>
using namespace std;
int a[100][100];
char b[100][100];

//move in all 8 directions
int di[]={-1,0,1,0,-1,1,-1,1};
int dj[]={0,-1,0,1,-1,1,1,-1};

int main(){
int m,n;
int tc=0;
while(cin>>m>>n && m!=0){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>b[i][j];
            a[i][j] =0;
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(b[i][j] == '*'){
                for(int k=0; k<8; k++){
                    if(i+di[k]>=0 && i+di[k]<m &&  j+dj[k]>=0 && j+dj[k]<n && b[i+di[k]][j+dj[k]] !='*'){
                         a[i+di[k]][j+dj[k]]++;
                    }
                }
            }
        }
    }
    if(tc !=0) cout<<endl;
    cout<<"Field #"<<++tc<<":"<<endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(b[i][j] =='*') cout<<"*";
            else cout<<a[i][j];
        }
        cout<<endl;
    }
}

}
