/* find th product of a array excluding that element without using /(division) operator and don't use more than 1 array */

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n; i++){
        cin>>arr[i];
    }

    int product[n];
    int lp = 1;
    for(int i=0; i<n ; i++){
        product[i]= lp;
        lp = lp * arr[i];
    }
    int rp = 1;
    for(int i=n-1;i>=0;i--){
        product[i] = product[i]* rp;
        rp = rp * arr[i];
    }
    for(int i=0 ; i<n; i++){
        cout<<product[i]<<" ";
    }

    return 0;
}