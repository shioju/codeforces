#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> origin(n+1, 0);

  int num_seed;
  cin >> num_seed;

  deque<int> unprocessed;

  for (int i=0; i<num_seed; i++) {
    int seed;
    cin >> seed;
    unprocessed.push_back(seed);
    origin[seed] = seed;
  }

  vector<deque<int>> contacts(n+1, deque<int>(0));
  for (int i=1; i<=n; i++) {
    int num_contacts;
    cin >> num_contacts;
    for (int j=0; j<num_contacts; j++) {
      int contact;
      cin >> contact;
      contacts[i].push_back(contact);
    }
  }

  while (unprocessed.size() > 0) {
    int p = unprocessed.front();
    unprocessed.pop_front();
    for (int contact : contacts[p]) {
      // only process uninfected to prevent infinite loops
      if (origin[contact] == 0) {
        origin[contact] = origin[p];
        unprocessed.push_back(contact);
      }
    }
  }

  map<int, int> clusters;
  for (int i=1; i<=n; i++) {
    if (origin[i] > 0) {
      clusters[origin[i]]++;
    }
  }

  cout << clusters.size() << endl;

  for (pair<int, int> cluster: clusters) {
    cout << cluster.second << " ";
  }
}
