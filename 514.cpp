#include<iostream>
#include<stack>
using namespace std;

int main(){
    int n,m;
    int target[1000];
    while(true){
        cin>>n;
        if(n==0) break;
        while(true){
            cin>>target[0];
            if(target[0]==0) break;
            for(int i=1; i<n; i++){
                cin>>target[i];
            }
            int j=0;
            stack<int> station;
            for(int i=1; i<=n; i++){
                station.push(i);
                while(!station.empty() && station.top() == target[j]){
                    station.pop();
                    j++;
                    if(j>=n) break;
                }
            }
           if(station.empty()) 
               cout<<"Yes"<<endl;
           else
               cout<<"No"<<endl;
        }
        cout<<endl;
    }
}



