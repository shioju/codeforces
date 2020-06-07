#include <bits/stdc++.h>

using namespace std;
bool same(vector<int>, vector<int>);

int main() {
  int n;
  cin >> n;
  vector<int> rowSums1(n), colSums1(n);
  for (int i=0; i<n; i++) {
    string row;
    cin >> row;
    for (int j=0; j<n; j++) {
      if (row[j] == 'X') {
        rowSums1[i]++;
        colSums1[j]++;
      }
    }
  }

  vector<int> rowSums2(n), colSums2(n);
  for (int i=0; i<n; i++) {
    string row;
    cin >> row;
    for (int j=0; j<n; j++) {
      if (row[j] == 'X') {
        rowSums2[i]++;
        colSums2[j]++;
      }
    }
  }

  if ((same(rowSums1, rowSums2) && same(colSums1, colSums2)) ||
      (same(rowSums1, colSums2) && same(colSums1, rowSums2))) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}

bool same(vector<int> a, vector<int> b) {
  bool forward = true, backward = true;
  int n = a.size();
  for (int i=0; i<n && forward; i++) {
    forward &= a[i] == b[i];
  }
  if (forward) return true;

  for (int i=0; i<n && backward; i++) {
    backward &= a[i] == b[n-i-1];
  }
  return backward;
}
