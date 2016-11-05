#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

int main(){
   vector<int> v;
   for(int i=0; i<10;i++){
        v.push_back(i);
   }
   vector<int>::iterator it;
   for(it = v.begin(); it != v.end() ; it++){
        cout<<*it<<" ";
   }

   map<int,int> m;
   m.insert(make_pair(1,10));
   m.insert(make_pair(2,20));
   m.insert(make_pair(3,30));
   
   cout<<endl;
   
   map<int,int>::iterator mit;
   for(mit=m.begin(); mit != m.end(); mit++){
        cout<<mit->first<<"==>"<<mit->second<<endl;
   }
    
}
