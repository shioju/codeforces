#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i=0; i<t; i++) {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int last = -1;
    int result = 0;
    for (int j=0; j<n; j++) {
      if (s[j] == '1') {
        if (last == -1) {
          int add = j / (k+1);
          result += add;
        } else {
          int add = (j - last) / (k+1) - 1;
          if (add > 0) result += add;
        }
        last = j;
      }
    }
    if (last == -1) {
      int add = n / (k+1);
      result += add;
    } else {
      int add = (n - last) / (k+1) - 1;
      if (add > 0) result += add;
    }

    if (result == 0 && last == -1) {
      cout << 1 << endl;
    } else {
      cout << result << endl;
    }
  }
}
