// #include<bits/stdc++.h>
// using namespace std;

// int subs(string input,string output[]){
//     if(input.empty()){
//         output[0]="";
//         return 1;
//     }
//     string smallString = input.substr(1);
//     int smallOutputSize = subs(smallString,output);
//     for(int i=0;i<smallOutputSize;i++){
//         output[i+smallOutputSize]=input[0]+output[i];
//     }
//     return 2*smallOutputSize;
// }

// int main(){
//     string input;
//     cin>>input;
//     int num = pow(2,input.length());

//     string output[num];
//     int count = subs(input,output);
//     for(int i=0;i<count;i++){
//         cout<<output[i]<<endl;
//     }

//     return 0;
// }

#include <iostream>
using namespace std;

void print_subs(string input, string output) {
	if (input.length() == 0) {
		cout << output << endl;
		return;
	}

	print_subs(input.substr(1), output);
	print_subs(input.substr(1), output + input[0]);
}

int main() {
	string input;
	cin >> input;
	string output = "";
	print_subs(input, output);
}
