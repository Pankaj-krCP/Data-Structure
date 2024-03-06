#include<iostream>
#include<utility>
using namespace std;

int main(){
    pair<int,char> p;
    p = make_pair(1,'a');
    cout<<p.first<<" "<<p.second<<endl;

    pair<int,char> p1(2,'b');
    cout<<p1.first<<" "<<p1.second<<endl;

    return 0;
}