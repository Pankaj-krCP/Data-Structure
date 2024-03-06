//Kth Permutation Sequence of first n natural number
#include<bits/stdc++.h>
using namespace std;

void kthPermute(int k,int n,int fact[],vector<int> num,string& ans){
	if(n == 1){
		ans += to_string(num.back());
		return;
	}

	int idx = k/fact[n-1];
	if (k%fact[n-1] == 0) idx--;

	ans += to_string(num[idx]);
	num.erase(num.begin()+idx);
	k -= fact[n-1]*idx;
	kthPermute(k,n-1,fact,num,ans);
}

int main(){
	int n = 4;
	int k = 9;
	string ans="";
	int fact[] = {1,1,2,6,24,120,720,720*7,720*7*8,720*7*8*9};
	vector<int> num;
	for(int i=0;i<n;i++){
		num.push_back(i+1);
	}
	kthPermute(k,n,fact,num,ans);
	cout<<ans;
	return 0;
}