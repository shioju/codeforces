#include <bits/stdc++.h>

using namespace std;

int main() {
  int t, n;
  cin >> t;
  for (int i=0; i<t; i++) {
    cin >> n;
    string prev(n, '0');
    string result="YES";
    for (int j=0; j<n; j++) {
      string s;
      cin >> s;
      for (int k=0; (k<n-1) && (result!="NO"); k++) {
        if (prev[k]=='1' && s[k]=='0') {
          result = "NO";
          break;
        }
        prev[k]=0;
        if (s[k]=='1' && s[k+1]=='0') {
          prev[k]='1';
        }
      }
    }
    cout << result << endl;
  }
}
