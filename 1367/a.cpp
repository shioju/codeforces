#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i=0; i<t; i++) {
    string b;
    cin >> b;
    int length = b.length();
    cout << b[0];
    for (int j=1; j<length-1; j+=2) {
      cout << b[j];
    }
    cout << b[length-1] << endl;
  }
}
