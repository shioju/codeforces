#include <bits/stdc++.h>

using namespace std;

int main() {
  int up, down;
  cin >> up >> down;
  int total = up + down + 1;
  for (int i=total-up; i<=total; i++) {
    cout << i << " ";
  }
  for (int i=total-up-1; i>0; i--) {
    cout << i << " ";
  }
}
