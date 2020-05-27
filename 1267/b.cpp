#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  int left = 0, right = s.size()-1;
  int count = 0;
  char color = s[0];
  int lastLeft = left, lastRight = right;
  while (left<=right) {
    if (s[left] == color) {
      left++;
      count++;
    } else if (s[right] == color) {
      right--;
      count++;
    } else {
      if (count>2 && lastLeft < left && right < lastRight) {
        color = s[left];
        count = 0;
        lastLeft = left;
        lastRight = right;
      } else {
        cout << 0;
        return 0;
      }
    }
  }
  if (count>1) {
    cout << (count + 1);
  } else {
    cout << 0;
  }
}
