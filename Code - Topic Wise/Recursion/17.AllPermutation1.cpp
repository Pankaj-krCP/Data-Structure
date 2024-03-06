//print all permutation of a given string
#include<bits/stdc++.h>
using namespace std;

void permutation(int idx,int arr[],int n){
	if(idx == n-1){
		for(int i=0;i<n;i++) cout<<arr[i]<<" ";
		cout<<endl;
		return;
	}
	for(int i=idx;i<n;i++){
		swap(arr[idx],arr[i]);
		permutation(idx+1,arr,n);
		swap(arr[idx],arr[i]);
	}
}

int main(){
	int nums[] = {1,2,3};
	int n = 3;
	permutation(0,nums,n);
	return 0;
}