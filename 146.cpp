#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){
string line;
while(getline(cin,line) && line !="#"){
    if(next_permutation(line.begin(),line.end())){
        cout<<line<<endl;        
    }else{
        cout<<"No Successor"<<endl;
    }
}

}
