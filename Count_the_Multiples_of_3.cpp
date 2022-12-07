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
    type lazy, zero, one, two;
    Type() : lazy(0), zero(0), one(0), two(0) {};
  };
  vector<Type> tree;
  int n;

  void build(int at, int b, int e) {
    if (b == e) {
      tree[at].zero = 1;
      tree[at].one = tree[at].two = 0;
      return;
    }
    int mid = (b + e) >> 1;
    build(2 * at, b, mid);
    build(2 * at + 1, mid + 1, e);
    tree[at].zero = tree[2 * at].zero + tree[2 * at + 1].zero;
    tree[at].one = tree[2 * at].one + tree[2 * at + 1].one;
    tree[at].two = tree[2 * at].two + tree[2 * at + 1].two;
  }

  void propagate(int at, int b, int e) {
    int cnt = tree[at].lazy % 3;
    while (cnt--) {
      int temp = tree[at].two;
      tree[at].two = tree[at].one;
      tree[at].one = tree[at].zero;
      tree[at].zero = temp;
    }
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
      int temp = tree[at].two;
      tree[at].two = tree[at].one;
      tree[at].one = tree[at].zero;
      tree[at].zero = temp;
      if (b != e) {
        tree[2 * at].lazy += val;
        tree[2 * at + 1].lazy += val;
      }
      return;
    }
    int mid = (b + e) >> 1;
    update(2 * at, b, mid, l, r, val);
    update(2 * at + 1, mid + 1, e, l, r, val);
    tree[at].zero = tree[2 * at].zero + tree[2 * at + 1].zero;
    tree[at].one = tree[2 * at].one + tree[2 * at + 1].one;
    tree[at].two = tree[2 * at].two + tree[2 * at + 1].two;
  }

  type query(int at, int b, int e, int l, int r) {
    if (tree[at].lazy) propagate(at, b, e);
    if (r < b or e < l) return 0;
    if (l <= b and e <= r) return tree[at].zero;
    int mid = (b + e) >> 1;
    type x = query(2 * at, b, mid, l, r);
    type y = query(2 * at + 1, mid + 1, e, l, r);
    return x + y;
  }

public:
  SegTreeLaxySum(int n) {
    this->n = n;
    tree.resize(4 * n);
    build(1, 1, n);
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
      if (op == 0) {
        int l, r; cin >> l >> r;
        l++, r++;
        segTree.update(l, r, 1);
      } else {
        int l, r; cin >> l >> r;
        l++, r++;
        cout << segTree.query(l, r) << nl;
      }
    }
  }
  return 0;
}
