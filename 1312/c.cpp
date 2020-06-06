#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i=0; i<t; i++) {
    int n;
    long long k;
    cin >> n >> k;
    bitset<54> bs;
    bool bad = false;
    for (int j=0; j<n; j++) {
      long long a;
      cin >> a;

      long long maxElement = 1;
      int maxIndex = 0;
      while (maxElement < a) {
        maxElement *= k;
        maxIndex++;
      }

      // the below lines are mathematically sound, but susceptible to
      // precision problems for large inputs.
      // e.g. 3^34 = 16677181699666569, but pow(3,34) = 16677181699666570
      // int maxIndex = ceil(log(a)/log(k));
      // long long maxElement = pow(k, maxIndex);

      if (a>0 && !bad) {
        long long element = maxElement;
        for (int m=maxIndex; m>=0; m--) {
          if (a >= element) {
            if (bs[m] == 1) {
              bad = true;
              break;
            }
            bs[m] = 1;
            a -= element;
          }
          element /= k;
        }
        if (a > 0) {
          bad = true;
        }
      }
    }
    cout << (bad ? "NO" : "YES") << endl;
  }
}

