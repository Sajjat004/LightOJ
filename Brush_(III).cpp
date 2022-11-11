// In the name of Allah, Most Gracious, Most Merciful.
#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

int dp[200][200];
vector<pair<int, int>> v;

int fun(int pos, int k, int n, int w) {
  if (k == 0) return 0;
  if (pos == n) return 0;
  if (dp[pos][k] != -1) return dp[pos][k];
  int ans = fun(pos + 1, k, n, w);
  int ans1 = 0, sum = 0;
  for (int i = pos; i < n; ++i) {
    if ((v[pos].first) + w >= v[i].first) {
      sum += v[i].second;
      ans1 = max(ans1, sum + fun(i + 1, k - 1, n, w));
    }
  }
  return dp[pos][k] = max(ans, ans1);
}

int main() {
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(false); cin.tie(0);
  int test = 1, tc = 0; cin >> test;
  while (test--) {
    int n, w, k; cin >> n >> w >> k;
    map<int, int> cnt;
    set<int> s;
    for (int i = 0; i < n; ++i) {
      int x, y; cin >> x >> y;
      cnt[y]++;
      s.insert(y);
    }
    v.clear();
    for (int x : s) {
      v.push_back({x, cnt[x]});
    }
    memset(dp, -1, sizeof dp);
    cout << "Case " << ++tc << ": " << fun(0, k, v.size(), w) << nl;
  }
  return 0;
}
