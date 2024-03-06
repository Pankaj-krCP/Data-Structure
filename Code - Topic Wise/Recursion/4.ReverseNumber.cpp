#include<iostream>
using namespace std;

int reverse(int n,int ans = 0){
	if (n==0)
		return ans;
	
	ans = ans*10 + n%10;
	return reverse(n/10,ans);
}

int main(){
	int num;
	cin>>num;
	cout<<reverse(num);
	return 0;
}