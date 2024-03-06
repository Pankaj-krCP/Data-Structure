#include<bits/stdc++.h>
using namespace std;

void findAll(map<char,string> mp,string digits,string temp,vector<string> &ans,int i){
	if (i>=digits.size()){
		ans.push_back(temp);
		return;
	}
	char c = digits[i];
	for(auto ch: mp[c]){
		temp.push_back(ch);
		findAll(mp,digits,temp,ans,i+1);
		temp.pop_back();
	}
}

int main(){
	string digits;
	cin>>digits;
	map<char,string> mp{
		{'0',"0"},
		{'1',"1"},
		{'2',"abc"},
		{'3',"def"},
		{'4',"ghi"},
		{'5',"jkl"},
		{'6',"mno"},
		{'7',"pqrs"},
		{'8',"tuv"},
		{'9',"wxyz"}
	};

	string temp = "";
	vector<string> ans;

	if(digits.size()==0)
		cout<<"";

	findAll(mp,digits,temp,ans,0);
	for (auto i:ans)
		cout<<i<<" ";

	return 0;
}