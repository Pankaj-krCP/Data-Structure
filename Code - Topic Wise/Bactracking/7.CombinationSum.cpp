// //Input:
// 4
// 2 4 6 8
// 8
// //Output:
// 2 2 2 2 
// 2 2 4 
// 2 6 
// 4 4 
// 8 

#include <bits/stdc++.h>
using namespace std;
void CombinationSum(vector<int> arr,vector<vector<int>> &ans,vector<int> curr,int i,int sum,int n){
	if (sum == 0){
		ans.push_back(curr);
		return;
	}
	if (i>=n or sum<0)
		return;
	curr.push_back(arr[i]);
	CombinationSum(arr,ans,curr,i,sum-arr[i],n);
	curr.pop_back();
	CombinationSum(arr,ans,curr,i+1,sum,n);
	return;
}

int main(){
	int n;
	cin>>n;
	vector<int> arr = {2,4,6,8};
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		arr.push_back(num);
	}
	int sum;
	cin>>sum;
	vector<vector<int>> ans;
	vector<int> curr;
	CombinationSum(arr,ans,curr,0,sum,n);
	for (auto i:ans){
		for(auto j:i)
			cout<<j<<" ";
		cout<<"\n";
	}
	return 0;
}