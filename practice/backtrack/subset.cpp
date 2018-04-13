#include<iostream>
#include <vector>
#include<algorithm>

using namespace std;

bool flag;
void printV(vector<int> v){
    for(int i=0; i<v.size()-1; i++){
        cout<<v[i]<<"+";
    }
    cout<<v[v.size()-1]<<endl;
}

void backTrack(int num[], int n, vector<int> v, int target, int pos){
    int sum =0;
    for(int i=0; i< v.size();i++) sum = sum+v[i];
    if(sum == target){
        printV(v);
        flag=true;
        return;
    }
    if( sum < target){
        for(int i=pos; i< n; i++){
            if(pos !=i && num[i] == num[i-1]) continue;
            v.push_back(num[i]);
            backTrack(num,n,v, target, i+1);
            v.pop_back();
        }
    }
}


int main(){
    
  int target,n;
  while(cin>>target>>n && n!=0){
  int num[n];
  for(int i=0; i<n;i++) cin>>num[i];
  vector<int> v;
  flag = false;
  cout<<"Sums of "<<target<<":"<<endl;
  backTrack(num,n,v, target,0);
  
  if(!flag){
    cout<<"NONE"<<endl;
  }
  }
  return 0;
}
