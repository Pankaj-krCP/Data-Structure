#include<bits/stdc++.h>
using namespace std;

int main(){
    // n is the number
    // i is the position from right to left
    // from ith position we have to clear all the LSB
    // n = 27 (00011011) and i =2 
    // then answer will be 00011000 = 24
    int n,i;

    cin>>n>>i;

    cout<< (n & (~((1<<(i+1))-1)));

    return 0;
}