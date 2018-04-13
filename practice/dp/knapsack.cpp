#include<iostream>
using namespace std;

int knapsack(int W, int w[], int v[], int n){
    //if there are no weights or no knapsack, the value is zero
    if( n == 0 || W==0 ) return 0;
    // if the weight to be filled is greater than the knapsack itself, we can not take this item
    if( w[n-1] - W > 0) {
        return knapsack(W,w,v,n-1);
    } 
    //decision space is wether to take nth item or not.
    return max( v[n-1] + knapsack(W-w[n-1],w,v,n-1), knapsack(W,w,v,n-1));
}

int uknapsack(int W, int w[], int v[], int n){
   if( W<=0) return 0;
   int max=INT_MIN;
   //decision space is checking all the items available and take the one which results into maximum value 
   //at this stage
   for(int i=0; i<n; i++){
        if(W - w[i] >= 0){
            int val = v[i] + uknapsack(W-w[i],w,v,n);
            if(max < val) max = val;
        } 
   }
   return max;
}

int coinChange(int A, int d[], int n){
    if(A<=0) return 0;
    int min= INT_MAX;
    for(int i=0; i<n; i++){
        if(A-d[i]>=0){
            int val = 1+ coinChange(A-d[i],d,n);
            if(min > val) min = val;
        }
    }
    return min;
}

int partition(int sum1, int sum2, int a[], int n){
    if(n==0) return abs(sum2-sum1);
    return min( partition(sum1+a[n-1],sum2,a,n-1) , partition(sum1, sum2+a[n-1],a,n-1));
}


int main(){
    /*int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 50;
    int n = sizeof(val)/sizeof(val[0]);*/
    int W = 50;
    int val[] = {100, 30, 20};
    int wt[] = {5, 10, 15};
    int n = sizeof(val)/sizeof(val[0]);
    //cout<<uknapsack(W,wt,val,n);

    int a[] ={5,3};
    int m = sizeof(a)/sizeof(a[0]);
    cout<<partition(0,0,a,m);
    return 0;
}
