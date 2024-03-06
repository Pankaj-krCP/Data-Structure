//Winner of the Death In a circle (Josephus Prolem)
// 1 2 3 4 5
// 3 4 5 1
// 5 1 3
// 3 5
// 3


#include <bits/stdc++.h>
using namespace std;

int answer(int n,int k){
    if (n == 1) return 0;
    int x = answer(n-1,k);
    return (x+k)%n;
}

int main(){
	cout<<answer(5,2)+1;
	return 0;
}