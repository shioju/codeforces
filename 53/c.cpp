#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  int left = 1, right = n;

  while (left <= right) {
    cout << left++ << " ";
    if (left <= right) {
      cout << right-- << " ";
    }
  }
}
