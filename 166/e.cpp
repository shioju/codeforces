#include <bits/stdc++.h>

using namespace std;

int main() {
  const int MOD = 1000000007;
  int n;
  cin >> n;

  vector<int> d(n+2);
  vector<int> x(n+2);

  d[1]=0;
  d[2]=3;
  x[1]=1;
  x[2]=2;

  for (int i=3; i<=n; i++) {
    d[i] = ((x[i-1] + x[i-1]) % MOD + x[i-1]) % MOD;
    x[i] = ((x[i-1] + x[i-1]) % MOD + d[i-1]) % MOD;
  }

  cout << d[n];
}

