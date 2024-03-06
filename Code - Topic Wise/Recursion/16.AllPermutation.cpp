//print all permutation of a given string
#include<bits/stdc++.h>
using namespace std;

void permutation(int arr[],vector<int> temp,int freq[],int n){
	if(temp.size() == n){
		for(auto i:temp) cout<<i<<" ";
		cout<<endl;
	return;
	}
	for(int i=0;i<n;i++){
		if(!freq[i]){
			temp.push_back(arr[i]);
			freq[i] = 1;
			permutation(arr,temp,freq,n);
			freq[i] = 0;
			temp.pop_back();
		}
	}
}

int main(){
	int nums[] = {1,2,3};
	int n = 3;
	vector<int> temp;
	int freq[n] = {0};
	permutation(nums,temp,freq,n);
	return 0;
}