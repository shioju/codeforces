#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> results(n+1);

  for (int i=1; i<n; i++) {
    int m;
    cin >> m;
    results[i] += m;
    int furthest = i + pow(2, floor(log2(n-i)));  
    results[furthest] += results[i];
    results[i] += results[i-1];
    cout << results[i] << endl;
  }
}

