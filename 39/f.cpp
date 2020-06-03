#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> frogs(m);
  vector<int> mosquitoes(k);
  for (int i=0; i<m; i++) {
    int f;
    cin >> f;
    frogs[i] = f;
  }

  for (int i=0; i<k; i++) {
    int m;
    cin >> m;
    mosquitoes[i] = m;
  }

  vector<int> winners;
  int min = 1000000000;
  for (int i=0; i<m; i++) {
    int kills = 0;
    for (int j=0; j<k; j++) {
      if (mosquitoes[j] % frogs[i] == 0) {
        kills++;
      }
    }
    if (kills < min) {
      winners = vector<int> (1, i+1);
      min = kills;
    } else if (kills == min) {
      winners.push_back(i+1);
    }
  }

  cout << winners.size() << endl;
  for (int n: winners) {
    cout << n << " ";
  }
}
