#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	string t;
	while(getline(cin,t)){
		istringstream ss(t);
		string word;
		bool f=false;
		while( ss >> word){
			if(f) cout<<" ";
			f=true;
			for(int i=word.length()-1; i>=0; i--){
				cout<<word[i];
			}
		}
		cout<<endl;
	}

}
