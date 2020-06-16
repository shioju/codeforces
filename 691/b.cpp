#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;

  map<char, char> reflection = {{'A', 'A'}, {'b', 'd'}, {'d', 'b'}, {'H', 'H'}, {'I', 'I'}, {'M', 'M'}, {'O', 'O'}, {'o', 'o'}, {'p', 'q'}, {'q', 'p'}, {'T', 'T'}, {'U', 'U'}, {'V', 'V'}, {'v', 'v'}, {'W', 'W'}, {'w', 'w'}, {'X', 'X'}, {'x', 'x'}, {'Y', 'Y'}};
  int left = 0;
  int right = s.length()-1;

  while (left<=right) {
    if (reflection[s[left++]] != s[right--]) {
      cout << "NIE";
      return 0;
    }
  }

  cout << "TAK";
}
