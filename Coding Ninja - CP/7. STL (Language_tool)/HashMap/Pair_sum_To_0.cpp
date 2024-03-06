/*
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int count=0;
    map<int,int> m;
    map<int,int>:: iterator it;
    for(int i=0;i<n;i++){
        int num=arr[i];
        m[arr[i]]++;
        for(it=m.begin();it!=m.end();it++){
            if(-num==it->first){
                while(it->second--){
                    count++;
                }
            }
        }
    }
    cout<<count;
    return 0;
}
*/

#include<bits/stdc++.h>
using namespace std;

void PairSum(int *arr, int n)
{
    sort(arr, arr+n);
    int starting_position_of_positive_elements=0;
    while(arr[starting_position_of_positive_elements]<0)
    {
        starting_position_of_positive_elements++;
    }
    map<int, int>m;
    for(int i=starting_position_of_positive_elements; i<n; i++)
    {
        m[arr[i]]+=1;
    }
    for(int i=0; i<starting_position_of_positive_elements; i++)
    {
        int temp=m[-arr[i]];
        if(temp>0)
        {
            while(temp--)
            {
                cout<<arr[i]<<" "<<-arr[i]<<endl;
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    PairSum(arr,n);
    return 0;
}
