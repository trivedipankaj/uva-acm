#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>


using namespace std;
int main(){
int n;
cin>>n;
int number;
getchar();
while(n--){
    vector<int> v;
    vector<string> arr;
    vector<pair<int,string> > p;
    string line,t;
    int cnt=0;
    getchar();
    getline(cin,line);
    istringstream iss(line);
    int number;
    while( iss >> number){
        cnt++;
        v.push_back(number);
    } 
    getline(cin,line);
    istringstream iss1(line);
    while(iss1 >> t){
        arr.push_back(t);
    }
    int size = min(arr.size(),v.size());
    
    for(int i=0; i<size;i++){ 
         p.push_back(make_pair(v[i],arr[i]));
    }
    sort(p.begin(),p.end());
    
    for(int i=0; i<size;i++){
        cout<<p[i].second<<endl;
    }
    if(n)
        cout<<endl;
    
}

}
