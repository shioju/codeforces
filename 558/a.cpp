#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  map<int, int> left;
  map<int, int> right;

  for (int i=0; i<n; i++) {
    int x, a;
    cin >> x;
    cin >> a;
    if (x>0) {
      right[x] = a;
    } else {
      left[-x] = a;
    }
  }

  int ls = left.size();
  int rs = right.size();
  int lower = min(ls, rs);

  map<int,int>::iterator itr = right.begin();
  map<int,int>::iterator itl = left.begin();
  int total = 0;
  for (int i=0; i<lower; i++) {
    total += itl++->second;
    total += itr++->second;
  }
  if (ls>rs) {
    total += itl++->second;
  } else if (rs>ls) {
    total += itr++->second;
  }
  cout << total << endl;
}
