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

    sort(s.begin(), s.end());
    cout << "sorted: " << s << endl;
  }
}
