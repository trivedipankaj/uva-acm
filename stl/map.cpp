#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
    map<string,int> map1;
    map1["first"] =1;
    map1.insert(make_pair("second",2));
    cout<<map1.size()<<endl;
}
