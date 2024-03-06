#include <bits/stdc++.h>
using namespace std;

void buildTree(int *arr, int *tree, int start, int end, int treeNode)
{
    if (start == end)
    {
        tree[treeNode] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    buildTree(arr, tree, start, mid, 2 * treeNode);
    buildTree(arr, tree, mid + 1, end, 2 * treeNode + 1);
    tree[treeNode] = tree[2 * treeNode] + tree[2 * treeNode + 1];
    return;
}

void updateTree(int *arr, int *tree, int start, int end, int treeNode, int idx, int val)
{
    if (start == end)
    {
        arr[idx] = val;
        tree[treeNode] = val;
        return;
    }
    int mid = (end + start) / 2;
    if (idx > mid)
    {
        updateTree(arr, tree, mid + 1, end, 2 * treeNode + 1, idx, val);
    }
    else
    {
        updateTree(arr, tree, start, mid, 2 * treeNode, idx, val);
    }
    tree[treeNode] = tree[2 * treeNode + 1] + tree[2 * treeNode];
    return;
}

int query(int *tree, int start, int end, int treenode, int left, int right)
{
    //compeletely outside given range
    if (start > right || end < left)
    {
        return 0;
    }

    //compeletely inside given range
    if (start >= left && end <= right)
    {
        return tree[treenode];
    }

    //partialy inside or partially outside given range

    int mid = (start + end) / 2;
    int ans1 = query(tree, start, mid, 2 * treenode, left, right);
    int ans2 = query(tree, mid + 1, end, 2 * treenode + 1, left, right);
    return ans1 + ans2;
}

int main()
{
    int n;
    // cout<<"Enter the size of array"<<endl;
    cin >> n;
    int *arr = new int[n];
    //Insert Element in array
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }
    int *tree = new int[4 * n];
    buildTree(arr, tree, 0, n - 1, 1);

    int idx, val;
    // cout<<"Enter index and value to update"<<endl;
    cin >> idx >> val;
    updateTree(arr, tree, 0, n - 1, 1, idx, val);

    int ans = query(tree, 0, 4, 1, 2, 4); //ans from range 2-4
    cout << "query ans is " << ans << endl;

    delete[] arr;
    delete[] tree;

    return 0;
}