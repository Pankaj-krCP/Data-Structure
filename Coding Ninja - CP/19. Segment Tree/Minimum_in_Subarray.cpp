#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
void buildtree(int *arr, int *tree, int start, int end, int treenode)
{
    if (start == end)
    {
        tree[treenode] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    buildtree(arr, tree, start, mid, 2 * treenode);
    buildtree(arr, tree, mid + 1, end, 2 * treenode + 1);
    tree[treenode] = min(tree[2 * treenode], tree[2 * treenode + 1]);
}
void updatetree(int *arr, int *tree, int start, int end, int treenode, int index, int value)
{
    if (start == end)
    {
        arr[index] = value;
        tree[treenode] = value;
        return;
    }
    int mid = (start + end) / 2;
    if (index > mid) //right
    {
        updatetree(arr, tree, mid + 1, end, 2 * treenode + 1, index, value);
    }
    else //left
    {
        updatetree(arr, tree, start, mid, 2 * treenode, index, value);
    }
    tree[treenode] = min(tree[2 * treenode], tree[2 * treenode + 1]);
}
int query(int *tree, int start, int end, int treenode, int left, int right)
{
    if (start > right || end < left)
    {
        return INT_MAX;
    }

    if (start >= left && end <= right)
    {
        return tree[treenode];
    }
    int mid = (start + end) / 2;
    int ans1 = query(tree, start, mid, 2 * treenode, left, right);
    int ans2 = query(tree, mid + 1, end, 2 * treenode + 1, left, right);
    return min(ans1, ans2);
}
int main()
{
    int n, q;
    cin >> n >> q;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int *tree = new int[4 * n];
    buildtree(arr, tree, 0, n - 1, 1);
    //at this point of time i have my tree with me.
    while (q--)
    {
        char query_type;
        cin >> query_type;
        if (query_type == 'q')
        {
            int l, r;
            cin >> l >> r;
            cout << query(tree, 0, n - 1, 1, l - 1, r - 1) << endl;
        }
        else
        {
            int x, y;
            cin >> x >> y;
            //we need to update arr[x]=y;
            updatetree(arr, tree, 0, n - 1, 1, x - 1, y);
        }
    }
}