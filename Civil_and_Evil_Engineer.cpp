#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define ff first
#define ss second

class Dsu {
  vector<int> par, rank;
  int n;

  int root(int x) {
    return par[x] = par[x] == x ? x : root(par[x]);
  }

public:
  Dsu(int n) {
    this->n = n;
    par.assign(n + 2, 0);
    rank.assign(n + 2, 0);
    for (int i = 0; i <= n; ++i) {
      par[i] = i;
    }
  }

  bool merge(int a, int b) {
    int x = root(a), y = root(b);
    if (x == y) return 0;
    if (rank[x] <= rank[y]) swap(x, y);
    par[y] = x;
    if (rank[x] == rank[y]) rank[x]++;
    return 1;
  }
};

int fun(vector<pair<int, pair<int, int>>>& edge, int n) {
  Dsu ds(n);
  int cost = 0;
  for (auto x : edge) {
    int w = x.ff, u = x.ss.ff, v = x.ss.ss;
    if (ds.merge(u, v)) cost += w;
  }
  return cost;
}

int main() {
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(false); cin.tie(0);
  int test = 1, tc = 0;
  cin >> test;
  while (test--) {
    int n; cin >> n;
    vector<pair<int, pair<int, int>>> edge;
    while (1) {
      int u, v, w; cin >> u >> v >> w;
      if (u == 0 and v == 0 and w == 0) break;
      edge.push_back({w, {u, v}});
    }
    sort(edge.begin(), edge.end());
    int minCost = fun(edge, n);
    reverse(edge.begin(), edge.end());
    int maxCost = fun(edge, n);
    int avgCost = (minCost + maxCost) / 2;
    if ((avgCost * 2) == (minCost + maxCost)) cout << "Case " << ++tc << ": " << avgCost << nl;
    else cout << "Case " << ++tc << ": " << (minCost + maxCost) << "/2" << nl;
  }
  return 0;
}
