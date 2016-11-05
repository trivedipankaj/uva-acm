#include<iostream>
#include<string>
using namespace std;

int main(){
 string line;
 int cnt=0;
 while(getline(cin,line)){
 	for(int i=0; i<line.length();i++){
		if(line[i] == '"'){
			cout<<((++cnt%2 ==1) ? "``" : "''");
		}else{
			cout<<line[i];
		}

	}
	cout<<endl;
 }

return 0;
}
