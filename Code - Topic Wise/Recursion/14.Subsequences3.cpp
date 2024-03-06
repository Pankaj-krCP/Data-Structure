//print any subsequence whose sum is sum
#include<bits/stdc++.h>
using namespace std;

bool Subsequences(int idx,int s,int arr[],vector<int> temp,int sum,int n){
	if (s>sum) return false;
	if (idx == n){
		if (s==sum){
			for(auto i:temp) cout<<i<<" ";
			cout<<endl;
			return true;
		}
		return false;
	}

	temp.push_back(arr[idx]);
	s += arr[idx];
	if (Subsequences(idx+1,s,arr,temp,sum,n)) return true;
	temp.pop_back();
	s -= arr[idx];
	if (Subsequences(idx+1,s,arr,temp,sum,n)) return true;
	return false;
}

int main(){
	int arr[] = {1,2,1};
	int n = 3;
	int sum = 2;
	vector<int> temp;
	Subsequences(0,0,arr,temp,sum,n);
	return 0;
}