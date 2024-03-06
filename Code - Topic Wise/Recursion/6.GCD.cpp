#include<bits/stdc++.h>
using namespace std;

int GCD(int a,int b){
	if (a == 0)
		return b;
	return GCD(b%a,a);
}

int main(){
	int n1,n2;
	cin>>n1>>n2;
	cout<<__gcd(n1,n2)<<endl;
	cout<<GCD(n1,n2);
	return 0;
}