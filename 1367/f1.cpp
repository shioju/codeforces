#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i=0; i<t; i++) {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int j=0; j<n; j++) {
      int a;
      cin >> arr[j];
    }

    int left = 0;
    for (int j=0; j<n; j++) {
      for (int k=j+1; k<n; k++) {
        if (arr[k] < arr[j]) {
          left++;
        }
      }
    }

    int right = 0;
    for (int j=n-1; j>=0; j--) {
      for (int k=j-1; k>=0; k--) {
        if (arr[k] > arr[j]) {
          right++;
        }
      }
    }

    cout << min(left, right) << endl;
  }
}
