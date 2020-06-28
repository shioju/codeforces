#include<bits/stdc++.h>
using namespace std;
int t, level;
long long res;
string s;
int cur; 
int main(){
  cin >> t;
  for(;t--;){
    cin >> s;
    res = 0;
    level = 0;
    cur = 0;
    for (int i=0, len=s.length(); i<len; i++) {
      if (s[i] == '-') {
        cur-=1;
      } else {
        cur+=1;
      }

      if (level + cur < 0) {
        res+=i+1;
        level++;
      }
    }
    res+=s.length();

    cout << res << endl;
  }
}
