#include<bits/stdc++.h>
using namespace std;
bool included[200001]{false};
set<int> neighbors[200001];
set<pair<int,int>> result;
queue<int> tovisit;

int main() {
  int n, m, u, v, max=0;

  cin >> n >> m;
  for (;m--;) {
    cin >> v >> u;
    neighbors[u].insert(v);
    neighbors[v].insert(u);
  }

  for (int i=1; i<=n; i++) {
    if (neighbors[i].size() > neighbors[max].size()) {
      max = i;
    }
  }
  tovisit.push(max);
  included[max] = true;

  while (!tovisit.empty()) {
    v = tovisit.front();
    tovisit.pop();
    for (int u:neighbors[v]) {
      if (!included[u]) {
        result.insert(pair<int,int>(v,u));
        tovisit.push(u);
        included[u] = true;
      }
    }
  }

  for (auto p: result) {
    cout << p.first << " " << p.second << endl;
  }
}
