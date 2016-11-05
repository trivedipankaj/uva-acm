#include<iostream>
using namespace std;

int main(){
    int n,m,c;
    int cnt=0;
    while(cin>>n>>m>>c && n!=0){  
        cnt++;
        int cap[n];
        bool status[n];
        int actions[m];
        for(int i=0; i<n;i++){
            cin>>cap[i];
            status[i] =false;
        }
        for(int i=0; i<m;i++){
            cin>>actions[i];
        }
        int curr=0;
        int j=0;
        int maximum=-1;
        while(curr <= c && j<m){
            int index = actions[j]-1;
            curr += !status[index] ? cap[index] : -1*cap[index];
            status[index] = !status[index];
            j++;
            if(curr > maximum) maximum = curr;
        }
        cout<<"Sequence "<<cnt<<endl;
        if(curr > c){
            cout<<"Fuse was blown."<<endl;
        }else{
            cout<<"Fuse was not blown."<<endl;
            cout<<"Maximal power consumption was "<<maximum<<" amperes."<<endl;
        }
        cout<<endl;
    }
}



