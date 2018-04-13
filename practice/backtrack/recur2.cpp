#include<iostream>
#include <vector>
using namespace std;

void printV(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void backTrack(int num[], int n, vector<int> v, int pos){
        printV(v);
        //recursion must end here for one branch
        for(int i=pos; i< n; i++){
                v.push_back(num[i]);
                backTrack(num,n,v,i);
                //cout<<"Removing.."<<v[v.size()-1]<<endl;
                v.pop_back();
           
        }
    
}


int main(){
  int num[] = {1,2,3,4};
  vector<int> v;
  int n = sizeof(num)/sizeof(num[0]);
  backTrack(num,n,v,0);
    return 0;
}
