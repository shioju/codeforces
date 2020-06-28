#include<bits/stdc++.h>
using namespace std;
long long t, a, b, c;
int main() {
  cin >> t;
  for(;t--;) {
    cin >> a >> b >> c;
    long long r1, r2;
    if (a<c) {
      r1 = 1;
    } else {
      r1 = -1;
    }

    long long d = a*b-c;
    if (d > 0) {
      r2 = b;
    } else {
      r2 = -1;
    }
    cout << r1 << " " << r2 << endl;
  }
}
