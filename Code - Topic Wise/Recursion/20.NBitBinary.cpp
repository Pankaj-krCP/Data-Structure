//N-Bit Binary Number Having More 1's than 0's for any prefix
#include<bits/stdc++.h>
using namespace std;

void NBitBinary(int n,int ones=0,int zeros=0,string ans= ""){
	if (ans.size() == n){
		cout<<ans<<endl;
		return;
	}
	NBitBinary(n,ones+1,zeros,ans+"1");
	if (ones > zeros)
		NBitBinary(n,ones,zeros+1,ans+"0");
}

int main(){
	int n = 4;
	NBitBinary(n);
	return 0;
}