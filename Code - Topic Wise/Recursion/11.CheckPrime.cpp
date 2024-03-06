#include<bits/stdc++.h>
using namespace std;

bool CheckPrime(int n,int i=2){
	if (i*i==n)
		return true;
	if (i%n == 0)
		return false;

	return CheckPrime(n,i+1);
}

int main(){
	int num;
	cin>>num;
	cout<<CheckPrime(num);
	return 0;
}