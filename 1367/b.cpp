#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i=0; i<t; i++) {
    int n;
    cin >> n;
    int bad[2] = {0, 0};
    for (int j=0; j<n; j++) {
      int a;
      cin >> a;
      int parity = j % 2;
      if (a % 2 != parity) {
        bad[parity]++;
      }
    }
    if (bad[0] == bad[1]) {
      cout << bad[0] << endl;
    } else {
      cout << -1 << endl;
    }
  }
}
