#include<bits/stdc++.h>
using namespace std;

char getchar(int i){
    return (char)(i+97);
}

void printPalindrom(string s){
    map<char,vector<int>> indexMap;
    for(int i=0;i<s.length();i++){
        indexMap[s[i]].push_back(i);
    }

    int odd_freq_count =0;
    for(int i=0;i<26;i++){
        if((indexMap[getchar(i)].size() %2) != 0){
            odd_freq_count++;
        }
    }
    if(odd_freq_count >= 2){
        cout<<"-1";
        return;
    }

    int ans[s.length()];
    int start =0;
    int end = s.length()-1;

    for(int i=0;i<26;i++){
        char currentchar = getchar(i);
        for(int j=0;j<indexMap[currentchar].size();j+=2){
            if((indexMap[currentchar].size()-j)==1){
                ans[s.length()/2]=indexMap[currentchar][j];
                continue;
            }
            ans[start]=indexMap[currentchar][j];
            ans[end]=indexMap[currentchar][j+1];
            start++;
            end--;
        }
    }
    for(int i=0;i<s.length();i++){
        cout<<ans[i] + 1 <<" ";
    }
    return;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        printPalindrom(s);
        cout<<endl;
    }
    return 0;
}