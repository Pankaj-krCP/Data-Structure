// //print all subsequences of an array
// #include<bits/stdc++.h>
// using namespace std;

// void Subsequences(int idx,int arr[],vector<int> temp,int n){
// 	if(idx == n){
// 		for(auto i:temp)
// 			cout<<i<<" ";
// 		if (temp.size()==0)
// 			cout<<"{}";
// 		cout<<endl;
// 		return;
// 	}
// 	//take the particular index into the subsequences
// 	temp.push_back(arr[idx]);
// 	Subsequences(idx+1,arr,temp,n);
// 	temp.pop_back();
// 	//not take the particular index into the subsequences
// 	Subsequences(idx+1,arr,temp,n);
// }

// int main(){
// 	int arr[] = {3,1,2};
// 	int n = 3;
// 	vector<int> temp;
// 	Subsequences(0,arr,temp,n);
// 	return 0;
// }


#include <bits/stdc++.h>
using namespace std;

void printSubsequence(int idx,string input, string output,int n)
{
	if (idx == n) {
		cout<<output<<endl;
		return;
	}
	printSubsequence(idx+1,input, output + input[idx],n);
	printSubsequence(idx+1,input, output,n);
}

int main()
{
	string output = "";
	string input = "abc";
	int n = 3;
	printSubsequence(0, input, output,n);
	return 0;
}