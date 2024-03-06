#include<bits/stdc++.h>
using namespace std;

int DigitSum(int n){
	if (n == 0)
		return 0;
	return n%10+DigitSum(n/10);
}

int main(){
	int num;
	cin>>num;
	cout<<DigitSum(num);
	return 0;
}