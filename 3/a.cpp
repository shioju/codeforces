#include <bits/stdc++.h>

using namespace std;

int main() {
  string s, t;
  cin >> s >> t;

  char sx, sy, tx, ty;
  sx = s[0];
  sy = s[1];
  tx = t[0];
  ty = t[1];

  int dx = tx - sx;
  int dy = ty - sy;
  cout << max(abs(dx), abs(dy)) << endl;

  while (dx!=0 || dy!=0) {
    if (dx>0) {
      cout << "R";
      dx--;
    } else if (dx<0) {
      cout << "L";
      dx++;
    }

    if (dy>0) {
      cout << "U";
      dy--;
    } else if (dy<0) {
      cout << "D";
      dy++;
    }

    cout << endl;
  }
}
