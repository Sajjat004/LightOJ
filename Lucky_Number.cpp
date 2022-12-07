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

 class SegTree {
  vector<int> tree;
  int n;
  void build(int at, int b, int e) {
    if (b == e) {
      tree[at] = b & 1;
      return;
    }
    int mid = (b + e) >> 1;
    build(2 * at, b, mid);
    build(2 * at + 1, mid + 1, e);
    tree[at] = tree[2 * at] + tree[2 * at + 1];
  }
  void update(int at, int b, int e, int fre) {
    if (b == e) {
      tree[at] = 0;
      return;
    }
    int mid = (b + e) >> 1;
    if (tree[2 * at] >= fre) update(2 * at, b, mid, fre);
    else update(2 * at + 1, mid + 1, e, fre - tree[2 * at]);
    tree[at] = tree[2 * at] + tree[2 * at + 1];
  }
  int query(int at, int b, int e, int fre) {
    if (b == e) return b;
    int mid = (b + e) >> 1;
    if (tree[2 * at] >= fre) return query(2 * at, b, mid, fre);
    else return query(2 * at + 1, mid + 1, e, fre - tree[2 * at]);
  }
public:
  SegTree(int n) {
    this->n = n;
    tree.assign(4 * n, 0);
    build(1, 1, n);
  }
  void update(int fre) {
    update(1, 1, n, fre);
  }
  int query(int fre) {
    return query(1, 1, n, fre);
  }
};

int main() {
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(false); cin.tie(0);
  int test = 1, tc = 0; cin >> test;
  vi ans(100001, 0);
  SegTree segTree(1429432);
  ans[1] = 1;
  for (int i = 2; i <= 100000; ++i) {
    int k = segTree.query(i);
    ans[i] = k;
    int j = (1429431 / k) * k;
    for ( ; j >= k; j -= k) {
      segTree.update(j);
    }
  }
  while (test--) {
    int n; cin >> n;
    cout << "Case " << ++tc << ": " << ans[n] << nl;
  }
  return 0;
}
