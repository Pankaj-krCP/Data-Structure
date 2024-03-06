#include<bits/stdc++.h>
using namespace std;

int GCD(int a,int b){
	if (a == 0)
		return b;
	return GCD(b%a,a);
}

int LCM(int a,int b){
	return (a*b)/GCD(a,b);
}

int main(){
	int n1,n2;
	cin>>n1>>n2;
	cout<<(n1*n2)/(__gcd(n1,n2))<<endl;
	cout<<LCM(n1,n2);
	return 0;
}