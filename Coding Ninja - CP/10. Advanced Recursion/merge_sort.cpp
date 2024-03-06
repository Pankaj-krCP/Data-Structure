/*
Merge Sort Code
Send Feedback
Sort an array A using Merge Sort.
Change in the input array itself. So no need to return or print anything.
Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)
Output format :
Array elements in increasing order (separated by space)
Constraints :
1 <= n <= 10^3
Sample Input 1 :
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8
Sample Input 2 :
5
2 1 5 2 3
Sample Output 2 :
1 2 2 3 5 
*/
#include<bits/stdc++.h>
using namespace std;

void merge(int arr[],int low,int mid,int high){
    int i,j,k;
    int B[high];
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
            B[k++]=arr[i++];
        }
        else{
            B[k++]=arr[j++];
        }
    }
     while (i <= mid)
    {
        B[k++] = arr[i++];
    }
    while (j <= high)
    {
        B[k++] = arr[j++];
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = B[i];
    }
}

void merge_sort(int arr[],int low,int high){
    if(low==high){
        return;
    }
    int mid=(low+high)/2;
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
    merge(arr,low,mid,high);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    merge_sort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}