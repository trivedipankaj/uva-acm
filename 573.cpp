#include<iostream>
using namespace std;

int main(){
	int h,u,d,f;
	while(cin>>h>>u>>d>>f && h!=0){
		int day=0;
		float curr=0;
		float diff= u*f*0.01;
		float climb=u+diff;
		while( 1){
			day++;
			climb -= diff;
			curr += climb>0 ? climb: 0;
			if( curr > h){
				cout<<"success on day "<<day<<endl;
				break;
			}
			curr -= d;
			if( curr < 0){
				cout<<"failure on day "<<day<<endl;
				break;
			}
		} 	
	}

}
