#include<iostream>
#include<queue>

using namespace std;
int main(){
    priority_queue<int> p;
    p.push(14);
    p.push(30);
    p.push(10);
    p.push(40);
    p.push(15);

    cout<<p.top()<<endl;
    p.pop();
    cout<<p.top()<<endl;
}
