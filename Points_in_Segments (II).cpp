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


template<typename type> class SegTreeLaxySum {
private:
  struct Type {
    type sum, lazy;
    Type() : sum(0), lazy(0) {}
  };
  vector<Type> tree;
  int n;
  void propagate(int at, int b, int e) {
    tree[at].sum += tree[at].lazy * (e - b + 1);
    if (b != e) {
      tree[2 * at].lazy += tree[at].lazy;
      tree[2 * at + 1].lazy += tree[at].lazy;
    }
    tree[at].lazy = 0;
  }
  void update(int at, int b, int e, int l, int r, type val) {
    if (tree[at].lazy) propagate(at, b, e);
    if (r < b or e < l) return;
    if (l <= b and e <= r) {
      tree[at].sum += val * (e - b + 1);
      if (b != e) {
        tree[2 * at].lazy += val;
        tree[2 * at + 1].lazy += val;
      }
      return;
    }
    int mid = (b + e) >> 1;
    update(2 * at, b, mid, l, r, val);
    update(2 * at + 1, mid + 1, e, l, r, val);
    tree[at].sum = tree[2 * at].sum + tree[2 * at + 1].sum;
  }
  type query(int at, int b, int e, int l, int r) {
    if (tree[at].lazy) propagate(at, b, e);
    if (r < b or e < l) return 0;
    if (l <= b and e <= r) return tree[at].sum;
    int mid = (b + e) >> 1;
    type x = query(2 * at, b, mid, l, r);
    type y = query(2 * at + 1, mid + 1, e, l, r);
    return x + y;
  }
public:
  SegTreeLaxySum(int n) {
    this->n = n;
    tree.resize(4 * n);
  }
  void update(int l, int r, type val) {
    update(1, 1, n, l, r, val);
  }
  type query(int l, int r) {
    return query(1, 1, n, l, r);
  }
};
int main() {
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(false); cin.tie(0);
  int test = 1, tc = 0; cin >> test;
  while (test--) {
    int n, m; cin >> n >> m;
    vector<pii> range;
    set<int> s;
    for (int i = 1; i <= n; ++i) {
      int x, y; cin >> x >> y;
      range.push_back({x, y});
      s.insert(x);
      s.insert(y);
    }
    vi point;
    for (int i = 1; i <= m; ++i) {
      int x; cin >> x;
      point.push_back(x);
      s.insert(x);
    }
    map<int, int> Map;
    int cnt = 0;
    for (int x : s) Map[x] = ++cnt;
    for (auto& x : range) {
      x.ff = Map[x.ff];
      x.ss = Map[x.ss];
    }
    SegTreeLaxySum<ll> segTree(cnt);
    for (int& x : point) x = Map[x];
    for (auto x : range) segTree.update(x.ff, x.ss, 1);
    cout << "Case " << ++tc << ":\n";
    for (auto x : point) cout << segTree.query(x, x) << nl;
  }
  return 0;
}
