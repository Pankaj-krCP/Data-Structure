#include<bits/stdc++.h>
using namespace std;

bool isSafe(int node, int color[], bool graph[101][101], int n, int col) {
  for (int k = 0; k < n; k++) {
    if (k != node && graph[node][k] == 1 && color[k] == col) {
      return false;
    }
  }
  return true;
}
bool solve(int node, int color[], int m, int N, bool graph[101][101]) {
  if (node == N) {
    return true;
  }

  for (int i = 1; i <= m; i++) {
    if (isSafe(node, color, graph, N, i)) {
      color[node] = i;
      if (solve(node + 1, color, m, N, graph)) return true;
      color[node] = 0;
    }
  }
  return false;
}

int main() {
  int N = 4;
  int m = 3;

  bool graph[101][101] = {
    {0, 1, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 0, 1},
    {1, 0, 1, 0}
  };

  int color[N] = {0};

  bool ans = solve(0, color, m, N, graph);
  for(int i=0;i<N;i++){
    cout<<color[i]<<" ";
  }
  cout<<endl;
  cout<<ans;

}