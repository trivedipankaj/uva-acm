#include<iostream>
using namespace std;
double a[1001];

int main(){
    int n;
    double s;
    while(cin>>n && n!=0){
        s =0;
        for(int i=0; i<n; i++){
            cin>>a[i]; 
            s += a[i];
        }
        s /= n;
        double pos=0, neg=0;
        for(int i=0; i<n; i++){
            double v = (long) ((a[i] - s)*100.0);
            if(v >0) pos += v;
            else neg += v;
        }
        neg = -neg;
         printf("$%.2f\n", neg > pos? neg/100.0 : pos/100.0);
    }
}
