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
    Type() : sum(0), lazy(-1) {}
  };
  vector<Type> tree;
  int n;

  void propagate(int at, int b, int e) {
    tree[at].sum = tree[at].lazy * (e - b + 1);
    if (b != e) {
      tree[2 * at].lazy = tree[at].lazy;
      tree[2 * at + 1].lazy = tree[at].lazy;
    }
    tree[at].lazy = -1;
  }

  void update(int at, int b, int e, int l, int r, type val) {
    if (tree[at].lazy != -1) propagate(at, b, e);
    if (r < b or e < l) return;
    if (l <= b and e <= r) {
      tree[at].sum = val * (e - b + 1);
      if (b != e) {
        tree[2 * at].lazy = val;
        tree[2 * at + 1].lazy = val;
      }
      return;
    }
    int mid = (b + e) >> 1;
    update(2 * at, b, mid, l, r, val);
    update(2 * at + 1, mid + 1, e, l, r, val);
    tree[at].sum = tree[2 * at].sum + tree[2 * at + 1].sum;
  }

  type query(int at, int b, int e, int l, int r) {
    if (tree[at].lazy != -1) propagate(at, b, e);
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
    int n, q; cin >> n >> q;
    SegTreeLaxySum<ll> segTree(n);
    cout << "Case " << ++tc << ":\n";
    while (q--) {
      int op; cin >> op;
      if (op == 1) {
        int l, r, val; cin >> l >> r >> val;
        ++l, ++r;
        segTree.update(l, r, val);
      } else {
        int l, r; cin >> l >> r;
        ++l, ++r;
        ll sum = segTree.query(l, r);
        ll len = r - l + 1;
        if (sum % len == 0) cout << sum / len << nl;
        else {
          ll g = __gcd(sum, len);
          cout << sum / g << "/" << len / g << nl;
        }
      }
    }
  }
  return 0;
}
