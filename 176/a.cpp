#include <bits/stdc++.h>

using namespace std;

bool moreProfit(tuple<int,int,int> a, tuple<int,int,int> b) {
  return get<1>(a) > get<1>(b);
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<tuple<int, int, int>>> data(n, vector<tuple<int, int, int>>(m));

  for (int i=0; i<n; i++) {
    string planet;
    cin >> planet;
    for (int j=0; j<m; j++) {
      int a, b, c;
      cin >> a >> b >> c;
      data[i][j] = make_tuple(a, b, c);
    }
  }

  int maxMoola = 0;
  for (int i=0; i<n; i++) {
    vector<tuple<int, int, int>> buy = data[i];
    for (int j=0; j<n; j++) {
      if (i==j) continue;

      vector<tuple<int, int, int>> sell = data[j];
      vector<tuple<int, int, int>> profits;
      for (int item=0; item<m; item++) {
        int p = get<1>(sell[item]) - get<0>(buy[item]);
        int stock = get<2>(buy[item]);
        profits.push_back(make_tuple(item, p, stock));
      }

      sort(profits.begin(), profits.end(), moreProfit);

      int capacity = k;
      int moola = 0;
      for (tuple<int, int, int> zzz: profits) {
        int item, profit, stock;
        tie(item, profit, stock) = zzz;

        if (profit>0) {
          if (capacity >= stock) {
            moola += stock * profit;
            capacity -= stock;
          } else {
            moola += capacity * profit;
            capacity = 0;
          }
        } else {
          break;
        }
      }

      if (moola > maxMoola) {
        maxMoola = moola;
      }
    }
  }
  cout << maxMoola;
}

