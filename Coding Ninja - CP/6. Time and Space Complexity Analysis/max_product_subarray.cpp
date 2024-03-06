#include<bits/stdc++.h>
using namespace std;

int max_Product(int arr[],int n){
    int max_ending_here = 1;
    int min_ending_here = 1;
    int max_so_far = 0;

    for(int i=0;i<n; i++){
        if(arr[i]>0){
            max_ending_here = max_ending_here * arr[i];
            min_ending_here = 1;
            max_so_far = max(max_ending_here,max_so_far);
        }
        else if(arr[i]==0){
            max_ending_here = 1;
            min_ending_here = 1;
        }
        else{
            min_ending_here = min_ending_here * arr[i];
            max_ending_here = 1 ;
            max_so_far = max(min_ending_here,max_so_far);
        }
    }
    return max_so_far;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<max_Product(arr,n);
    return  0;
}