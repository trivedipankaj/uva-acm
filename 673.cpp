#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(){
    int n;
    cin>>n;
    getchar();
    while(n--){
        string line;
        getline(cin,line);
        stack<char> s;
        int i=0;
        bool flag=true;
        int t=0;
        for( i=0; i<line.length(); i++){
            if(line[i] =='(' || line[i] == '['){
                t++;
                s.push(line[i]);
            }else  if(line[i] ==')' || line[i] == ']'){
                if(s.empty()){ flag =false;
                    break;
                }
                if((line[i] ==')' && s.top() =='(') || (line[i] ==']' && s.top() =='[')){
                    s.pop();    
                }else{
                    flag=false;
                }
            }
            
        }
        if(s.empty() && flag){
            cout<<"Yes"<<endl;
        }else  cout<<"No"<<endl;
    }

}
