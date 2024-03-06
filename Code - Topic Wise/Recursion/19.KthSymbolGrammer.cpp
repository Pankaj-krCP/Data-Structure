//Kth Symbol in Grammer
// 0
// 0 1
// 0 1 1 0
// 0 1 1 0 1 0 0 1
// 0 1 1 0 1 0 0 1 1 0 0 1 0 1 1 0
//                      /|\
// input n = 5,k = 12
// output 1
#include<bits/stdc++.h>
using namespace std;

int kthSymbol(int n, int k){
	if(n == 1)
		return 0;
	if (k>pow(2,n-2))
		return kthSymbol(n-1,k - int(pow(2,n-2))) == 0 ? 1 : 0;
	else
		return kthSymbol(n-1,k);
}

int main(){
	int n = 5,k = 12;
	cout<<kthSymbol(n,k);
	return 0;
}
