/*
Set ith bit
Send Feedback
You are given two integers N and i. You need to make ith bit of binary representation of N to 1 and return the updated N.
Counting of bits start from 0 from right to left.
Input Format :
Two integers N and i (separated by space)
Output Format :
Updated N
Sample Input 1 :
4 1
Sample Output 1 :
6
Sample Input 2 :
4 4
Sample Output 2 :
20
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i;
    cin>>n>>i;

    int z = n | (1 << i);
    cout<<z<<endl;

    return 0;
}