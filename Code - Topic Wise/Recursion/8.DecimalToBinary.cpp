#include<iostream>
using namespace std;

int DecimalToBinary(int n){

	 if (n == 1)
	 	return 1;

	return DecimalToBinary(n/2)*10 + n%2;
}

int main(){
	int n;
	cin>>n;
	cout<<DecimalToBinary(n);
	return 0;
}