#include<bits/stdc++.h>
using namespace std;
int t, m;
int counts[2];
string s;
int main(){
  cin >> t;
  for(;t--;){
    cin >> s;
    counts[0]=0;
    counts[1]=0;
    for (char c: s){
      counts[c-'0']++;
    }
    m = min(counts[0], counts[1]);
    if (m % 2 == 1) {
      cout << "DA" << endl;
    } else {
      cout << "NET" << endl;
    }
  }
}
