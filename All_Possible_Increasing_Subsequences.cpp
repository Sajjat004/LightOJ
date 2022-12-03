// In the name of Allah, Most Gracious, Most Merciful.
#include <bits/stdc++.h>
using namespace std;

using ll  = long long;
using vll = vector<ll>;
using vi  = vector<int>;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

const int N   = (int) 2e5 + 5;
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9 + 9;

#define nl      '\n'
#define ff      first
#define ss      second
#define szof(x) (int) x.size()
#define all(x)  x.begin(), x.end()

template<typename type> class FenwickTree {
private:
  vector<type> tree;
  int n;
public:
  FenwickTree(int n) {
    this->n = n;
    tree.assign(n + 2, 0);
  }
  void update(int idx, type val) {
    while (idx <= n) {
      tree[idx] += val;
      idx += (idx & -idx);
    }
  }
  type query(int idx) {
    type sum = 0;
    while (idx > 0) {
      sum += tree[idx];
      idx -= (idx & -idx);
    }
    return sum;
  }
  type query(int l, int r) {
    return query(r) - query(l - 1);
  }
};

int main() {
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(false); cin.tie(0);
  int test = 1, tc = 0; cin >> test;
  while (test--) {
    int n; cin >> n;
    vi v(n);
    set<int> s;
    for (int& x : v) {
      cin >> x;
      s.insert(x);
    }
    map<int, int> Map;
    int cnt = 0;
    for (int x : s) Map[x] = ++cnt;
    for (int& x : v) x = Map[x];
    FenwickTree<ll> bit(cnt);
    ll ans = 0;
    for (int& x : v) {
      ll sub = bit.query(x - 1) + 1;
      sub %= MOD;
      ans += sub;
      ans %= MOD;
      bit.update(x, sub);
    }
    cout << "Case " << ++tc << ": " << ans << nl;
  }
  return 0;
}
