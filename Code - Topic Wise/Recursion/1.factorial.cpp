#include<iostream>
using namespace std;

int fact(int num){
	if(num == 0)
		return 1;
	return num*fact(num-1);
}

int main(){
	cout<<"Enter a Number to find factorial"<<endl;
	int num;
	cin>>num;
	int ans = fact(num);
	cout<<ans;
	return 0;
}