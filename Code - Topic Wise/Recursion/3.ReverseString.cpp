#include<iostream>
using namespace std;

string reverse(string s){
	if(s.size() == 0)
		return "";
	return s[s.size()-1] + reverse(s.substr(0,s.size()-1));
}

int main(){
	string s;
	cin>>s;
	cout<<reverse(s);
	return 0;
}