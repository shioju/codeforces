#include<bits/stdc++.h>
using namespace std;

int t=1, node[20001], start[20001], finish[20001];
set<int> sub[20001];

void dfs(int v) {
  node[t] = v;
  start[v] = t++;
  for (int i: sub[v]) {
    dfs(i);
  }
  finish[v] = t;
}

int main() {
  int n, q, x, u, k;
  cin >> n >> q;

  for (int i=2; i<=n; i++) {
    cin >> x;
    sub[x].insert(i);
  }
  dfs(1);

  for (;q--;) {
    cin >> u >> k;
    cout << (finish[u]-start[u]>=k?node[start[u]+k-1]:-1) << endl;
  }
}
