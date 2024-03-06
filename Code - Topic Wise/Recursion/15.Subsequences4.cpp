//Count the number of subsequences whose sum is sum
#include<bits/stdc++.h>
using namespace std;

int Subsequences(int idx,int s,int arr[],vector<int> temp,int sum,int n){
	if (s > sum) return 0;
	if (idx == n){
		if (sum == s) return 1;
		return 0;
	}

	temp.push_back(arr[idx]);
	s += arr[idx];
	int l = Subsequences(idx+1,s,arr,temp,sum,n);
	temp.pop_back();
	s -= arr[idx];
	int r = Subsequences(idx+1,s,arr,temp,sum,n);
	return l+r;
}

int main(){
	int arr[] = {1,2,1,2,1};
	int n = 5;
	int sum = 3;
	vector<int> temp;
	cout<<Subsequences(0,0,arr,temp,sum,n);
	return 0;
}