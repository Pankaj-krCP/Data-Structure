#include<bits/stdc++.h>
using namespace std;

int main(){
    //n is that number
    // ith position to be check it is 1 or 0 in n binary form
    //n = 9 , i = 2   // 9=00001001 here 2th position is 0 from right to left
    // then answer will be false
    //for 3 position answer will be true

    int n,i;
    cin>>n>>i;

    int z = n & (1 << i);

    if(z){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    return 0;

}