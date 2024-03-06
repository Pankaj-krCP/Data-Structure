//print all sunsequences whose sum is sum
#include<bits/stdc++.h>
using namespace std;

void Subsequences(int idx,int arr[],vector<int>temp,int sum,int n){
	if(idx == n){
		if (sum == 0){
			for(auto i:temp) cout<<i<<" ";
			cout<<endl;
		}
		return;
	}
	temp.push_back(arr[idx]);
	Subsequences(idx+1,arr,temp,sum-arr[idx],n);
	temp.pop_back();
	Subsequences(idx+1,arr,temp,sum,n);
}

int main(){
	int arr[] = {1,2,3};
	int n = 3;
	int sum = 3;
	vector<int> temp;
	Subsequences(0,arr,temp,sum,n);
	return 0;
}