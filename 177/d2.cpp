#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m, c;
  cin >> n >> m >> c;
  vector<int> msg(n, 0), keysum(m, 0);
  
  for (int i=0; i<n; i++) {
    cin >> msg[i];
  }

  cin >> keysum[0];
  for (int i=1; i<m; i++) {
    cin >> keysum[i];
    keysum[i] = keysum[i] + keysum[i-1];
  }

  for (int i=0; i<n; i++) {
    int end = min(i, m-1);
    int start = max(0,m-n+i);
    if (start==0) {
      cout << (msg[i] + keysum[end]) % c << " ";
    } else {
      cout << (msg[i] + keysum[end] - keysum[start-1] + c) % c << " ";
    }
  }
}
