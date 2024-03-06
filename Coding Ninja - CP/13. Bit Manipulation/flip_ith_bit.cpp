#include<bits/stdc++.h>
using namespace std;

int main(){
    //n is that number
    // ith position to be flip that bits in n binaray form
    //n = 9 , i = 2   // 9=00001001 here 2th position is 0 from right to left
    // then answer will be 00001101 = 13

    int n,i;
    cin>>n>>i;

    int z = n ^ (1 << i);

    cout<<z<<endl;
    return 0;

}