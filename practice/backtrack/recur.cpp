#include<iostream>
#include <vector>
using namespace std;

void printV(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void backTrack(int num[], int n, vector<int> v){
    if (n== v.size()){
       cout<<"Printing.."<<endl;
        printV(v);
        return;
        //recursion must end here for one branch
    }else{
        for(int i=0; i< n; i++){
            bool flag = false;
           for(int j=0; j< v.size(); j++) {
                if(num[i]==v[j]){
                    flag =true;
                } 
           }
           if(flag) continue;
                v.push_back(num[i]);
                printV(v);
                backTrack(num,n,v);
                cout<<"Removing.."<<v[v.size()-1]<<endl;
                v.pop_back();
           
        }
    
    }
}


int main(){
  int num[] = {1,2,3,4};
  vector<int> v;
  int n = sizeof(num)/sizeof(num[0]);
  backTrack(num,n,v);
    return 0;
}
