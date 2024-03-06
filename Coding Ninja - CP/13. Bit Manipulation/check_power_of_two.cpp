#include<bits/stdc++.h>
using namespace std;

int main(){
    //we have to check n is power of 2 or not
    //print yes if power of two else print no
    int n;
    cin>>n;

    if(n & (n-1)){
        cout<<"no"<<endl;
    }else{
        cout<<"yes"<<endl;
    }
    return 0;

}